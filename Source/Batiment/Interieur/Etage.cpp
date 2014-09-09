#include "Etage.h"
#include "../../Personnage/Personnage.h"

/*! \file Interieur/Etage.cpp
	\brief Un étage d'un batiment
	\author RIOU, MAUSSION
*/


/*! \brief Constructeur d'un étage, initialise les variables puis construit les murs et le sol
	\param width La largeur
	\param prof La profondeur
	\param perso Le personnage qui est dans l'étage
	\param mapParent La map parent de l'étage
*/	
Etage::Etage(int width, int prof, ConteneurPersonnage* perso, Map* mapParent) : Map(this, perso, mapParent), width_(width), prof_(prof), sol(sf::RectangleShape(sf::Vector2f(width_,prof_)))
{
	sf::Vector2f hg(0, 0);
	sf::Vector2f hd(width_ - Propriete::Etage::tailleMur(), 0);
	sf::Vector2f bg(0, prof_ - Propriete::Etage::tailleMur());
	
    murs_.push_back(new MurVertical(hg, prof_));    // mur g
    murs_.push_back(new MurHorizontal(hg, width_));    //mur h
    murs_.push_back(new MurVertical(hd,prof_));    //mur d
    murs_.push_back(new MurHorizontal(bg,width_));    //mur b	
    
    murs_.back()->addFrontDoor(sf::Vector2f(width_/2 - 25, prof_), sf::Vector2f(width_/2 + 25, prof_));
    frontDoor_ = murs_.back()->getFrontDoor();
    
    genererEtage();
    
    sol.setFillColor(Propriete::Etage::colorSol());
}

/*! \brief Destructeur de l'étage */
Etage::~Etage()
{
	for (unsigned int i=0; i<murs_.size();i++)
        delete murs_[i];
        
    for (unsigned int i=0; i<objet_.size();i++)
        delete objet_[i];	
}


/*! \brief Fonction appeler quand un personnage entre dans l'étage (place le personnage et gère la view)
*/
void Etage::entrer()
{
	sf::Vector2f p(frontDoor_->getPoint(0));
	p.x += 5;
	p.y -= (*Kurt)->getTaille().y;
	(*Kurt)->setPosition(p, HAUT);
	
	viewMap_.setCenter(width_/2+5, prof_ - Propriete::Fenetre::hauteurSol()/2);
	
	std::cerr << "Nombre d'objets (cle) dans ce batiment : " << objet_.size() << std::endl;
}

/*! \brief Place des murs dans l'étage
*/
void Etage::genererEtage()
{
	murs_.push_back(new MurHorizontal(sf::Vector2f(0, prof_/3), 2*width_/3));
	murs_.back()->addDoor(sf::Vector2f(width_/3, prof_/3), sf::Vector2f(width_/3 + 50, prof_/3));
	murs_.push_back(new MurVertical(sf::Vector2f(2*width_/3, 0), prof_));
	murs_.back()->addDoor(sf::Vector2f(2*width_/3, prof_/8), sf::Vector2f(2*width_/3, prof_/8 + 50));
	murs_.back()->addDoor(sf::Vector2f(2*width_/3, 4*prof_/6), sf::Vector2f(2*width_/3, 4*prof_/6 + 50));
}


/*! \brief Ajoute un objet à une position aléatoire dans l'étage
	\param o Objet que l'on veut ajouter
*/
void Etage::addObjet(Objet* o)
{
	int i = Aleatoire::getNext(2, murs_.size() );
	if (murs_[i]->isHorizontal())
		o->setPosition( sf::Vector2f( murs_[i]->getPosition().x + Propriete::Etage::tailleMur(), murs_[i]->getPosition().y -o->getTaille().y));
	else
		o->setPosition( sf::Vector2f( murs_[i]->getPosition().x -o->getTaille().x, murs_[i]->getPosition().y));
	objet_.push_back(o);
}




/*! \brief Permet de gérer les évènements (entrées clavier) si il s'agit de la map courante
	Si on il s'agit de la map courante, on teste les diférentes entrées clavier
*/
void Etage::gestionEvent()
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
	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			deplacer(HAUT);
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			deplacer(BAS);
			
			sf::Vector2f newPosKurt(posKurt.x, posKurt.y + (*Kurt)->getTaille().y);
			sf::Vector2f newPosKurt2(posKurt.x + (*Kurt)->getTaille().x, posKurt.y + (*Kurt)->getTaille().y);
			
			if(frontDoor_ != NULL && Espace::estDans(newPosKurt, frontDoor_->getPoint(0), frontDoor_->getPoint(2)) && Espace::estDans(newPosKurt2, frontDoor_->getPoint(0), frontDoor_->getPoint(2)))
			{
				if((*Kurt)->sortirBatiment())
					mapParent_->sortir();
			}
		}
		
		

	}
	else
		mapCourante_->gestionEvent();
}

