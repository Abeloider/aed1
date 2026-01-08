a.out: main.o Interprete.o Diccionario.o TablaHash.o Arbol.o Cuac.o Fecha.o Conversiones.o 
	g++ main.o Interprete.o Diccionario.o TablaHash.o Arbol.o Cuac.o Fecha.o Conversiones.o -o a.out
# MAIN 
main.o: main.cpp Interprete.h
	g++ -c main.cpp
# INTÉRPRETE 
Interprete.o: Interprete.cpp Interprete.h Diccionario.h
	g++ -c Interprete.cpp
# DICCIONARIO 
Diccionario.o: Diccionario.cpp Diccionario.h TablaHash.h Arbol.h
	g++ -c Diccionario.cpp
#TABLA HASH 
TablaHash.o: TablaHash.cpp TablaHash.h Cuac.h
	g++ -c TablaHash.cpp
# ÁRBOLES AVL 
Arbol.o: Arbol.cpp Arbol.h Cuac.h
	g++ -c Arbol.cpp
# CUACS
Cuac.o: Cuac.cpp Cuac.h Fecha.h Conversiones.h
	g++ -c Cuac.cpp
# FECHAS
Fecha.o: Fecha.cpp Fecha.h
	g++ -c Fecha.cpp
# CONVERSIONES 
Conversiones.o: Conversiones.cpp Conversiones.h
	g++ -c Conversiones.cpp
