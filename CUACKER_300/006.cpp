#include "006.h"
#include "005.h" 
#include <iostream>

using namespace std;

TablaHash::TablaHash() {
    nElem = 0;
}

int TablaHash::funcionHash(string clave) {
    unsigned long h = 13; 
    for (int i = 0; i < clave.length(); i++) {
        h = (h * 33) + clave[i];
    }
    return h % M; 
}
// tenemos que modificar el metodo insertar para que el arbol almacene punteros a loc cuacs de la tabla
// por lo que ahora el metodo insertar devuelve un puntero al cuac insertado 

Cuac* TablaHash::insertar(Cuac nuevo) {
    string usuario = nuevo.getUsuario(); // Obtener el nombre de usuario del cuac como indica en el enunciado
    int indice = funcionHash(usuario);  // Calcular el indice usando la funcion hash
    list<Cuac>::iterator itLista = tabla[indice].begin();
    // Buscamos la posicion correcta cronologicamente
    while (itLista != tabla[indice].end() && nuevo.es_anterior(*itLista)) {
        itLista++;
    }
    // Insertamos y obtenemos el iterador al nuevo elemento
    list<Cuac>::iterator itNuevo = tabla[indice].insert(itLista, nuevo);
    nElem++;
    return &(*itNuevo);
}

void TablaHash::consultar(string nombre) {
    cout << "follow " << nombre << endl;
    int indice = funcionHash(nombre); // Calcular el indice usando la funcion hash
    int count = 0;
    list<Cuac>::iterator it;
    for (it = tabla[indice].begin(); it != tabla[indice].end(); it++) {
        if (it->getUsuario() == nombre) {
            count++;
            cout << count << ". ";
            it->escribir();
        }
    }
    cout << "Total: " << count << " cuac" << endl;
}
