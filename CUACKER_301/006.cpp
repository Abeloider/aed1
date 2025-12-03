#include "006.h"
#include <iostream>

using namespace std;

TablaHash::TablaHash() {
    nElem = 0;
}

 //Funcion de dispersion1 
 int TablaHash::funcionHash(string clave) {
   unsigned int h = 5381; // Valor inicial y que no sea negativo
     for (int i = 0; i < clave.length(); i++) { // Recorremos carácteres
         h = (h * 33) + clave[i]; // Actualizamos
     }
     return h % M; // Retornamos el indice dentro del tamaño de la tabla
}
/*
// muy mala
 int TablaHash::funcionHash(string clave) {
     unsigned int h = 5381; 
     for (int i = 0; i < clave.length(); i++) {
         h = clave[i];
     } 
     return h % M; 
 }

 // peor aun
 int TablaHash::funcionHash(string clave) {
     unsigned int h = 13; 
     for (int i = 0; i < clave.length(); i++) {
         h = h;
     } 
     return h % M; 
 } 

// suma 
int TablaHash:::funcionHash(string clave) {
    unsigned int h = 5381;
    for (int i = 0; i < clave.length(); i++) {
        h = clave[i] + M;
    } 
    return h % M; 
}

*/

// insertar un cuac en la tabla hash y devolver un puntero al cuac insertado
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

// consultar los cuacs de un usuario
void TablaHash::consultar(string nombre) {
    cout << "follow " << nombre << endl; 
    int indice = funcionHash(nombre); // Calcular el indice usando la funcion hash
    int count = 0;
    list<Cuac>::iterator it;
    for (it = tabla[indice].begin(); it != tabla[indice].end(); it++) {
        if (it->getUsuario() == nombre) {
            count++;
            cout << count << ". ";
            it->escribir(); // Imprimimos el cuac
        }
    }
    cout << "Total: " << count << " cuac" << endl;
}
