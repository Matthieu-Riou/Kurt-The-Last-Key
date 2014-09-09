#include <SFML/Graphics.hpp>
#include "Gestionnaire.h"

/*! \file main.cpp
	\brief La fonction appelée au démarrage
	\author RIOU Matthieu, MAUSSION Damien
*/

/*! \brief Fonction main
	Crée la fenêtre de jeu ainsi que le gestionnaire
	Tant que la fenêtre est ouverte, met à jour et affiche le gestionnaire
*/ 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Kurt : The Last Key");

	Gestionnaire gestionnaire;

	window.setFramerateLimit(60);

    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (window.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
        
        gestionnaire.action(window);

        window.clear(sf::Color::Black);
		
		gestionnaire.afficher(window);

        window.display();

    }

    return 0;
}




/*! \mainpage Etat du projet

	\section actuel Etat actuel
	Le gameplay est en place, mais il n'y a rien autour, ni histoire, ni menu, ni réel intérêt au jeu.
	On peut se déplacer sur la map et dans les bâtiments, ramasser et utiliser des objets.
	
	\section probleme Problèmes qui se posent
	Le Personnage est trop dispersé dans le code, beaucoup de classes totalement distinctes y accèdent, ce qui a été très bien mis en lumière tout récemment par l'ajout du pattern Decorator. Même le patch de ConteneurPersonnage ne résout pas réellement les problèmes, il faut donc s'y repenché.
	
	\section immediat Dans l'immediat
	- Mise en place d'un depot pour simplifier le travail
	- Retravail sur la structure général, notamment pour Personnage (ça prendra sûrement son temps)
	- Reprise de la génération aléatoire des étages, mis en pause pour la rendu du projet
	
	\section aVenir À Venir (Pour se lècher les babines)
	- Des menus
	- Des sons
	- Une histoire
	- Une fin
	- Un monde plus complet (génération des bâtiments, ajout de meuble, d'objet divers, ...)
	- Un système de combat
	...
	
	
*/
