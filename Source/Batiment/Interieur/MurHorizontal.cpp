#include "MurHorizontal.h"

/** \file MurHorizontal.cpp
	\brief Représentation d'un mur horizontal
	\author RIOU, MAUSSION
*/

/** \brief Constructeur de MurHorizontal
	Crée un sous mur horizontal de la longueur passée en parametre
	\param p Le point en haut à gauche
	\param longueur La longueur du mur
*/
MurHorizontal::MurHorizontal(sf::Vector2f p,int longueur): MurAbstrait(p, longueur)
{
	addRectangle(p, sf::Vector2f( p.x+longueur, p.y), sf::Vector2f( p.x+longueur , p.y+Propriete::Etage::tailleMur() ), sf::Vector2f(p.x, p.y+Propriete::Etage::tailleMur()));
}
/** \brief Destructeur de MurHorizontal */
MurHorizontal::~MurHorizontal(){}

/** \brief Renvoie que le mur est horizontal
	\return true
*/
bool MurHorizontal::isHorizontal() const{
	return true;
}
/** \brief Renvoie que le mur n'est pas vertical
	\return false
*/
bool MurHorizontal::isVertical() const {
	return false;
}


/** \brief Ajoute une porte
		Trouve le sous mur contenant les deux points passés en parametre puis le coupe en deux sous murs et ajoute la porte
	\param p1 Le premier point de la porte
	\param p2 Le second point de la porte
	\return vrai si l'opération a réussie
*/
bool MurHorizontal::addDoor(sf::Vector2f p1, sf::Vector2f p2){
    int i = rectangles_.size()-1;
    while (i>0 && (!Espace::estDans(p1,rectangles_[i].getPoint(0),rectangles_[i].getPoint(2)) || !Espace::estDans(p2,rectangles_[i].getPoint(0),rectangles_[i].getPoint(2)) )){
        i--;
    }
    if (i>-1){      					//si on a trouvé un sous mur qui contient les 2 points, on crée la porte
      	//reduit la 1ere partie du mur
        sf::Vector2f backupP1(rectangles_[i].getPoint(1)), backupP2(rectangles_[i].getPoint(2));
		sf::Vector2f p0(rectangles_[i].getPoint(0));
		
        rectangles_[i].setPoint(1, sf::Vector2f(p1.x, p0.y));
        rectangles_[i].setPoint(2, sf::Vector2f(p1.x, p0.y+Propriete::Etage::tailleMur()));

        addPorte(sf::Vector2f(p1.x, p0.y-2+Propriete::Etage::tailleMur()/2), sf::Vector2f(p2.x, p0.y-2+Propriete::Etage::tailleMur()/2), sf::Vector2f(p2.x, p0.y+3+Propriete::Etage::tailleMur()/2), sf::Vector2f(p1.x, p0.y+3+Propriete::Etage::tailleMur()/2));

		//On créé la 2eme partie du mur
        addRectangle(sf::Vector2f(p2.x, p0.y), backupP1, backupP2, sf::Vector2f(p2.x, p0.y+Propriete::Etage::tailleMur()));

        return true;
    }
    else
    	return false;
}
