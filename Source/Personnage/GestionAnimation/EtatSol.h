#ifndef ETATSOL_H
#define ETATSOL_H

/** \file EtatSol.h
	\brief Etat lorsque le personnage est au sol
	\author RIOU, MAUSSION
*/

#include "EtatAnimation.h"

/** \class EtatSol
	\brief Classe héritant de EtatAnimation gérant le personnage au sol
*/
class EtatSol : public EtatAnimation{
    public:
        EtatSol(ConteneurPersonnage* p);

        virtual void sauter();
        virtual void sauterDouble();

		virtual bool entrerBatiment();
        virtual void animer(Dir d);
};


#endif // ETATSOL_H
