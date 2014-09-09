#include "Propriete.h"
#include <iostream>

/** \file Propriete/Hero.cpp
	\brief Regroupement des proprietes du héro
	\author RIOU, MAUSSION
*/


Propriete::Hero* Propriete::Hero::instance_ = NULL;		//Initialisation de l'instance

/** \brief Constructeur privé de Hero  */
Propriete::Hero::Hero() : 
			taille_(sf::Vector2f(33.,34.)), 
			textures_(std::vector<sf::Texture*>(16)), 
			valeurSaut_(25), 
			vitesse_(2.)
{	
	// On crée les textures (certaines cases ont les mêmes)
	
	textures_[GAUCHE*4] = new sf::Texture();
	textures_[GAUCHE*4 + 1] = new sf::Texture();
	textures_[GAUCHE*4 + 2] = textures_[GAUCHE*4];
	textures_[GAUCHE*4 + 3] = new sf::Texture();
	
	textures_[DROITE*4] = new sf::Texture();
	textures_[DROITE*4 + 1] = new sf::Texture();
	textures_[DROITE*4 + 2] = textures_[DROITE*4];
	textures_[DROITE*4 + 3] = new sf::Texture();
	
	textures_[HAUT*4] = new sf::Texture();
	textures_[HAUT*4 + 1] = new sf::Texture();
	textures_[HAUT*4 + 2] = textures_[HAUT*4];
	textures_[HAUT*4 + 3] = new sf::Texture();

	
	textures_[BAS*4] = new sf::Texture();
	textures_[BAS*4 + 1] = new sf::Texture();
	textures_[BAS*4 + 2] = textures_[BAS*4];
	textures_[BAS*4 + 3] = new sf::Texture();
	
	// On charge les images
	if ( !textures_[GAUCHE*4]->loadFromFile("Image/Kurt_Gauche0.png") ||
            !textures_[GAUCHE*4 + 1]->loadFromFile("Image/Kurt_Gauche1.png") ||
            !textures_[GAUCHE*4 + 3]->loadFromFile("Image/Kurt_Gauche2.png") ||
            !textures_[DROITE*4]->loadFromFile("Image/Kurt_Droite0.png") ||
            !textures_[DROITE*4+1]->loadFromFile("Image/Kurt_Droite1.png") ||
            !textures_[DROITE*4+3]->loadFromFile("Image/Kurt_Droite2.png") ||
            !textures_[HAUT*4]->loadFromFile("Image/Kurt_Haut0.png") ||
            !textures_[HAUT*4+1]->loadFromFile("Image/Kurt_Haut1.png") ||
            !textures_[HAUT*4+3]->loadFromFile("Image/Kurt_Haut2.png") ||
            !textures_[BAS*4]->loadFromFile("Image/Kurt_Bas0.png") ||
            !textures_[BAS*4+1]->loadFromFile("Image/Kurt_Bas1.png") ||
            !textures_[BAS*4+3]->loadFromFile("Image/Kurt_Bas2.png"))
    {
    	std::cerr<< "Impossible de charger une texture de la classe Hero." << std::endl;
    }
}

/** \brief Destructeur de Hero (détruit les textures) */
Propriete::Hero::~Hero(){
	for (unsigned int i=0; i<textures_.size(); i++){
		if (i%4 != 2)
			delete textures_[i];
	}
}


/** \brief Getter sur l'instance
*/
Propriete::Hero* Propriete::Hero::hero() {
	if(instance_ == NULL)
		instance_ = new Hero();
		
	return instance_;
}

/** \brief Détruit l'instance */
void Propriete::Hero::deleteHero(){
	delete instance_;
	instance_ = NULL;
}

/** \brief Getter sur la taille du héro
*/
sf::Vector2f Propriete::Hero::taille(){
	return instance_->taille_;
}

/** \brief Getter sur le tableau de textures
*/
std::vector<sf::Texture*> Propriete::Hero::textures(){
	return instance_->textures_;
}

/** \brief Getter sur la valeur de saut
*/
int Propriete::Hero::valeurSaut()
{
	return instance_->valeurSaut_;
}

/** \brief Getter sur la vitesse du héro
*/
float Propriete::Hero::vitesse()
{
	return instance_->vitesse_;
}
