#include "repertoire.h"
#include "type_def.h"
#include "utilitaires.h"
#include <fstream>
#include <iostream>

void afficherPersonne(const personne &p)
{
	std::cout << "******************" << std::endl;
	std::cout << "*    Nom: " << p.nom << std::endl;
	std::cout << "* Prenom: " << p.prenom << std::endl;
	std::cout << "*  NumSS: " << p.numss << std::endl; 
}





void afficherVector(vectPersonne mon_vector)
{

}
void ajouterVector()
{

}
void rechercherVector()
{

}
void supprimerVector()
{

}
void lectureRepertoireVector(vectPersonne mon_vector, const std::string FILE_NAME)
{

}







elementListe *creeUnElementListe(elementListe *precedent, const personne &p, elementListe *suivant)
{
	elementListe *new_element = new elementListe();
	new_element->precedent = precedent;
	new_element->p = p;
	new_element->suivant = suivant;
	return new_element;
}

void afficherListe(elementListe *ma_liste)
{
	if(ma_liste == NULL)
		return;
	std::cout << "Personne -" << std::endl;
	afficherPersonne(ma_liste->p);
	afficherListe(ma_liste->suivant);
}
elementListe *ajouterListe(elementListe *ma_liste, const personne &p) 
{
	elementListe *new_element = NULL;
	// Armazenaremos na lista de forma crescente
	if(ma_liste == NULL)
	{
		new_element = creeUnElementListe(NULL, p, NULL);
		return new_element;
	}
	if(comparerPersonne(p, ma_liste->p)) // personne p est avant que la personne dans le element ma_liste
	{
		new_element = creeUnElementListe(ma_liste->precedent, p, ma_liste);
		ma_liste->precedent = new_element;
		return new_element;
	}
	ma_liste->suivant = ajouterListe(ma_liste->suivant, p);
	(ma_liste->suivant)->precedent = ma_liste;
	return ma_liste;
}
bool rechercherListe(elementListe *ma_liste, const personne &p)
{
	elementListe *mon_pointer = ma_liste;
	while(mon_pointer != NULL)
	{
		if(egalitePersonne(p, mon_pointer->p))
			return true;
		mon_pointer = mon_pointer->suivant;
	}
	return false;
}
void libereListe(elementListe *ma_liste)
{
	if(ma_liste == NULL)
		return;
	libereListe(ma_liste->suivant);
	delete ma_liste;
}
elementListe *supprimerListe(elementListe *ma_liste, const personne &p)
{
	elementListe *mon_pointer = ma_liste;
	if(egalitePersonne(p, ma_liste->p))
	{
		mon_pointer = ma_liste.suivant;
		mon_pointer->precedent = NULL;
		delete ma_liste;
		return mon_pointer;
	}
	while(mon_pointer != NULL)
	{
		if(egalitePersonne(p, mon_pointer->p))
		{
			(mon_pointer->suivant)->precedent = mon_pointer->precedent;
			(mon_pointer->precedent)->suivant = mon_pointer->suivant;
			delete mon_pointer;
			return ma_liste;
		}
		mon_pointer = mon_pointer->suivant;
	}
	std::cout << "Il n'y a pas la personne dans la liste" << std::endl;
	return ma_liste;
}
elementListe *lectureRepertoireListe(const std::string FILE_NAME)
{
	std::ifstream input_file;
	int i, qtt_personnes;
	elementListe *ma_liste = NULL;
	personne p;

	input_file.open(FILE_NAME);
	if (input_file.fail())
    {
    	std::cout << "Le archive " << FILE_NAME << " n'a pas pus etre trouve";
    	return NULL;
    }
    input_file >> qtt_personnes;
	for(i = 0; i < qtt_personnes; i++)
    {
    	input_file >> p.nom >> p.prenom >> p.numss;
    	ma_liste = ajouterListe(ma_liste, p);
    }
    afficherListe(ma_liste);
	input_file.close();
	return ma_liste;
}














noeud *creeUnNoeud(const personne &p)
{
	noeud *new_element = new noeud();
	new_element->filsDroit = NULL;
	new_element->p = p;
	new_element->filsGauche = NULL;
	return new_element;
}

void afficherArbre(noeud *unArbre)
{
	if(unArbre == NULL)
		std::cout << "Arbre nulle!" << std::endl;
	//afficherArbrePrefixe(unArbre);
	afficherArbreInfixe(unArbre);
	//afficherArbrePosfixe(unArbre);
}
void afficherArbrePrefixe(noeud *unArbre)
{
	if(unArbre == NULL)
		return;
	afficherPersonne(unArbre->p);
	afficherArbrePrefixe(unArbre->filsGauche);
	afficherArbrePrefixe(unArbre->filsDroit);
}

