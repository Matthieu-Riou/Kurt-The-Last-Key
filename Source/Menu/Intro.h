#ifndef INTRO_H
#define INTRO_H

#include <SFML/Graphics.hpp>
#include "../Aleatoire.h"
#include "../Propriete/Propriete.h"
#include "../Map/Exterieur.h"

class Intro
{
	private:
		unsigned int bat_etage_;
		unsigned int bat_nbFenLargeur_;
		float bat_posX;

		sf::Vector2f bat_tailleFen_;
		sf::Vector2f bat_espaceFen_;
		sf::Vector2f bat_taillePorte_;
		sf::Vector2f bat_taille_;

		sf::RectangleShape bat_mur_;
		sf::RectangleShape bat_porte_;
		std::vector<sf::RectangleShape> bat_fen_;



		sf::RectangleShape fond_;
		sf::Font font_;
		sf::Text texte_;

		std::list<Decor*> decor_;

	public:
		Intro();
		~Intro();

		void run(sf::RenderWindow &app);
		void afficher(sf::RenderWindow &app);
};

#endif //INTRO_H
