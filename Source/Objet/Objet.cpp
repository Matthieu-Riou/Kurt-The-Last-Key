#include "Objet.h"
#include <iostream>
#include "../Personnage/ConteneurPersonnage.h"
#include "../Personnage/Personnage.h"
#include "../Batiment/BatimentExterieur.h"

/** \file Objet/Objet.cpp
	\brief Représentation d'un objet du jeu
	\author RIOU, MAUSSION
*/

/** \brief Constructeur protége d'Objet
	\param texture La texture de l'objet
*/
Objet::Objet(sf::Texture* texture)
{
	texture_=texture;
	sprite_.setTexture(*(texture_));
}

/** \brief Destructeur d'Objet
*/
Objet::~Objet()
{}

/** \brief Utilise l'objet sur le batiment
	\param batiment Le batiment sur lequel on utilise l'objet
	\return vrai s'il a été utilisé (faux par défaut)
*/
bool Objet::utiliser(BatimentExterieur *batiment)
{
	return false;
}

/** \brief Utilise l'objet sur le personnage
	\param personnage Le personnage sur lequel on utilise l'objet (ConteneurPersonnage pour géré les Decorateurs)
	\return vrai s'il a été utilisé (faux par défaut)
*/
bool Objet::utiliser(ConteneurPersonnage* personnage)
{
	return false;
}

/** \brief Getter sur la texture
	\return texture_
*/
sf::Texture* Objet::getTexture()
{
	return texture_;
}

/** \brief Getter sur la taille
*/
sf::Vector2f Objet::getTaille() const
{
	return sf::Vector2f(texture_->getSize().x, texture_->getSize().y);
}

/** \brief Getter sur la position de la sprite
*/
sf::Vector2f Objet::getPosition() const
{
	return sprite_.getPosition();
}

/** \brief Setter sur la position de la sprite */
void Objet::setPosition(sf::Vector2f pos)
{
	sprite_.move(pos);
}

/** \brief Affiche l'objet
	\param app La fenetre du jeu
*/
void Objet::afficher(sf::RenderWindow &app) const
{
	app.draw(sprite_);
}
