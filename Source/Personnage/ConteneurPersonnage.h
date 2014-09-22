#ifndef CONTENEUR_PERSONNAGE_H
#define CONTENEUR_PERSONNAGE_H

/** \file ConteneurPersonnage.h
	\brief Encapsule Personnage pour permettre au décorateur d'être pris en compte dans tout le programme
	\author RIOU Matthieu, MAUSSION Damien
*/

#include <memory>
#include "Personnage.h"

/** \class ConteneurPersonnage
	\brief La classe encapsulant Personnage
*/
class ConteneurPersonnage
{
	private:
		std::shared_ptr<Personnage> perso_;		/*!< Un smart pointer sur Personnage */
		
	public:
		ConteneurPersonnage();
		ConteneurPersonnage(Personnage* p);
		
		void creerHero();
		void decorerVitesse(float vitesse);
		void decorerSaut();
		void decorerTexture();
		
		Personnage& operator*() const;
		std::shared_ptr<Personnage> operator->() const;
};

#endif //CONTENEUR_PERSONNAGE_H
		
		