/*! \brief Actualise l'étage en fonction des entrées clavier
*/
void Etage::update()
{
	gestionEvent();
}



/*! \brief Permet de savoir si le personnage entre en collision avec un mur en se déplacant dans la direction d
	\param d La direction du déplacement
	\return vrai si on entre en collision avec un mur en se déplacant vers d, faux sinon
*/
bool Etage::collision(Dir d) const
{
	sf::Vector2f newPosKurt = (*Kurt)->getPosition();
	sf::Vector2f newPosKurt2 = (*Kurt)->getPosition();
	
	float vitesseKurt = (*Kurt)->getVitesse(); //Attention, si la vitesse est trop grande, il pourra traverser un mur
	
	/* Simulation du déplacement */
	switch(d)
	{
		case GAUCHE:
			newPosKurt.x -= vitesseKurt;
			
			newPosKurt2.x -= vitesseKurt;
			newPosKurt2.y += (*Kurt)->getTaille().y;
			break;
			
		case DROITE:
			newPosKurt.x += vitesseKurt + (*Kurt)->getTaille().x;
			
			newPosKurt2.x += vitesseKurt + (*Kurt)->getTaille().x;
			newPosKurt2.y += (*Kurt)->getTaille().y;
			
			break;
			
		case HAUT:
			newPosKurt.y -= vitesseKurt;
			
			newPosKurt2.x += (*Kurt)->getTaille().x;
			newPosKurt2.y -= vitesseKurt;
			break;
			
		case BAS:
			newPosKurt.y += vitesseKurt + (*Kurt)->getTaille().y;
			
			newPosKurt2.x += (*Kurt)->getTaille().x;
			newPosKurt2.y += vitesseKurt + (*Kurt)->getTaille().y;
			break;
			
	}
	
	/* Test de la nouvelle position */
	bool collision(false);
	unsigned int i(0);
	
	while(!collision && i < murs_.size())
	{
		collision = murs_[i]->collision(newPosKurt) || murs_[i]->collision(newPosKurt2);
		i++;
	}
	
	return  collision;
				
}



