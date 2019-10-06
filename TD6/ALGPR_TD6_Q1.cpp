/* ---------------------------------------------------------------------------------------
ALGPR - TD
Passages de paramètres

Equipe Pédagogique ALGPR
Centrale Nantes
Mars 2016
--------------------------------------------------------------------------------------- */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------------------
// Définition de constantes et types de base pour le TD

const int MAXARTICLES = 200;

struct t_Article {
	int reference;
	float prix;
	string nom;
};
typedef t_Article t_VectArticles[MAXARTICLES];

// ---------------------------------------------------------------------------------------
// Les fonctions à tester


// -------------------------------------------------------
t_Article lectureArticleClavier() {
	t_Article unArticle;
	
	// à compléter ...

	return unArticle;
}

// -------------------------------------------------------
t_Article lectureArticle(int reference, float prix, string nom) {
	t_Article unArticle;

	// à compléter ...
	
	return unArticle;
}
// -------------------------------------------------------
void ecrireArticle(t_Article unArticle)
{
    
    // à compléter ...
}

// -------------------------------------------------------
float sommePrixArticles(int nbArticles, t_VectArticles articles) {
	float somme;
	
	// à compléter
	
	return somme;
}

// -------------------------------------------------------
void prixMinMax(int nbArticles, t_VectArticles articles, float & pMin, float & pMax) {
	
	// à compléter ...
	
	}

// -------------------------------------------------------
void miseAJourPrix(t_Article & article, float nouveauPrix) {

	// à compléter ...

}

// -------------------------------------------------------
void miseAJourTableau(int nbArticles, t_VectArticles articles, t_Article nouvelArticle, int indice) {

	// à compléter ...

}

// -------------------------------------------------------
void lectureTableau(int & nbArticles, t_VectArticles articles) {

	// à compléter ...

}

// ---------------------------------------------------------------------------------------
// Programme principal
int main() {

	// à compléter ...
	
	return EXIT_SUCCESS;
}
	
