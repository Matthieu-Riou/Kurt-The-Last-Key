#include "Gestionnaire.h"

/*! \file Gestionnaire.cpp
	\brief Le gestionnaire du jeu
	\author RIOU Matthieu, MAUSSION Damien
*/

/*! \brief Constructeur du gestionnaire 
	Initialise Aleatoire et Propriete
	Construit le Personnage, une map et un menu statique
*/ 
Gestionnaire::Gestionnaire()
{
	Aleatoire::init();
	Propriete::init(); //Initialisation
	
	ConteneurPersonnage* Kurt = new ConteneurPersonnage();
	Kurt->creerHero();
	
    map_ = new Exterieur(Aleatoire::getNext(1,5), Kurt); //Exterieur = map principale
	statique_ = new MenuStatique(Kurt); //juste observer, pas singleton ,permet d'avoir un menu par personnage*/
	
}

/*! \brief Destructeur de gestionnaire
	Detruit la map et le menu statique
*/
Gestionnaire::~Gestionnaire(){
    delete map_;
    delete statique_;
    Propriete::destruction();
}

void Gestionnaire::start(sf::RenderWindow &app)
{
	map_->start(app);
}

/*! \brief Actualise la map et le menu
	\param app La fenetre
*/
void Gestionnaire::action(sf::RenderWindow const& app)
{
	map_->update();
	statique_->update(app);
}

/*! \brief Affiche la map et le menu
	\param app La fenetre
*/
void Gestionnaire::afficher(sf::RenderWindow &app) const
{
	map_->afficher(app);
	statique_->afficher(app);
}
