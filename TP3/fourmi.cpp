#include "fourmi.h"
#include "proba.h"
#include "constantes.h"
#include <math.h>
#include <iostream>


t_fourmi DeplaceFourmi (t_fourmi f , t_monde monde) 
{ 

	/*
     5 6 7
     4 - 0
     3 2 1

	*/
	
	int rot, dx, dy;
	do
	{
		rot = nalea(8);
		switch (rot)
		{
			case 0:
				dx = 1;
				break;
			case 1:
				dx = 1;
				dy = -1;
				break;
			case 2: 
				dy = -1;
				break;
			case 3: 
				dx = -1;
				dy = -1;
				break;
			case 4: 
				dx = -1;
				break;
			case 5:
				dx = -1; 
				dy = 1;
				break;
			case 6: 
				dy = 1;
				break;
			case 7: 
				dx = 1;
				dy = 1;
				break;
		}
	}while (!PositionPossible(f.x+dx, f.y+dy, monde));
	f.x = f.x + dx;
	f.y = f.y + dy;
	return f;
}

bool PositionPossible (int x, int y, t_monde monde)
{
	if (x < monde.L && x>=0 && y>=0 && y< monde. H) 
	{
		if (monde.mat[x][y] != -1)
		{
			return true; 
		}
	}

	return false;  
}




int modulo8 (int x)
{
	int y;
	y = (x+8)%8;
	return y;
}


int DirFourmiliere(int x, int y, int Fx, int Fy)     //et regarder à quelle direction il se référe
{
	int tdx[8] = {1,1,0,-1,-1,-1,0,1};
	int tdy[8] = {0,1,1,1,0,-1,-1,-1};
	int resultat;
	int dx = x - Fx;  //x, y position fourmiliere ; Fx et Fy position fourmi
	int dy = y - Fy;
	float norme = sqrt(dx*dx + dy*dy);
	dx = (int)round(dx/norme); 		  // round retourne un réel qu’il faut transformer en entier
	dy = (int)round(dy/norme);
	for (int i = 0; i <= 7; i++)  // vérifier pour les 8 dir possibles celle qui oriente au mieux vers la fourmilière
	{ 
		if(dx == tdx[i] && dy == tdy[i]) 
		{
			return i;
		}
	}
}



t_fourmi DeplaceFourmi_Better (t_fourmi f, t_monde envir, t_matrice phero)
{
	int tdx[8] = {1,1,0,-1,-1,-1,0,1};
	int tdy[8] = {0,1,1,1,0,-1,-1,-1};
	int p_toutdroit[8] = {12,2,1,1,0,1,1,2};
	int dir, i, dir_phero;
	int pond[8];

	//choix de une direction, en privilegiant la direction "tout droit"
	if(f.mode == 0)  // Achei comida!!
	{
		f.dir = DirFourmiliere(envir.Fx, envir.Fy, f.x, f.y);
		std::cout << f.dir << std::endl;
		p_toutdroit[0] = 200;
		p_toutdroit[1] = p_toutdroit[7] = 32;
		p_toutdroit[2] = p_toutdroit[6] = 8;
		p_toutdroit[3] = p_toutdroit[5] = 2;
		p_toutdroit[4] = 1;
		for (i=0; i<8; i++)
		{	
			dir = modulo8(i-f.dir);
			pond[i] = p_toutdroit[dir];
		}
	}
	else // Recherche la norriture
	{
		dir_phero = 0;
		for(i = 1; i < 8; i++)
		{
			if(phero[f.x+tdx[dir_phero]][f.y+tdy[dir_phero]] < phero[f.x+tdx[i]][f.y+tdy[i]])
				dir_phero = i;
		}
		for (i=0; i<8; i++)
		{	
			dir = modulo8(i- f.dir);
			if(envir.mat[f.x+tdx[dir]][f.y+tdy[dir]] > 0 )// Se na direcao da comida, ponderacao vai ser gigante
			{
				pond[i] = 100000;
			}
			else
			{
				pond[i] = p_toutdroit[dir];
			}
		}
		//pondération nulle quand le déplacement n’est pas possible
		
	}
	
	for (i=0; i<8; i++)
	{
		if (!PositionPossible(f.x + tdx[i], f.y + tdy[i], envir))
		{
			pond[i] = 0;
		}
	}
	// détermination de la direction par tirage au sort suivant la pondération
	f.dir = nalea_pondere(pond);
	// 2) déplacement suivant cette direction
	f.x = f.x + tdx[f.dir];
	f.y = f.y + tdy[f.dir];
	if(envir.mat[f.x][f.y] > 0)
	{
		f.mode = 0;
	}
	else if(envir.Fx == f.x && envir.Fy == f.y)
	{
		f.mode = 1;
	}
	return f;
}


