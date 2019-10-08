#include "utilitaires.h"


EntierLong convertion_sl(int entierstand)
{
	EntierLong n;
	int i;
	i= 0;
	int resto; 

	if (entierstand <0)
	{
		n.Negatif = true; 
		entierstand = -entierstand;
	}

	else 
	{
		n.Negatif = false; 
	}

	while (entierstand != 0)
	{
		resto = entierstand % 10;
		n.Chiffres [i]= resto;
		i ++; 
		entierstand = entierstand/10;
		//std::cout << "(" << entierstand << "," << resto << std::endl;
	}
	for(; i<MAXCHIFFRES; i++)
	{
		n.Chiffres [i]= 0;
	}
	return n;


}

bool compare (EntierLong entier1, EntierLong entier2)
{
	int i;
	if (entier1.Negatif != entier2.Negatif) 
	{
		return false; 
	}
	for (i=0; i< MAXCHIFFRES; i++)
	{
		if(entier1.Chiffres[i] != entier2.Chiffres[i])
		{
			return false;
		}
	}
	return true; 
}


bool menor_abs (EntierLong entier1, EntierLong entier2)
{
	int i; 
	for (i= MAXCHIFFRES-1; i>= 0; i--)
	{
		if (entier2.Chiffres[i] > entier1.Chiffres [i])
		{
			return true; 
		}
	}
	return false; 
}
