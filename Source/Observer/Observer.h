#ifndef OBSERVER_H
#define OBSERVER_H

/** \file Observer.h
	\brief Observateur du pattern Observer
	\author RIOU, MAUSSION
*/
	
/** \class Observer<S>
	\brief Classe utilisant des templates représentant les observeurs d'objets de type S
*/	
template<typename S> //S pour sujet
class Observer
{
	protected:
		S* sujet_;					/*!< Le sujet observé */
	public:
		Observer(S* sujet);
		
		/** \brief Fonction virtuelle pure pour actualiser l'Observer
		*/
		virtual void actualiser() = 0;

};

/** \brief Constructeur d'Observer<S> qui spécifie le type S
	\param sujet Le sujet à observer
*/
template<typename S>
Observer<S>::Observer(S* sujet) : sujet_(sujet)
{
}

#endif //OBSERVER_H
