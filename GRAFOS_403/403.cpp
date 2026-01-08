#include <iostream>
#include <string.h>  // Funcion memset
#include <stdlib.h>  // Funcion exit

using namespace std;

// --- CONSTANTES Y GLOBALES ---
#define MAX_NODOS 20005    // Maximo numero de nodos
#define MAX_ADY 10         // Maximo 10 adyacentes
#define MAX_CAMINO 200000  // Espacio suficiente para el recorrido con retrocesos

int nnodos;                // Numero de nodos del grafo
int G[MAX_NODOS][MAX_ADY]; // Matriz de adyacencia
int grado[MAX_NODOS];      // El numero de vecinos de cada sala

bool visitado[MAX_NODOS];  // Marcas de nodos visitados
int camino[MAX_CAMINO];    // Camino actual (con retrocesos)
int long_camino;           // Longitud del camino actual
bool exito;                // Indicador de exito en la busqueda

// --- FUNCIONES DEL PROGRAMA ---

// construimos la lista de adyacencia transformando los caracteres a enteros 
// separados por un salto do linea 

void leeGrafo (void) {
  cin >> nnodos; 
  memset(grado, 0, sizeof(grado));
  // leemos el salto de linea de numero de nodos ya que este numero no me sirve
  char c; 
  cin.get(c); // Leer el salto de linea despues del numero de nodos
  for (int i = 1; i <= nnodos; i++) {
    cin.get(c); // leemos el primer caracter de la linea
    while (c != '\n') { // mientras no sea salto de linea
      if (c >= '0' && c <= '9') { // si es un digito
        int valor = 0; 
        while (c >= '0' && c <= '9') {
          valor = valor * 10 + (c - '0'); // convertimos el caracter a entero cogemos el valor ascii y restamos el de '0'
          cin.get(c); 
      }
          G[i][grado[i]] = valor;
            grado[i]++;
      } else { // en el caso de que no sea digito entonces leemos el siguiente caracter que sera un espacio o salto de linea
          cin.get(c);
          }
      }
  }
}


// Procedimiento recursivo de la busqueda en profundidad con retrocesos
// depth first search
void dfs(int u) {
  camino[long_camino] = u; 
  long_camino++;
  if (u == nnodos) {
    exito = true; // exitoso 
    return; // terminar la busqueda
  }
  visitado[u] = true; // marcar como visitado
  // comprobamos todos los posibles adyacentes empezando desde el nodo u
  for (int i = 0; i < grado[u]; i++) { // iterar sobre adyacentes
    int v = G[u][i];  // nodo adyacente
    if (!visitado[v]) { // si no ha sido visitado
      dfs(v); // llamda recursiva para visitar v
      if (exito) {
        return; // si se encontro el camino, terminamos
      } else { // si no se encontro el camino, retrocedemos
        camino[long_camino] = u; // retroceder al nodo u
        long_camino++; // incrementar longitud del camino
    }
  }
}
}

// invocamos el algoritmo de busqueda en profundidad y luego 
// imprimimos las salidas 

void resolverCaso(int nCaso) {
  long_camino = 0; // Longitud del camino actual
  exito = false; // Indicador de exito en la busqueda
  memset(visitado, 0, sizeof(visitado)); // inicializacion marcas de visitado

  if (nnodos > 0) { // Si hay nodos en el grafo
    dfs(1); // Iniciar DFS desde el nodo 1 como indica en el enunciado
  }

  cout << "Caso " << nCaso << endl;
  if (exito) {  // Si se ha encontrado un camino
    cout << long_camino << endl;
    for (int i = 0; i < long_camino; i++) {
      cout << camino[i] << endl; // Imprimir cada nodo del camino
    }
  } else {
    cout << "INFINITO" << endl;  // No se ha encontrado un camino
  } 
}


int main (void)
{
  int ncasos;  
  cin >> ncasos;
  for (int i= 0; i<ncasos; i++) {
    leeGrafo();
    resolverCaso(i+1);
  }
}