#include <iostream>
using namespace std;

// --- CONSTANTES ---
#define MAX_NODOS 25       // M <= 20, damos un poco de margen
#define MAX_HORARIOS 15    // V <= 12
#define INFINITO 1000000   // Un valor muy alto para representar "no conectado"

// --- VARIABLES GLOBALES (Representación del Grafo) ---
int M, K; // Personas y Conexiones

// En lugar de una matriz de booleanos (Diapositiva 20), guardamos los horarios.
// horarios[i][j][k] guarda el k-ésimo horario de reunión entre la persona i y j.
int horarios[MAX_NODOS][MAX_NODOS][MAX_HORARIOS];
int cantidad_reuniones[MAX_NODOS][MAX_NODOS]; // Cuántas veces se ven al día

// --- VARIABLES DEL ALGORITMO DE DIJKSTRA (Diapositiva 58) ---
int D[MAX_NODOS];    // D[v]: Tiempo mínimo para que la noticia llegue a v
bool S[MAX_NODOS];   // S[v]: Si ya hemos visitado/cerrado el nodo v

// --- FUNCIÓN AUXILIAR: Calcular peso dinámico ---
// No sale en el PDF porque es específica del problema. 
// Calcula cuándo se verán 'u' y 'v' si la noticia llega a 'u' en 'tiempo_actual'.
int calcularEncuentro(int u, int v, int tiempo_actual) {
    int dia = tiempo_actual / 100;
    int minuto = tiempo_actual % 100;
    
    int mejor_hora = -1;
    int primera_hora_manana = 1000; 

    // Miramos todos los horarios de reunión entre u y v
    for (int k = 0; k < cantidad_reuniones[u][v]; k++) {
        int hora_reunion = horarios[u][v][k];
        
        // 1. ¿Hay reunión HOY después de que me entere?
        if (hora_reunion >= minuto) {
            if (mejor_hora == -1 || hora_reunion < mejor_hora) {
                mejor_hora = hora_reunion;
            }
        }
        
        // 2. Guardamos la reunión más temprana para MAÑANA por si acaso
        if (hora_reunion < primera_hora_manana) {
            primera_hora_manana = hora_reunion;
        }
    }

    if (mejor_hora != -1) {
        // Nos vemos hoy: Mismo día + hora de reunión
        return (dia * 100) + mejor_hora;
    } else {
        // Nos vemos mañana: (Día siguiente) + primera hora disponible
        return ((dia + 1) * 100) + primera_hora_manana;
    }
}

void resolverCaso() {
    // 1. Inicialización de estructuras (Como BorraMarcas, Diapositiva 28)
    // Limpiamos la matriz de reuniones poniendo todo a 0
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            cantidad_reuniones[i][j] = 0;
        }
    }

    // 2. Lectura del Grafo
    for (int i = 0; i < K; i++) {
        int u, v, veces;
        cin >> u >> v >> veces;
        
        // Grafo NO Dirigido (Diapositiva 12): La arista (u,v) es igual a (v,u)
        cantidad_reuniones[u][v] = veces;
        cantidad_reuniones[v][u] = veces; // Simetría

        for (int j = 0; j < veces; j++) {
            int instante;
            cin >> instante;
            horarios[u][v][j] = instante;
            horarios[v][u][j] = instante; // Guardamos en ambos sentidos
        }
    }

    // 3. Inicialización Dijkstra (Diapositiva 58)
    for (int v = 1; v <= M; v++) {
        D[v] = INFINITO;  // Coste infinito inicialmente
        S[v] = false;     // Nadie está visitado (conjunto S vacío)
    }
    D[1] = 0; // El cotilla jefe (1) se entera en el minuto 0

    // 4. Bucle Principal Dijkstra (Diapositiva 59)
    // Repetimos M veces para asegurar visitar todos
    for (int i = 1; i <= M; i++) {
        
        // a) Buscar el nodo 'u' con D[u] mínimo y que no esté en S
        int u = -1;
        int min_dist = INFINITO;
        
        for (int v = 1; v <= M; v++) {
            if (S[v] == false && D[v] < min_dist) {
                min_dist = D[v];
                u = v;
            }
        }

        // Si no encontramos nodo (todos son infinitos o visitados), terminamos
        if (u == -1) break;

        // b) Marcar como visitado (Añadir a S)
        S[u] = true;

        // c) Actualizar vecinos (Relajación de aristas)
        for (int w = 1; w <= M; w++) {
            // Si w es vecino de u (tienen reuniones) y no está visitado
            if (cantidad_reuniones[u][w] > 0 && S[w] == false) {
                
                // Calculamos el peso de la arista (tiempo de encuentro)
                int tiempo_llegada = calcularEncuentro(u, w, D[u]);
                
                // Si encontramos un camino más rápido, actualizamos D[w]
                if (tiempo_llegada < D[w]) {
                    D[w] = tiempo_llegada;
                }
            }
        }
    }

    // 5. Calcular la solución final
    // Buscamos el tiempo MAYOR en el array D (el último en enterarse)
    int tiempo_final = 0;
    for (int i = 1; i <= M; i++) {
        if (D[i] == INFINITO) {
            tiempo_final = -1; // Alguien no se enteró nunca
            break;
        }
        if (D[i] > tiempo_final) {
            tiempo_final = D[i];
        }
    }
    
    cout << tiempo_final << endl;
}

int main() {
    int ncasos;
    cin >> ncasos;
    while (cin >> M >> K) { // Leemos M y K aquí para cada caso
        resolverCaso();
    }
    return 0;
}