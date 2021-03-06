#include "ConteneurPersonnage.h"
#include "Decorateur/BonusVitesse.h"
#include "Decorateur/DoubleSaut.h"
#include "Hero.h"
#include <iostream>

#include "../Objet/Objet.h"
#include "GestionAnimation/EtatAnimation.h"
#include "GestionAnimation/EtatSol.h"
#include "GestionAnimation/EtatEnAir.h"
#include "GestionAnimation/EtatEnAirIntermediaire.h"
#include "GestionAnimation/EtatBatiment.h"


/** \file ConteneurPersonnage.cpp
	\brief Encapsule Personnage pour permettre au décorateur d'être pris en compte dans tout le programme
	\author RIOU Matthieu, MAUSSION Damien
*/

/** \brief Constructeur par défaut de ConteneurPersonnage
*/
ConteneurPersonnage::ConteneurPersonnage()
{
	//Par défaut ne fait rien
	//Doit être mis car il exite un autre constructeur
}

/** \brief Constructeur de ConteneurPersonnage
	\param p Un pointeur sur Personnage
*/
ConteneurPersonnage::ConteneurPersonnage(Personnage* p) : perso_(p)
{}

/** \brief instancie un personnage
*/
void ConteneurPersonnage::creerHero()
{
	if(perso_ == nullptr)
		perso_ = std::shared_ptr<Personnage>(new Hero(new EtatSol(this), new EtatEnAir(this), new EtatEnAirIntermediaire(this), new EtatBatiment(this), new Inventaire(this)));
}

/** \brief Decore le personnage avec un bonus de vitesse
	\param vitesse Le bonus de vitesse
*/
void ConteneurPersonnage::decorerVitesse(float vitesse)
{
	perso_ = std::shared_ptr<Personnage>(new BonusVitesse(perso_, vitesse));
}

/** \brief Decore le personnage avec un bonus de double saut
*/
void ConteneurPersonnage::decorerSaut()
{
	perso_ = std::shared_ptr<Personnage>(new DoubleSaut(perso_));
}

/** \brief Decore le personnage avec une texture rouge
*/
void ConteneurPersonnage::decorerTexture()
{
	perso_->setTexture(Propriete::Hero::texturesRouges());
	perso_->updateSprite();
}

/** \brief Surcharge de l'operateur *
	\return Une référence sur le personnage encapsulé
*/
Personnage& ConteneurPersonnage::operator*() const
{
	return *perso_;
}

/** \brief Surcharge de l'operateur ->
	\return Un smart pointer sur le personnage encapsulé
*/
std::shared_ptr<Personnage> ConteneurPersonnage::operator->() const
{
	return perso_;
}
