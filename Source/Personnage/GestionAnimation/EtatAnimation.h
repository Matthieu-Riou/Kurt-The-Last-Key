#ifndef ETATANIMATION_H
#define ETATANIMATION_H

/** \file EtatAnimation.h
	\brief Représentation d'un état d'un personnage
	\author RIOU, MAUSSION
*/

#include "../ConteneurPersonnage.h"
#include "../Personnage.h"

/** \class EtatAnimation
	\brief Class mére des états du Personnage définissant des implémentations par défaut pour certaines méthodes
*/
class EtatAnimation{
    protected:
        ConteneurPersonnage* personnage_;			/*!< Le personnage sur lequel s'applique l'état */
    public:
        EtatAnimation(ConteneurPersonnage* p);
        virtual ~EtatAnimation(); //Mis pour éviter le warning "undefined behavior"

		virtual bool entrerBatiment();
		virtual bool sortirBatiment();
        virtual void sauter();
        virtual void sauterDouble();
        virtual void update();

		/** \brief Gère l'animation du personnage
		*/
        virtual void animer(Dir d)=0;
};


#endif // ETATANIMATION_H
