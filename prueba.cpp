#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "004.h"
#include <list>
#include <string>

using namespace std;


class Par {
    friend class TablaHash; 
    private: 
    string nombre;
    list<Cuac> listaCuacs;
};

class TablaHash {
    private:
        int M;//Tamaño inicial de la tabla
        int nElem;//número de elementos en la tabla
        List<Par> *T;
        int hash(string nombre)
        {
            int suma = 0;
            for (char c : nombre) {
                suma += c;
            }
            return suma % M;
        };
        
    public:
        TablaHash();
        ~TablaHash();
        void insertar(Cuac nuevo);
        void consultar(string nombre);
        int numElem() { return nElem; }
};

void insertar::TablaHash(Cuac nuevo){
    
}
#endif