#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

/** \file Personnage.h
	\brief représentation d'un personnage du jeu
	\author RIOU, MAUSSION
*/

#include <SFML/Graphics.hpp>

#include "../Espace.h"
#include "../Propriete/Propriete.h"
#include "Inventaire.h"
#include <vector>


class EtatAnimation;				/*!< Forward declaration */
class EtatSol;						/*!< Forward declaration */
class EtatEnAirIntermediaire;		/*!< Forward declaration */
class EtatEnAir;					/*!< Forward declaration */
class EtatBatiment;					/*!< Forward declaration */

class Objet;

/** \class Personnage
	\brief Classe représentant un personnage du jeu
*/
class Personnage
{
    protected:
    	Personnage();

        sf::Sprite sprite_;							/*!< La sprite (image) du personnage */
        std::vector<sf::Texture*> textures_;		/*!< L'ensemble des textures du personnage */
	
        Dir dir_;									/*!< La direction courante */

        sf::Vector2f taille_;						/*!< La taille du personnage */
        int valeurSaut_;							/*!< La valeur de saut du personnage */

        int cptPied_;								/*!< Le compteur de pied */
        int cptMax_;								/*!< Le compteur maximum de pied (tous les cptMax_, on change de pied) */
        
        int vitesse_;								/*!< La vitesse du personnage */
        
     	EtatAnimation* etatSol_;					/*!< L'état sol */
        EtatAnimation* etatAir_;					/*!< L'état air */
        EtatAnimation* etatAirIntermediaire_;		/*!< L'état air intermediaire */
        EtatAnimation* etatBatiment_;				/*!< L'état batiment */
        
        EtatAnimation* etatCourant_;				/*!< L'état courant */
        
        Inventaire* inventaire_;					/*!< L'inventaire du personnage */

        
    public:
        Personnage(Dir d ,sf::Vector2f taille, std::vector<sf::Texture*> textures, EtatAnimation* etatSol, EtatAnimation* etatAir, EtatAnimation* etatAirIntermediaire, EtatAnimation* etatBatiment, Inventaire* inventaire);
        virtual ~Personnage();

        virtual bool essayerOuvrirBatiment(BatimentExterieur *bat);
        virtual void ramasser(Objet *objet);

		virtual Inventaire* getInventaire();


		virtual float getVitesse() const;

        virtual sf::Vector2f getTaille() const;
        virtual sf::Vector2f getPosition() const;
        virtual sf::Vector2f getCentre() const;
        
        virtual Dir getDirection() const;
        virtual void setDir(Dir d);
        
        virtual int getValeurSaut();
        virtual void setValeurSaut(int val);

        virtual void incrementeCptPied();

        virtual void setPosition(sf::Vector2f pos, Dir dir);

		virtual void setEtatAnimation(EtatAnimation* e);
        virtual EtatAnimation* getEtatSol();
        virtual EtatAnimation* getEtatAirIntermediaire();
        virtual EtatAnimation* getEtatAir();
        virtual EtatAnimation* getEtatBatiment();

		virtual void sauter();
		virtual void sauterDouble();
		virtual bool entrerBatiment();
		virtual bool sortirBatiment();

        virtual void update();
        
        virtual void updateSprite();
        virtual void moveSprite(float x, float y);

        virtual void deplacer(Dir dir, float value);
        virtual void animer(Dir dir);
		virtual void afficher(sf::RenderWindow &app) const;


		virtual void setTexture(std::vector<sf::Texture*> textures);

};

#endif //PERSONNAGE_H_INCLUDED
