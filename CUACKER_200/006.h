#ifndef DICCIONARIO_CUACS_H
#define DICCIONARIO_CUACS_H

#include "004.h"
#include "200.h"  // incluimos TablaHash 
#include <string> 
using namespace std; 

class DiccionarioCuacs {
   private:
        TablaHash tabla; 
   public:
        DiccionarioCuacs();
        void insertar(Cuac nuevo);
        void follow(string nombre);
        void last(int N);
        void date(Fecha f1, Fecha f2);
        int numElem();
};

#endif