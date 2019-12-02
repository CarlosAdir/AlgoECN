/*************************************************************

              Définition de constantes Fourmiz

    ------------------------------------------------------

 Auteurs : équipe pédagogique ALGPR
 Modifié : 10/04/2013, 04/11/2013 (Vincent Tourre)
 Fichier: constantes.h
 But: définition de constantes relatives à Fourmiz

*************************************************************/


#ifndef CONSTANTES_H
#define CONSTANTES_H

// définition de constantes de taille
const int TAILLE_MONDE_MAX=100;
const int PHEROMONES_MAX=100;

// définition de constante pour l'environnement
const int OBSTACLE=-1;
const int VIDE=0;
const int NOURRITURE_MAX=50;



// définition d'un type de matrice de dimension TAILLE_MONDE_MAX * TAILLE_MONDE_MAX d'entier
typedef int t_matrice[TAILLE_MONDE_MAX][TAILLE_MONDE_MAX];


// définition d'un type "t_monde" qui est une structure caractérisant le monde
// et permettant de stocker l'environnement. Elle est composée de :
// 	- une matrice de type t_matrice
// 	- une largeur
// 	- une hauteur
// permet de stocker l'environnement
struct t_monde
{
	t_matrice mat;		// matrice
	int L;			// largeur
	int H;			// hauteur
	int Fx,Fy;		// position de la fourmiliËre
};

#endif