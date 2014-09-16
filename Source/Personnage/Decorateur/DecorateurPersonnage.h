#ifndef DECARATEURPERSONNAGE_H
#define DECARATEURPERSONNAGE_H

/** \file DecorateurPersonnage.h
	\brief Implémentation du pattern Decorator
	\author RIOU, MAUSSION
*/

#include <memory>
#include "../Personnage.h"

/** \class DecorateurPersonnage
	\brief Classe héritant de Personnage (pour le type), contenant un Personnage (pattern Decorator)
	et pour chaque méthode applique la même sur le personnage contenu
*/
class DecorateurPersonnage : public Personnage
{
	protected :
		std::shared_ptr<Personnage> perso_;				/*!< Le personnager décoré */
		
	public :
		DecorateurPersonnage(std::shared_ptr<Personnage> p);

        virtual bool essayerOuvrirBatiment(BatimentExterieur *bat);
        virtual void ramasser(Objet *objet);

		virtual Inventaire* getInventaire();

		virtual float getVitesse() const;

        virtual sf::Vector2f getTaille() const;
        virtual sf::Vector2f getPosition() const;
        virtual sf::Vector2f getCentre() const;
        
        virtual Dir getDirection() const;
        virtual void setDir(Dir d);
        
        virtual int getValeurSaut();
        virtual void setValeurSaut(int val);
        virtual void sauterDouble();

        virtual void incrementeCptPied();

        virtual void setPosition(sf::Vector2f pos, Dir dir);

		virtual void setEtatAnimation(EtatAnimation* e);
        virtual EtatAnimation* getEtatSol();
        virtual EtatAnimation* getEtatAir();
        virtual EtatAnimation* getEtatBatiment();
        virtual EtatAnimation* getEtatAirIntermediaire();

		virtual void sauter();
		virtual bool entrerBatiment();
		virtual bool sortirBatiment();

        virtual void update();
        
        virtual void updateSprite();
        virtual void moveSprite(float x, float y);

        virtual void deplacer(Dir dir, float value);
        virtual void animer(Dir dir);
		virtual void afficher(sf::RenderWindow &app) const;
};

#endif

