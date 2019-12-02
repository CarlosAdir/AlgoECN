all: programa clean clear executa

programa: main.o
	g++ main.o -o executavel

main.o:
	g++ -c main.cpp -Wall

clean:
	rm *.o

clear:
	clear

executa:
	./executavel
