#ifndef TYPES_H
#define TYPES_H

#include <iostream>

using namespace std;

typedef string t_mot;

struct t_liste
{
	t_mot mot;
	int f;
	t_liste *suiv;
};

const int TAILLE = 26;
typedef t_liste* t_dictionnaire[TAILLE];



#endif