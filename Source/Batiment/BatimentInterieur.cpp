#include "BatimentInterieur.h"
#include "../Objet/Cle.h"

/** \file Batiment/BatimentInterieur.cpp
	\brief L'intérieur d'un batiment
	\author RIOU, MAUSSION
*/


/** \brief Constructeur de BatimentInterieur, constuit l'étage qu'il contient
	\param parent La map contenant le batiment
	\param perso Le personnagedu joueur
*/
BatimentInterieur::BatimentInterieur(Map* parent, ConteneurPersonnage* perso) : 
				etage_(Etage(Propriete::Etage::tailleEtage().x,Propriete::Etage::tailleEtage().y, perso, parent))
{
}

/** \brief Ajoute une clé à l'étage contenu dans le batiment
	\param c La clé a ajouter
*/
void BatimentInterieur::addCle(Cle* c)
{
	etage_.addObjet(c);
}

/** \brief Getter sur l'étage
	\return &etage_
*/
Etage* BatimentInterieur::getEtage()
{
	return &etage_;
}

/** \brief Reporte la gestion des evenements sur l'étage
*/
void BatimentInterieur::gestionEvent()
{
	etage_.gestionEvent();
}

/** \brief Actualise le batiment
*/
void BatimentInterieur::update()
{
	gestionEvent();
}

/** \brief Deplace l'étage qu'il contient
*/
void BatimentInterieur::deplacer(Dir d)
{
	etage_.deplacer(d);
}

/** \brief Affiche l'étage contenu dans le batiment intérieur
*/
void BatimentInterieur::afficher(sf::RenderWindow &app) const
{
	etage_.afficher(app);
}
