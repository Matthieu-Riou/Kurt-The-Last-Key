#include "Propriete.h"

/** \file Propriete/Fenetre.cpp
	\brief Regroupement des proprietes de la fenetre
	\author RIOU, MAUSSION
*/

Propriete::Fenetre* Propriete::Fenetre::instance_ = NULL;	// Initialisation de l'instance 

/** \brief Contructeur privé de Fenetre */
Propriete::Fenetre::Fenetre() : fenX_(800), fenY_(600), hauteurSol_(350)
{
}

/** \brief Détruit de Fenetre */
void Propriete::Fenetre::deleteFenetre()
{
	delete instance_;
	instance_ = NULL;
}

/** \brief Retourne l'instance (la crée si elle n'existait pas)
	\return instance_
*/
Propriete::Fenetre* Propriete::Fenetre::fenetre()
{
	if(instance_ == NULL)
		instance_ = new Fenetre();
		
	return instance_;
}

/** \brief Getter sur la longueur de la fenetre
*/
int Propriete::Fenetre::fenX()
{
	return instance_->fenX_;
}

/** \brief Getter sur la hauteur de la fenetre
*/
int Propriete::Fenetre::fenY()
{
	return instance_->fenY_;
}

/** \brief Getter sur la hauteur du sol
*/
int Propriete::Fenetre::hauteurSol()
{
	return instance_->hauteurSol_;
}
