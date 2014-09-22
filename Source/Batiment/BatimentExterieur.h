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
#include "BatimentExterieur_Apparence.h"

/*! \class BatimentExterieur
	\brief Classe gérant l'extérieur des batiments
*/
class BatimentExterieur
{
	private:
		BatimentExterieur_Apparence apparence_;		

		BatimentInterieur* interieur_;			/*!< Pointeur vers l'interieur du batiment */ 
		
		bool ouvert_;					/*!< Booléen qui prend vrai si le batiment est ouvert */
		
	public:
	
		BatimentExterieur(float posX, Map* exterieur, ConteneurPersonnage* perso);
		~BatimentExterieur();
		
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
