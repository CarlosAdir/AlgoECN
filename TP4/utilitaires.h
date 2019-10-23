#ifndef UTILITAIRES_H_INCLUDED
#define UTILITAIRES_H_INCLUDED

#define NOMS_FILENAME "Noms_TP4.txt"
#define PRENOMS_FILENAME "Prenoms_TP4.txt"

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
bool initTabNomPrenom(std::string* listNom, std::string* listPrenom, int *nbNom, int *nbPrenom);



/*
Génération aléatoire d’un répertoire de 10000 personnes.
Cette fonction utilise les tableaux contenant les noms et les prénoms, ainsi que la fonction generer-
Personne pour créer une personne aléatoirement, puis écrit cette personne dans le fichier repertoire.txt.
*/
/*
Notre especification:
	Il renverra la personne que il a tiré
*/
bool genererRepertoire();



/*
Détermine si deux personnes ont les mêmes informations, nom,
prénom et numéro de sécurité sociale.
Cette fonction retourne un booléen :
	* vrai en cas d’égalité,
	* faux dans l’autre cas
*/
bool egalitePersonne(personne p1, personne p2);



/*
Définition d’un ordre sur les personnes (qui sera utilisé pour ordonner les structures de données).
Cette comparaison se fait d’abord selon le nom de la personne,
puis son prénom et enfin son numéro de sécurité sociale.
On considère que les deux personnes ne sont pas identiques en entrée de la fonction.
Cette fonction retourne un booléen :
	* vrai si la première personne est avant l’autre
	* faux dans l’autre cas.
*/
bool comparerPersonne(personne p1, personne p2);


#endif 
