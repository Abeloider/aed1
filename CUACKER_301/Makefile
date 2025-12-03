a.out: main.o 005.o 006.o 300.o 004.o 003.o 001_002.o
	g++ main.o 005.o 006.o 300.o 004.o 003.o 001_002.o
# MAIN (Llama al intérprete)
main.o: main.cpp 005.h
	g++ -c main.cpp
# INTÉRPRETE (Llama al diccionario)
005.o: 005.cpp 005.h 006.h 004.h
	g++ -c 005.cpp
# DICCIONARIO (Usa TablaHash y Árbol)
006.o: 006.cpp 006.h 300.h 004.h
	g++ -c 006.cpp
# ÁRBOLES AVL (Usa Cuac y Fecha)
300.o: 300.cpp 300.h 004.h
	g++ -c 300.cpp
# CUACS (Usa Fecha y Conversiones)
004.o: 004.cpp 004.h 003.h 001_002.h
	g++ -c 004.cpp
# FECHAS
003.o: 003.cpp 003.h
	g++ -c 003.cpp
# CONVERSIONES
001_002.o: 001_002.cpp 001_002.h
	g++ -c 001_002.cpp
