all: compila clean clear executa

compila: constantes.o affichage.o proba.o main.o fourmi.o
	g++ fourmi.o affichage.o proba.o main.o -o executavel -L/usr/X11R6/lib -lX11

constantes.o:

fourmi.o:
	g++ -c fourmi.cpp -Wall

affichage.o:
	g++ -c affichage.cpp -Wall -L/usr/X11R6/lib -lX11

proba.o:
	g++ -c proba.cpp -Wall

main.o:
	g++ -c main.cpp -Wall -L/usr/X11R6/lib -lX11

clean:
	rm *.o

clear:
	clear

executa:
	./executavel
