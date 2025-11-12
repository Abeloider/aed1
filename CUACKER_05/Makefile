a.out: 001_002.o 003.o 004.o 005.o main.o
	g++ 001_002.o 003.o 004.o 005.o main.o
# ejecutamos las conversiones de texto a num y de num a text
001_002.o: 001_002.cpp 001_002.h
	g++ -c 001_002.cpp

# FECHAS
003.o: 003.cpp 003.h
	g++ -c 003.cpp

# CUACS
004.o: 004.cpp 004.h 003.h 001_002.h
	g++ -c 004.cpp

# INTERPRETE DE COMANDOS
005.o: 005.cpp 005.h 004.h 003.h 001_002.h
	g++ -c 005.cpp

#MAIN 
main.o: main.cpp 005.h 004.h 003.h 001_002.h
	g++ -c main.cpp