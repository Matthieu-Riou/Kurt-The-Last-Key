#ifndef ETAGE_H
#define ETAGE_H

/** \file Etage.h
	\brief Un etage d'un batiment
	\author RIOU, MAUSSION
*/

#include "../../Aleatoire.h"
#include "../../Map/Map.h"
#include "MurAbstrait.h"
#include "MurVertical.h"
#include "MurHorizontal.h"
#include <vector>

/** \class Etage
	\brief Classe gérant un étage
*/
class Etage : public Map
{
	public:
		Etage(int width, int prof, ConteneurPersonnage* perso, Map* mapParent);
		virtual ~Etage();
		
		virtual void gestionEvent();
        virtual void update();
        virtual void deplacer(Dir d);
        
        virtual void addObjet(Objet* o);
        
        virtual void afficher(sf::RenderWindow &app) const;

		
	private:
		std::vector<MurAbstrait*> murs_;	/*!< Un tableau de murs */
		sf::ConvexShape* frontDoor_;		/*!< La porte d'entrée */
        int width_;							/*!< La largeur */
    	int prof_;							/*!< La profondeur */
   		sf::RectangleShape sol;				/*!< Le sol de l'étage*/						
        
        bool collision(Dir d) const;		
        
        virtual void entrer();
        
        void genererEtage();
		
		/*void addPoint(sf::Vector2f v);

        bool hasHorizotalMur(sf::Vector2f v) const;
        bool hasVerticalMur(sf::Vector2f v) const;
        bool hasHorizotalRightMur(sf::Vector2f v) const;

        bool inRestectedArea(sf::Vector2f p) const;

        sf::Vector2f trouveNextI(sf::Vector2f &lastX, sf::Vector2f &lastY) const;*/
		
};

#endif //ETAGE_H
