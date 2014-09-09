#include "EtatEnAir.h"

/** \file EtatEnAir.cpp
	\brief Etat lorsque le personnage est dans les airs et ne peut resauter
	\author RIOU, MAUSSION
*/

/** \brief Constructeur de l'EtatAir
	\param p Le personnage sur lequel s'applique l'état
*/
EtatEnAir::EtatEnAir(ConteneurPersonnage* p): EtatAnimation(p)
{}

/** \brief Actualise la position de la sprite. 
	Si la valeur de saut est positive, on monte
	Sinon si le personnage n'est pas au sol, on le fait descendre
	Sinon
		On revient à l'état sol
*/
void EtatEnAir::update(){
    int valeurSaut = (*personnage_)->getValeurSaut();
    if(valeurSaut > 0){																		
		(*personnage_)->moveSprite(0., -2.);
		(*personnage_)->setValeurSaut(valeurSaut-1);
	}
	else if ( (*personnage_)->getPosition().y + (*personnage_)->getTaille().y < Propriete::Fenetre::hauteurSol() )
		(*personnage_)->moveSprite(0., 2.);
	else
        (*personnage_)->setEtatAnimation((*personnage_)->getEtatSol());
}


/** \brief Change la direction du personnage
	\param d La direction du mouvement
*/
void EtatEnAir::animer(Dir d){
    if (d == GAUCHE || d == DROITE )
        (*personnage_)->setDir(d);
}
