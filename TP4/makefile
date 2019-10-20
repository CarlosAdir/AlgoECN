all: compila clean clear executa

c: clean compila

compila: type_def utilitaire_generation utilitaires repertoire main 
	g++ utilitaires.o utilitaire_generation.o repertoire.o TP4.o -o executavel -L/usr/X11R6/lib -lX11

type_def:

utilitaires: type_def utilitaire_generation
	g++ -c utilitaires.cpp -Wall

utilitaire_generation: type_def
	g++ -c utilitaire_generation.cpp -Wall

repertoire: type_def utilitaires utilitaire_generation
	g++ -c repertoire.cpp -Wall

main: type_def utilitaires utilitaire_generation repertoire
	g++ -c TP4.cpp -Wall


clean:
	rm *.o

clear:
	clear

executa:
	./executavel
