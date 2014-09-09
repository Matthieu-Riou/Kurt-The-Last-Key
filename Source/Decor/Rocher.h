#ifndef ROCHER_H
#define ROCHER_H

/** \file Rocher.h
	\brief Element de décor rocher
	\author RIOU, MAUSSION
*/

#include <SFML/Graphics.hpp>
#include "Decor.h"
#include "../Propriete/Propriete.h"

/** \class Rocher
	\brief Classe héritant de Decor représentant un rocher
*/
class Rocher : public Decor
{
	public:
		Rocher(int posX);
		
};


#endif //ROCHER_H
