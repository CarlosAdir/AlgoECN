

#include <iostream>
#include <vector>
#include "tris.h"

using namespace std; 






void trocar_objet(objet *obj1, objet *obj2)
{

	objet tmp; 
	matiere m;
	//int i; 

	tmp.nom = obj1->nom;
	tmp.nombre = obj1->nombre;
	tmp.nombre_matiers = obj1->nombre_matiers;
	tmp.date = obj1->date;
	tmp.duree = obj1->duree;
	tmp.matieres.swap(obj1->matieres);/*
	for (i=0; i<obj1->nombre_matiers; i++)
	{
		m.nom = obj1->matieres[i].nom;
		m.poids = obj1->matieres[i].poids;
		tmp.matieres.push_back(m);
	}
	obj1->matieres.erase(obj1->matieres.begin(), obj1->matieres.end()); */

	obj1->nom = obj2->nom;
	obj1->nombre = obj2->nombre;
	obj1->nombre_matiers = obj2->nombre_matiers;
	obj1->date = obj2->date;
	obj1->duree = obj2->duree;
	obj1->matieres.swap(obj2->matieres);
	/*for (i=0; i<obj2->nombre_matiers; i++) 
	{
		m.nom = obj2->matieres[i].nom;
		m.poids = obj2->matieres[i].poids;
		obj1->matieres.push_back(m);
	}
	obj2->matieres.erase(obj2->matieres.begin(), obj2->matieres.end());*/ 

	obj2->nom = tmp.nom;
	obj2->nombre = tmp.nombre;
	obj2->nombre_matiers = tmp.nombre_matiers;
	obj2->date = tmp.date;
	obj2->duree = tmp.duree;
	obj2->matieres.swap(tmp.matieres);/*
	for (i=0; i<tmp.nombre_matiers; i++)
	{
		m.nom = tmp.matieres[i].nom;
		m.poids = tmp.matieres[i].poids;
		obj2->matieres.push_back(m); 
	}*/
}





void tri_vecteur (ensObjets *eo)
{
	unsigned int i; 
	bool aucunEchange; 

	aucunEchange = false; 
	while (!aucunEchange)
	{
		aucunEchange = true; 
		for (i=0; i< eo->size() -1; i++) 
		{
			if ( eo->at(i).date > eo->at(i+1).date)
			{
				trocar_objet ( & eo->at(i), & eo->at(i+1) ); 
				aucunEchange = false;
			}
		}
	}
}


void ajouter_objet (ensObjets *eo, objet o)
{
	unsigned int i;
	if ( eo -> size()== 0)
		eo->push_back (o);
	else 
	{
		for (i= 0; i< eo -> size(); i++) 
			if (eo->at(i).date > o.date)
			{
				eo -> insert (eo-> begin() + i,o); 
				break;
			}
		if(i == eo->size())
			eo->push_back(o); 
	}
}

void ajouter_objet2 (ensObjets *eo, objet o)
{
	int gauche, droit, i;
	
	if ( eo -> size() == 0)
	{
		eo->push_back (o);
	}
	else if(eo -> size() == 1)
	{
		if (o.date > eo->at(0).date)
			eo -> insert (eo->begin() + 1, o);
		else if(o.date < eo->at(0).date)
			eo -> insert (eo->begin() + 0, o);
	}

	else 
	{
		gauche = 0;
		droit = eo->size();
		while (droit - gauche != 1) 
		{
			i = (gauche + droit)/2;
			if (o.date > eo->at(i).date)
				gauche = i;
			else if(o.date < eo->at(i).date)
				droit = i;
			else
				break;
		}
		eo -> insert (eo->begin() + i, o); 
	}
}
