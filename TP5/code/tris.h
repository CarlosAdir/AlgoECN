#ifndef TRIS_H_INCLUDED
#define TRIS_H_INCLUDED

#include "types.h"

void trocar_objet(objet *obj1, objet *obj2);
/* Nous faisons l'echange des infomations entre les objects
	C'est-a-dire, c'est la meme chose que faire:
		tmp = *obj1;
		*obj1 = *obj2;
		*obj2 = tmp;
*/

void tri_vecteur (ensObjets *eo);
/* Faire la organization de le vecteur(deja complet) avec la utilisation du algorithme bubble sort*/

void ajouter_objet (ensObjets *eo, objet o);
/* Nous faisons la fonction ajouter, dans l'ordre, avec la recherche lineaire */

void ajouter_objet2 (ensObjets *eo, objet o);
/* Nous faisons la fonction ajouter, dans l'ordre, avec la recherche dichotomique */

#endif 