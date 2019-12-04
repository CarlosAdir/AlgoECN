all: compila limpa executa

compila: fonctions main
	g++ fonctions.o main.o -o executavel

fonctions:
	g++ -c fonctions.cpp

main: fonctions
	g++ -c main.cpp


limpa:
	rm *.o

executa:
	./executavel > output.txt