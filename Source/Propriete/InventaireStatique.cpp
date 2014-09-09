#include "Propriete.h"


/** \file Propriete/InventaireStatique.cpp
	\brief Regroupement des proprietes de l'inventaire statique (inventaire affiché sous la map)
	\author RIOU, MAUSSION
*/

Propriete::InventaireStatique* Propriete::InventaireStatique::instance_ = NULL;			// Initialisation de l'instance

/** \brief Constructeur privé d'InventaireStatique */
Propriete::InventaireStatique::InventaireStatique() : 
				colorFond_(sf::Color::Red), 
				espaceBordure_(sf::Vector2f(5, 5)), 
				nbObjet_(sf::Vector2i(9,2)),
				tailleFond_(sf::Vector2f(nbObjet_.x*Propriete::Objet::taille().x + 2*espaceBordure_.x, nbObjet_.y*Propriete::Objet::taille().y + 2*espaceBordure_.y)),
				posFond_(sf::Vector2f((Propriete::Fenetre::fenX() - tailleFond_.x)/2, 400))
{
}

/** \brief Getter sur l'instance
*/
Propriete::InventaireStatique* Propriete::InventaireStatique::inventaireStatique()
{
	if(instance_ == NULL)
		instance_ = new InventaireStatique();
		
	return instance_;
}

/** \brief Détruit l'instance */
void Propriete::InventaireStatique::deleteInventaireStatique(){
	delete instance_;
	instance_ = NULL;
}

/** \brief Getter sur la couleur de fond
*/
sf::Color Propriete::InventaireStatique::colorFond()
{
	return instance_->colorFond_;
}
/** \brief Getter sur la taille du fond
*/
sf::Vector2f Propriete::InventaireStatique::tailleFond()
{
	return instance_->tailleFond_;
}
/** \brief Getter sur la position du fond
*/
sf::Vector2f Propriete::InventaireStatique::posFond()
{
	return instance_->posFond_;
}
/** \brief Getter sur l'espace de bordure
*/
sf::Vector2f Propriete::InventaireStatique::espaceBordure()
{
	return instance_->espaceBordure_;
}

/** \brief Getter sur le nombre d'objets
*/
sf::Vector2i Propriete::InventaireStatique::nbObjet()
{
	return instance_->nbObjet_;
}
