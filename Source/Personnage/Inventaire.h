#ifndef INVENTAIRE_H
#define INVENTAIRE_H

/** \file Inventaire.h
	\brief Inventaire des personnages
	\author RIOU, MAUSSION
*/

#include <list>
#include "../Objet/Objet.h"
#include "../Objet/Cle.h"
#include "../Statique/InventaireStatique.h"
#include "../Observer/Sujet.h"
#include "ConteneurPersonnage.h"

class Personnage;					/*!< Forward declaration */
class BatimentExterieur;			/*!< Forward declaration */

/** \class Inventaire
	\brief Classe héritant de Sujet<InventaireStatique>, il est donc observé par un InventaireStatique
*/
class Inventaire : public Sujet<InventaireStatique>
{	
	private:
		ConteneurPersonnage* proprietaire_;		/*!< Le proprietaire de l'inventaire */
		std::list<Objet*> inventaire_;			/*!< Les objets contenus par l'inventaire */
		
	public:
		Inventaire(ConteneurPersonnage* proprietaire);
		~Inventaire();
		
		void ranger(Objet *objet);
		
		bool testerTous(BatimentExterieur *batiment);

		std::list<Objet*> getObjets() const;
		unsigned int getNbObjet() const;
		
		bool utiliser(Objet* objet, BatimentExterieur *batiment);
		bool utiliser(Objet* objet, ConteneurPersonnage* personnage);
		bool utiliser(Objet* objet);
};

#endif //INVENTAIRE_H