// -------------------------------------------------------
void afficherArbreInfixe(noeud *unArbre)
{
	if(unArbre == NULL)
		return;
	afficherArbreInfixe(unArbre->filsGauche);
	afficherPersonne(unArbre->p);
	afficherArbreInfixe(unArbre->filsDroit);
}

// -------------------------------------------------------
void afficherArbrePosfixe(noeud *unArbre)
{
	if(unArbre == NULL)
		return;
	afficherArbrePosfixe(unArbre->filsGauche);
	afficherArbrePosfixe(unArbre->filsDroit);
	afficherPersonne(unArbre->p);
}

noeud *ajouterArbre(noeud *ma_arbre, const personne &p)
{
	noeud *new_element = NULL;
	// Armazenaremos na lista de forma crescente
	if(ma_arbre == NULL)
	{
		new_element = creeUnNoeud(p);
		return new_element;
	}
	if(comparerPersonne(p, ma_arbre->p)) // personne p est avant que la personne dans le element ma_arbre
		ma_arbre->filsGauche = ajouterArbre(ma_arbre->filsGauche, p);
	else if(comparerPersonne(ma_arbre->p, p))
		ma_arbre->filsDroit = ajouterArbre(ma_arbre->filsDroit, p);
	else
	{
		std::cout << "Pessoa repetida!" << std::endl;
		exit(1);
	}
	return ma_arbre;
}
bool rechercherArbre(noeud *ma_arbre, const personne &p)
{
	if(ma_arbre == NULL)
		return false;
	if(comparerPersonne(p, ma_arbre->p)) // personne p est avant que la personne dans le element ma_arbre
		return rechercherArbre(ma_arbre->filsGauche, p);
	else if(comparerPersonne(ma_arbre->p, p))
		return rechercherArbre(ma_arbre->filsDroit, p);
	else
		return true;
}
void libereArbre(noeud *unArbre)
{
	if (unArbre == NULL)
		return;
	libereArbre(unArbre->filsGauche);
	libereArbre(unArbre->filsDroit);
	delete unArbre;
}
noeud *supprimerArbre(noeud *ma_arbre, const personne &p)
{
	// Ici nous irons trouver ou est le noued
	noeud *aux, *aux2;
	if(ma_arbre == NULL) // Il n y a pas un element qui est le meme que la personne p
		return NULL;
	if(comparerPersonne(p, ma_arbre->p)) // personne p est avant que la personne dans le element ma_arbre
	{
		ma_arbre->filsGauche = supprimerArbre(ma_arbre->filsGauche, p);
		return ma_arbre;
	}
	else if(comparerPersonne(ma_arbre->p, p)) // La personne ma_arbre->p est avant que la personne p
	{
		ma_arbre->filsDroit = supprimerArbre(ma_arbre->filsDroit, p);
		return ma_arbre;
	}
	else // Si est le noeud que nous devons supprimer, parce que c'est le meme que la personne p
	{
		std::cout << "Nous irons retirer le" << std::endl;
		afficherPersonne(p);
		if(ma_arbre->filsGauche == NULL) // Si il y a n'import qui est zero 
		{

			aux = ma_arbre->filsDroit;
			std::cout << "cas 1" << std::endl;
			delete ma_arbre;
			return aux;	
		}
		if(ma_arbre->filsDroit == NULL)
		{
			aux = ma_arbre->filsGauche;
			std::cout << "cas 2" << std::endl;
			delete ma_arbre;
			return aux;		
		}
		// Ici, aucun fils est nulle
		aux = ma_arbre->filsGauche; // Nous aurons pu utiliser a droit, mais c'est une convention
		if(aux->filsDroit == NULL)
		{
			aux->filsDroit = ma_arbre->filsDroit;
			std::cout << "cas 3" << std::endl;
			delete ma_arbre;
			return aux;
		}
		while( (aux->filsDroit)->filsDroit != NULL) // Si on choisit a droit, ici c'est a gauche
			aux = aux->filsDroit; // Et ici aussi
		aux2 = aux->filsDroit;
		aux2->filsDroit = ma_arbre->filsDroit;
		aux->filsDroit = aux2->filsGauche;
		aux2->filsGauche = ma_arbre->filsGauche;
		std::cout << "cas 4" << std::endl;
		delete ma_arbre;
		return aux2;
		
	}
	

}
noeud *lectureRepertoireArbre(const std::string FILE_NAME)
{
	std::ifstream input_file;
	int i, qtt_personnes;
	noeud *ma_arbre = NULL;
	personne p;

	input_file.open(FILE_NAME);
	if (input_file.fail())
    {
    	std::cout << "Le archive " << FILE_NAME << " n'a pas pus etre trouve";
    	return NULL;
    }
    input_file >> qtt_personnes;
	for(i = 0; i < qtt_personnes; i++)
    {
    	input_file >> p.nom >> p.prenom >> p.numss;
    	ma_arbre = ajouterArbre(ma_arbre, p);
    }
	input_file.close();
	return ma_arbre;
}