#ifndef BATIMENT_INTERIEUR_H
#define BATIMENT_INTERIEUR_H

/*! \file BatimentInterieur.h
	\brief L'intérieur d'un batiment
	\author RIOU, MAUSSION
*/
#include "../Propriete/Propriete.h"
#include "../Map/Map.h"
#include "Interieur/Etage.h"
#include <vector>


class Cle; /*!< Forward declaration */

/*! \class BatimentInterieur
	\brief Classe gérant l'intérieur des batiments 
	Elle peut sembler manquer d'intérêt, mais elle est sencé contenir plusieurs étages (au lieu d'un) et faire les liens entre eux
*/
class BatimentInterieur
{
	private:
		
		Etage etage_; /*!< Un étage, au futur un vector d'étage */
		
	public:
	
		BatimentInterieur(Map* parent, ConteneurPersonnage* perso);
		
		void addCle(Cle* c);
		
		Etage* getEtage();
                
    	void gestionEvent();
        void update();
        void deplacer(Dir d);
		
		void afficher(sf::RenderWindow &app) const;
		
};

#endif //BATIMENT_INTERIEUR_H
