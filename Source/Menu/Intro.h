#ifndef INTRO_H
#define INTRO_H

#include <SFML/Graphics.hpp>
#include "../Personnage/ConteneurPersonnage.h"
#include "../Aleatoire.h"
#include "../Propriete/Propriete.h"
#include "../Batiment/BatimentExterieur_Apparence.h"
#include "../Map/Exterieur.h"

class Intro
{
	private:
		BatimentExterieur_Apparence bat_;

		ConteneurPersonnage perso_;


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
