#ifndef SUJET_H
#define SUJET_H

#include <list>

/** \file Sujet.h
	\brief Sujet du pattern Observer
	\author RIOU, MAUSSION
*/
	
/** \class Sujet<O>
	\brief Classe utilisant des templates représentant les sujets d'objets de type O
*/	
template<typename O> //O pour observer
class Sujet
{
	protected:
		std::list<O*> observer_;			/*!< La liste des observer */
		
	public:
		virtual void enregistrerObs(O* observer);
		virtual void supprimerObs(O* observer);
		virtual void notifierObs();

};

/** \brief Ajoute un observer
	\param observer L'observer a ajouter
*/
template<typename O>
void Sujet<O>::enregistrerObs(O* observer)
{
	observer_.push_back(observer);
}

/** \brief Supprime un observer
	\param observer L'observer a supprimer
*/
template<typename O>
void Sujet<O>::supprimerObs(O* observer)
{
	observer_.remove(observer);
}

/** \brief Actualise tous les observers
*/
template<typename O>
void Sujet<O>::notifierObs()
{
	for(typename std::list<O*>::iterator it = observer_.begin(); it != observer_.end(); ++it)
	{
		(*it)->actualiser();
	}
}

#endif //SUJET_H
