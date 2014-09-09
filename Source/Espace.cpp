#include "Espace.h"

/*! \file Espace.cpp
	\brief Ensemble de méthodes gérant les points dans l'espace
	\author RIOU Matthieu, MAUSSION Damien
*/ 

/*! \brief Permet de savoir si une valeur est entre un minimum et un maximum
	\param point La valeur à tester
	\param min Le minimum
	\param max Le maximum
	\return vrai si point est compris entre min inclu et max inclu, faux sinon
*/
bool Espace::estDans(float point, float min, float max)
{
	return (point >= min && point <= max);
}

/*! \brief Permet de savoir si un point est entre un point minimum et un point maximum
	\param point Le point à tester
	\param min Le minimum
	\param max Le maximum
	\return vrai si point est compris entre min inclu et max inclu
*/
bool Espace::estDans(sf::Vector2f point, sf::Vector2f min, sf::Vector2f max)
{
	return estDans(point.x, min.x, max.x) && estDans(point.y, min.y, max.y);
}

/*! \brief Permet de savoir si un point est dans une RectangleShape
	\param point Le point à tester
	\param rect Le rectangle
	\return vrai si point est dans le rectangle
*/
bool Espace::estDans(sf::Vector2f point, sf::RectangleShape rect)
{
	return estDans(point, rect.getPosition(), rect.getPosition() + rect.getSize());
}

