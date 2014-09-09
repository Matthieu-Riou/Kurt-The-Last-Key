#include "Propriete.h"
#include <iostream>

/** \file Propriete/Propriete.cpp
	\brief Initialise les classes de proprietes
*/

/** \brief Méthode statique initialisant toutes les classes de proprietés
*/
void Propriete::init()
{
	Propriete::Fenetre::fenetre();
	Propriete::BatimentExterieur::batimentExterieur();
	Propriete::Etage::etage();
	Propriete::Hero::hero();
	Propriete::Objet::objet();
	Propriete::InventaireStatique::inventaireStatique();
	Propriete::Decor::decor();
}

/** \brief Fonction qui supprime toute les instances des classes du namespace */
void Propriete::destruction(){
	Propriete::Fenetre::deleteFenetre();
	Propriete::BatimentExterieur::deleteBatimentExterieur();
	Propriete::Etage::deleteEtage();
	Propriete::Hero::deleteHero();
	Propriete::Objet::deleteObjet();
	Propriete::InventaireStatique::deleteInventaireStatique();
	Propriete::Decor::deleteDecor();
}


