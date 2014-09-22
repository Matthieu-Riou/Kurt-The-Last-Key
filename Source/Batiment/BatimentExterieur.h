#ifndef BATIMENT_EXTERIEUR_H
#define BATIMENT_EXTERIEUR_H

/*! \file BatimentExterieur.h
	\brief L'extérieur des batiments
	\author RIOU, MAUSSION
*/
#include <SFML/Graphics.hpp>

#include <vector>

#include "BatimentInterieur.h"
#include "../Aleatoire.h"
#include "../Propriete/Propriete.h"
#include "../Espace.h"

/*! \class BatimentExterieur
	\brief Classe gérant l'extérieur des batiments
*/
class BatimentExterieur
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
		
		BatimentInterieur* interieur_;			/*!< Pointeur vers l'interieur du batiment */ 
		
		bool ouvert_;					/*!< Booléen qui prend vrai si le batiment est ouvert */
		
	public:
	
		BatimentExterieur(float posX, Map* exterieur, ConteneurPersonnage* perso);
		~BatimentExterieur();
		
		/*! \fn void ouvrir()
			\brief Ouvre le batiment, puis change la couleur de la porte
		*/
		void ouvrir();
		void fermer();

		bool estOuvert() const;
		bool estFerme() const;

		void addCle(Cle* c);
		
		
		sf::Vector2f getTaille() const;
		sf::Vector2f getTaillePorte() const;
		
		sf::Vector2f getPositionPorte() const;
		
		BatimentInterieur* getInterieur() const;
		
		void afficher(sf::RenderWindow &app) const;
};

#endif //BATIMENT_EXTERIEUR_H
