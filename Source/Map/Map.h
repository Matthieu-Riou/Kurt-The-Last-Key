#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

/** \file Map.h
	\brief Représentation du monde dans lequel évolue le personnage
	\author RIOU, MAUSSION
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../Espace.h"
#include "../Personnage/ConteneurPersonnage.h"
#include "../Objet/Objet.h"

/** \class Map
	\brief Classe abstraite représentant le monde dans lequel vie Kurt (que ce soit l'extérieur ou l'intérieur des batiments)
*/
class Map
{
    protected:
    	Map* mapCourante_;   				/*!< Map courante ( que l'on doit afficher ) */
		Map *mapParent_;					/*!< Map de laquelle on vient */
        ConteneurPersonnage* Kurt;			/*!< Le personnage du joueur */
        
        sf::Vector2f posKurt;				/*!< La position (x,y) du personnage dans la map */
        Dir dirKurt;						/*!< la direction dans laquelle va Kurt */
        
        sf::View viewMap_;					/*!< La view dans laquelle on affiche la map */
				
        std::vector<Objet*> objet_;			/*!< Un ensemble d'objets déposés dans la map(que le personnage peut récupérer */
        
        virtual void testRamasserObjet();
        
    public:
        Map(Map* mapCourante_, ConteneurPersonnage* perso, Map* mapParent = NULL);
        virtual ~Map();

		virtual void start(sf::RenderWindow &app);
        
        virtual void entrer();
        virtual void sortir();
        
        /** \brief Ajoute un objet dans la map
        */
        virtual void addObjet(Objet* o) = 0;
        
        /** \brief Gère les évènements dans la map
        */     
    	virtual void gestionEvent() = 0;
    	
    	/** \brief Met à jour la map
        */
        virtual void update() = 0;
        
        /** \brief Déplace la map
        */
        virtual void deplacer(Dir d) = 0;
        
        virtual void afficher(sf::RenderWindow &app) const;

};

#endif //MAP_H_INCLUDED
