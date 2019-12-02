all: compila clean clear executa

c: clean compila

compila: types tris utils main 
	g++ main.o utils.o tris.o -o executavel

types:

utils: types tris
	g++ -c utils.cpp -Wall

tris: types
	g++ -c tris.cpp -Wall

main: types utils 
	g++ -c main.cpp -Wall


clean:
	rm *.o

clear:
	clear

executa:
	./executavel
