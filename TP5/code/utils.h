#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "types.h" 

void lireObjets_1 (ensObjets *eo);
void ecrireObjets_1 (ensObjets eo);
void lireObjets_2 (ensObjets *eo);
void ecrireObjets_2 (ensObjets eo);
void lireObjets_3 (ensObjets *eo);








void lireMatiere (ensLivraison *em);
/* Lire et faire la stockage de tout les livraisons du fichier matieres_100.txt */

void Initialisation_matieres (ensMatieres *stock);
/* Faire la lecture du fichier matieres_100.txt, et prendre tout les noms des matiers */

void put_in_stock(ensMatieres *stock, livraison liv);
/* Prendre une livraison et mettre dans le stock.
	Par example, si la livraison est le verre 1000, alors, dans le stock, le verre sera plus 1000 */

bool il_y_a_matiere_dans_stock(ensMatieres *stock, const objet &o);
/* Il verifie si il y a tout les matieres necessaires pour faire le objet dans le stock
	Par example, si le objet a besoin:
		* 2 verre
		* 5 acier
	Et le stock a seulement 3 verre et 4 acier, alors, il renvoie false
	Si le stock au moins 2 verre et 5 acier, alors, il renvoie true
*/


void add_livraisons_to_stock(ensMatieres *stock, const ensLivraison *em, const int date);
/* Faire la livraison de toutes les livraisons dans le vecteur de livraison qui sont avant la date */
void RetirerObjetDuStock(ensMatieres *stock, const ensObjets *vectObj, const objet o);
/* Elle retire tout les objets */
void miseajour_stock(ensMatieres *stock, const ensLivraison *em, const ensObjets *vectObj, const objet o, const int date);


int calculRetardUnObjet (const ensLivraison *em, const ensObjets *vectObj, objet ob);

int calculRetard (const ensLivraison *em, const ensObjets *vectObj);
#endif 