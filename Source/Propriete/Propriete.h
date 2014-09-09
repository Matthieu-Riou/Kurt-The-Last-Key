#ifndef PROPRIETE_H
#define PROPRIETE_H

/** \file Propriete/Propriete.h
	\brief Ensemble de valeurs qui servent pour tout le jeu
	\author RIOU, MAUSSION
*/
#include <SFML/Graphics.hpp>
#include "../Espace.h"
#include <iostream>

/** \namespace Propriete
	\brief Namespace contenant plusieurs singlotons qui contiennent les valeurs nécessaires au fonctionnement du jeu
*/
namespace Propriete
{
	/** \class Fenetre 
		\brief Classe regroupant les proprièté de la fenetre
	*/
	class Fenetre
	{
		private:
			int fenX_;			/*!< Longueur de la fenetre */	
			int fenY_;			/*!< Hauteur de la fenetre */	
	
			int hauteurSol_;	/*!< Hauteur du sol */	
	
			Fenetre();
			
			static Fenetre* instance_; 	 		/*!< instance de Fenetre (singloton) */
			static Fenetre* fenetre();
			static void deleteFenetre();		
	
		public:
			static int fenX();
			static int fenY();
			static int hauteurSol();
			
		friend void init();					/*!< Methode ami pour l'initialiser */
		friend void destruction();			/*!< Methode ami pour supprimer l'instance */
	};

	/** \class BatimentExterieur 
		\brief Classe regroupant les proprièté de l'extérieur des batiments
	*/
	class BatimentExterieur
	{
		private:
			sf::Color colorMur_;					/*!< Couleur du mur extérieur */
			sf::Color colorFenetre_;				/*!< Couleur des fenetres */
			sf::Color colorPorteOuverte_;			/*!< Couleur de la porte ouverte */
			sf::Color colorPorteFerme_;				/*!< Couleur de la porte fermée */
			
			int nbEtageMin_;						/*!< Nombre d'étages minimum */
			int nbEtageMax_;						/*!< Nombre d'étages maximum */
			int nbFenLargeurMin_;					/*!< Nombre minimum de fenetres */
			int nbFenLargeurMax_;					/*!< Nombre maximum de fenetres */
			sf::Vector2f tailleFenetre_;			/*!< Taille d'une fenetre */
			sf::Vector2f espaceFenetre_;			/*!< Espace entre 2 fenetres */
			sf::Vector2f taillePorte_;				/*!< Taille de la porte */
			
			BatimentExterieur();
			
			static BatimentExterieur* instance_;	/*!< instance du BatimentExterieur (singloton) */
			static BatimentExterieur* batimentExterieur();
			static void deleteBatimentExterieur();
			
		public:
			static sf::Color colorMur();
			static sf::Color colorFenetre();
			static sf::Color colorPorteOuverte();
			static sf::Color colorPorteFerme();
			
			static int nbEtageMin();
			static int nbEtageMax();
			static int nbFenLargeurMin();
			static int nbFenLargeurMax();
			static sf::Vector2f tailleFenetre();
			static sf::Vector2f espaceFenetre();
			static sf::Vector2f taillePorte();
			
		friend void init();				/*!< Methode ami pour l'initialiser */
		friend void destruction();		/*!< Methode ami pour supprimer l'instance */
	};
	
	/** \class Etage
		\brief Classe regroupant les proprietés d'un étage
	*/
	class Etage
	{
		private:
			sf::Color colorSol_;				/*!< Couleur du sol */
			sf::Color colorMur_;				/*!< Couleur des murs */
			sf::Color colorFrontDoor_;			/*!< Couleur de la porte d'entrée */
			
			int tailleMur_;						/*!< Taille d'un mur */
			sf::Vector2f tailleEtage_;			/*!< Taille d'un étage */
			
			Etage();
			
			static Etage* instance_;			/*!< instance d'Etage (singloton) */
			static Etage* etage();
			static void deleteEtage();
			
		public:
			static sf::Color colorSol();
			static sf::Color colorMur();
			static sf::Color colorFrontDoor();
			
