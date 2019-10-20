#ifndef REPERTOIRE_H_INCLUDED
#define REPERTOIRE_H_INCLUDED

#include "type_def.h"

void lectureRepertoireVector(vectPersonne mon_vector, const std::string FILE_NAME);
elementListe *lectureRepertoireListe(const std::string FILE_NAME);
noeud *lectureRepertoireArbre(const std::string FILE_NAME);

elementListe *ajouterListe(elementListe *ma_liste, const personne &p);
bool rechercherListe(elementListe *ma_liste, const personne &p);
void libereListe(elementListe *ma_liste);

noeud *supprimerArbre(noeud *ma_arbre, const personne &p);
noeud *ajouterArbre(noeud *ma_arbre, const personne &p);
bool rechercherArbre(noeud *ma_arbre, const personne &p);
void libereArbre(noeud *unArbre);

void afficherArbre(noeud *unArbre);
void afficherArbrePrefixe(noeud *unArbre);
void afficherArbreInfixe(noeud *unArbre);
void afficherArbrePosfixe(noeud *unArbre);

#endif 
