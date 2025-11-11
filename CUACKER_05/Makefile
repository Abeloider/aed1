# Makefile para el programa de cuacs
a.out: 003.o 004.o main.o
	g++ 003.o 004.o main.o

# ejecutamos las fechas 
003.o: 003.cpp 003.h
	g++ -c 003.cpp

# ejecutamos los cuacs 
004.o: 004.cpp 004.h 003.h 001_002.h
	g++ -c 004.cpp

# vemos si 
main.o: main.cpp 004.h 003.h 001_002.h
	g++ -c main.cpp

