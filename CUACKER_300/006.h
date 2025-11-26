#ifndef DICCIONARIO_CUACS_H
#define DICCIONARIO_CUACS_H

#include "004.h" 
#include "300.h" // Incluimos el Arbol AVL
#include <list>
#include <string>
#include <vector>

using namespace std;


// DEFINICION DE LA TABLA HASH CON LISTAS
class TablaHash {
    private:
        static const int M = 5281; // Tamaño de la tabla (numero primo)
        list<Cuac> tabla[M]; // Tabla de listas de cuacs
        int nElem; // Numero de elementos en la tabla
        int funcionHash(string clave);

    public:
        TablaHash();
        Cuac* insertar(Cuac nuevo); //REVISAR
        void consultar(string nombre); 
        int numElem() { return nElem; }
};

// DEFINICION DEL DICCIONARIO DE CUACS AVL CON LA TABLA HASH DEL EJERCICIO 200

class DiccionarioCuacs {
   private:
        TablaHash tabla;
        ArbolAVL arbol; 
   public:
        DiccionarioCuacs() {} 
        void insertar (Cuac nuevo) { 
            Cuac *ref = tabla.insertar(nuevo); 
            arbol.insertar(ref);

        }
        void follow (string nombre) { tabla.consultar(nombre); }
        int numElem () { return tabla.numElem(); }
        void last (int N) { arbol.last(N); } 
        void date (Fecha f1, Fecha f2) { arbol.date(f1, f2); }
};

#endif