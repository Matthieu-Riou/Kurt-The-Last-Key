#include "Math.h"

/*! \file Math.cpp
	\brief Ensemble de méthodes mathématiques
	\author RIOU Matthieu, MAUSSION Damien
*/ 


/*! \brief Trouve le max entre a et b
	\param a La premiere valeur
	\param b La seconde valeur
	\return Le maximum
*/
int Math::max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

/*! \brief Trouve le min entre a et b
	\param a La premiere valeur
	\param b La seconde valeur
	\return Le minimum
*/
int Math::min(int a, int b)
{
	if(a < b)
		return a;
	else
		return b;
}
