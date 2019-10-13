/*************************************************************

                  Fichier entete de proba.cpp

    ------------------------------------------------------

 Auteurs : équipe pédagogique ALGPR
 Date: 01/10/2005
 Fichier: proba.h
 But: prototypes des fonctions permettant d'effectuer un tirage
      au sort (compris entre 0 et un nombre maximum donné en parametre)
      et un tirage au sort pondéré, entre 0 et 7 (le tirage n'est pas
      équiprobable, un vecteur de ponderation est fourni en parametre)

*************************************************************/

#ifndef PROBA_H
#define PROBA_H


// définition d'un type "t_poids" qui est un vecteur de 8 entiers
typedef int t_poids[8];


//fonction: nalea
//parametre: max : valeur maximum pour le tirage aléatoire
//but: renvoie un entier aléatoire compris entre 0 et max-1 (inclus)
int nalea(int max);


//fonction: nalea_pondere
//parametre: poids : vecteur de ponderation
//but: renvoie un nombre tiré au sort (entre 0 et 7). Le tirage n'est pas équiprobable car il est pondéré par le vecteur poids
int nalea_pondere( t_poids poids);

#endif