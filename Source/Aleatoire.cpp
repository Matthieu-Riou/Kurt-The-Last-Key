#include "Aleatoire.h"

/*! \file Aleatoire.cpp
	\brief Gestionnaire de l'aléatoire du jeu
	\author RIOU Matthieu, MAUSSION Damien
*/


Aleatoire *Aleatoire::instance_ = NULL; /*!< On initialise l'instance à NULL */

/*! \brief Constructeur privé de l'aléatoire
	\param seed La graine de l'aléatoire
*/
Aleatoire::Aleatoire(int seed) : seed_(seed)
{
	srand(seed_);
}

/*! \brief Retourne un entier aléatoire
	\param min la valeur minimum voulue
	\param max la valeur maximal voulue
	\return un entier aleatoire entre min et max exclu.
		Si max <= min, il ya une erreur 
*/
int Aleatoire::genereInt(int min, int max)
{
	return rand()%(max-min) +min;	
}


/*! \brief Initialise l'instance de l'aléatoire
	\param seed La graine voulu (par défaut le temps courant)
*/
void Aleatoire::init(int seed)
{
	instance_ = new Aleatoire(seed);
}
/*! \brief Retourne un entier aléatoire
	\param min la valeur minimum voulue
	\param max la valeur maximal voulue
	\return un entier aleatoire entre min et max exclu.
		Si max <= min, il ya une erreur 
*/
int Aleatoire::getNext(int min, int max)
{
	return instance_->genereInt(min, max);
}
