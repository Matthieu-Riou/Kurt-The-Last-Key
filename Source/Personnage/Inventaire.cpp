#include "Inventaire.h"
#include "Personnage.h"
#include "../Batiment/BatimentExterieur.h"
#include "../Statique/InventaireStatique.h"
#include "ConteneurPersonnage.h"
#include <iostream>

/** \file Inventaire.cpp
	\brief Inventaire des personnages
	\author RIOU, MAUSSION
*/

/** \brief Constructeur d'un inventaire
	\param proprietaire Le proprietaire de l'inventaire
*/
Inventaire::Inventaire(ConteneurPersonnage* proprietaire) : proprietaire_(proprietaire)
{}

/** \brief Destructeur d'un inventaire */
Inventaire::~Inventaire()
{
	for(std::list<Objet*>::const_iterator it = inventaire_.begin(); it != inventaire_.end(); ++it)
		delete *it;
}

/** \brief Ajoute un objet à l'inventaire
	\param objet L'objet à ajouter
*/
void Inventaire::ranger(Objet *objet)
{
	inventaire_.push_back(objet);
	notifierObs();
}

/** \brief Renvoie vrai si un objet a ouvert le batiment
	\param batiment Le batiment à ouvrir
*/
bool Inventaire::testerTous(BatimentExterieur *batiment)
{
	std::list<Objet*>::iterator it = inventaire_.begin();
	bool ouvert(false);
	
	while(!ouvert && it != inventaire_.end())
	{
		ouvert = utiliser(*it, batiment);
		++it;
	}
	
	return ouvert;
} 

/** \brief Getter sur les objets de l'inventaire
*/
std::list<Objet*> Inventaire::getObjets() const
{
	return inventaire_;
}

/** \brief Getter sur la taille de l'inventaire
*/
unsigned int Inventaire::getNbObjet() const
{
	return inventaire_.size();
}

/** \brief Utilise un objet sur un batiment
	\param objet L'objet à utiliser
	\param batiment Le batiment sur lequel on utilise l'objet
	\return vrai si on a utilisé l'objet
*/
bool Inventaire::utiliser(Objet* objet, BatimentExterieur *batiment)
{
	bool valide = objet->utiliser(batiment);
	
	if(valide)
		inventaire_.remove(objet);
		
	notifierObs();
		
	return valide;
}

/** \brief Utilise un objet sur un personnage
	\param objet L'objet à utiliser
	\param personnage Le personnage sur lequel on utilise l'objet
	\return vrai si on a utilisé l'objet
*/
bool Inventaire::utiliser(Objet* objet, ConteneurPersonnage* personnage)
{
	bool valide = objet->utiliser(personnage);
	
	if(valide)
		inventaire_.remove(objet);
		
	notifierObs();
		
	return valide;
}

/** \brief Utilise l'objet sur le proprietaire de l'inventaire
	\param objet L'objet à utiliser
	\return vrai si on a utilisé l'objet
*/
bool Inventaire::utiliser(Objet* objet)
{
	return utiliser(objet, proprietaire_);
}


