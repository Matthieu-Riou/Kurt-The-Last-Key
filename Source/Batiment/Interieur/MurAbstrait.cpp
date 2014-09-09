#include "MurAbstrait.h"

/** \file MurAbstrait.cpp
	\brief Représente un mur d'un étage
	\author RIOU, MAUSSION
*/

/** \brief Constructeur d'un MurAbstrait
	\param p Le point en haut à gauche
	\param longueur La longueur du mur
*/
MurAbstrait::MurAbstrait(sf::Vector2f p,int longueur): p_(p), longueur_(longueur)
{}

MurAbstrait::~MurAbstrait()
{}

/** \brief Affiche le mur dans la fenetre du jeu
	\param app La fenetre du jeu
*/
void MurAbstrait::afficher(sf::RenderWindow &app) const{
    for (unsigned int i=0;i<rectangles_.size();i++)
        app.draw(rectangles_[i]);
    for (unsigned int i=0;i<portes_.size();i++)
        app.draw(portes_[i]);
}

/** \brief Getter sur la position du mur
	\return p_
*/
sf::Vector2f MurAbstrait::getPosition() const
{
	return p_;
}

/** \brief Test si un point est dans le mur
	\param pos Le point à tester
	\return vrai si le point est dans le mur (dans les sous murs)
*/
bool MurAbstrait::collision(sf::Vector2f pos) const
{
	bool collision(false);
	unsigned int i(0);
	
	while(!collision && i < rectangles_.size())
	{
		collision = Espace::estDans(pos, rectangles_[i].getPoint(0), rectangles_[i].getPoint(2));
		i++;
	}
	
	return collision;
}

/** \brief Ajoute un sous mur à l'ensemble de rectangleShape
	\param p1 Le point en haut à gauche
	\param p2 Le point en haut à droite
	\param p3 Le point en bas à droite
	\param p4 Le point en bas à gauche
*/
void MurAbstrait::addRectangle(sf::Vector2f p1,sf::Vector2f p2,sf::Vector2f p3,sf::Vector2f p4){
    sf::ConvexShape convex;
    convex.setPointCount(4);
    convex.setPoint(0, p1);
    convex.setPoint(1, p2);
    convex.setPoint(2, p3);
    convex.setPoint(3, p4);
    convex.setFillColor(Propriete::Etage::colorMur());
    rectangles_.push_back(convex);
}

/** \brief Ajoute une porte à l'ensemble de rectangleShape
	\param p1 Le point en haut à gauche
	\param p2 Le point en haut à droite
	\param p3 Le point en bas à droite
	\param p4 Le point en bas à gauche
*/
void MurAbstrait::addPorte(sf::Vector2f p1,sf::Vector2f p2,sf::Vector2f p3,sf::Vector2f p4){
    sf::ConvexShape convex;
    convex.setPointCount(4);
    convex.setPoint(0, p1);
    convex.setPoint(1, p2);
    convex.setPoint(2, p3);
    convex.setPoint(3, p4);
    convex.setFillColor(Propriete::Etage::colorSol());
    portes_.push_back(convex);
}

/** \brief Ajoute un porte d'entrée
	\param p1 Le premier point
	\param p2 Le second point
	\return vrai si la porte a été ajoutée
*/
bool MurAbstrait::addFrontDoor(sf::Vector2f p1, sf::Vector2f p2)
{
	bool res = addDoor(p1, p2);
	
	if(res)
	{
		portes_.back().setFillColor(Propriete::Etage::colorFrontDoor());
		frontDoor_ = &portes_.back();
	}
		
	return res;
}

/** \brief Getter sur la porte d'entrée
	\return frontDoor_
*/
sf::ConvexShape* MurAbstrait::getFrontDoor()
{
	return frontDoor_;
}
