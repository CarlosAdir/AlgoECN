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
	// A modifier ...
		
	return laListe;
}

// -------------------------------------------------------
void afficheIteratif(ListeElt* laListe) {
	// A modifier ...
	
}

// -------------------------------------------------------
void afficheRecursif(ListeElt* laListe) {
	// A modifier ...
	
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
	
