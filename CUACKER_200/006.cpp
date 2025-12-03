#include "006.h"
#include "005.h" // incluimos diccionarioCuacs
#include <iostream>

using namespace std;

// IMPLEMENTACION DE TABLA HASH
TablaHash::TablaHash() {
    nElem = 0;
}

 //Funcion de dispersion1 

int TablaHash::funcionHash(string clave) {
   unsigned int h = 5381; // Valor inicial y hacemos que no sea un numero negativo 
     for (int i = 0; i < clave.length(); i++) { // Recorremos cada caracter
         h = (h * 33) + clave[i]; // Actualizamos el hash con el caracter actual
     }
     return h % M; // Retornamos el indice dentro del tamaño de la tabla
}
/*

int TablaHash::funcionHash(string clave) {
    unsigned int h = 5381;
    int aux=0;
    for (int i = 0; i < clave.length(); i++) {
        aux=aux+clave[i];
    } 
    return aux % M; 
}
    
int TablaHash::funcionHash(string clave) {
    unsigned int h = 5381;
    int aux=0;
    for (int i = 0; i < clave.length(); i++) {
        aux=aux+clave[i];
    } 
    return aux % M; 
}


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

*/
// En vez de recorrer toda la tabla buscamos directamente la lista que corresponde al usuario
// para ello insertamos un indice calculado gracias a la funcion de dispersion. 
void TablaHash::insertar(Cuac nuevo) {
    string usuario = nuevo.getUsuario(); // Obtener el nombre de usuario del cuac como indica en el enunciado
    int indice = funcionHash(usuario); // Calcular el indice usando la funcion hash
    list<Cuac>::iterator itLista = tabla[indice].begin();
    // Buscamos la posicion correcta cronologicamente
    while (itLista != tabla[indice].end() && nuevo.es_anterior(*itLista)) {
        itLista++;
    }
    tabla[indice].insert(itLista, nuevo);
    nElem++;
}

void TablaHash::consultar(string nombre) {
    cout << "follow " << nombre << endl;
    int indice = funcionHash(nombre); // Calcular el indice usando la funcion hash
    int count = 0;
    list<Cuac>::iterator it;
    for (it = tabla[indice].begin(); it != tabla[indice].end(); it++) {
        if (it->getUsuario() == nombre) {
            count++;
            cout << count <<". ";
            it->escribir();
        }
    }
    cout << "Total: " << count << " cuac" << endl;
}

// IMPLEMENTACION DE DICCIONARIO CUACS
// 
DiccionarioCuacs::DiccionarioCuacs() {
}

void DiccionarioCuacs::last(int N) {
    // Vacío 
}

void DiccionarioCuacs::date(Fecha f1, Fecha f2) {
    // Vacío 
}