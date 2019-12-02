#include "operations.h"

EntierLong add (EntierLong entier1, EntierLong entier2)
{
	EntierLong entier3;
	int i; 

	for(i=0; i<MAXCHIFFRES; i++)
	{
		entier3.Chiffres [i]= 0;
	}

	if (entier1.Negatif == entier2.Negatif)
	{
		for (i= 0; i < MAXCHIFFRES; i++)
		{

			if (entier1.Chiffres[i] + entier2.Chiffres[i] < 10)
			{
				entier3.Chiffres [i] = entier3.Chiffres [i]+ entier1.Chiffres[i] + entier2.Chiffres[i];
			}
			else
			{
				entier3.Chiffres [i] = entier3.Chiffres [i]+ entier1.Chiffres[i] + entier2.Chiffres[i] -10; 
				entier3.Chiffres [i+1] ++; 
			}
		}
	}
	else
	{
		//std:: cout << "Signals sont differents";
	}
	entier3.Negatif = entier1.Negatif;
	return entier3; 
}

EntierLong sub (EntierLong entier1, EntierLong entier2)
{
	bool teste; 
	EntierLong entier3;
	int i;
	for(i=0; i<MAXCHIFFRES; i++)
	{
		entier3.Chiffres [i]= 0;
		
	}


	if (entier1.Negatif == entier2.Negatif)
	{
		teste = menor_abs (entier2, entier1); 
		if (teste == true)
		{
			for (i= 0; i < MAXCHIFFRES-1; i++)
			{
				entier3.Chiffres [i] = entier3.Chiffres[i] + entier1.Chiffres[i] - entier2.Chiffres[i];
					if (entier3.Chiffres [i] < 0)
				{
					entier3.Chiffres [i] += 10;
					entier3.Chiffres [i+1] --;
				}
			}
		}
	}
	entier3.Negatif = entier1.Negatif;

	
	return entier3; 

}

EntierLong add_qq (EntierLong entier1, EntierLong entier2)
{
	EntierLong a;
	if (entier1.Negatif == entier2.Negatif)
	{
		return add (entier1, entier2);
	}
	else 
	{
		if (menor_abs (entier1, entier2))
		{
			entier1.Negatif = !entier1.Negatif;
			a = sub (entier2, entier1);
			return a; 
		}
		else 
		{
			entier2.Negatif = !entier2.Negatif;
			a= sub (entier1, entier2);
			return a;
		}

	}
 
}

EntierLong sub_qq (EntierLong entier1, EntierLong entier2)
{
	EntierLong a; 
	if (entier1.Negatif == entier2.Negatif)
	{
		if (menor_abs (entier1, entier2))
		{
			a= sub (entier2, entier1);
			a.Negatif = entier2.Negatif; 
			return a; 
		}
		else 
		{
			a= sub (entier1, entier2);
			a.Negatif = entier1.Negatif; 
			return a;
		}
	}
	else
	{
		entier2.Negatif =! entier2.Negatif;
		return (add(entier1, entier2)); 

	}

}