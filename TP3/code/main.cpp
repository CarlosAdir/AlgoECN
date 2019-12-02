#include "constantes.h"
#include "affichage.h"
#include "proba.h"
#include "monde.cpp"
#include "fourmi.h"

void add_phero(t_fourmi f, t_matrice phero, const int L, const int H)
{
	int i, j;
	phero[f.x][f.y] += 5;
	for(i = -1; i < 2; i++)
		for(j = -1; j < 2; j++)
		{
			if(f.x+i >= 0 && f.x+i < L && f.y+j >= 0 && f.y+j < H)
			{
				phero[f.x+i][f.y+j] += 5;
				if(phero[f.x+i][f.y+j] > 100)
					phero[f.x+i][f.y+j] = 100;	
			}
		}

}
void evapora_phero(t_matrice phero, const int L, const int H)
{
	int i, j;
	for(i = 0; i < L; i++)
		for(j = 0; j < H; j++)
		{
			phero[i][j] -= 1;
			if(phero[i][j] < 0)
				phero[i][j] = 0;
		}
}

int main()
{
	int ok, i, j;
	int qtd_fourmi = 3; //Quantite de fourmi 
	t_fourmi vetor_formigas[qtd_fourmi];
	t_matrice phero;
	t_monde world;

	world = LireEnvironnement ("monde1.dat");
	for(i = 0; i < qtd_fourmi; i++)
	{
		vetor_formigas[i].x = nalea(world.L);
		vetor_formigas[i].y = nalea(world.H);
		vetor_formigas[i].mode = 1;
		vetor_formigas[i].dir = nalea(9)-4;	
	}
	for(i = 0; i < world.L; i++)
		for(j = 0; j < world.H; j++)
			phero[i][j] = 0;

	ok = InitAffichage(world.L, world.H);
	while (ok==1)
	{
		evapora_phero(phero, world.L, world.H);
		for (i= 0; i<qtd_fourmi; i++)
		{
			vetor_formigas[i] = DeplaceFourmi_Better (vetor_formigas[i], world, phero);
			if(vetor_formigas[i].mode == 0)
				add_phero(vetor_formigas[i], phero, world.L, world.H);
			MiseAJourPheromones(phero);
			MiseAJourFourmi(vetor_formigas[i].x, vetor_formigas[i].y, vetor_formigas[i].mode);
		}

		MiseAJourEnvironnement(world);
		Affichage();
	}



	return 0;
}