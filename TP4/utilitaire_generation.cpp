#include <fstream>
#include <iostream>
#include <ostream>
#include <cstdio>

using namespace std;

#include "type_def.h"
#include "utilitaire_generation.h"


personne creerPersonne(std::string nom,
                          std::string prenom,
                          std::string secu)
{
    personne result;

    result.nom = nom;
    result.prenom = prenom;
    result.numss = secu;

    return result;
}

personne genererPersonne(std::string* listNom, std::string* listPrenom, int nbNom, int nbPrenom)
{
    char sexe[2], annee[3], moisNaiss[3], depart[3], commune[4], etatCiv[4];
    sprintf(sexe,"%d", (rand())%2+1);
    sprintf(annee,"%02d",rand()%98+1);
    sprintf(moisNaiss,"%02d",rand()%12+1);
    sprintf(depart,"%02d",rand()%98+1);
    sprintf(commune,"%03d",rand()%998+1);
    sprintf(etatCiv,"%03d",rand()%998+1);

    std::cout<<annee<<" "<<moisNaiss<<" "<<depart<<" "<<commune<<" "<<etatCiv<<std::endl;

    string num = std::string(sexe,1)+std::string(annee,2)+std::string(moisNaiss,3)+std::string(depart,2)+std::string(commune,3)+std::string(etatCiv,3);
    
    std::cout<<num<<std::endl;

    return creerPersonne(listNom[rand()%nbNom],listPrenom[rand()%nbPrenom], num);
}

