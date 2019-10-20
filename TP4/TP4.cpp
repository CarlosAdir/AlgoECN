#include <iostream>
#include <fstream>
#include <time.h>
#include "type_def.h"
#include "utilitaires.h"
#include "utilitaire_generation.h"
#include "repertoire.h"


bool estceque_file_exist(const std::string FILE_NAME)
{
	std::ifstream input_file;
	input_file.open(FILE_NAME);
	if (input_file.fail())
    	return false;
	input_file.close();
	return true;
}

int main()
{
	srand((unsigned)time(NULL));
	vectPersonne mon_vector;
	elementListe *ma_liste;
	noeud *ma_arbre;
	bool response;

	if(!estceque_file_exist(NOM_REPERTOIRE))
	{
		response = genererRepertoire(mon_vector);
		if(response == false)
		{
			std::cout << "Il ne peut pas generer le Repertoire des personnes" << std::endl;
			return -1;
		}	
	}
	
	//lectureRepertoireVector(mon_vector, NOM_REPERTOIRE);
	ma_liste = lectureRepertoireListe(NOM_REPERTOIRE);
	ma_arbre = lectureRepertoireArbre(NOM_REPERTOIRE);
	afficherArbre(ma_arbre);
	ma_arbre = supprimerArbre(ma_arbre, (ma_liste->suivant->suivant->suivant->p));
	
	afficherArbre(ma_arbre);


	return 0;
}