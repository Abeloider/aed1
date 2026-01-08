#ifndef ARBOL_H
#define ARBOL_H
#include <list>
#include <algorithm> // Para max
#include "Cuac.h" // Cuac

using namespace std;

class NodoAVL {
    friend class ArbolAVL; // El arbol puede acceder a los privados del nodo
    private:
        Fecha fecha;           // Clave del arbol
        list<Cuac*> lista;     // Valor: Lista de punteros a los cuacs con esa fecha
        NodoAVL *izq;          // Hijo izquierdo
        NodoAVL *der;          // Hijo derecho
        int altura;            // para el balanceo

    public:
        NodoAVL(Fecha f, Cuac* c);
        ~NodoAVL(); // Destructor para liberar memoria recursivamente
        void insertarOrdenado(Cuac* c);
};

// Clase Arbol AVL (Implementacion de Last y Date)
class ArbolAVL {
    private:
        NodoAVL *raiz;

        // Metodos internos recursivos
        int altura(NodoAVL* nodo); // Altura segura 
        void insertar(NodoAVL* &nodo, Cuac* ref);  // Insercion recursiva
        
        // Rotaciones para balanceo 
        void RSI(NodoAVL* &nodo); // Rotacion Simple Izquierda II
        void RSD(NodoAVL* &nodo); // Rotacion Simple Derecha DD
        void RDI(NodoAVL* &nodo); // Rotacion Doble Izquierda ID
        void RDD(NodoAVL* &nodo); // Rotacion Doble Derecha DI
        // Recorridos para operaciones
        void recorridoLast(NodoAVL* nodo, int &n, int &total); // Recorrido inverso para last
        void recorridoDate(NodoAVL* nodo, Fecha f1, Fecha f2, int &count); // Recorrido para date
    public:
        ArbolAVL();
        ~ArbolAVL(); 
        void insertar(Cuac* ref);
        void last(int N);
        void date(Fecha f1, Fecha f2);
};


#endif