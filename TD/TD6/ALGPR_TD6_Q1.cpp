/* ---------------------------------------------------------------------------------------
         @file: ALGPR_TD6_Q1.cpp
       @author: Carlos Adir | Ely Murussi Leite
         @date: 06 de outubro de 2019
  @description: Arquivo dado pelo TD6 da disciplina de Algo da Ecole Centrale de Nantes.
  				Aqui contem estruturas de dados e funcoes implementadas solicitadas pelo PDF que esta na mesma pasta que esse arquivo.
  				O exercicio tem como foco utilizar funcoes, sabendo a passagem de argumento através de 3 metodos:
  				* Valor
  				* Referencia
  				* Endereco
  				Na funcao principal(main), contem os testes realizados.
  				Nela foram separados os blocos de codigos.
  				Inicialmente se tem a declaracao das variaveis utilizadas, depois dentro de cada condicional, a chamada das funcoes.
  				Caso queira que determinado bloco de codigo nao seja chamado, entao basta trocar o valor dentro do if para 0,
  				que tudo dentro do bloco do if nao sera realizado.
  				Por exemplo, para testar as funcoes finais, nao eh necessario digitar a todo momento os valores para my_article,
  				visto que so serao utilizados os valores do vetor.

  				Nota: 	Todas as coisas escritas pela main estao em ingles, enquanto dentro das funcoes, se escreve em portugues.
  						Dessa maneira facilita saber por onde o programa passou, e facilitar o entendimento.
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
	
	cout << "-------- Lendo um artigo --------"
	cout << "- Digite o numero de referencia: ";
	cin >> unArticle.reference;
	cout << "- Digite o preco do artigo: ";
	cin >> unArticle.prix;
	cout << "- Digite o nome do artigo: ";
	cin >> unArticle.nom;
	cout << "---------------------------------"
	
	return unArticle;
}

// -------------------------------------------------------
t_Article lectureArticle(int reference, float prix, string nom) {
	t_Article unArticle;

	unArticle.reference = reference;
	unArticle.prix = prix;
	unArticle.nom = nom;
	
	return unArticle;
}
// -------------------------------------------------------
void ecrireArticle(t_Article unArticle)
{
    cout << "-------- Print Article --------" << endl;
    cout << "-  Artigo " << unArticle.reference << ":" << endl;
    cout << "-  Preco: " << unArticle.prix << endl;
    cout << "-  Nome:  " << unArticle.nom << endl;
    cout << "-------------------------------" << endl;
}

// -------------------------------------------------------
float sommePrixArticles(int nbArticles, t_VectArticles articles)
{
	float somme = 0;
	int i;
	for(i = 0; i < nbArticles; i++)
		somme += articles[i].prix;
	return somme;
}

// -------------------------------------------------------
void prixMinMax(int nbArticles, t_VectArticles articles, float & pMin, float & pMax)
{
	
	int i;
	pMin = pMax = articles[0].prix;
	for(i = 1; i < nbArticles; i++)
	{
		if(articles[i].prix < pMin)
			pMin = articles[i].prix;
		else if(articles[i].prix > pMax)
			pMax = articles[i].prix;
	}
	
}
void prixMinMaxPointers(int nbArticles, t_VectArticles articles, float * pMin, float * pMax)
{
	
	int i;
	*pMin = *pMax = articles[0].prix;
	for(i = 1; i < nbArticles; i++)
	{
		if(articles[i].prix < *pMin)
			*pMin = articles[i].prix;
		else if(articles[i].prix > *pMax)
			*pMax = articles[i].prix;
	}
	
}

// -------------------------------------------------------
void miseAJourPrix(t_Article & article, float nouveauPrix)
{
	article.prix = nouveauPrix;
}
void miseAJourPrixPointer(t_Article * article, float nouveauPrix)
{
	article->prix = nouveauPrix;
}


// -------------------------------------------------------
void miseAJourTableau(int nbArticles, t_VectArticles articles, t_Article nouvelArticle, int indice)
{
	if(indice < nbArticles)
	{
		articles[indice] = nouvelArticle;
	}
	else
	{
		cout << "Hey! O indice enviado eh maior " << endl;
	}
}

// -------------------------------------------------------
void lectureTableau(int & nbArticles, t_VectArticles articles)
{
	int i;
	cout << "Digite o numero de artigos que voce quer: ";
	cin >> nbArticles;
	cout << "Agora iremos digitar todos os artigos do vetor:" << endl;
	for(i = 0; i < nbArticles; i++)
	{
		articles[i] = lectureArticleClavier();
	}
	cout << "Artigos lidos com sucesso!" << endl;

	return;
}


// ---------------------------------------------------------------------------------------
// Programme principal

int main() {
	/* Declaration of variables */
	t_Article my_article;
	t_VectArticles my_vector;
	float sum;
	float min, max;
	int indice, Nb;

	/* A inicializacao do vetor com alguns valores. Poderiamos digitar, mas fazer isso toda hora da trabalho */
	my_vector[0] = lectureArticle(1, 2.3, "mesa");
	my_vector[1] = lectureArticle(2, 3.3, "cadeira");
	my_vector[2] = lectureArticle(3, 1.4, "papel");
	my_vector[3] = lectureArticle(4, 12.3, "joia");
	Nb = 4; /* Porque temos apenas 4 elementos no vetor my_vector */

	/* Here we do the tests we need*/
	if(1) /* Aqui lemos um artigo do teclado, e logo em seguida escrevemos o artigo para sabermos se tudo ocorreu tudo certo */
	{
		cout << "\n\n\nNow we are going to use the function \"lectureArticleClavier\" " << endl;
		cout << "Reading an article from the keyboard" << endl;
		my_article = lectureArticleClavier(); /* Lendo o artigo do teclado */
		cout << endl;

		cout << "Writing an article" << endl;
		ecrireArticle(my_article); /* Escrevendo o artigo na tela*/
		cout << endl;
		cout << endl; /* Pula uma linha */
	}

	if(1) /* Here will show the sum of the values*/
	{
		cout << "\n\n\nNow we are going to use the function \"sommePrixArticles\" " << endl;
		cout << "Doing the sum of the values from the article's vector" << endl;
		sum = sommePrixArticles(Nb, my_vector);
		cout << "Sum value: " << sum << endl;
		cout << endl; /* Pula uma linha */
	}

	if(1) /* Aqui pegamos o valor minimo e maximo dentro do vetor dado, funcao por refencia*/
	{
		cout << "\n\n\nNow we are going to use the function \"prixMinMax\" " << endl;
		min = 0; /* Resetamos o valor, para saber se a funcao funciona corretamente*/
		max = 9999; /* Resetamos o valor, para saber se a funcao funciona corretamente*/
		cout << "The minimum and the maximum value inside the vector for reference" << endl;
		prixMinMax(Nb, my_vector, min, max);
		cout << "Minimum value: " << min << endl;
		cout << "Maximum value: " << max << endl;
		cout << endl; /* Pula uma linha */
	}
	if(1) /* Aqui pegamos o valor minimo e maximo dentro do vetor dado, funcao por ponteiro*/
	{
		cout << "\n\n\nNow we are going to use the function \"prixMinMaxPointers\" " << endl;
		min = 0; /* Resetamos o valor, para saber se a funcao funciona corretamente*/
		max = 9999; /* Resetamos o valor, para saber se a funcao funciona corretamente*/
		cout << "The minimum and the maximum value inside the vector for pointer" << endl;
		prixMinMaxPointers(Nb, my_vector, &min, &max);
		cout << "Minimum value: " << min << endl;
		cout << "Maximum value: " << max << endl;
		cout << endl; /* Pula uma linha */
	}
	if(1) /* Atualizacao do my_article, utilizando referencia */
	{
		cout << "\n\n\nNow we are going to use the function \"miseAJourPrix\" " << endl;
		my_article = lectureArticle(1, 2.4, "mesa");
		cout << "Now we will change the value in an article with reference:" << endl;
		cout << "Old value:" << endl;
		ecrireArticle(my_article); /* Escrevemos o artigo na tela */
		cout << "Changing the value in a article..." << endl;
		miseAJourPrix(my_article, 4.2); /* Mudamos o valor*/
		cout << "Value changed" << endl;
		cout << "New value:" << endl;
		ecrireArticle(my_article); /* Escrevemos o artigo na tela */
		cout << endl; /* Pula uma linha */
	}
	if(1) /* Atualizacao do my_article, utilizando ponteiros */
	{
		cout << "\n\n\nNow we are going to use the function \"miseAJourPrixPointer\" " << endl;
		my_article = lectureArticle(1, 2.4, "mesa");
		cout << "Now we will change the value in an article with pointer:" << endl;
		cout << "Old value:" << endl;
		ecrireArticle(my_article); /* Escrevemos o artigo na tela */
		cout << "Changing the value in a article..." << endl;
		miseAJourPrixPointer(&my_article, 4.2); /* Mudamos o valor*/
		cout << "Value changed" << endl;
		cout << "New value:" << endl;
		ecrireArticle(my_article); /* Escrevemos o artigo na tela */
		cout << endl; /* Pula uma linha */
	}
	if(1) /* Atualizacao do my_vector, no elemento de indice "indice"*/
	{
		cout << "\n\n\nNow we are going to use the function \"miseAJourTableau\" " << endl;
		indice = 2;
		my_article = lectureArticle(1, 2.4, "mesa");
		cout << "The new article that we will change:" << endl;
		ecrireArticle(my_article); /* Escrevemos o artigo na tela */
		cout << "The article in position of indice " << indice << " in our vector" << endl;
		ecrireArticle(my_vector[indice]); /* Escrevemos o artigo na tela */
		cout << "Now we will use the function to change:" << endl;
		miseAJourTableau(Nb, my_vector, my_article, indice); /* Mudamos o artigo no indice */
		cout << "Value changed!" << endl;
		cout << "The article in position of indice " << indice << " in our vector" << endl;
		ecrireArticle(my_vector[indice]); /* Escrevemos o artigo na tela */
		cout << endl; /* Pula uma linha */
	}
	if(1)
	{
		cout << "\n\n\nNow we are going to use the function \"lectureTableau\" " << endl;
		cout << "Calling the function..." << endl;
		lectureTableau(Nb, my_vector);
		cout << "... function ended" << endl;
	}
	
	

	return EXIT_SUCCESS;
}
	