			static int tailleMur();
			static sf::Vector2f tailleEtage();
			
		friend void init();				/*!< Methode ami pour l'initialiser */
		friend void destruction();		/*!< Methode ami pour supprimer l'instance */
	};
	
	/** \class Hero 
		\brief Class regroupant les proprietés du héro
	*/
	class Hero
	{
		private:
			sf::Vector2f taille_;					/*!< Taille de l'image représentant le héro */
			std::vector<sf::Texture*> textures_;	/*!< Ensemble des textures du héro */
			int valeurSaut_;						/*!< Valeur d'un saut */
			float vitesse_;							/*!< Vitesse par défaut d'un héro */
			
			Hero();
			~Hero();
			
			static Hero* instance_;					/*!< instance de Hero (singloton) */
			static Hero* hero();
			static void deleteHero();
			
		public:
			
			static sf::Vector2f taille();
			static std::vector<sf::Texture*> textures();
			static int valeurSaut();
			static float vitesse();
			
		friend void init();				/*!< Methode ami pour l'initialiser */
		friend void destruction();		/*!< Methode ami pour supprimer l'instance */
	};
	
	/** \class InventaireStatique
		\brief Classe regrouant les proprietés de l'inventaire affiché sous la Map
	*/
	class InventaireStatique
	{
		private:
			sf::Color colorFond_;							/*!< Couleur de fond */
			
			sf::Vector2f espaceBordure_;					/*!< Espace de bordure */
			
			sf::Vector2i nbObjet_; 							/*!< Nombre d'objets : x Objets par ligne, y Objets par colonne */
			
			sf::Vector2f tailleFond_;						/*!< Taille du rectangle en fond */
			sf::Vector2f posFond_;							/*!< Position du fond */
			
			InventaireStatique();
			
			static InventaireStatique* instance_;			/*!< instance d'InventaireStatique (singloton) */
			static InventaireStatique* inventaireStatique();
			static void deleteInventaireStatique();
		
		public:
			static sf::Color colorFond();
			static sf::Vector2f tailleFond();
			static sf::Vector2f posFond();
			
			static sf::Vector2f espaceBordure();
			
			static sf::Vector2i nbObjet();
			
			
		friend void init();				/*!< Methode ami pour l'initialiser */
		friend void destruction();		/*!< Methode ami pour supprimer l'instance */
	};
	
	/** \class Objet
		\brief Classe regroupant les proprietés des objets
	*/
	class Objet
	{
		private:
			sf::Vector2f taille_;			/*!< Taille des objets */
			sf::Texture etoileJaune_;		/*!< Texture de l'étoile jaune*/
			sf::Texture etoileBleue_;		/*!< Texture de l'étoile bleue*/
			sf::Texture cle_;				/*!< Texture de la cle */
			
			Objet();
			
			static Objet* instance_;	/*!< instance de Objet (singloton) */
			static Objet* objet();
			static void deleteObjet();
			
		public:
			static sf::Vector2f taille();
			static sf::Texture* etoileJaune();
			static sf::Texture* etoileBleue();
			static sf::Texture* cle();
			
			
		friend void init();				/*!< Methode ami pour l'initialiser */
		friend void destruction();		/*!< Methode ami pour supprimer l'instance */
	};
	
	/** \class Decor 
		\brief Classe regroupant les proprietés des éléments de décors
	*/
	class Decor
	{
		private:
			sf::Texture arbre_;				/*!< Texture de l'arbre */
			sf::Texture nuage_;				/*!< Texture du nuage */
			sf::Texture rocher_;			/*!< Texture du rocher */
			
			Decor();
			
			static Decor* instance_;		/*!< instance de Fenetre (singloton) */
			static Decor* decor();
			static void deleteDecor();
			
		public:
			static sf::Texture* arbre();
			static sf::Texture* nuage();
			static sf::Texture* rocher();
			
			
		friend void init();				/*!< Methode ami pour l'initialiser */
		friend void destruction();		/*!< Methode ami pour supprimer l'instance */
	};
	
	void init();
	void destruction();
}

#endif //PROPRIETE_H
