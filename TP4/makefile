all: compila clean clear executa

compila: type_def utilitaire_generation utilitaires main 
	g++ utilitaires.o utilitaire_generation.o TP4.o -o executavel -L/usr/X11R6/lib -lX11

type_def:

utilitaires: type_def utilitaire_generation
	g++ -c utilitaires.cpp -Wall

utilitaire_generation: type_def
	g++ -c utilitaire_generation.cpp -Wall

main: type_def utilitaires utilitaire_generation
	g++ -c TP4.cpp -Wall


clean:
	rm *.o

clear:
	clear

executa:
	./executavel
