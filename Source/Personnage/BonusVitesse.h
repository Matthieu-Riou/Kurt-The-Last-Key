#ifndef BONUSVITESSE_H
#define BONUSVITESSE_H

/** \file BonusVitesse.h
	\brief Bonnus de vitesse pour un personnage
	\author RIOU, MAUSSION
*/

#include "DecorateurPersonnage.h"

/** \class BonusVitesse 
	\brief Classe héritant de DecorateurPersonnage servant à augmenter la vitesse d'un personnage
*/
class BonusVitesse : public DecorateurPersonnage
{
	protected :
		float bonusVitesse_;				/*!< Le bonus à ajouter */
		
	public :
		BonusVitesse(std::shared_ptr<Personnage> p, float val);
		virtual float getVitesse() const;
};


#endif
