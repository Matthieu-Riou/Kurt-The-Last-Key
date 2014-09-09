#include "MenuStatique.h"

/** \file MenuStatique.cpp
	\brief Menu affiché sous la map
	\author RIOU, MAUSSION
*/

/** \brief Constructeur de MenuStatique, definit l'InventaireStatique et fixe la view
	\param perso Le Personnage du joueur dont on doit afficher les informations 
*/
MenuStatique::MenuStatique(ConteneurPersonnage* perso) : inventaireStatique_(InventaireStatique(perso))
{
	viewMenu_.reset(sf::FloatRect(0, 350, 800, 250));
	viewMenu_.setViewport(sf::FloatRect(0, 350./600., 1.f, 250./600.));
}

/** \brief Lance la détection des entrées utilisateur (souris)
	\param app La fenetre du jeu
*/
void MenuStatique::update(sf::RenderWindow const& app)
{
	inventaireStatique_.gestionEvent(app);
}

/** \brief Affiche le menu
	\param app La fenetre du jeu
*/
void MenuStatique::afficher(sf::RenderWindow &app) const
{
	app.setView(viewMenu_);
	inventaireStatique_.afficher(app);
}
