#include "EtatBatiment.h"

/** \file EtatBatiment.cpp
	\brief Etat lorsque le personnage est dans un batiment
	\author RIOU, MAUSSION
*/


/** \brief Constructeur de l'EtatBatiment
	\param p Le personnage sur lequel s'applique l'état
*/
EtatBatiment::EtatBatiment(ConteneurPersonnage* p): EtatAnimation(p)
{}

/**	\brief Change la direction du personnage et incrémente le compteur de pied
	\param d La direction du mouvement
*/
void EtatBatiment::animer(Dir d){
    (*personnage_)->setDir(d);
    (*personnage_)->incrementeCptPied();
}

/** \brief Change l'état pour un état sol et renvoie vrai
*/
bool EtatBatiment::sortirBatiment(){
	(*personnage_)->setEtatAnimation((*personnage_)->getEtatSol());
	return true;
}