/*! \brief Déplace le personnage en fonction de la direction choisie et teste si il est sur un objet pour le lui ajouter
	\param d La direction voulue	
*/
void Etage::deplacer(Dir d)
{
	sf::Vector2f centreVue = viewMap_.getCenter();
	float vitesseKurt = (*Kurt)->getVitesse();
	
	float ecart;
	
    switch(d)
    {
        case GAUCHE:
            if(Espace::estDans((*Kurt)->getCentre().x, centreVue.x -10, centreVue.x +10) && centreVue.x > Propriete::Fenetre::fenX()/2 && !collision(GAUCHE))
            {
               	viewMap_.move(-vitesseKurt, 0.);
            	(*Kurt)->deplacer(GAUCHE, vitesseKurt);
            	
            	
        	 	ecart = Propriete::Fenetre::fenX()/2 - centreVue.x;
           	
				if(ecart > 0)
				{
					viewMap_.move(ecart, 0.);
				}
            	
            }
            else if((*Kurt)->getPosition().x > 0 && !collision(GAUCHE))          
           	{
           		(*Kurt)->deplacer(GAUCHE, vitesseKurt);
           		
           		ecart = -(*Kurt)->getPosition().x;
           	
				if(ecart > 0)
				{
					viewMap_.move(ecart, 0.);
				}
				
			}
            else
            	(*Kurt)->animer(GAUCHE);
            	
           
                
            break;
            

        case DROITE:
            if(Espace::estDans((*Kurt)->getCentre().x, centreVue.x -10, centreVue.x +10) && centreVue.x < width_ - Propriete::Fenetre::fenX()/2 && !collision(DROITE))
             {  
                viewMap_.move(vitesseKurt, 0.);
            	(*Kurt)->deplacer(DROITE, vitesseKurt);
            	
            	
            	ecart = centreVue.x - (width_ - Propriete::Fenetre::fenX()/2);
           	
		        if(ecart > 0)
		        {
		        	viewMap_.move(-ecart, 0.);
		        }
            	
            }
            else if((*Kurt)->getPosition().x + (*Kurt)->getTaille().x < width_ && !collision(DROITE))         
            {
            	(*Kurt)->deplacer(DROITE, vitesseKurt);
            	
            	ecart = ((*Kurt)->getPosition().x + (*Kurt)->getTaille().x) - width_;
           	
		        if(ecart > 0)
		        {
		        	viewMap_.move(-ecart, 0.);
		        }
            }
            else
            	(*Kurt)->animer(DROITE);
            	
            	
            
            

            break;
            
            
        case HAUT:
            if(Espace::estDans((*Kurt)->getCentre().y, centreVue.y -10, centreVue.y +10) && centreVue.y > Propriete::Fenetre::hauteurSol()/2 && !collision(HAUT))
             {  
                viewMap_.move(0., -vitesseKurt);
            	(*Kurt)->deplacer(HAUT, vitesseKurt);
            	
            	ecart = Propriete::Fenetre::hauteurSol()/2 - centreVue.y;
           	
		        if(ecart > 0)
		        {
		        	viewMap_.move(0., ecart);
		        }
            
            }
            else if((*Kurt)->getPosition().y > 0 && !collision(HAUT))         
            {
            	(*Kurt)->deplacer(HAUT, vitesseKurt);
            	
            	ecart = -(*Kurt)->getPosition().y;
           	
		        if(ecart > 0)
		        {
		        	viewMap_.move(0., ecart);
		        }
            }
            else
            	(*Kurt)->animer(HAUT);
            	
            	
            
            

            break;
            
            
        case BAS:
            if(Espace::estDans((*Kurt)->getCentre().y, centreVue.y -10, centreVue.y +10) && centreVue.y < prof_ - Propriete::Fenetre::hauteurSol()/2 && !collision(BAS))
             {  
                viewMap_.move(0., vitesseKurt);
            	(*Kurt)->deplacer(BAS, vitesseKurt);
            	
            	ecart = centreVue.y - (prof_ - Propriete::Fenetre::hauteurSol()/2);
           	
		        if(ecart > 0)
		        {
		        	viewMap_.move(0., -ecart);
		        }
            }
            else if((*Kurt)->getPosition().y + (*Kurt)->getTaille().y < prof_ && !collision(BAS))         
            {
                (*Kurt)->deplacer(BAS, vitesseKurt);
                
                ecart = ((*Kurt)->getPosition().y + (*Kurt)->getTaille().y) - prof_;
            	
            	if(ecart > 0)
            		(*Kurt)->deplacer(BAS, -ecart);
            }
            else
            	(*Kurt)->animer(BAS);
            	
            	
            
            
            
            
                       	

            break;
        default:
        	break;
    }
    
    posKurt = (*Kurt)->getPosition();
	dirKurt = (*Kurt)->getDirection();
    
    testRamasserObjet(); //Dans Map
}

/*! \brief Affiche l'étage
	\param app La fenetre du jeu
*/
void Etage::afficher(sf::RenderWindow &app) const
{
	Map::afficher(app);
	
    app.draw(sol);
    for (unsigned int i=0; i<murs_.size();i++){
        murs_[i]->afficher(app);
    }
    
    for (unsigned int i=0; i<objet_.size();i++){
        objet_[i]->afficher(app);
    }
    
    (*Kurt)->afficher(app);
}





/* Fonctions permettant de créer des murs aléatoirements.
	Les résultats n'était pas concluant, nous avons fixé les murs
*/

