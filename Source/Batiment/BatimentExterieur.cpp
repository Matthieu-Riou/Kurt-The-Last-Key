#include "BatimentExterieur.h"

/*! \file Batiment/BatimentExterieur.cpp
	\brief L'extérieur des batiments
	\author RIOU, MAUSSION
*/

/*! \brief Constructeur de batiment
	Trouve aléatoirement un nombre d'étages et un nombre de fenetres
	Retrouve la taille d'une fenetre, d'une porte et de l'espace inter-fenetres
	Calcule la taille du batiment obtenu
	Construit le mur, la porte, l'interieur du batiment puis ouvre le batiment
	Applique à chaque RectangleShape les mdifications nécéssaires (couleur, position...)
*/
BatimentExterieur::BatimentExterieur(float posX, Map* exterieur, ConteneurPersonnage* perso) : 
				etage_(Aleatoire::getNext(Propriete::BatimentExterieur::nbEtageMin(),Propriete::BatimentExterieur::nbEtageMax())), //Entre 0 et 5 inclus (6 exclus)
				nbFenLargeur_(Aleatoire::getNext(Propriete::BatimentExterieur::nbFenLargeurMin(),Propriete::BatimentExterieur::nbFenLargeurMax())),
				tailleFen_(Propriete::BatimentExterieur::tailleFenetre()),
				espaceFen_(Propriete::BatimentExterieur::espaceFenetre()),
				taillePorte_(Propriete::BatimentExterieur::taillePorte()),
				taille_(nbFenLargeur_*(tailleFen_.x + espaceFen_.x) + espaceFen_.x, (etage_)*(tailleFen_.y + espaceFen_.y) + taillePorte_.y + espaceFen_.y), 			
				mur_(sf::RectangleShape(taille_)), 
				porte_(sf::RectangleShape(taillePorte_)),
				interieur_(new BatimentInterieur(exterieur, perso)),
				ouvert_(true)
				
{
	mur_.move(posX, Propriete::Fenetre::hauteurSol() - taille_.y);
	mur_.setFillColor(Propriete::BatimentExterieur::colorMur());
	mur_.setOutlineThickness(1);
	mur_.setOutlineColor(sf::Color::Black);
	

	porte_.move((posX + taille_.x/2 - taillePorte_.x/2),  Propriete::Fenetre::hauteurSol() - taillePorte_.y);
	porte_.setFillColor(Propriete::BatimentExterieur::colorPorteOuverte());
	porte_.setOutlineThickness(1);
	porte_.setOutlineColor(sf::Color::Black);
	
	for(unsigned int i = 0; i < etage_; i++)
	{
		for(unsigned int j = 0; j < nbFenLargeur_; j++)
		{
			fen_.push_back(sf::RectangleShape(tailleFen_));
			fen_.back().move(posX + espaceFen_.x + j*(tailleFen_.x + espaceFen_.x), Propriete::Fenetre::hauteurSol() - taillePorte_.y -((tailleFen_.y + espaceFen_.x)*(i+1)));
			fen_.back().setFillColor(Propriete::BatimentExterieur::colorFenetre());
			fen_.back().setOutlineThickness(1);
			fen_.back().setOutlineColor(sf::Color::Black);
		}
	}
}

/*! \brief Destructeur de BatimentExterieur 

*/
BatimentExterieur::~BatimentExterieur()
{
	delete interieur_;	
	interieur_ = NULL;
}

/*! \brief Ouvre le batiment, puis change la couleur de la porte
*/
void BatimentExterieur::ouvrir()
{
	ouvert_ = true;
	porte_.setFillColor(Propriete::BatimentExterieur::colorPorteOuverte());
}

/*! \brief Ferme le batiment, puis change la couleur de la porte
*/
void BatimentExterieur::fermer()
{
	ouvert_ = false;
	porte_.setFillColor(Propriete::BatimentExterieur::colorPorteFerme());
}

/*! \brief Permet de savoir si le batiment est ouvert
 	\return ouvert_
*/
bool BatimentExterieur::estOuvert() const
{
	return ouvert_;
}

/*! \brief Permet de savoir si le batiment est fermé
 	\return !ouvert_
*/
bool BatimentExterieur::estFerme() const
{
	return !ouvert_;
}

/*! \brief Ajoute une clé dans le batiment
	\param c La clé à ajouter
*/
void BatimentExterieur::addCle(Cle* c)
{
	interieur_->addCle(c);
}


/*! \brief Getter sur la taille
	\return taille_
*/
sf::Vector2f BatimentExterieur::getTaille() const
{
	return taille_;
}
/*! \brief Getter sur la taille de la porte
	\return taillePorte_
*/
sf::Vector2f BatimentExterieur::getTaillePorte() const
{
	return taillePorte_;
}
/*! \brief Getter sur la position de la porte (position du rectangle la représentant)
	\return porte_.getPosition()
*/
sf::Vector2f BatimentExterieur::getPositionPorte() const
{
	return porte_.getPosition();
}

/*! \brief Getter sur l'interieur du batiment
	\return interieur_
*/
BatimentInterieur* BatimentExterieur::getInterieur() const
{
	return interieur_;
}

/*! \brief Deplace le batiment suivant la direction
	\param dir La direction voulue
*/
void BatimentExterieur::deplacer(Dir dir)
{
	switch(dir)
    {
        case GAUCHE:
            mur_.move(2., 0.);
            porte_.move(2., 0.);
            
            for(unsigned int i = 0; i < fen_.size(); i++)
            {
            	fen_[i].move(2., 0.);
        	}
            
            break;

        case DROITE:
            mur_.move(-2., 0.);
            porte_.move(-2., 0.);
            
            for(unsigned int i = 0; i < fen_.size(); i++)
            {
            	fen_[i].move(-2., 0.);
        	}
        	
            break;
            
		case HAUT:
            mur_.move(0., -2.);
            porte_.move(0., -2.);
            
            for(unsigned int i = 0; i < fen_.size(); i++)
            {
            	fen_[i].move(0., -2.);
        	}
        	
            break;
            
		case BAS:
            mur_.move(0., 2.);
            porte_.move(0., 2.);
            
            for(unsigned int i = 0; i < fen_.size(); i++)
            {
            	fen_[i].move(0., 2.);
        	}
        	
            break;
    }
}

/*! \brief Affiche l'extérieur du batiment:  le mur, la porte puis les fenetres
	\param app La fenetre du jeu
*/
void BatimentExterieur::afficher(sf::RenderWindow &app) const
{
	app.draw(mur_);
	app.draw(porte_);
	
	for(unsigned int i = 0; i < fen_.size(); i++)
    {
    	app.draw(fen_[i]);
	}
}


