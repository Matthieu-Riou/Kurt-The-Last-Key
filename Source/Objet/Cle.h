#ifndef CLE_H
#define CLE_H

/** \file Cle.h
	\brief Représentation d'une clé
	\author RIOU, MAUSSION
*/

#include <SFML/Graphics.hpp>
#include "Objet.h"

class BatimentExterieur;

/** \class Cle
	\brief Classe héritant d'Objet représentant une clé
*/
class Cle : public Objet
{
	private:
		BatimentExterieur* batiment_;		/*!< Le batiment qu'elle ouvre */
		
	public:
		Cle(BatimentExterieur* batiment);
		
		virtual bool utiliser(BatimentExterieur* batiment);
		

};

#endif //CLE_H
