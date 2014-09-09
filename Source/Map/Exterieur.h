#ifndef EXTERIEUR_H
#define EXTERIEUR_H

/** \file Exterieur.h
	\brief Représentation du monde extérieur
	\author RIOU, MAUSSION
*/

#include <list>
#include <vector>
#include <iostream>

#include "Map.h"
#include "../Decor/Decor.h"
#include "../Decor/Nuage.h"
#include "../Decor/Arbre.h"
#include "../Decor/Rocher.h"
#include "../Aleatoire.h"
#include "../Espace.h"
#include "../Math.h"
#include "../Propriete/Propriete.h"
#include "../Batiment/BatimentExterieur.h"
#include "../Objet/Objet.h"
#include "../Objet/EtoileVitesse.h"
#include "../Objet/EtoileSaut.h"

/** \class Exterieur
	\brief Classe héritant de Map représentant le monde extérieur (extérieur des batiments)
*/
class Exterieur : public Map
{
    private:
        sf::RectangleShape fond_;				/*!< Le ciel */
        
        std::list<Decor*> decor_;				/*!< Ensemble d'éléments de décors */
        int longueur_;							/*!< La longueur de la map */
        
        void genererDecorSol();
        void genererDecorAir();
        int genererBatiment(int nbBatiment); 
        void genererCle(int nbBatiment);       
        
        std::vector<BatimentExterieur*> batiments_;		/*!< Ensemble de BatimentExterieur */

    public:
        Exterieur(int difficulte, ConteneurPersonnage* perso);
        virtual ~Exterieur();
        
        virtual void sortir();
        
        virtual void addObjet(Objet* o);

		virtual void gestionEvent();
        virtual void update();
        virtual void deplacer(Dir d);
        
        virtual void afficher(sf::RenderWindow &app) const;
};

#endif // EXTERIEUR_H
