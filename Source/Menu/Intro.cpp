#include "Intro.h"

Intro::Intro() : 
			bat_etage_(5),
			bat_nbFenLargeur_(3),
			bat_posX(600.),
			bat_tailleFen_(Propriete::BatimentExterieur::tailleFenetre()),
			bat_espaceFen_(Propriete::BatimentExterieur::espaceFenetre()),
			bat_taillePorte_(Propriete::BatimentExterieur::taillePorte()),
			bat_taille_(bat_nbFenLargeur_*(bat_tailleFen_.x + bat_espaceFen_.x) + bat_espaceFen_.x, (bat_etage_)*(bat_tailleFen_.y + bat_espaceFen_.y) + bat_taillePorte_.y + bat_espaceFen_.y),
			bat_mur_(sf::RectangleShape(bat_taille_)), 
			bat_porte_(sf::RectangleShape(bat_taillePorte_))
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
	texte_.setPosition(sf::Vector2f((Propriete::Fenetre::fenX() - rect.width) / 2, (Propriete::Fenetre::fenY() - Propriete::Fenetre::hauteurSol() - rect.height/2)));


	bat_mur_.move(bat_posX, Propriete::Fenetre::hauteurSol() - bat_taille_.y);
	bat_mur_.setFillColor(Propriete::BatimentExterieur::colorMur());
	bat_mur_.setOutlineThickness(1);
	bat_mur_.setOutlineColor(sf::Color::Black);
	

	bat_porte_.move((bat_posX + bat_taille_.x/2 - bat_taillePorte_.x/2),  Propriete::Fenetre::hauteurSol() - bat_taillePorte_.y);
	bat_porte_.setFillColor(Propriete::BatimentExterieur::colorPorteOuverte());
	bat_porte_.setOutlineThickness(1);
	bat_porte_.setOutlineColor(sf::Color::Black);
	
	for(unsigned int i = 0; i < bat_etage_; i++)
	{
		for(unsigned int j = 0; j < bat_nbFenLargeur_; j++)
		{
			bat_fen_.push_back(sf::RectangleShape(bat_tailleFen_));
			bat_fen_.back().move(bat_posX + bat_espaceFen_.x + j*(bat_tailleFen_.x + bat_espaceFen_.x), Propriete::Fenetre::hauteurSol() - bat_taillePorte_.y -((bat_tailleFen_.y + bat_espaceFen_.x)*(i+1)));
			bat_fen_.back().setFillColor(Propriete::BatimentExterieur::colorFenetre());
			bat_fen_.back().setOutlineThickness(1);
			bat_fen_.back().setOutlineColor(sf::Color::Black);
		}
	}

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
	for(unsigned int i = 0; i < 500; i++)
	{
		sf::FloatRect rect = texte_.getLocalBounds();
		texte_.setPosition(sf::Vector2f((Propriete::Fenetre::fenX() - rect.width) / 2, (Propriete::Fenetre::fenY() - Propriete::Fenetre::hauteurSol() - rect.height/2 -500 + i )));

		afficher(app);
	}

	while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
	{
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


	app.draw(bat_mur_);
	app.draw(bat_porte_);

	for(unsigned int i = 0; i < bat_fen_.size(); i++)
    {
		app.draw(bat_fen_[i]);
	}

	app.draw(texte_);

    app.display();
}
