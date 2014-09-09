#ifndef ETATENAIRINTERMEDIAIRE_H
#define ETATENAIRINTERMEDIAIRE_H

/** \file EtatEnAirIntermediaire.h
	\brief Etat lorsque le personnage est en l'air et peut sauter
	\author RIOU, MAUSSION
*/

#include <SFML/Graphics.hpp>

#include "EtatAnimation.h"

/** \class EtatEnAirIntermediaire
	\brief Classe héritant de EtatAnimation gérant le personnage en l'air et qui peut sauter
*/
class EtatEnAirIntermediaire : public EtatAnimation
{
    private:
        bool jump_;			/*!< booleen pour géré les multiples evenements pour un seul appui sur le barre espase */

    public:
        EtatEnAirIntermediaire(ConteneurPersonnage* p);

        virtual void update();
        virtual void sauterDouble();

        virtual void animer(Dir d);
};

#endif // ETATENAIRINTERMEDIAIRE_H
