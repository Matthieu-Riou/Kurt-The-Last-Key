#include "EtoileVitesse.h"

/** \file EtoileVitesse.cpp
	\brief Représentation d'une étoile qui donne un bonus de vitesse (etoile jaune)
	\author RIOU, MAUSSION
*/

/** \brief Constructeur d'EtoileVitesse en mettant la bonne texture */
EtoileVitesse::EtoileVitesse() : Objet(Propriete::Objet::etoileJaune()), vitesse_(1.)
{
}

/** \brief Utilise l'objet sur le ConteneurPersonnage
	\param personnage Le conteneur de personnage à décorer
*/
bool EtoileVitesse::utiliser(ConteneurPersonnage* personnage)
{
	personnage->decorerVitesse(vitesse_);
	return true;
}
