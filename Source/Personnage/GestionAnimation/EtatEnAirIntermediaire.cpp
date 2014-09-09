#include "EtatEnAirIntermediaire.h"

#include <iostream>

/** \file EtatEnAirIntermediaire.cpp
	\brief Etat lorsque le personnage est en l'air et peut sauter
	\author RIOU, MAUSSION
*/

/** \brief Constructeur de l'EtatAirIntermediaire, jump_ prend faux
	\param p Le personnage sur lequel s'applique l'état
*/
EtatEnAirIntermediaire::EtatEnAirIntermediaire(ConteneurPersonnage* p): EtatAnimation(p), jump_(false)
{}

/** \brief Fait sauter le personnage, le met en état air (impossible de resauter)
*/
void EtatEnAirIntermediaire::sauterDouble(){
    if (jump_){
	    (*personnage_)->setValeurSaut((*personnage_)->getValeurSaut() +Propriete::Hero::valeurSaut());
        jump_=false;			
	    (*personnage_)->setEtatAnimation((*personnage_)->getEtatAir());
    }
}

/**	\brief Actualise la position de la sprite. 
	Si la valeur de saut est positive, on monte
	Sinon si le personnage n'est pas au sol, on le fait descendre
	Sinon
		On revient à l'état sol
*/
void EtatEnAirIntermediaire::update(){
    jump_ = jump_ || !sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    int valeurSaut = (*personnage_)->getValeurSaut();
    if (valeurSaut > 0){																		
		(*personnage_)->moveSprite(0., -2.);
		(*personnage_)->setValeurSaut(valeurSaut-1);
	}
	else if ( (*personnage_)->getPosition().y + (*personnage_)->getTaille().y < Propriete::Fenetre::hauteurSol() )
		(*personnage_)->moveSprite(0., 2.);
	else {
        jump_=false;
        (*personnage_)->setEtatAnimation((*personnage_)->getEtatSol());
    }
}

/** \brief Change la direction du personnage
	\param d La direction du mouvement
*/
void EtatEnAirIntermediaire::animer(Dir d){
    if (d == GAUCHE || d == DROITE )
        (*personnage_)->setDir(d);
}
