gol: ca.o main.o
	cc -o gol ca.o main.o
ca.o: ca.c ca.h
	cc -c ca.c
main.o: main.c ca.h
	cc -c main.c
