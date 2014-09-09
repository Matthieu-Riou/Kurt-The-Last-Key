#include "EtatAnimation.h"
#include <iostream>

/** \file EtatAnimation.cpp
	\brief Représentation d'un état d'un personnage
	\author RIOU, MAUSSION
*/

/** \brief Constructeur d'EtatAnimation
	\param p Le personnage sur lequel s'applique l'état
*/
EtatAnimation::EtatAnimation(ConteneurPersonnage* p) : personnage_(p)
{
}

/** \brief Destructeur d'EtatAnimation
*/
EtatAnimation::~EtatAnimation()
{}

/** \brief Retourne vrai si on peut entrer dans un batiment
	\return faux (valeur par defaut)
*/
bool EtatAnimation::entrerBatiment(){return false;}

/** \brief Retourne vrai si on peut sortir d'un batiment
	\return faux (valeur par defaut)
*/
bool EtatAnimation::sortirBatiment(){return false;}

/** \brief Lance une variante de sauter permettant de réaliser un double saut (par défaut ne fait rien)
*/
void EtatAnimation::sauterDouble(){}

/**	\brief Fait sauter le personnage s'il le peut (par défaut ne fait rien)
*/
void EtatAnimation::sauter(){}

/** \brief Actualise (par défaut ne fait rien)
*/
void EtatAnimation::update(){}

