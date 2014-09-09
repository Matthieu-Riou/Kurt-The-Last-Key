#ifndef DOUBLESAUT_H
#define DOUBLESAUT_H

/** \file DoubleSaut.h
	\brief Bonus double saut
	\author RIOU, MAUSSION
*/

#include "DecorateurPersonnage.h"

/** \class DoubleSaut
	\brief Classe héritant de DecorateurPersonnage servant à réaliser le double saut
*/
class DoubleSaut : public DecorateurPersonnage
{
	public :
		DoubleSaut(std::shared_ptr<Personnage> p);
		virtual void sauter();
};


#endif
