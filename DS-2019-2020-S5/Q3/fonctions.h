#ifndef FONCTIONS_H
#define FONCTIONS_H


#include <iostream>
#include <fstream>
#include "types.h"

using namespace std;

t_liste *ajouter_mot_liste(t_liste *l, t_mot mot);
void ajouter_mot_dictionnaire(t_liste *dictionnaire[], t_mot mot);
//t_mot lire_mot(std::ifstream fin);
bool lire_texte(t_liste *dictionnaire[], const char *filename);
void afficher_frequences(t_liste *dictionnaire[]);


#endif