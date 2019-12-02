
#include "types.h"
#include "utils.h"
#include <time.h>


#include <iostream>
using namespace std; 

void afficher_stock(ensMatieres *stock)
{
	unsigned short int i;
	cout << "    *********" << endl;
	cout << "    * STOCK *" << endl;
	cout << "    *********" << endl;
	for(i = 0; i < stock->size(); i++)
	{
		// Afficher une matiere
		cout << "Matiere: " << stock->at(i).nom << endl;
		cout << "  Poids: " << stock->at(i).poids << endl;
	}
}

void testes_temps1() // Pour le 2 et 3
{

	clock_t t1, t2, t3,t4,t5, t6; 
	ensObjets a, b, c; 


	t1 = clock ();
	lireObjets_1 (&a); 
	t2 = clock ();
	ecrireObjets_1 (a);
	t3 = clock ();
	lireObjets_2 (&b); 
	t4= clock ();
	ecrireObjets_2 (b); 
	t5= clock ();
	lireObjets_3 (&c); 
	t6 = clock();


	cout << "Temps fonction    [lire_1]   : " << 1000*float(t2-t1)/CLOCKS_PER_SEC << " micro-segundos" << endl;
	cout << "Temps fonction   [ecrire_1]  : " << 1000*float(t3-t2)/CLOCKS_PER_SEC << " micro-segundos" << endl; 
	cout << "Temps fonction    [lire_2]   : " << 1000*float(t4-t3)/CLOCKS_PER_SEC << " micro-segundos" << endl; 
	cout << "Temps fonction   [ecrire_2]  : " << 1000*float(t5-t4)/CLOCKS_PER_SEC << " micro-segundos" << endl; 
	cout << "Temps fonction    [lire_3]   : " << 1000*float(t6-t5)/CLOCKS_PER_SEC << " micro-segundos" << endl; 

}

void testes_temps2() // Pour le question 4 et 5
{
	ensObjets mes_objets;
	ensLivraison mes_arrives;
	clock_t t1, t2; 
	int penalidade;
	
	lireObjets_1(&mes_objets);
	lireMatiere(&mes_arrives);
	
	t1 = clock();
	penalidade = calculRetard(&mes_arrives, &mes_objets);
	t2 = clock();
	cout << "Temps fonction [calculRetard]: " << 1000*float(t2-t1)/CLOCKS_PER_SEC << " micro-segundos" << endl;
	cout << "Penalite: " << penalidade << endl;
	
}




int main ()
{
	testes_temps1();
	testes_temps2();
	
	return 0; 
}; 