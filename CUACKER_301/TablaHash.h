#ifndef TABLAHASH_H
#define TABLAHASH_H 

#include "Cuac.h" // Incluimos la clase Cuac
#include <list>
#include <string>
#include <vector>

using namespace std;

// DEFINICION DE LA TABLA HASH CON LISTAS
class TablaHash {
    private:
        static const int M = 5381; // Tamaño de la tabla (numero primo)
        list<Cuac> tabla[M]; // Tabla de listas de cuacs
        int nElem; // Numero de elementos en la tabla
        int funcionHash(string clave);

    public:
        TablaHash();
        Cuac* insertar(Cuac nuevo); //REVISAR
        void consultar(string nombre); 
        int numElem() { return nElem; }
};

#endif