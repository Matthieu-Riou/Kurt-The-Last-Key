#ifndef ETATBATIMENT_H
#define ETATBATIMENT_H

/** \file EtatBatiment.h
	\brief Etat lorsque le personnage est dans un batiment
	\author RIOU, MAUSSION
*/

#include "EtatAnimation.h"

/** \class EtatBatiment
	\brief Classe héritant de EtatAnimation gérant le personnage dans un batiment
*/
class EtatBatiment : public EtatAnimation
{
    public:
        EtatBatiment(ConteneurPersonnage* p);

		virtual bool sortirBatiment();
        virtual void animer(Dir d);

};


#endif // ETATBATIMENT_H
