

#include <iostream>
#include <fstream>
#include "utils.h"
#include "tris.h"

using namespace std; 

const int QUANTITE_INITIAL = 2;

void lireObjets_1 (ensObjets *eo)
{
	
	ifstream fichier; 
	string text = "objetsInput_100.txt";
	fichier.open (text); 
	objet o;
	matiere m; 
	char c;
	int i; 
	
	while (!fichier.eof ())
	{
		fichier >> o.nom; 
		fichier >> o.nombre; 
		fichier >> o.nombre_matiers; 
		for (i = 0; i < o.nombre_matiers; i++)
		{
			fichier >> m.nom; 
			fichier >> m.poids; 
			o.matieres.push_back (m); 
		}
		fichier >> o.date;
		fichier >> o.duree;
		fichier >> c;
		eo->push_back (o);
		o.matieres.erase(o.matieres.begin(), o.matieres.end());
	}

	fichier.close (); 
}

void ecrireObjets_1 (ensObjets eo)
{
	ofstream fichier; 
	fichier.open ("objetsOutput_100_1.txt");
	unsigned int i;      
	int j; 
	
	tri_vecteur (&eo); 

	for (i= 0; i<eo.size (); i++)
	{
		fichier << eo[i].nom << " "; 
		fichier << eo[i].nombre << " "; 
		fichier << eo[i].nombre_matiers << " "; 
		for (j = 0; j < eo[i].nombre_matiers; j ++)
		{
			fichier << eo[i].matieres[j].nom << " ";
			fichier << eo[i].matieres[j].poids << " "; 
		}
		fichier << eo[i].date << " "; 
		fichier << eo[i].duree << " ";
		fichier << endl; 
	}
	fichier.close();
};


void lireObjets_2 (ensObjets *eo)
{
	
	ifstream fichier; 
	string text = "objetsInput_100.txt";
	fichier.open (text); 
	objet o;
	matiere m;
	char c;
	int i; 
	
	while (!fichier.eof ())
	{
		fichier >> o.nom; 
		fichier >> o.nombre; 
		fichier >> o.nombre_matiers; 
		for (i = 0; i < o.nombre_matiers; i++)
		{
			fichier >> m.nom; 
			fichier >> m.poids; 
			o.matieres.push_back (m); 
		}
		fichier >> o.date;
		fichier >> o.duree;  
		fichier >> c;

	
		ajouter_objet (eo, o); 
		

		o.matieres.erase(o.matieres.begin(), o.matieres.end());
	}
	//cout << endl << eo->size() << endl;
	fichier.close (); 
}; 


void ecrireObjets_2 (ensObjets eo)
{
	ofstream fichier; 
	fichier.open ("objetsOutput_100_2.txt");
	unsigned int i;
	int j; 
	

	for (i= 0; i<eo.size (); i++)
	{
		fichier << eo[i].nom << " "; 
		fichier << eo[i].nombre << " "; 
		fichier << eo[i].nombre_matiers << " "; 
		for (j = 0; j < eo[i].nombre_matiers; j ++)
		{
			fichier << eo[i].matieres[j].nom << " ";
			fichier << eo[i].matieres[j].poids << " "; 
		}
		fichier << eo[i].date << " "; 
		fichier << eo[i].duree << " ";
		fichier << endl; 
	}
	fichier.close();
};



void lireObjets_3 (ensObjets *eo)
{
	
	ifstream fichier; 
	string text = "objetsInput_100.txt";
	fichier.open (text); 
	objet o;
	matiere m;
	char c;
	int i; 
	
	while (!fichier.eof ())
	{
		fichier >> o.nom; 
		fichier >> o.nombre; 
		fichier >> o.nombre_matiers; 
		for (i = 0; i < o.nombre_matiers; i++)
		{
			fichier >> m.nom; 
			fichier >> m.poids; 
			o.matieres.push_back (m); 
		}
		fichier >> o.date;
		fichier >> o.duree;  
		fichier >> c;

	
		ajouter_objet2 (eo, o); 
		

		o.matieres.erase(o.matieres.begin(), o.matieres.end());
	}
	//cout << endl << eo->size() << endl;
	fichier.close (); 
}; 






// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************



void lireMatiere (ensLivraison *em)
{
	livraison m;
	ifstream fichier; 
	string text = "matieres_100.txt";
	fichier.open (text); 


	while (!fichier.eof ())
	{
		fichier >> m.id; 
		fichier >> m.nom;
		fichier >> m.poids; 
		fichier >> m.date;  
		em->push_back (m); 
	}
	fichier.close (); 
}


