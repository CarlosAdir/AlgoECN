/*************************************************************

               Fichier entete de affichage.cpp

    ------------------------------------------------------
 Auteurs : équipe pédagogique ALGPR
 Date : 01/10/2005
 Modifié : 10/04/2013, 04/11/2013 (Vincent Tourre)
 Fichier: affichage.h
 But: prototypes des fonctions permettant de gérer l'affichage
      de fourmis, du monde dans lequel elles évoluent (nourriture
      et obstacles) et des pheromones

*************************************************************/

#ifndef AFFICHAGE_H
#define AFFICHAGE_H


//fonction: InitAffichage
//parametres: L : largeur du monde à afficher
//           H : hauteur du monde à afficher
//but: préparer l'affichage du monde
//     cette fonction renvoit 0 si l'initialisation n'a pas marché (et 1 sinon)
//     cette fonction doit être utilisée obligatoirement UNE SEULE FOIS, et avant toutes les autres
int InitAffichage( int L, int H);


//fonction: MiseAJourFourmi
//parametres: x : position en x de la fourmi à afficher
//           y : position en y de la fourmi à afficher
//           mode : indique dans quel mode se trouve la fourmi
//                  0 : la fourmi est en mode "j'ai trouvé de la nourriture, je retourne à la fourmillière"
//                  1 : la fourmi est en mode "je suis en recherche de nourriture"
//but: mettre à jour la fourmi dans le monde
void MiseAJourFourmi( int x, int y, int mode);


//fonction: MiseAJourEnvironnement
//parametre: environnement : t_monde contenant l'environnement (obstacles et nourriture)
//but: afficher l'environnement en cours (obstacles en bleu et nourriture en vert : un point vert au milieu, et un rectangle dont l'intensité
//     du vert indique la quantité de nourriture présente)
void MiseAJourEnvironnement( t_monde environnement);


//fonction: MiseAJourPheromones
//parametre: pheromones : matrice représentant le niveau de phéromones
//but: mettre à jour la quantité de phéromones du monde
void MiseAJourPheromones( t_matrice pheromones);


//fonction: Affichage
//but: permet de faire une pause en fin d'affichage
//     nécessaire pour gérer les évènements graphiques (déplacement de fenêtre, touche pressée au clavier, etc...)
//     renvoit 0 si l'utilisateur a pressé la touche ESC (et 1 sinon)
int Affichage();

#endif
