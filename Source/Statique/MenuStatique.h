#ifndef MENU_STATIQUE_H
#define MENU_STATIQUE_H

/** \file MenuStatique.h
	\brief Menu affiché sous la map
	\author RIOU, MAUSSION
*/

#include "InventaireStatique.h"
#include "../Personnage/ConteneurPersonnage.h"

/** \class MenuStatique
	\brief Classe du menu affiché sous la map courante
*/
class MenuStatique
{
	private:
		sf::View viewMenu_;							/*!< La view controllant l'affichage du menu */
		InventaireStatique inventaireStatique_;		/*!< L'inventaire à afficher */
		
	public:
		MenuStatique(ConteneurPersonnage* perso);
		
		void update(sf::RenderWindow const& app);
		
		void afficher(sf::RenderWindow &app) const;
};

#endif //MENU_STATIQUE_H
