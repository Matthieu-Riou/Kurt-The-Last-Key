#ifndef NUAGE_H
#define NUAGE_H

/** \file Nuage.h
	\brief Représentation d'un nuage
	\author RIOU, MAUSSION
*/

#include <SFML/Graphics.hpp>
#include "Decor.h"
#include "../Aleatoire.h"
#include "../Propriete/Propriete.h"

/** \class Nuage 
	\brief Classe héritant de Decor représentant un nuage
*/
class Nuage : public Decor
{
	public:
		Nuage(int posX);
		
		virtual void update();
};


#endif //NUAGE_H
