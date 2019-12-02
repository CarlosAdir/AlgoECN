/* ---------------------------------------------------------------------------------------
ALGPR - TD
Structures d'Arbres

Equipe Pédagogique ALGPR
Centrale Nantes
Mars 2016
--------------------------------------------------------------------------------------- */

#include <cstdlib>
#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------------------
// Définition de constantes et types de base pour le TD


struct t_Noeud {
	int valeur;
    t_Noeud* gauche;
    t_Noeud* droite;
};

// ---------------------------------------------------------------------------------------
// Les fonctions à écrire


// -------------------------------------------------------
t_Noeud* creeElement(int valeur) {
	t_Noeud* unElement;
	
	unElement = new t_Noeud;
	unElement->valeur = valeur;
	unElement->gauche = NULL;
	unElement->droite = NULL;

	return unElement;
}

// -------------------------------------------------------
t_Noeud* insertABR(t_Noeud* unArbre, int valeur)
{
	if(unArbre == NULL)
	{
		unArbre = creeElement(valeur);
	}
	else
	{
		if(valeur < unArbre->valeur)
			unArbre->gauche = insertABR(unArbre->gauche, valeur);
		else if(valeur > unArbre->valeur)
			unArbre->droite = insertABR(unArbre->droite, valeur);
		else
			cout << "Deu algo errado, porque o valor ja tem na arvore! Elemento nao adicionado!" << endl; 
	}
	return unArbre;
}

// -------------------------------------------------------
void libereArbre(t_Noeud* unArbre) {
	if (unArbre != NULL) {
		libereArbre(unArbre->gauche);
		libereArbre(unArbre->droite);
		delete unArbre;
	}
}

// -------------------------------------------------------
void affichePrefixe(t_Noeud* unArbre) 
{
	if(unArbre == NULL)
		return;
	cout << unArbre->valeur << endl;
	affichePrefixe(unArbre->gauche);
	affichePrefixe(unArbre->droite);
}

// -------------------------------------------------------
void afficheInfixe(t_Noeud* unArbre) 
{
	if(unArbre == NULL)
		return;
	afficheInfixe(unArbre->gauche);
	cout << unArbre->valeur << endl;
	afficheInfixe(unArbre->droite);
}

// -------------------------------------------------------
void affichePostfixe(t_Noeud* unArbre) 
{
	if(unArbre == NULL)
		return;
	affichePostfixe(unArbre->gauche);
	affichePostfixe(unArbre->droite);
	cout << unArbre->valeur << endl;
}

// -------------------------------------------------------
int nbNoeuds(t_Noeud* unArbre) {
	if(unArbre == NULL)
		return 0;
	else
		return 1 + nbNoeuds(unArbre->gauche) + nbNoeuds(unArbre->droite);
}

// -------------------------------------------------------
int hauteur(t_Noeud* unArbre) {
	int altura_esquerda, altura_direita, maior_altura;
	if(unArbre == NULL)
		return 0;
	else
	{
		altura_esquerda = hauteur(unArbre->gauche);
		altura_direita  = hauteur(unArbre->droite);
		if(altura_direita > altura_esquerda)
			maior_altura = altura_direita;
		else
			maior_altura = altura_esquerda;
		return 1 + maior_altura;
	}
}

// ---------------------------------------------------------------------------------------
// Programme principal
int main() {
	t_Noeud* unArbre;
	
	cout << "Construction de l'arbre" << endl;
	unArbre = NULL;
	
	unArbre = insertABR(unArbre, 20);
	unArbre = insertABR(unArbre, 12);
	unArbre = insertABR(unArbre, 1);
	unArbre = insertABR(unArbre, 47);
	unArbre = insertABR(unArbre, 31);
	unArbre = insertABR(unArbre, 22);
	
	cout << "Affichage Prefixe" << endl;
	affichePrefixe(unArbre);
	
	cout << "Affichage Infixe" << endl;
	afficheInfixe(unArbre);

	cout << "Affichage Postfixe" << endl;
	affichePostfixe(unArbre);

	cout << "Nombre de noeuds" << endl;
	cout << nbNoeuds(unArbre) << endl;
	
	cout << "Hauteur" << endl;
	cout << hauteur(unArbre) << endl;

	libereArbre(unArbre);
	
	return EXIT_SUCCESS;
}
	
