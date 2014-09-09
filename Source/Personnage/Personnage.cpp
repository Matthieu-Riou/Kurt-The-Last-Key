#include "Personnage.h"
#include "../Objet/Objet.h"
#include "GestionAnimation/EtatAnimation.h"
#include "GestionAnimation/EtatSol.h"
#include "GestionAnimation/EtatEnAir.h"
#include "GestionAnimation/EtatEnAirIntermediaire.h"
#include "GestionAnimation/EtatBatiment.h"
#include <iostream>

/** \file Personnage.cpp
	\brief Représentation d'un personnage du jeu
	\author RIOU, MAUSSION
*/

/** \brief Constructeur de Personnage servant uniquement pour les décorateurs */

Personnage::Personnage() : etatSol_(0), etatAir_(0),etatAirIntermediaire_(0), etatBatiment_(0), etatCourant_(0), inventaire_(0)
{}

/** \brief Constructeur de Personnage 
	\param p Le Conteneur du Personnage
	\param d La direction courante
	\param taille La taille de l'image
	\param textures L'ensembles des textures du personnage
*/
Personnage::Personnage(ConteneurPersonnage* p, Dir d ,sf::Vector2f taille, std::vector<sf::Texture*> textures) : textures_(textures), dir_(d), taille_(taille), valeurSaut_(0), cptPied_(0), cptMax_(10),vitesse_(Propriete::Hero::vitesse()), etatSol_(new EtatSol(p)), etatAir_(new EtatEnAir(p)),etatAirIntermediaire_( new EtatEnAirIntermediaire(p)), etatBatiment_(new EtatBatiment(p)), etatCourant_(etatSol_), inventaire_(new Inventaire(p))
{
	updateSprite();
}

/** \brief Destructeur de Personnage, détruit tous les états */
Personnage::~Personnage(){
    delete etatAir_;
    delete etatSol_;
    delete etatBatiment_;
    delete etatAirIntermediaire_;
}

/** \brief Ajoute l'objet à l'inventaire
*/
void Personnage::ramasser(Objet *objet){
	inventaire_->ranger(objet);
}

/** \brief Renvoie vrai si on a ouvert le batiment (on a la bonne clé)
	\param bat Le batiment que l'on essaie d'ouvrir
*/
bool Personnage::essayerOuvrirBatiment(BatimentExterieur *bat){
	return inventaire_->testerTous(bat);
}

/** \brief Getter sur l'inventaire
*/
Inventaire* Personnage::getInventaire(){
	return inventaire_;
}

/** \brief Getter sur la vitesse
*/
float Personnage::getVitesse() const{
	return vitesse_;
}

/** \brief Getter sur la taille du personnage
*/
sf::Vector2f Personnage::getTaille() const
{
	return taille_;
}

/** \brief Getter sur la position du personnage
*/
sf::Vector2f Personnage::getPosition() const
{
    return sprite_.getPosition();
}

/** \brief Getter sur le centre du personnage
*/
sf::Vector2f Personnage::getCentre() const
{
    float x = sprite_.getPosition().x + taille_.x/2;
	float y = sprite_.getPosition().y + taille_.y/2;

    return sf::Vector2f(x, y);
}

/** \brief Getter sur la direction courante
*/
Dir Personnage::getDirection() const
{
	return dir_;
}

/** \brief Setter de la direction courante puis mise à jour de la sprite
	\param d La nouvelle direction
*/
void Personnage::setDir(Dir d){
	dir_=d;
	updateSprite();
}

/** \brief Getter de la valeur de saut
*/
int Personnage::getValeurSaut(){
    return valeurSaut_;
}

/** \brief Setter de la valeur de saut
	\param val La nouvelle valeur de saut
*/
void Personnage::setValeurSaut(int val){
    valeurSaut_ = val;
}

/** \brief Incrémente le compteur de pied et met à jour la sprite si nécéssaire
*/
void Personnage::incrementeCptPied(){
    cptPied_++;
    if (cptPied_/cptMax_ != (cptPied_-1) / cptMax_)
        updateSprite();
}

/** \brief Change la position et la direction et met à jour la sprite
	\param pos La nouvelle position
	\param dir La nouvelle direction
*/
void Personnage::setPosition(sf::Vector2f pos, Dir dir)
{
	sprite_.setPosition(pos);
    dir_=dir;
    updateSprite();
}

/** \brief Setter de l'état courant
	\param e Le nouvel état
*/
void Personnage::setEtatAnimation(EtatAnimation* e){
    etatCourant_ = e;
}

/** \brief Getter de l'état sol
*/
EtatAnimation* Personnage::getEtatSol(){
    return etatSol_;
}

/** \brief Getter de l'état air intermediaire
*/
EtatAnimation* Personnage::getEtatAirIntermediaire(){
	return etatAirIntermediaire_;
}

/** \brief Getter de l'état air
*/
EtatAnimation* Personnage::getEtatAir(){
    return etatAir_;
}

/** \brief Getter de l'état batiment
*/
EtatAnimation* Personnage::getEtatBatiment(){
    return etatBatiment_;
}

/** \brief Appel sauter de l'état courant
*/
void Personnage::sauter(){
    etatCourant_->sauter();
}

/** \brief Appel sauterDouble de l'état courant
*/
void Personnage::sauterDouble(){
	etatCourant_->sauterDouble();
}

/** \brief Appel entrerBatiment de l'état courant
*/
bool Personnage::entrerBatiment(){
	return etatCourant_->entrerBatiment();
}

/** \brief Appel sortirBatiment de l'état courant
*/
bool Personnage::sortirBatiment(){
	return etatCourant_->sortirBatiment();
}

/** \brief Appel update de l'état courant
*/		
void Personnage::update(){
    etatCourant_->update();
}	

/** \brief Appel updateSprite de l'état courant
*/
void Personnage::updateSprite(){
    sprite_.setTexture(*(textures_[dir_*4 + (cptPied_/cptMax_)%4]));
}

/** \brief Deplace la sprite
	\param x Le déplacement en largeur
	\param y Le déplacement en hauteur
*/
void Personnage::moveSprite(float x, float y){
    sprite_.move(x,y);
}

/** \brief Anime le personnage puis le déplace
	\param dir La direction du mouvement
	\param value La valeur du dépacement
*/
void Personnage::deplacer(Dir dir, float value){
    animer(dir);

	switch(dir_)
    {
        case GAUCHE:
            sprite_.move(-value, 0);
            break;
        case DROITE:
            sprite_.move(value, 0);
            break;
        case HAUT:
            sprite_.move(0, -value);
            break;
        case BAS:
            sprite_.move(0, value);
            break;
    }
}


/** \brief Appel animer de l'état courant
	\param dir La direction
*/
void Personnage::animer(Dir dir){
    etatCourant_->animer(dir);
}

/** \brief Affiche le personnage
	\param app La fenetre du jeu
*/
void Personnage::afficher(sf::RenderWindow &app) const{
	app.draw(sprite_);
}
