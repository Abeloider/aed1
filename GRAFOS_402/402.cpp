#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>  // Variables cin y cout
using namespace std;

#define MAX_NODOS 26

//////////////////////////////////////////////////////////////
////////////        VARIABLES GLOBALES        ////////////////
//////////////////////////////////////////////////////////////

int nnodos;                   // Numero de nodos del grafo
int naristas;                 // Numero de aristas del grafo
bool G[MAX_NODOS][MAX_NODOS]; // Matriz de adyacencia
bool visitado[MAX_NODOS];     // Marcas de nodos visitados

//////////////////////////////////////////////////////////////
////////////     FUNCIONES DEL PROGRAMA       ////////////////
//////////////////////////////////////////////////////////////

void leeGrafo (void)
// Procedimiento para leer un grafo de la entrada
{
  cin >> nnodos >> naristas; // Lectura numero de nodos y aristas
  if (nnodos<0 || nnodos>MAX_NODOS) { // Comprobacion validez
    cerr << "Numero de nodos (" << nnodos << ") no valido\n";
    exit(0);
  }
  memset(G, 0, sizeof(G)); // Inicializacion matriz de adyacencia a 0
  char c1, c2; 
  for (int i= 0; i<naristas; i++) { // Lectura de aristas
    cin >> c1 >> c2; 
    G[c1-'A'][c2-'A']= true; // Actualizacion matriz
  }
}


// Procedimiento recursivo de la busqueda primero en anchura
// primero visitamos la v 
// luego visitamos sus adyacentes
// luego los adyacentes de los adyacentes

void bpa(int v) {
    // Inicializacion cola
    int cola[MAX_NODOS]; 
    int frente = 0; 
    int final = 0;
    // Encolar primer nodo
    visitado[v] = true;
    cola[final] = v; 
    final++; 

    while (frente < final) { // Mientras NOT EsVaciaCola
        int v = cola[frente]; // FrenteCola
        frente++;
        cout << char(v + 'A');
         
        for (int w = 0; w < nnodos; w++) { // Iterador sobre adyacentes
            if (!visitado[w] && G[v][w]){
                visitado[w] = true; // Marcar nodo como visitado
                cola[final] = w; // Encolar
                final++; // Incrementar final
            }
        }
    }
}

void busquedaPA() {
    memset(visitado, 0, sizeof(visitado)); // BorraMarcas
    for (int v = 0; v < nnodos; v++) {
        if (!visitado[v]) {
            bpa(v); // Llamada a bpa
        }
    }
    cout << endl;
}

//////////////////////////////////////////////////////////////
////////////        PROGRAMA PRINCIPAL        ////////////////
//////////////////////////////////////////////////////////////

int main (void) {
  int ncasos;  
  cin >> ncasos;
  for (int i= 0; i<ncasos; i++) {
    leeGrafo();
    busquedaPA();
  }
}