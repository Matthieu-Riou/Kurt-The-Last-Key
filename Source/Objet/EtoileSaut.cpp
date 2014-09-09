#include "EtoileSaut.h"

/** \file EtoileSaut.cpp
	\brief Représentation d'une étoile qui donne un bonus de DoubleSaut (etoile bleu)
	\author RIOU, MAUSSION
*/

/** \brief Constructeur d'EtoileSaut en mettant la bonne texture */
EtoileSaut::EtoileSaut() : Objet(Propriete::Objet::etoileBleue())
{
}

/** \brief Utilise l'objet sur le ConteneurPersonnage
	\param personnage Le conteneur de personnage à décorer
*/
bool EtoileSaut::utiliser(ConteneurPersonnage* personnage)
{
	personnage->decorerSaut();
	return true;
}
