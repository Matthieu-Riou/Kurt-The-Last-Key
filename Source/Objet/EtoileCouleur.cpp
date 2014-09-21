#include "EtoileCouleur.h"

/** \file EtoileCouleur.cpp
	\brief Représentation d'une étoile qui change la couleur de Kurt (etoile verte)
	\author RIOU, MAUSSION
*/

/** \brief Constructeur d'EtoileCouleur en mettant la bonne texture */
EtoileCouleur::EtoileCouleur() : Objet(Propriete::Objet::etoileVerte())
{
}

/** \brief Utilise l'objet sur le ConteneurPersonnage
	\param personnage Le conteneur de personnage à décorer
*/
bool EtoileCouleur::utiliser(ConteneurPersonnage* personnage)
{
	personnage->decorerTexture();
	return true;
}
