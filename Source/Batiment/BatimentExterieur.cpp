#include "BatimentExterieur.h"

/*! \file Batiment/BatimentExterieur.cpp
	\brief L'extérieur des batiments
	\author RIOU, MAUSSION
*/

/*! \brief Constructeur de batiment
	Trouve aléatoirement un nombre d'étages et un nombre de fenetres
	Retrouve la taille d'une fenetre, d'une porte et de l'espace inter-fenetres
	Calcule la taille du batiment obtenu
	Construit le mur, la porte, l'interieur du batiment puis ouvre le batiment
	Applique à chaque RectangleShape les mdifications nécéssaires (couleur, position...)
*/
BatimentExterieur::BatimentExterieur(float posX, Map* exterieur, ConteneurPersonnage* perso) : 
				apparence_(posX),
				interieur_(new BatimentInterieur(exterieur, perso)),
				ouvert_(true)
				
{}

/*! \brief Destructeur de BatimentExterieur 

*/
BatimentExterieur::~BatimentExterieur()
{
	delete interieur_;	
	interieur_ = NULL;
}

/*! \brief Ouvre le batiment, puis change la couleur de la porte
*/
void BatimentExterieur::ouvrir()
{
	ouvert_ = true;
	apparence_.ouvrir();
}

/*! \brief Ferme le batiment, puis change la couleur de la porte
*/
void BatimentExterieur::fermer()
{
	ouvert_ = false;
	apparence_.fermer();
}

/*! \brief Permet de savoir si le batiment est ouvert
 	\return ouvert_
*/
bool BatimentExterieur::estOuvert() const
{
	return ouvert_;
}

/*! \brief Permet de savoir si le batiment est fermé
 	\return !ouvert_
*/
bool BatimentExterieur::estFerme() const
{
	return !ouvert_;
}

/*! \brief Ajoute une clé dans le batiment
	\param c La clé à ajouter
*/
void BatimentExterieur::addCle(Cle* c)
{
	interieur_->addCle(c);
}


/*! \brief Getter sur la taille
	\return taille_
*/
sf::Vector2f BatimentExterieur::getTaille() const
{
	return apparence_.getTaille();
}
/*! \brief Getter sur la taille de la porte
	\return taillePorte_
*/
sf::Vector2f BatimentExterieur::getTaillePorte() const
{
	return apparence_.getTaillePorte();
}
/*! \brief Getter sur la position de la porte (position du rectangle la représentant)
	\return porte_.getPosition()
*/
sf::Vector2f BatimentExterieur::getPositionPorte() const
{
	return apparence_.getPositionPorte();
}

/*! \brief Getter sur l'interieur du batiment
	\return interieur_
*/
BatimentInterieur* BatimentExterieur::getInterieur() const
{
	return interieur_;
}


/*! \brief Affiche l'extérieur du batiment:  le mur, la porte puis les fenetres
	\param app La fenetre du jeu
*/
void BatimentExterieur::afficher(sf::RenderWindow &app) const
{
	apparence_.afficher(app);
}


