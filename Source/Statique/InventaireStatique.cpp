#include "InventaireStatique.h"
#include "../Personnage/ConteneurPersonnage.h"
#include "../Personnage/Personnage.h"
#include <iostream>

/** \file Statique/InventaireStatique.cpp
	\brief Inventaire observant l'inventaire du personnage et affiché en bas de la fenetre
	\author RIOU, MAUSSION
*/

/** \brief Constructeur d'InventaireStatique, création du fond, du tableau de sprites, initialisaton des attributs et enregistrement comme Observer du sujet
	\param perso Le proprietaire de l'inventaire à observer
*/
InventaireStatique::InventaireStatique(ConteneurPersonnage* perso) : 
				Observer((*perso)->getInventaire()),
				fond_(sf::RectangleShape(Propriete::InventaireStatique::tailleFond())), 
				nbObjetMax_(Propriete::InventaireStatique::nbObjet().x * Propriete::InventaireStatique::nbObjet().y),
				sprite_(std::vector<sf::Sprite>(nbObjetMax_)),
				mousePressed_(false)
{
	fond_.move(Propriete::InventaireStatique::posFond());
	fond_.setFillColor(Propriete::InventaireStatique::colorFond());
	
	for(int j = 0; j < Propriete::InventaireStatique::nbObjet().y; j++)
	{
		for(int i = 0; i < Propriete::InventaireStatique::nbObjet().x; i++)
		{
			float x = Propriete::InventaireStatique::espaceBordure().x + i*(Propriete::Objet::taille().x);
			float y = Propriete::InventaireStatique::espaceBordure().y + j*(Propriete::Objet::taille().y);
			x += Propriete::InventaireStatique::posFond().x;
			y += Propriete::InventaireStatique::posFond().y;
			
			sprite_[i + Propriete::InventaireStatique::nbObjet().x*j].setPosition(x, y);
		}
	}
	
	sujet_->enregistrerObs(this);
}

/** \brief Gestion des entrées souris : clique de souris sur un objet 
*/
void InventaireStatique::gestionEvent(sf::RenderWindow const& app)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && ! mousePressed_)
	{
		mousePressed_ = true;
		std::list<Objet*> objets = sujet_->getObjets();
		std::list<Objet*>::iterator it = objets.begin();
		
		unsigned int i(0);
		bool trouver(false);
		
		while(!trouver && i < nbObjetMax_ && i < sujet_->getNbObjet()) //Ainsi it ne dépassera jamais objets.end()
		{	
			sf::Vector2i posMouse = sf::Mouse::getPosition(app);
			sf::Vector2f min;
			sf::Vector2f max;
			
			int ligne = i%Propriete::InventaireStatique::nbObjet().x;
			int colonne = i/Propriete::InventaireStatique::nbObjet().x;
			
			float x = Propriete::InventaireStatique::espaceBordure().x + ligne*(Propriete::Objet::taille().x);
			float y = Propriete::InventaireStatique::espaceBordure().y + colonne*(Propriete::Objet::taille().y);
			
			x += Propriete::InventaireStatique::posFond().x;
			y += Propriete::InventaireStatique::posFond().y;
			
			min = sf::Vector2f(x, y);
			max = sf::Vector2f(x + Propriete::Objet::taille().x, y + Propriete::Objet::taille().y);
			
			
			if(Espace::estDans(sf::Vector2f(posMouse.x, posMouse.y), min, max))
			{
				sujet_->utiliser((*it));
				trouver = true;
			}
			
			i++;
			++it;
		}
	}
	else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePressed_)
	{
		mousePressed_ = false;
	}
}

/** \brief Actualise la liste d'objets en regardant le sujet
*/
void InventaireStatique::actualiser()
{
	std::list<Objet*> objets = sujet_->getObjets();
	
	unsigned int index(0);
	std::list<Objet*>::iterator it = objets.begin();
	
	while(index < nbObjetMax_ && it != objets.end())
	{
		sprite_[index].setTexture(*((*it)->getTexture()));
		index++;
		 ++it;
	}
}

/** \brief Affiche l'inventaire
	\param app La fenetre du jeu
*/
void InventaireStatique::afficher(sf::RenderWindow &app) const
{
	app.draw(fond_);
	
	for(int i = 0; i < Math::min(sujet_->getNbObjet(), nbObjetMax_); i++)
	{
		app.draw(sprite_[i]);
	}
}
