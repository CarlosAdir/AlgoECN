#include "type_def.h"
#include "utilitaires.h"
#include "utilitaire_generation.h"
#include <iostream>
#include <fstream>


/*
Lecture des fichiers Prenoms.txt et Noms.txt et stockage dans
des tableaux passés en paramètres.
*/
/*
Notre especification:
	* Il renverra un valeur boolean que montre si les archives ont pu lire les choses dedans
	* Faux si il y a n'importe que errour
	* Vrai sinon
*/
bool initTabNomPrenom(std::string* listNom, std::string* listPrenom, int *nbNom, int *nbPrenom)
{
	std::ifstream file_nom, file_prenom;
	int i;

	file_nom.open(NOMS_FILENAME);
	if (!file_nom) 
	{
		std::cout << "Unable to open file " << NOMS_FILENAME;
		return false;
	}
	file_prenom.open(PRENOMS_FILENAME);
	if (!file_prenom) 
	{
		std::cout << "Unable to open file " << PRENOMS_FILENAME;
		return false;
	}

	file_nom >> *nbNom;
	for(i = 0; i < *nbNom; i++)
		file_nom >> *(listNom+i);
	file_prenom >> *nbPrenom;
	*nbPrenom = 1000;
	for(i = 0; i < *nbPrenom; i++)
		file_prenom >> *(listPrenom+i);

	file_nom.close();
	file_prenom.close();
	return true;
}


/*
Génération aléatoire d’un répertoire de 10000 personnes.
Cette fonction utilise les tableaux contenant les noms et les prénoms, ainsi que la fonction generer-
Personne pour créer une personne aléatoirement, puis écrit cette personne dans le fichier repertoire.txt.
*/
/*
Notre especification:
	Il renverra la personne que il a tiré
*/
bool genererRepertoire()
{
	const int QTT_PERSONNES = NOMBRE_PERSONNES;
	std::string listNom[1000];
	std::string listPrenom[12000];
	int i, nbNom, nbPrenom;
	bool response;
	vectPersonne vector;
	std::ofstream out("repertoire.txt");

	response = initTabNomPrenom(listNom, listPrenom, &nbNom, &nbPrenom);
	if(response == false)
	{
		std::cout << "Ne peut pas faire la initialization des Noms et Prenoms";
		return false;
	}
	std::cout << "   nbNom = " << nbNom << std::endl;
	std::cout << "nbPrenom = " << nbPrenom << std::endl;
	out << QTT_PERSONNES << std::endl;
	for(i = 0; i < QTT_PERSONNES; i++)
	{
		vector[i] = genererPersonne(listNom, listPrenom, nbNom, nbPrenom);
		/*
		std::cout << vector[i].nom << " ";
		std::cout << vector[i].prenom << " ";
		std::cout << vector[i].numss;
		std::cout << std::endl; 
		*/
		out << vector[i].nom << " ";
		out << vector[i].prenom << " ";
		out << vector[i].numss << " ";
		out << std::endl;
	}
	out.close();

	return true;
}

/*
Détermine si deux personnes ont les mêmes informations, nom,
prénom et numéro de sécurité sociale.
Cette fonction retourne un booléen :
	* vrai en cas d’égalité,
	* faux dans l’autre cas
*/
bool egalitePersonne(personne p1, personne p2)
{
	if(p1.nom != p2.nom)
		return false;
	if(p1.prenom != p2.prenom)
		return false;
	if(p1.numss != p2.numss)
		return false;
	return true;
}


/*
Définition d’un ordre sur les personnes (qui sera utilisé pour ordonner les structures de données).
Cette comparaison se fait d’abord selon le nom de la personne,
puis son prénom et enfin son numéro de sécurité sociale.
On considère que les deux personnes ne sont pas identiques en entrée de la fonction.
Cette fonction retourne un booléen :
	* vrai si la première personne est avant l’autre
	* faux dans l’autre cas.
*/
bool comparerPersonne(personne p1, personne p2)
{
	// Ici dessous il y a la comparation pour verififer se sont les memes personnes
	// Bien que la hipothese est pour entrer dans la fonction est que ils ne sont pas le meme
	// nous irons faire ça seulemente pour la securité de le algorithme
	if(egalitePersonne(p1, p2)) // Si les personnes sont les memes
	{
		//std::cout << "As duas pessoas sao iguais! Nao pode!" << std::endl;
		//exit(1);
	}
	if(p1.nom < p2.nom)
		return true;
	else if(p1.nom > p2.nom)
		return false;
	if(p1.prenom < p2.prenom)
		return true;
	else if(p1.prenom > p2.prenom)
		return false;
	if(p1.numss < p2.numss)
		return true;
	else if(p1.numss > p2.numss)
		return false;

	// Si le algorithme Ici nous avons que si 
	// std::cout << "Il y a une malvaise chose, parce que ce n'est pas possible etre ici, ";
	// std::cout << "dans la fonction comparerPersonne" << std::endl;
	//exit(1);
	return false;
}
