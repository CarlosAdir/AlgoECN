#ifndef TYPE_DEF_H_INCLUDED
#define TYPE_DEF_H_INCLUDED

//#include <cstring>
#include <iostream>

#define NOMBRE_PERSONNES 10000
#define NOM_REPERTOIRE "repertoire.txt"

struct personne
{
	std::string nom;
	std::string prenom;
	std::string numss; // 
};

typedef personne vectPersonne[NOMBRE_PERSONNES];

struct elementListe
{
	personne p;
	elementListe *suivant, *precedent;
};

struct noeud
{
	personne p;
	noeud *filsDroit, *filsGauche;
};

#endif 
