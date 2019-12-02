
#include "entierlong.h"
#include "lit_ecrit.h"
#include "operations.h"
#include "utilitaires.h"
#include <iostream>







int main()
{
	int n1, n2;
	EntierLong k1, k2;

	EntierLong e; 
	int stand;  
	bool r;
	EntierLong a,w; 

	// std:: cout << "Write your number:" << std::endl; 
	// std:: cin >> stand; 
	// e= convertion_sl (stand);
	//AfficheEntierLong (e);  

	//r= compare (e,e); 
	// r= menor_abs (e,e);
	// if(r)
	// {
	// 	std::cout << "True";
	// }
	// else
	// {
	// 	std::cout << "False";
	// }
	while(1)
	{
		std::cout << "Digite dois numeros para somar: ";
		std::cin >> n1 >> n2;
		k1 = convertion_sl(n1);
		k2 = convertion_sl(n2);
		std::cout << "Soma: ";
		AfficheEntierLong(add_qq(k1, k2));
	}



	return 0;


}