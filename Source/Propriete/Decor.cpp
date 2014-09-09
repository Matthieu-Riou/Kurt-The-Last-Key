#include "Propriete.h"
#include <iostream>

/** \file Propriete/Decor.cpp
	\brief Regroupement des proprietes des decors
	\author RIOU, MAUSSION
*/

Propriete::Decor* Propriete::Decor::instance_=NULL; 		//Initialisation de l'instance

/** \brief Constructeur privé de Decor */
Propriete::Decor::Decor(){
	if (!arbre_.loadFromFile("Image/Decor/Arbre1.png") ||
		!nuage_.loadFromFile("Image/Decor/Nuage1.png") ||
		!rocher_.loadFromFile("Image/Decor/Rocher1.png") )
         std::cerr << "Impossible de charger l'image !" << std::endl;
}

/** \brief Getter sur l'instance
*/
Propriete::Decor* Propriete::Decor::decor(){
	if (instance_==NULL)
		instance_=new Decor();
	return instance_;
}

/** \brief Détruitet l'instance */
void Propriete::Decor::deleteDecor(){
	delete instance_;
	instance_ = NULL;
}

/** \brief Getter sur la texture de l'arbre
*/
sf::Texture* Propriete::Decor::arbre(){
	return &instance_->arbre_;
}
/** \brief Getter sur la texture du nuage
*/
sf::Texture* Propriete::Decor::nuage(){
	return &instance_->nuage_;
}
/** \brief Getter sur la texture du rocher
*/
sf::Texture* Propriete::Decor::rocher(){
	return &instance_->rocher_;
}
			
