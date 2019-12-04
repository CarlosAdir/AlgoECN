#include "fonctions.h"


t_liste *ajouter_mot_liste(t_liste *l, t_mot mot)
{
	t_liste *n;
	if(l == NULL)
	{
		n = new t_liste();
		n->mot = mot;
		n->f = 1;
		return n;
	}
	n = l;
	while(n->suiv != NULL)
	{
		if(n->mot == mot)
		{
			n->f += 1;
			return l;
		}
		n = n->suiv;
	}
	if(n->mot == mot)
	{
		n->f += 1;
		return l;
	}
	n->suiv = new t_liste();
	n = n->suiv;
	n->f = 1;
	n->mot = mot;
	return l;
}

void ajouter_mot_dictionnaire(t_liste *dictionnaire[], t_mot mot)
{
	int indice = mot[0] - 'a';
	dictionnaire[indice] = ajouter_mot_liste(dictionnaire[indice], mot);
}

/*
t_mot lire_mot(std::ifstream fin)
{
	t_mot mot;
	fin >> mot;
	return mot;
}
*/

bool lire_texte(t_liste *dictionnaire[], const char *filename)
{
	int i;
	ifstream fin;
	t_mot mot;
	fin.open(filename);
	for(i = 0; i < TAILLE; i++)
		dictionnaire[i] = NULL;
	if(!fin.is_open())
	{
		cout << "Je ne peut pas ouvrir le fichier: " << filename << endl;
		return false;
	}
	while(!fin.eof())
	{
		//mot = lire_mot(fin);
		fin >> mot;
		ajouter_mot_dictionnaire(dictionnaire, mot);
	}
	fin.close();
	return true;
}

void afficher_frequences(t_liste *dictionnaire[])
{
	int i, total = 0, freq[TAILLE];
	t_liste *p;
	for(i = 0; i < TAILLE; i++)
	{
		freq[i] = 0;
		p = dictionnaire[i];
		while(p != NULL)
		{
			freq[i] += p->f;
			p = p->suiv;
		}
		total += freq[i];
	}
	if(total != 0) // C'est-a-dire, il y a n'import qui mot dans le dictionnaire
		for(i = 0; i < TAILLE; i++)
		{
			cout << "La freq des mots qui commencent avec '" << (char) ('a' + i) << "': ";
			cout << ((float)freq[i])/total << endl;
		}
}