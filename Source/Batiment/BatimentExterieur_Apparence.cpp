#include "BatimentExterieur_Apparence.h"

BatimentExterieur_Apparence::BatimentExterieur_Apparence(float posX, int etage, int nbFenLargeur) : 
		etage_(etage), //Entre 0 et 5 inclus (6 exclus)
		nbFenLargeur_(nbFenLargeur),
		tailleFen_(Propriete::BatimentExterieur::tailleFenetre()),
		espaceFen_(Propriete::BatimentExterieur::espaceFenetre()),
		taillePorte_(Propriete::BatimentExterieur::taillePorte()),
		taille_(nbFenLargeur_*(tailleFen_.x + espaceFen_.x) + espaceFen_.x, (etage_)*(tailleFen_.y + espaceFen_.y) + taillePorte_.y + espaceFen_.y), 			

		mur_(sf::RectangleShape(taille_)), 
		porte_(sf::RectangleShape(taillePorte_))
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

/*! \brief Getter sur la taille
	\return taille_
*/
sf::Vector2f BatimentExterieur_Apparence::getTaille() const
{
	return taille_;
}
/*! \brief Getter sur la taille de la porte
	\return taillePorte_
*/
sf::Vector2f BatimentExterieur_Apparence::getTaillePorte() const
{
	return taillePorte_;
}
/*! \brief Getter sur la position de la porte (position du rectangle la représentant)
	\return porte_.getPosition()
*/
sf::Vector2f BatimentExterieur_Apparence::getPositionPorte() const
{
	return porte_.getPosition();
}


/*! \brief Ouvre le batiment, puis change la couleur de la porte
*/
void BatimentExterieur_Apparence::ouvrir()
{
	porte_.setFillColor(Propriete::BatimentExterieur::colorPorteOuverte());
}

/*! \brief Ferme le batiment, puis change la couleur de la porte
*/
void BatimentExterieur_Apparence::fermer()
{
	porte_.setFillColor(Propriete::BatimentExterieur::colorPorteFerme());
}



/*! \brief Affiche l'extérieur du batiment:  le mur, la porte puis les fenetres
	\param app La fenetre du jeu
*/
void BatimentExterieur_Apparence::afficher(sf::RenderWindow &app) const
{
	app.draw(mur_);
	app.draw(porte_);
	
	for(unsigned int i = 0; i < fen_.size(); i++)
    {
    	app.draw(fen_[i]);
	}
}

