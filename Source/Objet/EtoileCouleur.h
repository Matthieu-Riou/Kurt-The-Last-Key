#ifndef ETOILE_COULEUR_H
#define ETOILE_COULEUR_H

/** \file EtoileCouleur.h
	\brief Représentation d'une étoile qui change la couleur de Kurt
	\author RIOU, MAUSSION
*/

#include "Objet.h"
#include "../Personnage/ConteneurPersonnage.h"

/** \class EtoileCouleur
	\brief Classe héritant d'Objet représentant une étoile qui change la couleur de Kurt
*/
class EtoileCouleur : public Objet
{		
	public:
		EtoileCouleur();
		
		virtual bool utiliser(ConteneurPersonnage* personnage);
};

#endif //ETOILE_COULEUR_H
