#ifndef DICCIONARIO_CUACS_H
#define DICCIONARIO_CUACS_H

#include "TablaHash.h"
#include "Arbol.h"

// DEFINICION DEL DICCIONARIO DE CUACS AVL CON LA TABLA HASH DEL EJERCICIO 200
class DiccionarioCuacs {
   private:
        TablaHash tabla;
        ArbolAVL arbol;
   public:
        DiccionarioCuacs() {}
        void insertar (Cuac nuevo);
        void follow (string nombre);
        int numElem ();
        void last (int N);
        void date (Fecha f1, Fecha f2);
};

#endif

