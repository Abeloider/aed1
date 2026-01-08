// we are islands 
# include <iostream>
# include <string.h>  // Funcion memset

using namespace std;

// --- CONSTANTES Y GLOBALES ---
#define MAX_NODOS 20000   // Maximo numero de nodos lo suficiente para que quepa toda la entrada de mooshak
#define MAX_ADY 10      // Maximo 10 adyacentes

int N,M; 
int G[MAX_NODOS][MAX_ADY]; // Matriz de adyacencia
int grado[MAX_NODOS];      // Grado de cada nodo numero de amigos

int isla[MAX_NODOS];       // para saber a que isla pertenece cada nodo
bool visitado[MAX_NODOS];  // Marcas de nodos visitados

// lectura del grafo 

/*
leemos el numero de personas y sus relaciones para construir el mapa usando listas de adyacencia
una vez leidas guardamos y limpiamos gracias al memset
*/
void leeGrafo (void) {
    cin >> N >> M; // Lectura numero de nodos y aristas
    // limpiamos las memorias para los nuevos casos
    memset(grado, 0, sizeof(grado));
    memset(visitado, 0, sizeof(visitado));
    memset(isla, 0, sizeof(isla));

    for (int i=0; i<M ; i++) {
        int u,v; 
        cin >> u >> v;

        G[u][grado[u]] = v;
        grado[u]++;
        G[v][grado[v]] = u;
        grado[v]++;
    }
}

// vamos a usar el algoritmo busqueda en profundidad
// y marcamos su isla 

void bpp (int u, int num_isla) {
    visitado[u] = true;
    isla[u] = num_isla; 
    // recorremos todos los vecinos del nodo u 
    for (int i=0; i<grado[u]; i++) {// recorremos todos los vecinos de u
        int v = G[u][i]; 
        // si no ha sido visitado continuamos la busqueda recursiva
        if (!visitado[v]) {
            bpp(v, num_isla);
        }
    }
}


// resolvemos
// recorremos las personas cada vez que encuentra a alguien que no es visitado
// identifica una nueva isla iniciando un recorrido alfinal imprimimos el numero de casos 
// y la isla asignada a cada persona 
void resolverCaso(int nCaso) {
    int contador_islas = 0;
    // recorremos las personas desde 1 hasta N
    for (int i=1; i<=N; i++) { 
        if (!visitado[i]) {  
            contador_islas++; 
            bpp(i, contador_islas); // llamada a bpp 
        }
    }
    //imprimimos la salida de datos como indica el enuncaido 
    cout << "Caso "<< nCaso << endl;
    cout << contador_islas << endl;

    // imprimimos a que isla pertenece a la persona
    for (int i=1; i<=N; i++) {
        cout << isla[i] << endl;
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