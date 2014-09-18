#include "Propriete.h"

/** \file Propriete/Objet.cpp
	\brief Regroupement des Proprietes des objets
	\author RIOU, MAUSSION
*/ 


Propriete::Objet* Propriete::Objet::instance_ = NULL;	//Initialisation de l'instance

/** \brief Constructeur privé d'Objet */
Propriete::Objet::Objet() : taille_(sf::Vector2f(75, 75))
{
	if(!cle_.loadFromFile("Image/Cle/Cle_Or.png") ||
	   !etoileJaune_.loadFromFile("Image/Objet/Etoile.png") ||
	   !etoileBleue_.loadFromFile("Image/Objet/Etoile2.png") ||
	   !etoileVerte_.loadFromFile("Image/Objet/Etoile3.png"))
		std::cerr << "Erreur lors du chargement de l'image" << std::endl;
}

/** \brief Getter sur l'instance
*/
Propriete::Objet* Propriete::Objet::objet()
{
	if(instance_ == NULL)
		instance_ = new Objet();
		
	return instance_;
}

/** \brief Détruit l'instance */
void Propriete::Objet::deleteObjet(){
	delete instance_;
	instance_ = NULL;
}

/** \brief Getter sur la taille des objets
*/
sf::Vector2f Propriete::Objet::taille()
{
	return instance_->taille_;
}

/** \brief Getter sur la texture de l'étoile jaune 
*/
sf::Texture* Propriete::Objet::etoileJaune(){
	return &(instance_->etoileJaune_);
}
/** \brief Getter sur la texture de l'étoile bleue
*/
sf::Texture* Propriete::Objet::etoileBleue(){
	return &(instance_->etoileBleue_);
}

/** \brief Getter sur la texture de l'étoile verte
*/
sf::Texture* Propriete::Objet::etoileVerte(){
	return &(instance_->etoileVerte_);
}

/** \brief Getter sur la texture de la cle
*/
sf::Texture* Propriete::Objet::cle(){
	return &(instance_->cle_);
}
