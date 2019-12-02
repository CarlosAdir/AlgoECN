#ifndef FOURMI_H
#define FOURMI_H
#include "constantes.h"
struct t_fourmi
{
	int x;		// position x 
	int y;			// position y 
	int mode;			// mode trouvé de la nourriture(0) ou recherche(1) de nourriture
	int dir;            // huit directions definiees en pdf, entre -4 et +4
};

t_fourmi DeplaceFourmi (t_fourmi f , t_monde monde );
bool PositionPossible (int x, int y, t_monde monde);
t_fourmi DeplaceFourmi_Better (t_fourmi f, t_monde envir, t_matrice phero);

#endif