#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#include <iostream> // Pour les strings
#include <vector>

using namespace std; 


struct matiere
{
	string nom; 
	float poids; 
};

//typedef matiere ensMatieres []; 
typedef vector<matiere> ensMatieres;


struct objet
{
	string nom; 
	int nombre;
	int nombre_matiers;  
	ensMatieres matieres; 
	int date; 
	int duree; 
};

//typedef object ensObjets []; 
typedef vector<objet> ensObjets;

struct livraison
{
	int id; 
	string nom; 
	int poids; 
	int date; 
};

//typedef livraison ensLivraison []; 
typedef vector<livraison> ensLivraison;

#endif 