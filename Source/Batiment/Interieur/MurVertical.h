#ifndef MURVERTICAL_H
#define MURVERTICAL_H

/** \file MurVertical.h
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

/** \class MurVertical
	\brief Classe héritant de MurAbstrait représentant un mur vertical
*/
class MurVertical : public MurAbstrait
{
    public:
        MurVertical(sf::Vector2f p,int longueur);
        virtual ~MurVertical();
        
        virtual bool isVertical() const;
        virtual bool isHorizontal() const;

        virtual bool addDoor(sf::Vector2f p1, sf::Vector2f p2);
};

#endif // MURVERTICAL_H
