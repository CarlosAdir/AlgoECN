#include <iostream>
#include <time.h>
#include "utilitaire_generation.h"
#include "utilitaires.h"
#include "type_def.h"


int main()
{
	srand((unsigned)time(NULL));
	vectPersonne mon_vector;
	bool response;

	response = genererRepertoire(mon_vector);
	if(response == false)
	{
		std::cout << "Il ne peut pas generer le Repertoire des personnes" << std::endl;
		return -1;
	}	


	return 0;
}