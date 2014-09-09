#ifndef ARBRE_H
#define ARBRE_H

/** \file Arbre.h
	\brief Décor arbre
	\author RIOU, MAUSSION
*/

#include <SFML/Graphics.hpp>
#include "Decor.h"
#include "../Propriete/Propriete.h"

/** \class Arbre
	\brief Classe héritant de Decor pour représenter un arbre
*/
class Arbre : public Decor
{
	public:
		Arbre(int posX);
};


#endif //ARBRE_H
