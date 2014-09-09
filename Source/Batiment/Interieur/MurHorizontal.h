#ifndef MURHORIZINTAL_H
#define MURHORIZONTAL_H

/** \file MurHorizontal.h
	\brief Représentation d'un mur horizontal
	\author RIOU, MAUSSION
*/
#include <SFML/Graphics.hpp>

#include <string>
#include <sstream>
#include <vector>

#include <iostream>
#include "MurAbstrait.h"
#include "../../Espace.h"

/** \class MurHorizontal
	\brief Classe héritant de MurAbstrait représentant un mur horizontal
*/
class MurHorizontal : public MurAbstrait
{
    public:
        MurHorizontal(sf::Vector2f p,int longueur);
        virtual ~MurHorizontal();
        
        virtual bool isHorizontal() const;
        virtual bool isVertical() const;

        virtual bool addDoor(sf::Vector2f p1, sf::Vector2f p2);
};

#endif // MURHORIZONTAL_H
