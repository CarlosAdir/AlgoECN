#ifndef UTILITAIRE_GENERATION_H_INCLUDED
#define UTILITAIRE_GENERATION_H_INCLUDED

#include <string>

#include "type_def.h"

personne creerPersonne(std::string nom, std::string prenom, std::string secu);
                          
personne genererPersonne(std::string* listNom, std::string* listPrenom, int nbNom, int nbPrenom);

#endif // UTILITAIRES_H_INCLUDED
