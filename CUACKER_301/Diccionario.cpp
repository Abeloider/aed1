#include <iostream>
#include "Diccionario.h"

using namespace std;

void DiccionarioCuacs::insertar(Cuac nuevo) {
    Cuac *ref = tabla.insertar(nuevo); 
     arbol.insertar(ref);
}

void DiccionarioCuacs::follow(string nombre) {
    tabla.consultar(nombre);
}

int DiccionarioCuacs::numElem() {
    return tabla.numElem();
}

void DiccionarioCuacs::last(int N) {
    arbol.last(N);
}
void DiccionarioCuacs::date(Fecha f1, Fecha f2) {
    arbol.date(f1, f2);
}
