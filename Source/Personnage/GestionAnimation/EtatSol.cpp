#include "EtatSol.h"

#include <iostream>

/** \file EtatSol.cpp
	\brief Etat lorsque le personnage est au sol
	\author RIOU, MAUSSION
*/

/** \brief Constructeur de l'EtatSol
	\param p Le personnage sur lequel s'applique l'état
*/
EtatSol::EtatSol(ConteneurPersonnage* p) : EtatAnimation(p)
{}

/** \brief Fait sauter le personnage (changement d'état)
*/
void EtatSol::sauter(){
	(*personnage_)->setValeurSaut(Propriete::Hero::valeurSaut());
	(*personnage_)->setEtatAnimation((*personnage_)->getEtatAir());
}

/** \brief Met le personnage dans un état en air qui lui permet de resauter
*/
void EtatSol::sauterDouble(){
	(*personnage_)->setValeurSaut(Propriete::Hero::valeurSaut());										// Perso::valSaut
	(*personnage_)->setEtatAnimation((*personnage_)->getEtatAirIntermediaire());
}

/** \brief Change la direction du personnage et incrémente le compteur de pied
	\param d La direction du mouvement
*/
void EtatSol::animer(Dir d){
    if (d == GAUCHE || d==DROITE ) {
        (*personnage_)->setDir(d);
        (*personnage_)->incrementeCptPied();
    }
}

/** \brief Change l'état pour un état de batiment et renvoie vrai
*/
bool EtatSol::entrerBatiment()
{
	(*personnage_)->setEtatAnimation((*personnage_)->getEtatBatiment());
	return true;
}

