#include "Propriete.h"

/** \file Propriete/Etage.cpp
	\brief Regroupement des proprietes d'un étage
	\author RIOU, MAUSSION
*/

Propriete::Etage* Propriete::Etage::instance_ = NULL;			// Initialisation de l'instance

/** \brief Constructeur privé d'Etage */
Propriete::Etage::Etage() : colorSol_(sf::Color::White), colorMur_(sf::Color::Blue), colorFrontDoor_(sf::Color::Green), tailleMur_(10), tailleEtage_(sf::Vector2f(1000,500))
{
}

/** \brief Getter sur l'instance
*/
Propriete::Etage* Propriete::Etage::etage()
{
	if(instance_ == NULL)
		instance_ = new Etage();
		
	return instance_;
}

/** \brief Détruit l'instance */
void Propriete::Etage::deleteEtage(){
	delete instance_;
	instance_ = NULL;
}

/** \brief Getter sur la couleur du sol
*/
sf::Color Propriete::Etage::colorSol()
{
	return instance_->colorSol_;
}

/** \brief Getter sur la couleur des murs
*/
sf::Color Propriete::Etage::colorMur()
{
	return instance_->colorMur_;
}

/** \brief Getter sur la couleur de la porte d'entrée
*/
sf::Color Propriete::Etage::colorFrontDoor()
{
	return instance_->colorFrontDoor_;
}
/** \brief Getter sur la taille d'un mur
*/
int Propriete::Etage::tailleMur()
{
	return instance_->tailleMur_;
}
/** \brief Getter sur la taille d'un étage
*/
sf::Vector2f Propriete::Etage::tailleEtage()
{
	return instance_->tailleEtage_;
}
