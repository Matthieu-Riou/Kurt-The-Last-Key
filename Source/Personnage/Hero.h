#ifndef HERO_H
#define HERO_H

/** \file Hero.h
	\brief Le héro du jeu
	\author RIOU, MAUSSION
*/

#include "Personnage.h"

/** \class Hero
	\brief Classe héritant de Personnage représentant le héro du jeu
*/
class Hero : public Personnage
{
	public :
		Hero(ConteneurPersonnage* p);
};

#endif
