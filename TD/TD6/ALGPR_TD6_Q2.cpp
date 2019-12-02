/* ---------------------------------------------------------------------------------------
ALGPR - TD
Structures de Listes

Equipe Pédagogique ALGPR
Centrale Nantes
Mars 2016
--------------------------------------------------------------------------------------- */

#include <cstdlib>
#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------------------
// Définition de types de base pour le TD

struct ListeElt {
	int valeur;
	ListeElt* suivant;
};

// ---------------------------------------------------------------------------------------
// Les fonctions à écrire


// -------------------------------------------------------
ListeElt* creeElement(int valeur) {
	ListeElt* unElement;
	
	unElement = new ListeElt;
	unElement->valeur = valeur;
	unElement->suivant = NULL;
	
	return unElement;
}

// -------------------------------------------------------
ListeElt* addFirst(ListeElt* laListe, ListeElt* unElement) {
	unElement->suivant = laListe;
	laListe = unElement;
	return laListe;
}

// -------------------------------------------------------
void afficheIteratif(ListeElt* laListe) {
	while(laListe != NULL)
	{
		cout << laListe->valeur << endl;
		laListe = laListe->suivant;
	}
}

// -------------------------------------------------------
void afficheRecursif(ListeElt* laListe) {
	cout << laListe->valeur << endl;
	if(laListe->suivant != NULL)
		afficheRecursif(laListe->suivant);
}

// ---------------------------------------------------------------------------------------
// Programme principal
int main() {
	ListeElt* laListe;
	
	cout << "Construction de la liste" << endl;
	laListe = NULL;
	
	ListeElt* elt1 = creeElement(5);
	laListe = addFirst(laListe, elt1);
	
	laListe = addFirst(laListe, creeElement(10));

	laListe = addFirst(laListe, creeElement(8));
	
	laListe = addFirst(laListe, creeElement(1));
	
	cout << "Affichage Iteratif de la liste" << endl;
	afficheIteratif(laListe);
	
	cout << "Affichage Recursif de la liste" << endl;
	afficheRecursif(laListe);
	
	return EXIT_SUCCESS;
}
	
