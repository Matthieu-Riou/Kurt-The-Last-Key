#include "Intro.h"

void intro(sf::RenderWindow &app)
{
	sf::RectangleShape fond_;
	sf::Font font_;
	sf::Text texte_;

	fond_.setSize(sf::Vector2f(Propriete::Fenetre::fenX(), Propriete::Fenetre::hauteurSol()));
	fond_.setFillColor(sf::Color::Cyan);

	std::list<Decor*> decor_;

	decor_.push_back(new Arbre(50));
	decor_.push_back(new Nuage(Propriete::Fenetre::fenX()));

	font_.loadFromFile("Font/arial.ttf");
	texte_.setString("Kurt");
	texte_.setFont(font_);
	texte_.setColor(sf::Color::Red);
	texte_.setCharacterSize(150);
	texte_.setStyle(sf::Text::Bold);

	sf::FloatRect rect = texte_.getLocalBounds();
	texte_.setPosition(sf::Vector2f((Propriete::Fenetre::fenX() - rect.width) / 2, (Propriete::Fenetre::fenY() - Propriete::Fenetre::hauteurSol() - rect.height/2)));

	std::vector<sf::RectangleShape> fen_;	/*!< Ensemble de toutes les fenetres */

	unsigned int etage_ = 5; 			/*!< Nombre d'étages */
	unsigned int nbFenLargeur_ = 3;		/*!< Nembre de fenetres */
	float posX = 600.;

	sf::Vector2f tailleFen_ = Propriete::BatimentExterieur::tailleFenetre();		/*!< Taille d'une fenetre */
	sf::Vector2f espaceFen_ = Propriete::BatimentExterieur::espaceFenetre();		/*!< Espace entre 2 fenetres */
	sf::Vector2f taillePorte_ = Propriete::BatimentExterieur::taillePorte();		/*!< Taille de la porte */
	sf::Vector2f taille_(nbFenLargeur_*(tailleFen_.x + espaceFen_.x) + espaceFen_.x, (etage_)*(tailleFen_.y + espaceFen_.y) + taillePorte_.y + espaceFen_.y);			/*!< Taille du batiment */

	sf::RectangleShape mur_(taille_);		/*!< Le rectangle représentant le mur */
	sf::RectangleShape porte_(taillePorte_); 		/*!< Le rectangle représentant la porte */

	mur_.move(posX, Propriete::Fenetre::hauteurSol() - taille_.y);
	mur_.setFillColor(Propriete::BatimentExterieur::colorMur());
	mur_.setOutlineThickness(1);
	mur_.setOutlineColor(sf::Color::Black);
	

	porte_.move((posX + taille_.x/2 - taillePorte_.x/2),  Propriete::Fenetre::hauteurSol() - taillePorte_.y);
	porte_.setFillColor(Propriete::BatimentExterieur::colorPorteOuverte());
	porte_.setOutlineThickness(1);
	porte_.setOutlineColor(sf::Color::Black);
	
	for(unsigned int i = 0; i < etage_; i++)
	{
		for(unsigned int j = 0; j < nbFenLargeur_; j++)
		{
			fen_.push_back(sf::RectangleShape(tailleFen_));
			fen_.back().move(posX + espaceFen_.x + j*(tailleFen_.x + espaceFen_.x), Propriete::Fenetre::hauteurSol() - taillePorte_.y -((tailleFen_.y + espaceFen_.x)*(i+1)));
			fen_.back().setFillColor(Propriete::BatimentExterieur::colorFenetre());
			fen_.back().setOutlineThickness(1);
			fen_.back().setOutlineColor(sf::Color::Black);
		}
	}

	while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
	{
		app.clear(sf::Color::Black);

		app.draw(fond_);

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


		if(Aleatoire::getNext(0, 500) == 499) //Une chance sur 500
			decor_.push_back(new Nuage(Propriete::Fenetre::fenX()));	

		for(std::list<Decor*>::const_iterator it = decor_.begin(); it != decor_.end(); ++it)
			(*it)->afficher(app);


		app.draw(mur_);
		app.draw(porte_);
	
		for(unsigned int i = 0; i < fen_.size(); i++)
	    {
    		app.draw(fen_[i]);
		}

		app.draw(texte_);

        app.display();
	}

	for(std::list<Decor*>::iterator it = decor_.begin(); it != decor_.end(); ++it) //Destruction du décor
	{
		delete *it;
		*it = NULL;
	}

}
