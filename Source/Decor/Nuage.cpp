#include "Nuage.h"
#include <iostream>

/** \file Nuage.cpp
	\brief Représentation d'un nuage
	\author RIOU, MAUSSION
*/


/** \brief Connstructeur de Nuage
	\param posX La position en x du nuage
*/
Nuage::Nuage(int posX)
{
    sprite_.setTexture(*(Propriete::Decor::nuage()));
    sprite_.move(posX,Aleatoire::getNext(0, Propriete::Fenetre::hauteurSol()/2));
}

/** \brief Actualise la position du nuage ( il se déplace à gauche pour simuler le vent)
*/
void Nuage::update()
{
	sprite_.move(-0.3, 0.);
}
