#include "Cle.h"
#include "../Batiment/BatimentExterieur.h"

/** \file Cle.cpp
	\brief Représentation d'une clé
	\author RIOU, MAUSSION
*/


/** \brief Constructeur de Cle
	Met la bonne texture (depuis Propriete) et affecte le batiment
	\param batiment Le batiment qu'elle ouvre
*/
Cle::Cle(BatimentExterieur* batiment) : Objet(Propriete::Objet::cle()), batiment_(batiment)
{
}

/** \brief Utilise la cle sur le batiment passé en parametre
	Si il s'agit de celui en attribut, on l'ouvre et revoie vrai
	Sinon renvoie faux
	\param batiment Le batiment a ouvrir
	\return vrai si on a ouvert le batment
*/
bool Cle::utiliser(BatimentExterieur* batiment)
{
	if(batiment_ == batiment)
	{
		batiment_->ouvrir();
		
		return true;
	}
	else
		return false;
}

