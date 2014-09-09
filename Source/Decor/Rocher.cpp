#include "Rocher.h"
#include <iostream>

/** \file Rocher.cpp
	\brief Element de décor rocher
	\author RIOU, MAUSSION
*/


/** \brief Constructeur de Rocher
	\param posX La position en x du rocher
*/
Rocher::Rocher(int posX)
{ 
    sprite_.setTexture(*(Propriete::Decor::rocher()));
    sprite_.move(posX, Propriete::Fenetre::hauteurSol()-50.);
}
