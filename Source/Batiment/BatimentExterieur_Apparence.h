#ifndef BATIMENT_EXTERIEUR_APPARENCE_H
#define BATIMENT_EXTERIEUR_APPARENCE_H

#include <SFML/Graphics.hpp>

#include <vector>

#include "../Aleatoire.h"
#include "../Propriete/Propriete.h"

class BatimentExterieur_Apparence
{
	private:
		unsigned int etage_; 			/*!< Nombre d'étages */
		unsigned int nbFenLargeur_;		/*!< Nembre de fenetres */
		
		sf::Vector2f tailleFen_;		/*!< Taille d'une fenetre */
		sf::Vector2f espaceFen_;		/*!< Espace entre 2 fenetres */
		sf::Vector2f taillePorte_;		/*!< Taille de la porte */
		sf::Vector2f taille_;			/*!< Taille du batiment */
		
		sf::RectangleShape mur_;		/*!< Le rectangle représentant le mur */
		sf::RectangleShape porte_; 		/*!< Le rectangle représentant la porte */
		std::vector<sf::RectangleShape> fen_;	/*!< Ensemble de toutes les fenetres */

	public:
		BatimentExterieur_Apparence(float posX, int etage = Aleatoire::getNext(Propriete::BatimentExterieur::nbEtageMin(),Propriete::BatimentExterieur::nbEtageMax()), int nbFenLargeur = Aleatoire::getNext(Propriete::BatimentExterieur::nbFenLargeurMin(),Propriete::BatimentExterieur::nbFenLargeurMax()));

		sf::Vector2f getTaille() const;
		sf::Vector2f getTaillePorte() const;
		sf::Vector2f getPositionPorte() const;

		void ouvrir();
		void fermer();

		void afficher(sf::RenderWindow &app) const;
	
};

#endif //BATIMENT_EXTERIEUR_APPARENCE_H
