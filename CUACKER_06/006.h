#ifndef DICCIONARIO_CUACS_H
#define DICCIONARIO_CUACS_H

#include "004.h" // incluimos los interprete de comandos de cuacs
#include <list> 
#include <string> 
using namespace std; 


class DiccionarioCuacs {
   private:
        list<Cuac> lista;
        int contador;
   public:
        DiccionarioCuacs ();
        void insertar (Cuac nuevo);
        void last (int N);
        void follow (string nombre);
        void date (Fecha f1, Fecha f2);
        int numElem ()
        {return contador;}
};

#endif