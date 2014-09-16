#include "DoubleSaut.h"

/** \file DoubleSaut.cpp
	\brief Bonus double saut
	\author RIOU, MAUSSION
*/

/** \brief Constructeur de DoubleSaut
	\param p Le personnage que l'on décore
*/
DoubleSaut::DoubleSaut(std::shared_ptr<Personnage> p) : DecorateurPersonnage(p)
{}

/** \brief Surcharge de la méthode sauter pour appeler sauterDouble
*/
void DoubleSaut::sauter(){
	perso_->sauterDouble();
}
