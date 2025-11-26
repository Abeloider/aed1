#include "300.h"
#include <iostream>

using namespace std;
// IMPLEMETACION DE NODO AVL

NodoAVL::NodoAVL(Fecha f, Cuac* c) {
    fecha = f;
    lista.push_back(c); // Insertamos el puntero en la lista
    izq = NULL;
    der = NULL;
    altura = 0;
}

NodoAVL::~NodoAVL() {
   delete izq; // hijo izquierdo
   delete der; // hijo derecho
}


// tenemos que insertar el cuac en la lista de forma ordenada por texto y usuario 
void NodoAVL::insertarOrdenado(Cuac* c) {
    list<Cuac*>::iterator it = lista.begin();
    while (it != lista.end()) { // Recorremos la lista
        if (c->getTexto() < (*it)->getTexto()) { // Comparamos por texto
            lista.insert(it, c); // Insertamos antes de it
            return;
        }
        else if (c->getTexto() == (*it)->getTexto()) { // Si los textos son iguales
            if (c->getUsuario() < (*it)->getUsuario()) {//En caso de que los textos sean iguales comparamos por usuario
                lista.insert(it, c);  // Insertamos antes de it
                return;
            }
        }
        it++;
    }
    lista.push_back(c); // Si es el mayor, lo añadimos al final
}

// IMPLEMENTACION DE ARBOL AVL
ArbolAVL::ArbolAVL() {
    raiz = NULL;
}

ArbolAVL::~ArbolAVL() {
    delete raiz;
}

// devolvemos la altura de un nodo de forma segura
int ArbolAVL::altura(NodoAVL* nodo) {
    if (nodo == NULL) return -1;
    return nodo->altura;
}
// ROTACIONES PARA BALANCEO

// Rotacion Simple Izquierda (Caso II)
void ArbolAVL::RSI(NodoAVL* &A) {   
    NodoAVL* B = A->izq;
    A->izq = B->der;
    B->der = A;
    // Actualizar alturas
    A->altura = 1 + max(altura(A->izq), altura(A->der));
    B->altura = 1 + max(altura(B->izq), A->altura);
    A = B; // A ahora apunta a la nueva raiz del subarbol
}

// Rotacion Simple Derecha (Caso DD)
void ArbolAVL::RSD(NodoAVL* &A) {
    NodoAVL* B = A->der;
    A->der = B->izq;
    B->izq = A;
    // Actualizar alturas
    A->altura = 1 + max(altura(A->izq), altura(A->der));
    B->altura = 1 + max(altura(B->der), A->altura);
    A = B;
}
// Rotacion Doble Izquierda (Caso ID)
void ArbolAVL::RDI(NodoAVL* &A) {
    RSD(A->izq); // Convertimos en caso II
    RSI(A);      // Resolvemos caso II
}

// Rotacion Doble Derecha (Caso DI)
void ArbolAVL::RDD(NodoAVL* &A) {
    RSI(A->der); // Convertimos en caso DD
    RSD(A);      // Resolvemos caso DD
}

void ArbolAVL::insertar(Cuac* ref) {
    insertar(raiz, ref); // Llamada recursiva pasando por la raiz
}

// 3.3.3 OPERACION DE INSERCION EN AVL
void ArbolAVL::insertar(NodoAVL* &A, Cuac* x) {
    Fecha f = x->getFecha();
    if (A == NULL) {
        A = new NodoAVL(f, x);
    }   
    // Si la fecha es menor insertamos por la izquierda
    else if (f.esMenor(A->fecha)) { 
        insertar(A->izq, x);
        if (altura(A->izq) - altura(A->der) > 1) {
            if (x->getFecha().esMenor(A->izq->fecha))
                RSI(A);
            else
                RDI(A);
        }
        else {
            A->altura = 1 + max(altura(A->izq), altura(A->der));
        }
    }
    // Si la fecha es mayor insertamos por la derecha
    else if (A->fecha.esMenor(f)){ 
        insertar(A->der, x);
        if (altura(A->der) - altura(A->izq) > 1) {
            if (!x->getFecha().esMenor(A->der->fecha)) 
                RSD(A); // Caso Der-Der
            else
                RDD(A); // Caso Der-Izq
        }
        else {
            A->altura = 1 + max(altura(A->izq), altura(A->der));
        }
    }
    else {
        A->insertarOrdenado(x); // Misma fecha, insertamos en la lista ordenadamente
    }
}

// tenemos que buscar los cuacs mas nuevos por lo que tenemos que hacer un recorrido inverso
void ArbolAVL::last(int N) {
    int count = 0;
    cout << "last " << N << endl;
    recorridoLast(raiz, N, count); // recorrido inverso
    cout << "Total: " << count << " cuac" << endl;

}

void ArbolAVL::recorridoLast(NodoAVL* nodo, int &n, int &count) { // parametros nodo, n cuacs a imprimir, count cuacs impresos
    if (nodo == NULL || count >= n) return; // Caso base
    recorridoLast(nodo->der, n, count); // Primero recorremos el subarbol derecho (mas nuevos)
    if (count < n) { // Si no hemos impreso suficientes cuacs
        list<Cuac*>::iterator it; 
        for (it = nodo->lista.begin(); it != nodo->lista.end(); ++it) { // recorremos la lista de cuacs
            if (count < n) { // Si no hemos impreso suficientes cuacs
                count++; // Incrementamos el contador de cuacs impresos
                cout << count << ". "; // Imprimimos el número de cuac
                (*it)->escribir(); // Imprimimos el cuac
            }
        }
    }
    recorridoLast(nodo->izq, n, count); // alfinal recorremos el subarbol izquierdo (mas viejos)
}

void ArbolAVL::date(Fecha f1, Fecha f2) {
    // de momento no hacemos nada en el date ya que es parte del 301
}