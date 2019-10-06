all: compila clean clear executa

compila: entierlong.o lit_ecrit.o operations.o utilitaires.o main.o
	g++ lit_ecrit.o operations.o utilitaires.o main.o -o executavel

entierlong.o:


lit_ecrit.o:
	g++ -c lit_ecrit.cpp -Wall

operations.o:
	g++ -c operations.cpp -Wall

utilitaires.o:
	g++ -c utilitaires.cpp -Wall

main.o:
	g++ -c main.cpp -Wall

clean:
	rm *.o

clear:
	clear

executa:
	./executavel
