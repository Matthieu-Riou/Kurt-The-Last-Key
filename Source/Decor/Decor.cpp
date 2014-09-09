#include "Decor.h"

/** \file Decor/Decor.cpp
	\brief Représente les décors du jeu
	\author RIOU, MAUSSION
*/


/** \brief Destructeur de Decor
*/
Decor::~Decor()
{}

/** \brief Getter sur la position de l'image
	\return sprite_.getPosition()
*/
sf::Vector2f Decor::getPosition() const
{
	return sprite_.getPosition();
}

/** \brief Deplace l'image suivant la direction
	\param dir La direction du déplacement
*/
void Decor::deplacer(Dir dir)
{
	switch(dir)
    {
        case GAUCHE:
            sprite_.move(2., 0.);
            break;

        case DROITE:
            sprite_.move(-2., 0.);
            break;
            
		case HAUT:
            sprite_.move(0., -2.);
            break;
            
		case BAS:
            sprite_.move(0., 2.);
            break;
    }
}

/** \brief Actualise le décor (par défaut ne fait rien)
*/
void Decor::update()
{}

/** \brief Affiche le decor
	\param app La fenetre du jeu
*/
void Decor::afficher(sf::RenderWindow &app) const
{
	app.draw(sprite_);
}
