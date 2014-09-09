#ifndef INVENTAIRE_STATIQUE_H
#define INVENTAIRE_STATIQUE_H

/** \file InventaireStatique.h
	\brief Inventaire observant l'inventaire du personnage et affiché en bas de la fenetre
	\author RIOU, MAUSSION
*/

#include <SFML/Graphics.hpp>
#include "../Propriete/Propriete.h"
#include "../Espace.h"
#include "../Math.h"
#include "../Observer/Observer.h"

class ConteneurPersonnage;
class Inventaire;

/** \class InventaireStatique
	\brief Classe héritant de Observer<Inventaire>, elle observe donc un inventaire
*/
class InventaireStatique : public Observer<Inventaire>
{
	private:
		sf::RectangleShape fond_;				/*!< Le fond de l'inventaire */

		unsigned int nbObjetMax_;				/*!< Le nombre maximum d'objets */ 
		std::vector<sf::Sprite> sprite_;		/*!< Ensemble des sprites */
		
		
		bool mousePressed_;						/*!< Boolen permettant de gérer les multiples evenements lors d'un seul clique */
		
	public:
		InventaireStatique(ConteneurPersonnage* inventaire);
		
		void gestionEvent(sf::RenderWindow const& app);

		virtual void actualiser();
		
		void afficher(sf::RenderWindow &app) const;
};

#endif //INVENTAIRE_STATIQUE_H
