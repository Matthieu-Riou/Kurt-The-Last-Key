#include "Exterieur.h"
#include "../Personnage/Personnage.h"

/** \file Map/Exterieur.cpp
	\brief Représentation du monde extérieur
	\author RIOU, MAUSSION
*/

/** \brief Constructeur d'Exterieur
	Crée aléatoirement de batiments puis crée le ciel et les éléments de décors
	\param difficulte Permet de faire varier la difficulter (nombre de batiments)
	\param perso Le personnage qui évolue dans cette map
*/
Exterieur::Exterieur(int difficulte, ConteneurPersonnage* perso) : Map(this, perso)	
{    
	longueur_ = Math::max(genererBatiment(Aleatoire::getNext(3, 6) * difficulte), Propriete::Fenetre::fenX());

	fond_.setSize(sf::Vector2f(longueur_, Propriete::Fenetre::hauteurSol()));
	fond_.setFillColor(sf::Color::Cyan);

	genererDecorSol();
	genererDecorAir();
	
	addObjet(new EtoileVitesse());
	addObjet(new EtoileVitesse());
	addObjet(new EtoileSaut());
	addObjet(new EtoileCouleur());
	
}

/** \brief Destructeur d'Exterieur
	Détruit les décors, les batiments et le personnage
*/
Exterieur::~Exterieur()
{
	for(std::list<Decor*>::iterator it = decor_.begin(); it != decor_.end(); ++it) //Destruction du décor
	{
		delete *it;
		*it = NULL;
	}
	
	for(unsigned int i = 0; i < batiments_.size(); i++)
	{
		delete batiments_[i];
		batiments_[i] = NULL;
	}
	
	for (unsigned int i=0; i<objet_.size();i++)
        delete objet_[i];	
       
	delete Kurt; //On ne le delete pas de base dans Map (classe mère), comme ça, si on veut détruire un batiment sans arrête le jeu, on peut. Mais quand on détruit la map extérieure, alors on détruit aussi le personnage
}

/** \brief Génère des décors pour le sol (arbres et rochers) et leurs attribut des positions aléatoires (en x)
*/
void Exterieur::genererDecorSol()
{
	int espaceCote(50);
	int espace(50);
	int index(espaceCote);

	while(index < (longueur_ - espaceCote))
	{
		if(Aleatoire::getNext(0,100) == 49)
		{
			if(Aleatoire::getNext(0,3) == 1)
				decor_.push_back(new Rocher(index));
			else
				decor_.push_back(new Arbre(index));
				
			index += espace;
		}
		else
			index++;
	}
	
}
/** \brief Génère des décors du ciel (nuages) et leurs attribut des positions aléatoires (en x)
*/
void Exterieur::genererDecorAir()
{
	int espaceCote(50);
	int espace(150);
	int index(espaceCote);

	while(index < (longueur_ - espaceCote))
	{
		if(Aleatoire::getNext(0,100) == 99)
		{
			decor_.push_back(new Nuage(index));
			index += espace;
		}
		else
			index++;
	}
}

/** \brief Génère nb batiments et génère les clés associés
	\param nbBatiment Le nombre de batiments voulus
	\return La longueur obtenue pour créer les batiments
*/
int Exterieur::genererBatiment(int nbBatiment)
{
	int espace(50);
	int index(espace);
	int cptBatiment(0);

	while(cptBatiment < nbBatiment)
	{
		if(Aleatoire::getNext(0,50) == 49)
		{
			batiments_.push_back(new BatimentExterieur(index, this, Kurt));
				
			index += batiments_.back()->getTaille().x + espace;
			
			cptBatiment++;
		}
		else
			index++;
	}

	genererCle(nbBatiment);
	
	return index;
}

/** \brief Crée des clés, les places dans les batiments et ferme des batiments
	\param nbBatiment Le nombre de batiments voulus
*/
void Exterieur::genererCle(int nbBatiment)
{
	//classe union rapide et très simplifiée
	std::vector<int> cles(nbBatiment, -1);
	std::vector<int> classeUnion(nbBatiment);
		
	for(unsigned int i = 0; i < classeUnion.size(); i++)
	{
		classeUnion[i] = i;
	}

	int cptBatFerme(0);
	int bat;
	int batCible;

	//4 chances sur 5 de continuer à généré des clés
	do
	{
		//Revoir l'algo ! (optimisation)
		do
		{
			bat = Aleatoire::getNext(0, nbBatiment);
		}while(batiments_[bat]->estFerme()); //On prend un batiment ouvert

		do
		{
			batCible = Aleatoire::getNext(0, nbBatiment);
		}while(classeUnion[bat] == classeUnion[batCible]);

		//Union
		int id = classeUnion[bat];
		for(unsigned int i = 0; i < classeUnion.size(); i++)
		{
			if(classeUnion[i] == id)
				classeUnion[i] = classeUnion[batCible];
		}

		batiments_[bat]->fermer();
		batiments_[batCible]->addCle(new Cle(batiments_[bat]));

		cptBatFerme++;

	}while(cptBatFerme < nbBatiment - 1 && Aleatoire::getNext(0, 5) != 1); //Include la difficulte dans l'aleatoire d'arret
}

void Exterieur::start(sf::RenderWindow &app)
{
	(*Kurt)->setPosition(sf::Vector2f(-100, (*Kurt)->getPosition().y), DROITE);

	while((*Kurt)->getPosition().x < 50)
	{
		update();
		(*Kurt)->deplacer(DROITE, (*Kurt)->getVitesse());
		app.clear(sf::Color::Black);
		afficher(app);
		app.display();
	}
}

