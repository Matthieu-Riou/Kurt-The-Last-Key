#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

/*! \file Gestionnaire.h
	\brief Le gestionnaire du jeu
	\author RIOU Matthieu, MAUSSION Damien
*/

#include <SFML/Graphics.hpp>
#include "Map/Map.h"
#include "Map/Exterieur.h"
#include "Aleatoire.h"
#include "Propriete/Propriete.h"
#include "Statique/MenuStatique.h"
#include "Personnage/ConteneurPersonnage.h"


/*! \class Gestionnaire
	\brief La classe gérant tout le jeu
*/
class Gestionnaire
{
    private:
        Map* map_;					/*!< La map sur laquelle on joue */
		MenuStatique* statique_; 	/*!< Le menu affiché sous la map */
		
		/** \brief Constructeur de copie en privé sans définition : classe non copiable
		*/
		Gestionnaire(Gestionnaire const&);
		
		/** \brief Opérateur d'affectation en privé sans définition : classe non copiable
		*/
		Gestionnaire& operator=(Gestionnaire const&);
		
    public:
        Gestionnaire();
        ~Gestionnaire();

		void start(sf::RenderWindow &app);

        void action(sf::RenderWindow const& app);
        
        void afficher(sf::RenderWindow &app) const;
};

#endif // GESTIONNAIRE_H
