#include "200.h"
using namespace std;

TablaHash::TablaHash() {
    M=100;
    nElem=0;
    t=new list<Cuac>[M];
}

TablaHash::~TablaHash() {
    delete[] t;
}

TablaHash::insertar(Cuac nuevo){
    string usuario=nuevo.usuario();
    int indice=hash(usuario);
}