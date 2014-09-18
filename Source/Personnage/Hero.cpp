#include "Hero.h"

/** \file Personnage/Hero.cpp
	\brief Le héro du jeu
	\author RIOU, MAUSSION
*/

/** \brief Constructeur de Hero en utilisant les parametres de Propriete::Hero */
Hero::Hero(EtatAnimation* etatSol, EtatAnimation* etatAir, EtatAnimation* etatAirIntermediaire, EtatAnimation* etatBatiment, Inventaire* inventaire) : 
			Personnage(DROITE, Propriete::Hero::taille(), Propriete::Hero::textures(), etatSol, etatAir, etatAirIntermediaire, etatBatiment, inventaire)
{
    sprite_.move(200, Propriete::Fenetre::hauteurSol()-taille_.y);
}
