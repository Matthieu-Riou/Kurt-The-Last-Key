#include "DecorateurPersonnage.h"

/** \file DecorateurPersonnage.cpp
	\brief Implémentation du pattern Decorator, toutes les méthodes sont surchargées 
		Pour toutes méthodes M , on utilise p->M()    pour n'avoir à réécrir que le minimum dans les décorateurs concrets
	\author RIOU, MAUSSION
*/

/*! \brief Constructeur de DecorateurPersonnage. Décore un personnage passé en smart pointer
*/
DecorateurPersonnage::DecorateurPersonnage(std::shared_ptr<Personnage> p) : Personnage(), perso_(p)
{}


void DecorateurPersonnage::ramasser(Objet *objet){
	perso_->ramasser(objet);
}


bool DecorateurPersonnage::essayerOuvrirBatiment(BatimentExterieur *bat){
	return perso_->essayerOuvrirBatiment(bat);
}

Inventaire* DecorateurPersonnage::getInventaire(){
	return perso_->getInventaire();
}


float DecorateurPersonnage::getVitesse() const{
	return perso_->getVitesse();
}

sf::Vector2f DecorateurPersonnage::getTaille() const{
	return perso_->getTaille();
}

sf::Vector2f DecorateurPersonnage::getPosition() const
{
    return perso_->getPosition();
}

sf::Vector2f DecorateurPersonnage::getCentre() const{
    return perso_->getCentre();
}

Dir DecorateurPersonnage::getDirection() const{
	return perso_->getDirection();
}

void DecorateurPersonnage::setDir(Dir d){
	perso_->setDir(d);
}

int DecorateurPersonnage::getValeurSaut(){
    return perso_->getValeurSaut();
}
void DecorateurPersonnage::setValeurSaut(int val){
    perso_->setValeurSaut(val);
}

void DecorateurPersonnage::incrementeCptPied(){
	perso_->incrementeCptPied();
}

void DecorateurPersonnage::sauterDouble()
{
	perso_->sauterDouble();
}


void DecorateurPersonnage::setPosition(sf::Vector2f pos, Dir dir){
	perso_->setPosition(pos, dir);
}

void DecorateurPersonnage::setEtatAnimation(EtatAnimation* e){
    perso_->setEtatAnimation(e);
}
EtatAnimation* DecorateurPersonnage::getEtatSol(){
    return perso_->getEtatSol();
}
EtatAnimation* DecorateurPersonnage::getEtatAirIntermediaire(){
	return perso_->getEtatAirIntermediaire();
}
EtatAnimation* DecorateurPersonnage::getEtatAir(){
    return perso_->getEtatAir();
}
EtatAnimation* DecorateurPersonnage::getEtatBatiment(){
    return perso_->getEtatBatiment();
}


void DecorateurPersonnage::sauter(){
    perso_->sauter();
}

bool DecorateurPersonnage::entrerBatiment(){
	return perso_->entrerBatiment();
}

bool DecorateurPersonnage::sortirBatiment(){
	return perso_->sortirBatiment();
}
		
void DecorateurPersonnage::update(){
    perso_->update();
}	

void DecorateurPersonnage::updateSprite(){
    perso_->updateSprite();
}
void DecorateurPersonnage::moveSprite(float x, float y){
   perso_->moveSprite(x,y);
}


void DecorateurPersonnage::deplacer(Dir dir, float value){
    perso_->deplacer(dir, value);
}



void DecorateurPersonnage::animer(Dir dir){
    perso_->animer(dir);
}


void DecorateurPersonnage::afficher(sf::RenderWindow &app) const{
	perso_->afficher(app);
}
