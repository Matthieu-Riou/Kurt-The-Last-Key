#include "Map.h"
#include "../Personnage/Personnage.h"

/** \file Map.cpp
	\brief Représentation du monde dans lequel évolue le personnage
	\author RIOU, MAUSSION
*/

/** \brief Constructeur de Map
	Initialise les différents attributs et fixe la view 
	\param mapCourante La map courante
	\param perso Le personnage du joueur
	\param mapParent La map parente (de laquelle on vient)
*/
Map::Map(Map* mapCourante, ConteneurPersonnage* perso, Map* mapParent) : mapCourante_(mapCourante), mapParent_(mapParent), Kurt(perso)
{
	posKurt = (*Kurt)->getPosition();
	dirKurt = (*Kurt)->getDirection();
	
	viewMap_.reset(sf::FloatRect(0, 0, 800, 350));
	viewMap_.setViewport(sf::FloatRect(0, 0, 1.f, 350./600.));
}

/** \brief Destructeur de Map
*/
Map::~Map()
{
}

/** \brief Fonction appelée lorsque l'on arrive sur la map (ne fait rien par défaut)
*/
void Map::entrer()
{
	//par défaut rien
}

/** \brief Fonction appelée lorsque l'on sort d'un batiment
*/
void Map::sortir()
{
	if(mapCourante_ == NULL)
	{
		std::cerr << "Erreur de map (sortir)" << std::endl;
	}
	else
	{
		mapCourante_ = this;
		(*Kurt)->setPosition(posKurt, dirKurt);
	}
}

/** \brief Parcours tous les objets contenus dans la map pour trouver ceux qui sont à la même position que le personnage et les lui ajouter (puis les supprimer de la map)
*/
void Map::testRamasserObjet()
{
	unsigned int i(0);
	bool trouve(false);
	
	while(!trouve && i < objet_.size())
	{
		if(Espace::estDans(posKurt, objet_[i]->getPosition(), objet_[i]->getPosition() + objet_[i]->getTaille()))
		{
			(*Kurt)->ramasser(objet_[i]);
			objet_.erase(objet_.begin() + i);
			trouve = true;
		}
		
		i++;
	}
}

/** \brief Affiche la map dans la fenetre
	\param app La fenetre du jeu
*/
void Map::afficher(sf::RenderWindow &app) const
{
	app.setView(viewMap_);
}
