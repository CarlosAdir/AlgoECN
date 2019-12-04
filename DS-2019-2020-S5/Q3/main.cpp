#include "fonctions.h"

#define FILENAME "input.txt"

int main()
{
	t_dictionnaire dictionnaire;
	bool sucess;

	sucess = lire_texte(dictionnaire, FILENAME);
	if(sucess)
	{
		afficher_frequences(dictionnaire);
	}

	return 0;
}