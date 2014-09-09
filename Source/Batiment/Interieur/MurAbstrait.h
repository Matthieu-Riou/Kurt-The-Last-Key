#ifndef MURABSTRAIT_H
#define MURABSTRAIT_H

/** \file MurAbstrait.h
	\brief Représente un mur d'un étage
	\author RIOU, MAUSSION
*/

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>

#include "../../Espace.h"
#include "../../Propriete/Propriete.h"

/** \class MurAbstrait
	\brief Classe représentant un mur
*/
class MurAbstrait
{
    public:
    
        MurAbstrait(sf::Vector2f p, int longueur);
        virtual ~MurAbstrait();

		/** \brief Vrai si le mur est Horizontal
		*/
        virtual bool isHorizontal() const = 0;
        /** \brief Vrai si le mur est Vertical
		*/
        virtual bool isVertical() const = 0;

		/** \brief Ajoute une porte au mur
		*/
        virtual bool addDoor(sf::Vector2f p1, sf::Vector2f p2)=0;
        virtual bool addFrontDoor(sf::Vector2f p1, sf::Vector2f p2);
        
        virtual sf::ConvexShape* getFrontDoor();
        
        virtual bool collision(sf::Vector2f pos) const;
        
        virtual sf::Vector2f getPosition() const;

        void afficher(sf::RenderWindow &app) const;
        
    protected:
    
        std::vector<sf::ConvexShape> rectangles_; 	/*!< Un ensemble de rectangles (ensemble de sous murs)*/
        std::vector<sf::ConvexShape> portes_;		/*!< Un ensemble de portes */
        
        sf::ConvexShape* frontDoor_;				/*!< Une porte d'entrée (qui est aussi dans le vecteur de porte => pas de destruction)*/
        
        sf::Vector2f p_;							/*!< Le point en haut à gauche du mur */
   		int longueur_;								/*!< La longueur du mur */				

        void addRectangle(sf::Vector2f p1,sf::Vector2f p2,sf::Vector2f p3,sf::Vector2f p4);
        void addPorte(sf::Vector2f p1,sf::Vector2f p2,sf::Vector2f p3,sf::Vector2f p4);
};

#endif // MURABSTRAIT_H
