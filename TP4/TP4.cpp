#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include "type_def.h"
#include "utilitaires.h"
#include "utilitaire_generation.h"
#include "repertoire.h"

#define QTT_TESTS 1000

bool estceque_file_exist(const std::string FILE_NAME)
{
	std::ifstream input_file;
	input_file.open(FILE_NAME);
	if (input_file.fail())
    	return false;
	input_file.close();
	return true;
}

void sort_1000_personnes_dif(personne from[], personne to[])
{
	const int QTT_FROM = 10000;
	int i, j, numeros[QTT_TESTS];
	bool cont = true;
	for(i = 0; i < QTT_TESTS; i++)
	{
		do
		{
			numeros[i] = rand()%QTT_FROM;
			cont = false;
			for(j = 0; j < i && !cont; j++)
				if(numeros[i] == numeros[j])
					cont = true;
		}while(cont);
		to[i] = from[numeros[i]];
	}
}


void testes()
{
	int i, j, taille_t;
	clock_t temps[3][4]; // (tableau, liste, arbre) x (lecture, afficher, recherche, supprimer)
	personne aleat[QTT_TESTS];
	vectPersonne mon_tableau;
	elementListe *ma_liste = NULL;
	noeud *ma_arbre;

	

	/* Pour la arbre */
	if(1)
	{
		i = 0;
		temps[i][0] = clock();
		taille_t = TableaulectureRepertoire(mon_tableau, NOM_REPERTOIRE);
		temps[i][0] = clock() - temps[i][0];
		i = 1;
		temps[i][0] = clock();
		ma_liste = lectureRepertoireListe(NOM_REPERTOIRE);
		temps[i][0] = clock() - temps[i][0];
		i = 2;
		temps[i][0] = clock();
		ma_arbre = lectureRepertoireArbre(NOM_REPERTOIRE);
		temps[i][0] = clock() - temps[i][0];
	}

	sort_1000_personnes_dif(mon_tableau, aleat); // On prend 1000 personnes aleatoires pour faire la recherche et la supression.
												 // Pour ça, on a besoin le tableau mon_tableau
	if(1)
	{
		i = 0;
		temps[i][1] = clock();
		afficherTableau(mon_tableau, taille_t);
		temps[i][1] = clock() - temps[i][1];
		temps[i][2] = clock();
		for(j = 0; j < QTT_TESTS; j++)
			rechercherTableau(mon_tableau, taille_t, aleat[j]);
		temps[i][2] = clock() - temps[i][2];
		temps[i][3] = clock();
		for(j = 0; j < QTT_TESTS; j++)
			supprimerTableau(mon_tableau, taille_t, aleat[j]);
		temps[i][3] = clock() - temps[i][3];

		i = 1;
		temps[i][1] = clock();
		afficherListe(ma_liste);
		temps[i][1] = clock() - temps[i][1];
		temps[i][2] = clock();
		for(j = 0; j < QTT_TESTS; j++)
			rechercherListe(ma_liste, aleat[j]);
		temps[i][2] = clock() - temps[i][2];
		temps[i][3] = clock();
		for(j = 0; j < QTT_TESTS; j++)
			ma_liste = supprimerListe(ma_liste, aleat[j]);
		temps[i][3] = clock() - temps[i][3];

		i = 2;
		temps[i][1] = clock();
		afficherArbre(ma_arbre);
		temps[i][1] = clock() - temps[i][1];
		temps[i][2] = clock();
		for(j = 0; j < QTT_TESTS; j++)
			rechercherArbre(ma_arbre, aleat[j]);
		temps[i][2] = clock() - temps[i][2];
		temps[i][3] = clock();
		for(j = 0; j < QTT_TESTS; j++)
			ma_arbre = supprimerArbre(ma_arbre, aleat[j]);
		temps[i][3] = clock() - temps[i][3];
		
	}


	std::cout << "--------------------- LE TEMPS -------------" << std::endl;
	std::cout << "----------- Tableau --- Liste ---- Arbre ---" << std::endl;
	for(j = 0; j < 4; j++)
	{
		if(j == 0)
			std::cout << "  Lecture - ";
		if(j == 1)
			std::cout << "Affichage - ";
		if(j == 2)
			std::cout << "Recherche - ";
		if(j == 3)
			std::cout << "Suppressi - ";
		for(i = 0; i < 3; i++)
		{
			printf("%.6f - ", float(temps[i][j])/CLOCKS_PER_SEC);
		}
		std::cout << std::endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	bool response;

	if(!estceque_file_exist(NOM_REPERTOIRE))
	{
		response = genererRepertoire();
		if(response == false)
		{
			std::cout << "Il ne peut pas generer le Repertoire des personnes" << std::endl;
			return -1;
		}	
	}
	
	testes();

	return 0;
}