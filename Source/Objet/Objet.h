#ifndef OBJET_H
#define OBJET_H

/** \file Objet.h
	\brief Représentation d'un objet du jeu
	\author RIOU, MAUSSION
*/

#include <SFML/Graphics.hpp>
#include <string>
#include "../Propriete/Propriete.h"

class ConteneurPersonnage;
class Personnage;
class BatimentExterieur;


/** \class Objet
	\brief Classe représentant un objet du jeu
*/
class Objet
{
	protected:
		sf::Texture* texture_;		/*!< La texture de l'objet (récupérée dans Propriete et détruite par Propriete) */
		sf::Sprite sprite_;			/*!< La Sprite (l'image) de l'objet */
		Objet(sf::Texture* texture); //Pour rendre la classe "abstraire"

	public:
		virtual ~Objet();
		
		//Fonctions par défaut
		virtual bool utiliser(BatimentExterieur *batiment);
		virtual bool utiliser(ConteneurPersonnage* personnage);
		
		virtual sf::Vector2f getTaille() const;

		virtual sf::Texture* getTexture();
		
		virtual sf::Vector2f getPosition() const;
		virtual void setPosition(sf::Vector2f pos);
		
		virtual void afficher(sf::RenderWindow &app) const;
		
};

#endif //OBJET_H