/*
void Etage::addPoint(sf::Vector2f v){

    sf::Vector2f BD(v);

    bool porte=false;

    if (v.y != prof_+2*TAILLE_MUR){
        sf::Vector2f BG(v);

        do {
            BG.x--;
        } while (!hasVerticalMur(BG) && !inRestectedArea(BG));

        murs_.push_back(new Mur(BG, BD));//Mur bas
        sf::Vector2f porte1(BG.x+TAILLE_MUR,BG.y),porte2(porte1.x+80,porte1.y);         // 80 => taille perso+marge ???
        porte = murs_[murs_.size()-1]->addDoor(porte1, porte2);                   // si porte2 hors du mur => pas de porte
    }

    if (v.x != width_+2*TAILLE_MUR){
        sf::Vector2f HD(v);

        do {
            HD.y--;
        }while ( !hasHorizotalMur(HD) && !inRestectedArea(HD) );

        murs_.push_back(new Mur(HD, BD));
        sf::Vector2f porte1(HD.x, HD.y+TAILLE_MUR),porte2(porte1.x,porte1.y+80);         // 80 => taille perso+marge ???
        porte = porte || murs_[murs_.size()-1]->addDoor(porte1, porte2);
    }

}


bool Etage::hasHorizotalMur(sf::Vector2f v) const{
    for (unsigned int i=0; i<murs_.size();i++){
        if (murs_[i]->isHorizontal() && murs_[i]->contain(v))
            return true;
    }
    return false;
}

bool Etage::hasVerticalMur(sf::Vector2f v) const{
    for (unsigned int i=0; i<murs_.size();i++){
        if (murs_[i]->isVertical() && murs_[i]->contain(v))
            return true;
    }
    return false;
}

bool Etage::hasHorizotalRightMur(sf::Vector2f v) const{
    for (unsigned int i=0; i<murs_.size();i++){
        if (murs_[i]->isHorizontalRight(v))
            return true;
    }
    return false;
}

bool Etage::inRestectedArea(sf::Vector2f p) const{
    return (frontDoor_!=0 && frontDoor_->isInRestectedArea(p));
}


sf::Vector2f Etage::trouveNextI(sf::Vector2f &lastX, sf::Vector2f &lastY) const{
	sf::Vector2f newI;

   	bool aDroite(Aleatoire::getNext(0,2) == 1);
   	int espaceMin = 70+2*TAILLE_MUR;
   	int maxY = prof_ - espaceMin;
   	int maxX = width_ - espaceMin;

	if(aDroite)
	{
		do {
		    int minTaille = lastX.x + espaceMin;

		    int nbAleatoireX = minTaille;

		    while(Aleatoire::getNext(0, 5) != 0 && nbAleatoireX < maxX) //Une chance sur 20 à chaque étape
		    {
		    	nbAleatoireX++;
		    }

		    newI = sf::Vector2f(nbAleatoireX, Aleatoire::getNext(espaceMin, maxY+1));

		    if ( newI.y -lastY.y < minTaille)
				newI.y += minTaille - (newI.y -lastY.y);

		} while (inRestectedArea(sf::Vector2f(newI.x+TAILLE_MUR,newI.y+TAILLE_MUR)) );

		lastX = sf::Vector2f(newI);

		lastY = (lastY.y < newI.y) ? sf::Vector2f(newI) : lastY;

	}
	else
	{
		do {
			int minTaille = lastY.y + espaceMin;

			int nbAleatoireY = minTaille;

		    while(Aleatoire::getNext(0, 5) != 0 && nbAleatoireY < maxY) //Une chance sur 20 à chaque étape
		    {
		    	nbAleatoireY++;
		    }

			newI = sf::Vector2f(Aleatoire::getNext(espaceMin, maxX+1), nbAleatoireY);

			if ( newI.x -lastX.x < minTaille)
				newI.x += minTaille - (newI.x -lastX.x);

		} while (inRestectedArea(sf::Vector2f(newI.x+TAILLE_MUR,newI.y+TAILLE_MUR)) );

		lastY = sf::Vector2f(newI);

		lastX = (lastX.x < newI.x) ? sf::Vector2f(newI) : lastX;

	}

    return sf::Vector2f(newI.x+TAILLE_MUR,newI.y+TAILLE_MUR);
}


void Etage::trouveNextI(std::vector<sf::Vector2f> &tab) const{
    sf::Vector2f newI= tab.size()==0? sf::Vector2f(0,0) : tab[tab.size()-1];
    sf::Vector2f lastI=newI;

    do {
        int minTaille=70+2*TAILLE_MUR;                  //taille Perso

        //Ordonnée
        int maxY = prof_-newI.y;

        int nbAleatoireY = minTaille;

        while(Aleatoire::getNext(0, 5) != 0) //Une chance sur 20 à chaque étape
        {
        	nbAleatoireY++;
        }

        newI.y += maxY<=minTaille ? minTaille : nbAleatoireY;

        if (prof_>newI.y && prof_-newI.y<minTaille)
            newI.y = prof_;

        //Abscissse
        int maxX = width_-newI.x;

        int nbAleatoireX = minTaille;

        while(Aleatoire::getNext(0, 20) != 0) //Une chance sur 20 à chaque étape
        {
        	nbAleatoireX++;
        }

        newI.x += maxX<=minTaille ? minTaille : nbAleatoireX;

        int maxXPrecedant = 0;
        int i=tab.size()-1;

        while (i>-1 && tab[i].x<=newI.x ){
            if (tab[i].x>maxXPrecedant)
                maxXPrecedant = tab[i].x;
            i--;
        }

        if (maxXPrecedant!=newI.x && newI.x-maxXPrecedant<minTaille)
            newI.x += minTaille - (newI.x-maxXPrecedant);

        if (width_>newI.x && width_-newI.x <minTaille)
            newI.x = width_;

    } while (inRestectedArea(sf::Vector2f(newI.x+TAILLE_MUR,newI.y+TAILLE_MUR)) );

    tab.push_back(sf::Vector2f(newI.x+TAILLE_MUR,newI.y+TAILLE_MUR));
}*/