void Initialisation_matieres (ensMatieres *stock)
{
	unsigned int i, j; 
	ensLivraison em;
	matiere new_mat;

	lireMatiere(&em);
	//cout << "   ba" << endl;
	for (i=0; i < em.size(); i++) // Pour chaque matiere que nous avons dans le ensMatiere que nous avons pris 
	{
		//cout << "   b" << i << "/" << em.size() << endl;
		for (j=0; j < stock->size(); j++) // La flag nous dire que il n'y a pas encore 
			if(em.at(i).nom == stock->at(j).nom) // Si il y a deja le matiere dans le vecteur stock
				break; // Nous pouvons arreter, parce que nous avons deja trouve la matiere dans notre tableau de Matieres
		//cout << "   b" << i << " - " << endl;
		if(j == stock->size()) // Si il n'y a pas la matiere dans le stock, nous devons ajouter
		{
		//	cout << "   bj" << endl;
			new_mat.nom = em.at(i).nom; // Nous prenons le nom de la nouvelle matiere
			new_mat.poids = QUANTITE_INITIAL; // Et nous pouvons mettre la quantite de matiere que nous avons
			stock->push_back(new_mat); // Et alors, nous pouvons ajouter dans le stock
		}

	}
}
void put_in_stock(ensMatieres *stock, livraison liv)
{
	unsigned int i;
	for(i = 0; i < stock->size(); i++)
	{
		if(liv.nom == stock->at(i).nom )
		{
			stock->at(i).poids += liv.poids;
			return;
		}
	}
	cout << "Ne peut pas trouver la matiere pour metre dans le stock!!" << endl;
}
bool il_y_a_matiere_dans_stock(ensMatieres *stock, const objet &o)
// Cette fonction nous dire si nous avons la quantite necessaire(dans le stock) pour faire le objet
// true si nous avons, false sinon
{
	int i;
	unsigned int j;
	for(i = 0; i < o.nombre_matiers; i++) // Pour chaque matiere dans le objet
		for(j = 0; j < stock->size(); j++) // Nous irons chercher la matiere dans le stock
			if(o.matieres.at(i).nom == stock->at(j).nom) // Si le nom de la matiere est le meme que de le stock
				if(stock->at(j).poids < o.matieres.at(i).poids) // Nous irons verifier se nous pouvons retirer la matiere
					return false; // Si arrive ici, alors, nous ne pouvons pas retirer
	// Si non, alors, nous pouvons retirer	
	return true;
}



void add_livraisons_to_stock(ensMatieres *stock, const ensLivraison *em, const int date)
{
	unsigned int i;
	for(i = 0; i < em->size(); i++) // Ici nous faisons la adiction des livraisons   
		if(em->at(i).date <= date) // Seulement si la date est plus petit que la date de le objet
			put_in_stock(stock, em->at(i));

}
void RetirerObjetDuStock(ensMatieres *stock, const ensObjets *vectObj, const objet o)
{
	unsigned int i, k;
	int j;
	for(i = 0; i < vectObj->size(); i++)
		if(vectObj->at(i).date <= o.date)
			for(j = 0; j < vectObj->at(i).nombre_matiers; j++) // Pour chaque matiere dans le objet
				for(k = 0; k < stock->size(); k++) // Nous irons chercher la matiere dans le stock
					if(vectObj->at(i).matieres.at(j).nom == stock->at(k).nom) // Si le nom de la matiere est le meme que de le stock
						stock->at(k).poids -= vectObj->at(i).matieres.at(j).poids;
}
void miseajour_stock(ensMatieres *stock, const ensLivraison *em, const ensObjets *vectObj, const objet o, const int date)
{
	//cout << "\t _1" << endl;
	add_livraisons_to_stock(stock, em, date);
	//cout << "\t _2" << endl;
	RetirerObjetDuStock(stock, vectObj, o);
	//cout << "\t _3" << endl;
}




int calculRetardUnObjet (const ensLivraison *em, const ensObjets *vectObj, objet ob)
{
	unsigned int k, date;
	int j, penalite = 0;
	ensMatieres stock;
	//while(il_y_a_matiere_dans_stock(&stock, ob))
	//{
	//	ob.date++;
	//	penalite += 1000;
	//}
	date = ob.date;
	Initialisation_matieres(&stock); // Ici nous faisons
	miseajour_stock (&stock, em, vectObj, ob, date);
	for (j=0; j< ob.nombre_matiers; j++)// Pour chaque materier dans le object selectionee
	{
		//cout << "\t a" << j << endl;
		for (k=0; k< stock.size(); k++) //Pour chaque matiere dans le vecteur de stock 
		{
			if ( ob.matieres[j].nom == stock.at(k).nom)// Quand le matiere est le meme que les matieres d'objet 
			{
				while (ob.matieres[j].poids > stock.at(k).poids)// Tant que il n' y a pas le matiere suffisant pour produire 
				{ 
					date += 1;
					//cout << "Somou!" << endl;
					penalite = penalite + 1000*ob.nombre;
					Initialisation_matieres(&stock);
					miseajour_stock (&stock, em, vectObj, ob, date); 
				}

			}	
		} 

	}
	return penalite;
}

int calculRetard (const ensLivraison *em, const ensObjets *vectObj)
{
	unsigned int i;
	int penalites = 0;  


	for (i= 0; i< vectObj->size(); i++) // Pour chaque objet
	{
		//cout << i << "/" << vectObj->size() << endl;
		penalites += calculRetardUnObjet(em, vectObj, vectObj->at(i));
	}
	return penalites;  
}

