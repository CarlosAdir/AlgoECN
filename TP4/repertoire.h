#ifndef REPERTOIRE_H_INCLUDED
#define REPERTOIRE_H_INCLUDED

#include "type_def.h"
#include "repertoire.h"
#include "type_def.h"
#include "utilitaires.h"
#include <fstream>
#include <iostream>

/* #################################################################
   #                                                               #
   #                                                               #
   #                                                               #
   #################################################################
*/

void afficherPersonne(const personne &p);

/* #################################################################
   #                                                               #
   #                                                               #
   #                                                               #
   #################################################################
*/

void afficherTableau(personne tableau[], int taille_t);
void ajouterTableau(vectPersonne tableau, int taille_t, personne p);
bool rechercherTableau(vectPersonne tableau, int taille_t, personne p);
void supprimerTableau(vectPersonne tableau, int taille_t, personne p);
int TableaulectureRepertoire(personne vect[], std::string repertoire_text);


/* #################################################################
   #                                                               #
   #                                                               #
   #                                                               #
   #################################################################
*/
   

elementListe *creeUnElementListe(elementListe *precedent, const personne &p, elementListe *suivant);
void afficherListe(elementListe *ma_liste);
elementListe *ajouterListe(elementListe *ma_liste, const personne &p);
bool rechercherListe(elementListe *ma_liste, const personne &p);
void libereListe(elementListe *ma_liste);
elementListe *supprimerListe(elementListe *ma_liste, const personne &p);
elementListe *lectureRepertoireListe(const std::string FILE_NAME);

/* #################################################################
   #                                                               #
   #                                                               #
   #                                                               #
   #################################################################
*/


noeud *creeUnNoeud(const personne &p);
void afficherArbre(noeud *unArbre);
void afficherArbrePrefixe(noeud *unArbre);
void afficherArbreInfixe(noeud *unArbre);
void afficherArbrePosfixe(noeud *unArbre);
noeud *ajouterArbre(noeud *ma_arbre, const personne &p);
bool rechercherArbre(noeud *ma_arbre, const personne &p);
void libereArbre(noeud *unArbre);
noeud *supprimerArbre(noeud *ma_arbre, const personne &p);
noeud *lectureRepertoireArbre(const std::string FILE_NAME);



#endif 
