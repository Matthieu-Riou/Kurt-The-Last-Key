#ifndef ALEATOIRE_H
#define ALEATOIRE_H

/*! \file Aleatoire.h
	\brief Gestionnaire de l'aléatoire du jeu
	\author RIOU Matthieu, MAUSSION Damien
*/
#include <cstdlib>
#include <ctime>

/*! \class Aleatoire 
	\brief Classe gérant l'aleatoire du jeu.
	Elle permet d'avoir une seule graine(déterminée par le temps courant ou envoyé en parametre) pour tout les aléatoires du jeu
*/
class Aleatoire //Genre de Singleton
{
	private:
				
		Aleatoire(int seed);
		
		static Aleatoire *instance_; 				/*!< L'instance de l'Aléatoire */
		int seed_; 									/*!< La graine utilisée */
		
		int genereInt(int min, int max);
		
	public:
		
		static void init(int seed = time(NULL));
		static int getNext(int min, int max); 
};

#endif //ALEATOIRE_H
