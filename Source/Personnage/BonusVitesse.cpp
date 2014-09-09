#include "BonusVitesse.h"

/** \file BonusVitesse.cpp
	\brief Bonnus de vitesse pour un personnage
	\author RIOU, MAUSSION
*/

/** \brief Constructeur de BonusVitesse
	\param p Le personnage à décorer
	\param val La valeur du bonus
*/
BonusVitesse::BonusVitesse(std::shared_ptr<Personnage> p, float val) : DecorateurPersonnage(p), bonusVitesse_(val)
{}

/** \brief Surcharge de getVitesse de Personnage
	\return bonus + la vitesse du Personnage contenu
*/
float BonusVitesse::getVitesse() const{
	return bonusVitesse_ + perso_->getVitesse();
}