/** \brief Appel à Map::sortir()
*/
void Exterieur::sortir()
{
	Map::sortir();
}


/** \brief Ajoute un objet à une position aléatoire dans la map
	\param o L'objet à ajouter
*/
void Exterieur::addObjet(Objet* o){
	sf::Vector2f pos(0, Propriete::Fenetre::hauteurSol() - o->getTaille().y );
	pos.x = Aleatoire::getNext(0, longueur_-o->getTaille().x );
	o->setPosition(pos);	
	objet_.push_back(o);
}



/** \brief Gére les entrées clavier si il s'agit de la map courante
*/
void Exterieur::gestionEvent()
{
	if(mapCourante_ == this)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			deplacer(GAUCHE);
		}
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			deplacer(DROITE);
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			(*Kurt)->sauter();
		}
	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			bool avant(true);
			unsigned int i(0);
		
			while(avant && i < batiments_.size())
			{
				sf::Vector2f centreKurt = (*Kurt)->getCentre();
			
				if(Espace::estDans(centreKurt.x,batiments_[i]->getPositionPorte().x,batiments_[i]->getPositionPorte().x + batiments_[i]->getTaillePorte().x))
				{
					if(batiments_[i]->estOuvert() || (*Kurt)->essayerOuvrirBatiment(batiments_[i]))
					{
						if((*Kurt)->entrerBatiment())
						{
							mapCourante_ = batiments_[i]->getInterieur()->getEtage();
							mapCourante_->entrer();
						}
					}
				
					avant = false;
				}
				else if(centreKurt.x < batiments_[i]->getPositionPorte().x)
					avant = false;
				
				i++;
			}
		}
	}
	else
		mapCourante_->gestionEvent();
}

/** \brief Actualise les éléments de la map (le personnage, les décors) et lance gestionEvent() (gestion entrées clavier)  s'il s'agit de la map courante
*/
void Exterieur::update()
{
	if(mapCourante_ == this)
	{	
		//Animation du décor
		for(std::list<Decor*>::iterator it = decor_.begin(); it != decor_.end(); )
		{
			(*it)->update();
	
			if((*it)->getPosition().x < fond_.getPosition().x - 92) //Pour les nuages
			{
				//Si on veut juste supprimer le nuage sans le remplacer :
				//Attention à la suppression pendant un parcours !
				delete *it;
				it = decor_.erase(it);
			}
			else
			{
				++it;
			}
		}
	
		//Création des nouveaux nuages
		if(Aleatoire::getNext(0, 500) == 499) //Une chance sur 500
			decor_.push_back(new Nuage(longueur_));	

		(*Kurt)->update();
	
		posKurt = (*Kurt)->getPosition();
		dirKurt = (*Kurt)->getDirection();
		
		gestionEvent();
	}
	else
		mapCourante_->update();
}

/** \brief Déplace le personnage en fonction de la direction puis test s'il gagne un objet
	\param d La direction du mouvement
*/
void Exterieur::deplacer(Dir d)
{
	sf::Vector2f centreVue = viewMap_.getCenter();
	float vitesse = (*Kurt)->getVitesse();
	float ecart;
	
    switch(d)
    {
        case GAUCHE:
            if(Espace::estDans((*Kurt)->getCentre().x, centreVue.x -10, centreVue.x +10) && centreVue.x > Propriete::Fenetre::fenX()/2)
            {
               	viewMap_.move(-vitesse, 0.);
            	(*Kurt)->deplacer(GAUCHE, vitesse);
            }
            else if((*Kurt)->getPosition().x > 0)          
                (*Kurt)->deplacer(GAUCHE, vitesse);
            else
            	(*Kurt)->animer(GAUCHE);
                
            
        	ecart = Propriete::Fenetre::fenX()/2 - centreVue.x;
           	
            if(ecart > 0)
            {
            	viewMap_.move(ecart, 0.);
            }
            
            
                
            break;

        case DROITE:
            if(Espace::estDans((*Kurt)->getCentre().x, centreVue.x -10, centreVue.x +10) && centreVue.x < longueur_ - Propriete::Fenetre::fenX()/2)
             {  
                viewMap_.move(vitesse, 0.);
            	(*Kurt)->deplacer(DROITE, vitesse);
            }
            else if((*Kurt)->getPosition().x + (*Kurt)->getTaille().x < longueur_)         
                (*Kurt)->deplacer(DROITE, vitesse);
            else
            	(*Kurt)->animer(DROITE);
            	
            	
           	ecart = centreVue.x - (longueur_ - Propriete::Fenetre::fenX()/2);
           	
            if(ecart > 0)
            {
            	viewMap_.move(-ecart, 0.);
            }

            break;
        default:
        	break;
    }
    
    posKurt = (*Kurt)->getPosition();
	dirKurt = (*Kurt)->getDirection();
	
	testRamasserObjet();
	
}

/** \brief Affiche l'extérieur (le ciel, les decors, les objets, les batiments et le personnage)
	\param app La fenetre du jeu
*/
void Exterieur::afficher(sf::RenderWindow &app) const
{
	if(mapCourante_ == this)
	{
		Map::afficher(app);
		
		app.draw(fond_);
		
		for(std::list<Decor*>::const_iterator it = decor_.begin(); it != decor_.end(); ++it)
			(*it)->afficher(app);
			
		for(unsigned int i = 0; i < batiments_.size(); i++)
			batiments_[i]->afficher(app);
			
	
		for(unsigned int i = 0; i < objet_.size(); i++)
		{
			objet_[i]->afficher(app);
		}
			
		(*Kurt)->afficher(app);
	}
	else
		mapCourante_->afficher(app);
}

