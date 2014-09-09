#include "Arbre.h"
#include <iostream>

/** \file Arbre.cpp
	\brief Décor arbre
	\author RIOU, MAUSSION
*/


/** \brief Constructeur d'Arbre
	\param posX La position en x
*/
Arbre::Arbre(int posX)
{
    sprite_.setTexture(*(Propriete::Decor::arbre()));				/*!< On va chercher la texture dans Propriete */
    sprite_.move(posX, Propriete::Fenetre::hauteurSol()-71.);
}
