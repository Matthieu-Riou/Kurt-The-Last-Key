#ifndef ETOILE_VITESSE_H
#define ETOILE_VITESSE_H

/** \file EtoileVitesse.h
	\brief Représentation d'une étoile qui donne un bonus de vitesse
	\author RIOU, MAUSSION
*/

#include "Objet.h"
#include "../Personnage/ConteneurPersonnage.h"

/** \class EtoileVitesse
	\brief Classe héritant d'Objet représentant une étoile qui donne un bonus de vitesse
*/
class EtoileVitesse : public Objet
{		
	private:
		float vitesse_; /*!< Bonus de vitesse */
		
	public:
		EtoileVitesse();
		
		virtual bool utiliser(ConteneurPersonnage* personnage);
};

#endif //ETOILE_VITESSE_H
