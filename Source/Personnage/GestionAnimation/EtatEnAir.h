#ifndef ETATENAIR_H
#define ETATENAIR_H

/** \file EtatEnAir.h
	\brief Etat lorsque le personnage est dans les airs et ne peut resauter
	\author RIOU, MAUSSION
*/

#include "EtatAnimation.h"

/** \class EtatEnAir
	\brief Classe héritant de EtatAnimation gérant le personnage en l'air et qui ne peut sauter
*/
class EtatEnAir : public EtatAnimation
{
    public:
        EtatEnAir(ConteneurPersonnage* p);

        void update();

        virtual void animer(Dir d);
};

#endif // ETATENAIR_H
