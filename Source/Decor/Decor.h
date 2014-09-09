#ifndef DECOR_H
#define DECOR_H

/** \file Decor.h
	\brief Représente les décors du jeu
	\author RIOU, MAUSSION
*/

#include <SFML/Graphics.hpp>
#include "../Espace.h"

/** \class Decor
	\brief Classe représentant les décors du jeu
*/
class Decor
{
	protected:
		sf::Sprite sprite_; /*!< La Sprite (image) du décor */
		
	public:
		virtual ~Decor();
		
		virtual sf::Vector2f getPosition() const;
		virtual void deplacer(Dir dir);
		virtual void update();
		virtual void afficher(sf::RenderWindow &app) const;
};
		

#endif //DECOR_H
