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

		app.draw(texte_);

        app.display();
	}

	for(std::list<Decor*>::iterator it = decor_.begin(); it != decor_.end(); ++it) //Destruction du décor
	{
		delete *it;
		*it = NULL;
	}

}
