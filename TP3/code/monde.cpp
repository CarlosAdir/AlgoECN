#include <cstring>
#include <iostream>
#include <fstream>

t_monde LireEnvironnement (std::string monde)
{
	int L, H, Fx, Fy; //largeur et à la hauteur de monde, Positions de fourmilière; 
	int i,j; // Indices matrice 
	t_monde m; 

	monde = "monde1.dat";
	//std:: cin >> monde;

	std::ifstream f;
	f.open(monde);
	f >> L;
	std:: cout << L;
	f >> H;
	std:: cout << H;

	
	f >> Fx; 
	f >> Fy; 

	for (i= 0; i< H; i++)
	{ 
		for (j= 0; j < L; j++ )
		{
			f>> m.mat [i] [j]; 

		}
	}

	m.L = L; 
	m.H = H; 
	m.Fx= Fx; 
	m.Fy= Fy; 

	
	return m;

	//MiseAJourFourmi( int x, int y, int mode);

	//void MiseAJourEnvironnement( t_monde environnement);
	//void MiseAJourPheromones( t_matrice pheromones);
	//int Affichage();

}