#ifndef ETOILE_SAUT_H
#define ETOILE_SAUT_H

/** \file EtoileSaut.h
	\brief Représentation d'une étoile qui donne un bonus DoubleSaut
	\author RIOU, MAUSSION
*/

#include "Objet.h"
#include "../Personnage/ConteneurPersonnage.h"

/** \class EtoileSaut
	\brief Classe héritant d'Objet représentant une étoile qui donne un bonus DoubleSaut
*/
class EtoileSaut : public Objet
{		
	public:
		EtoileSaut();
		
		virtual bool utiliser(ConteneurPersonnage* personnage);
};

#endif //ETOILE_SAUT_H
