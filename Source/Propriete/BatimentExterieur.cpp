#include "Propriete.h"

/** \file Propriete/BatimentExterieur.cpp
	\brief Regroupement des proprietés du batiment exterieur
	\author RIOU, MAUSSION
*/

Propriete::BatimentExterieur* Propriete::BatimentExterieur::instance_ = NULL;	// Initialisation de l'instance

/** \brief Constructeur privé de BatimentExterieur */
Propriete::BatimentExterieur::BatimentExterieur() : 
				colorMur_(sf::Color::White), 
				colorFenetre_(sf::Color::Cyan), 
				colorPorteOuverte_(sf::Color::Green), 
				colorPorteFerme_(sf::Color::Red), 
				nbEtageMin_(2),
				nbEtageMax_(9),
				nbFenLargeurMin_(2),
				nbFenLargeurMax_(6),
				tailleFenetre_(sf::Vector2f(20,20)),
				espaceFenetre_(sf::Vector2f(10,10)),
				taillePorte_(sf::Vector2f(30,40))
{
}

/** \brief Getter sur l'instance
*/
Propriete::BatimentExterieur* Propriete::BatimentExterieur::batimentExterieur()
{
	if(instance_ == NULL)
		instance_ = new BatimentExterieur();
		
	return instance_;
}

/** \brief Détruit l'instance */
void Propriete::BatimentExterieur::deleteBatimentExterieur(){
	delete instance_;
	instance_ = NULL;
}

/** \brief Getter sur la couleur du mur
*/
sf::Color Propriete::BatimentExterieur::colorMur()
{
	return instance_->colorMur_;
}

/** \brief Getter sur la couleur des fenetres
*/
sf::Color Propriete::BatimentExterieur::colorFenetre()
{
	return instance_->colorFenetre_;
}

/** \brief Getter sur la couleur de la porte ouverte
*/
sf::Color Propriete::BatimentExterieur::colorPorteOuverte()
{
	return instance_->colorPorteOuverte_;
}

/** \brief Getter sur la couleur de la porte fermée
*/
sf::Color Propriete::BatimentExterieur::colorPorteFerme()
{
	return instance_->colorPorteFerme_;
}

/** \brief Getter sur le nombre d'étages minimum
*/
int Propriete::BatimentExterieur::nbEtageMin()
{
	return instance_->nbEtageMin_;
}

/** \brief Getter sur le nombre d'étages maximum
*/
int Propriete::BatimentExterieur::nbEtageMax()
{
	return instance_->nbEtageMax_;
}


/** \brief Getter sur le nombre de fenetres minimum
*/
int Propriete::BatimentExterieur::nbFenLargeurMin()
{
	return instance_->nbFenLargeurMin_;
}

/** \brief Getter sur le nombre de fenetres maximum
*/
int Propriete::BatimentExterieur::nbFenLargeurMax()
{
	return instance_->nbFenLargeurMax_;
}

/** \brief Getter sur la taille d'une fenetre
*/
sf::Vector2f Propriete::BatimentExterieur::tailleFenetre()
{
	return instance_->tailleFenetre_;
}

/** \brief Getter sur l'espace entre 2 fenetres
*/
sf::Vector2f Propriete::BatimentExterieur::espaceFenetre()
{
	return instance_->espaceFenetre_;
}


/** \brief Getter sur la taille d'une porte
*/
sf::Vector2f Propriete::BatimentExterieur::taillePorte()
{
	return instance_->taillePorte_;
}
