#include "Intro.h"

Intro::Intro() : bat_(600., 5, 3)
{
	fond_.setSize(sf::Vector2f(Propriete::Fenetre::fenX(), Propriete::Fenetre::hauteurSol()));
	fond_.setFillColor(sf::Color::Cyan);

	decor_.push_back(new Arbre(50));
	decor_.push_back(new Nuage(Propriete::Fenetre::fenX()));

	font_.loadFromFile("Font/arial.ttf");
	texte_.setString("Kurt");
	texte_.setFont(font_);
	texte_.setColor(sf::Color::Red);
	texte_.setCharacterSize(150);
	texte_.setStyle(sf::Text::Bold);

	sf::FloatRect rect = texte_.getLocalBounds();
	texte_.setPosition(sf::Vector2f((Propriete::Fenetre::fenX() - rect.width) / 2, 0.));


	press_.setString("Press Enter to begin");
	press_.setFont(font_);
	press_.setColor(sf::Color::White);
	press_.setCharacterSize(40);
	press_.setStyle(sf::Text::Bold);

	sf::FloatRect pressRect = press_.getLocalBounds();
	press_.setPosition(sf::Vector2f((Propriete::Fenetre::fenX() - pressRect.width) / 2, ((Propriete::Fenetre::fenY() + Propriete::Fenetre::hauteurSol()) / 2) - pressRect.height));

	perso_.creerHero();
	perso_->setPosition(sf::Vector2f(-100.0, Propriete::Fenetre::hauteurSol() - Propriete::Hero::taille().x), DROITE);
}

Intro::~Intro()
{
	for(std::list<Decor*>::iterator it = decor_.begin(); it != decor_.end(); ++it) //Destruction du décor
	{
		delete *it;
		*it = NULL;
	}
}

void Intro::run(sf::RenderWindow &app)
{
	int i = 0;
	int j = 25;
	int pressCpt = 50;

	std::list<Dir> list_direction = {HAUT, BAS, GAUCHE, DROITE, BAS};

	while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
	{
		if(i < 500)
		{
			sf::FloatRect rect = texte_.getLocalBounds();
			texte_.setPosition(sf::Vector2f((Propriete::Fenetre::fenX() - rect.width) / 2, (Propriete::Fenetre::fenY() - Propriete::Fenetre::hauteurSol() - rect.height/2 -500 + i )));
			i++;
		}

		if(perso_->getPosition().x < bat_.getPositionPorte().x)
		{
			perso_->deplacer(DROITE, 2.);
		}
		else if(!list_direction.empty())
		{
			if(j == 25)
			{
				perso_->setDir(list_direction.front());
				list_direction.pop_front();
				j = 0;
			}
			else
			{
				j++;
			}
		}

		if(pressCpt > 0)
		{
			press_.setCharacterSize(40 - pressCpt/4);
		}
		else if(pressCpt > -50)
		{
			press_.setCharacterSize(40 + pressCpt/4);
		}
		else
		{
			pressCpt = 50;
		}

		
		sf::FloatRect pressRect = press_.getLocalBounds();
	press_.setPosition(sf::Vector2f((Propriete::Fenetre::fenX() - pressRect.width) / 2, ((Propriete::Fenetre::fenY() + Propriete::Fenetre::hauteurSol()) / 2) - pressRect.height));

		pressCpt --;
		afficher(app);
	}
}

void Intro::afficher(sf::RenderWindow &app)
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


	bat_.afficher(app);

	perso_->afficher(app);

	app.draw(texte_);

	app.draw(press_);

    app.display();
}
