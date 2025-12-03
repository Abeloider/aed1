#ifndef DICCIONARIO_CUACS_H
#define DICCIONARIO_CUACS_H

#include "004.h" 
#include <list>
#include <string>
#include <vector>

using namespace std;

class TablaHash {
    private:
        static const int M = 5381; // definimos el tamaño de la tabla hash
        // Usamos dispersion abierta
        // Cada entrada de la tabla es una lista de Cuacs
        list<Cuac> tabla[M]; 
        int nElem;
        // Funcion interna para calcular el indice
        int funcionHash(string clave);
    public:
        TablaHash();
        void insertar(Cuac nuevo);
        void consultar(string nombre); 
        int numElem() { return nElem; }
};

// Clase DiccionarioCuacs
class DiccionarioCuacs {
   private:
        TablaHash tabla;
   public:
        DiccionarioCuacs ();
        void insertar (Cuac nuevo) { tabla.insertar(nuevo); }
        void follow (string nombre) { tabla.consultar(nombre); }
        void last (int N); 
        void date (Fecha f1, Fecha f2);
     int numElem ()
        { return tabla.numElem(); }
};

#endif