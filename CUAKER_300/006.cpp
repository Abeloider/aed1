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
   unsigned int h = 13; // Valor inicial y hacemos que no sea un numero negativo 
     for (int i = 0; i < clave.length(); i++) { // Recorremos cada caracter
         h = (h * 64) + clave[i]; // Actualizamos el hash con el caracter actual
     }
     return h % M; // Retornamos el indice dentro del tamaño de la tabla
}

/*

 int TablaHash::funcionHash(string clave) {
     unsigned int h = 10; //no es numero primo
     for (int i = 0; i < clave.length(); i++) {
         h = clave[i] + h;
     } 
     return h % M; 
 }

int TablaHash:::funcionHash(string clave) {
    unsigned int h = 5003;
    for (int i = 0; i < clave.length(); i++) {
        h = clave[i] + M;
    } 
    return h % M; 
}
*/
// En vez de recorrer toda la tabla buscamos directamente en la lista correspondiente al usuario
// para ello insertamos el un indice que se calcula gracias a la funcion de dispersion. 
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
DiccionarioCuacs::DiccionarioCuacs() {
}

void DiccionarioCuacs::last(int N) {
    // Vacío 
}

void DiccionarioCuacs::date(Fecha f1, Fecha f2) {
    // Vacío 
}