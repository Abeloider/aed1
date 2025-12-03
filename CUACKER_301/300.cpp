#include "300.h"
#include <iostream>

using namespace std;
// IMPLEMETACION DE NODO AVL

// constructor
NodoAVL::NodoAVL(Fecha f, Cuac* c) {
    fecha = f;
    lista.push_back(c); // Insertamos el puntero en la lista
    izq = NULL;
    der = NULL;
    altura = 0;
}

// destructor
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
// constructor
ArbolAVL::ArbolAVL() {
    raiz = NULL;
}
// Destructor
ArbolAVL::~ArbolAVL() {
    delete raiz;
}

// devolvemos la altura de un nodo
int ArbolAVL::altura(NodoAVL* nodo) {
    if (nodo == NULL) return -1;
    return nodo->altura; 
}
// ROTACIONES PARA BALANCEO

// Rotacion Simple Izquierda (Caso II)
void ArbolAVL::RSI(NodoAVL* &A) {   
    NodoAVL* B = A->izq;
    A->izq = B->der; // Subarbol derecho de B pasa a ser hijo izquierdo de A
    B->der = A; // A pasa a ser hijo derecho de B
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
// inserta un cuac en el arbol AVL
void ArbolAVL::insertar(NodoAVL* &A, Cuac* x) {
    Fecha f = x->getFecha(); // Obtenemos la fecha del cuac
    if (A == NULL) {
        A = new NodoAVL(f, x); // Creamos un nuevo nodo si A es NULL
    }   
    // Si la fecha es anterior insertamos por la izquierda
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
    // Si la fecha es posterior insertamos por la derecha
    else if (A->fecha.esMenor(f)){ 
        insertar(A->der, x);
        if (altura(A->der) - altura(A->izq) > 1) {
            if (!x->getFecha().esMenor(A->der->fecha)) 
                RSD(A); 
            else
                RDD(A); 
        }
        else {
            A->altura = 1 + max(altura(A->izq), altura(A->der));  
        }
    }
    else { 
        A->insertarOrdenado(x); // Misma fecha, insertamos en la lista
    }
}

// tenemos que buscar los cuacs mas nuevos por lo que tenemos que hacer un recorrido inverso
void ArbolAVL::last(int N) {
    int count = 0;
    cout << "last " << N << endl;
    recorridoLast(raiz, N, count); // llamamos a la funcion recorridoLast
    cout << "Total: " << count << " cuac" << endl;

}

// hacemos el recorrido inverso
void ArbolAVL::recorridoLast(NodoAVL* nodo, int &n, int &count) { // parametros nodo, n cuacs a imprimir, count cuacs impresos
    if (nodo == NULL || count >= n) return; // Caso base
    // Primero recorremos el subarbol derecho (mas nuevos)
    recorridoLast(nodo->der, n, count); 
    if (count < n) { // Si no hemos impreso suficientes cuacs
        list<Cuac*>::iterator it; 
        // recorremos la lista de cuacs
        for (it = nodo->lista.begin(); it != nodo->lista.end(); ++it) { 
            if (count < n) { // Si no hemos impreso suficientes cuacs
                count++;
                cout << count << ". ";
                (*it)->escribir(); // Imprimimos el cuac
            }
        }
    }
    // Finalmente recorremos el subarbol izquierdo (mas viejos)
    recorridoLast(nodo->izq, n, count); 
}


// creamos la funcion date y llamamos al recorrido date
void ArbolAVL::date(Fecha f1, Fecha f2) {
    int count = 0;
    cout << "date "; 
    f1.escribir(); 
    cout << " "; 
    f2.escribir(); 
    cout << endl;
    recorridoDate(raiz, f1, f2, count);
    cout << "Total: " << count << " cuac" << endl;
}

// hacemos el recorrido de date
//f1 anterior f2 posterior
void ArbolAVL::recorridoDate(NodoAVL* nodo, Fecha f1, Fecha f2, int &count) {
    if (nodo == NULL) return; // caso base
    // Si el nodo es menor que f2, exploramos la rama derecha
    if (nodo->fecha.esMenor(f2)) {
        recorridoDate(nodo->der, f1, f2, count);
    }
    // si el nodo esta entre f1 y f2, lo procesamos 
    if (!nodo->fecha.esMenor(f1) && !f2.esMenor(nodo->fecha)) { // nodo >= f1 && nodo <= f2
        list<Cuac*>::iterator it;
        // Recorremos la lista de cuacs en el nodo
        for (it = nodo->lista.begin(); it != nodo->lista.end(); ++it) {
            count++;
            cout << count << ". ";
            (*it)->escribir(); 
        }
    }
    // Si el nodo es mayor que f1, exploramos la rama izquierda
    if (f1.esMenor(nodo->fecha)) {
        recorridoDate(nodo->izq, f1, f2, count);  
    }
}