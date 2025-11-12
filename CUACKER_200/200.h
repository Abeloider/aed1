#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "004.h"
#include <list>
#include <string>
using namespace std;

List<Par> T[M];

class Par {
    friend class TablaHash; 
    private: 
    string nombre;
    list<Cuac> listaCuacs;
};

class TablaHash {
    private:
        int M;
        int nElem;
        list<Cuac> t;
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

#endif