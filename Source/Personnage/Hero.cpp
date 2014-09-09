#include "Hero.h"

/** \file Personnage/Hero.cpp
	\brief Le héro du jeu
	\author RIOU, MAUSSION
*/

/** \brief Constructeur de Hero en utilisant les parametres de Propriete::Hero */
Hero::Hero(ConteneurPersonnage* p): Personnage(p, DROITE, Propriete::Hero::taille(), Propriete::Hero::textures())
{
    sprite_.move(200, Propriete::Fenetre::hauteurSol()-taille_.y);
}
