#include "MurVertical.h"

/** \file MurVertical.cpp
	\brief Représentation d'un mur vertical
	\author RIOU, MAUSSION
*/

/** \brief Constructeur de MurVertical
	Crée un sous mur vertical de la longueur passée en parametre
	\param p Le point en haut à gauche
	\param longueur La longueur du mur
*/
MurVertical::MurVertical(sf::Vector2f p,int longueur): MurAbstrait(p, longueur)
{
	sf::Vector2f p1(p);
	sf::Vector2f p2(p.x + Propriete::Etage::tailleMur(), p.y);
	sf::Vector2f p3(p.x+Propriete::Etage::tailleMur() , p.y+longueur_);
	sf::Vector2f p4(p.x, p.y+longueur_);
	
	addRectangle(p1, p2, p3, p4);
}
/** \brief Destructeur de MurVertical */
MurVertical::~MurVertical(){}

/** \brief Renvoie que le mur n'est pas horizontal
	\return false
*/
bool MurVertical::isHorizontal() const{
	return false;
}
/** \brief Renvoie que le mur est vertical
	\return true
*/
bool MurVertical::isVertical() const {
	return true;
}

/** \brief Ajoute une porte
		Trouve le sous mur contenant les deux points passés en parametre puis le coupe en deux sous murs et ajoute la porte
	\param p1 Le premier point de la porte
	\param p2 Le second point de la porte
	\return vrai si l'opération a réussie
*/
bool MurVertical::addDoor(sf::Vector2f p1, sf::Vector2f p2){
	int i = rectangles_.size()-1;
    while (i>0 && (!Espace::estDans(p1,rectangles_[i].getPoint(0),rectangles_[i].getPoint(2)) || !Espace::estDans(p2,rectangles_[i].getPoint(0),rectangles_[i].getPoint(2)) )){
        i--;
    }
    if (i>-1){      					//si on a trouvé un sous mur qui contient les 2 points, on crée la porte
		//reduit la 1ere partie du mur
        sf::Vector2f backupP2(rectangles_[i].getPoint(2)), backupP3(rectangles_[i].getPoint(3));
        
        sf::Vector2f p0(rectangles_[i].getPoint(0));

        rectangles_[i].setPoint(2, sf::Vector2f(p0.x+Propriete::Etage::tailleMur(), p1.y));
        rectangles_[i].setPoint(3, sf::Vector2f(p0.x, p1.y));

        addPorte(sf::Vector2f(p1.x-1+Propriete::Etage::tailleMur()/2, p1.y), sf::Vector2f(p1.x+1+Propriete::Etage::tailleMur()/2, p1.y), sf::Vector2f(p2.x+1+Propriete::Etage::tailleMur()/2, p2.y), sf::Vector2f(p2.x-1+Propriete::Etage::tailleMur()/2, p2.y));

		//On crée la 2eme partie du mur
        addRectangle(sf::Vector2f(p0.x, p2.y), sf::Vector2f(p0.x+Propriete::Etage::tailleMur(), p2.y), backupP2, backupP3);

        return true;
    }
    else
    	return false;
}
