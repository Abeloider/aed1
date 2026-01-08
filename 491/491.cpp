#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Usamos un límite cercano al máximo de unsigned long long para saturar.
// 2e18 es seguro para evitar desbordamientos negativos en signed, 
// y suficientemente grande para capturar torres pequeñas.
const long long LIMIT = 2000000000000000000LL; 

struct Edge {
    int to;
    int weight;
};

// Variables globales para el caso de prueba actual
int N, A_edges, S, E;
vector<vector<Edge>> adj;

// Memorización
// dp_val[u]: El valor saturado del camino desde u hasta E.
// best_next[u]: El siguiente nodo en el camino óptimo desde u.
// best_weight[u]: El peso de la arista hacia best_next[u].
// visited[u]: Para la DP.
// reaches_end[u]: Booleano, true si existe un camino de u a E.
vector<long long> dp_val;
vector<int> best_next;
vector<int> best_weight;
vector<bool> visited;
vector<bool> reaches_end;

// Función segura para potencias con saturación
long long saturated_pow(long long base, long long exp) {
    if (base == 1) return 1; // 1 elevado a cualquier cosa es 1
    if (exp == 0) return 1; // No debería ocurrir en este problema (pesos >=1)
    
    long long res = 1;
    // Potenciación binaria simple o lineal con chequeo de overflow.
    // Dado que LIMIT se alcanza muy rápido (ej: 2^62), un bucle lineal es eficiente.
    for (int i = 0; i < exp; ++i) {
        // Chequeo de overflow de multiplicación: a * b > LIMIT
        if (__builtin_mul_overflow(res, base, &res)) return LIMIT + 1;
        if (res > LIMIT) return LIMIT + 1;
    }
    return res;
}

// Declaración adelantada para recursión mutua
int compare_paths(int u, int v);

// Función que calcula (y memoriza) el valor saturado desde u
// Retorna el valor saturado.
long long get_val(int u) {
    if (u == E) return 1; // El "exponente" final implícito es 1 (o valor base de la arista anterior)
    // Nota: dp_val se rellena en la función solve(), aquí solo lo consultamos
    // pero para la lógica recursiva de comparación necesitamos asegurar que existe.
    return dp_val[u];
}

// Compara el camino óptimo que empieza en u vs el camino óptimo que empieza en v.
// Retorna: 1 si u > v, -1 si v > u, 0 si u == v (costes iguales)
int compare_paths(int u, int v) {
    if (u == v) return 0;
    
    long long val_u = get_val(u);
    long long val_v = get_val(v);

    // Caso 1: Ambos son finitos (o uno finito y otro infinito)
    // Si son distinguibles por el valor saturado, usamos eso.
    bool u_inf = (val_u > LIMIT);
    bool v_inf = (val_v > LIMIT);

    if (!u_inf && !v_inf) {
        if (val_u > val_v) return 1;
        if (val_v > val_u) return -1;
        return 0;
    }
    if (u_inf && !v_inf) return 1;
    if (!u_inf && v_inf) return -1;

    // Caso 2: Ambos son INFINITOS (> LIMIT)
    // Aquí tenemos w_u ^ (Camino desde next_u)  VS  w_v ^ (Camino desde next_v)
    // Como ambos son infinitos, las bases w_u y w_v deben ser >= 2 (si fueran 1, val sería 1).
    
    // Regla: En torres infinitas, el exponente domina. Comparamos los exponentes recursivamente.
    int next_u = best_next[u];
    int next_v = best_next[v];
    
    // Llamada recursiva para comparar los exponentes (los caminos restantes)
    int cmp_exponents = compare_paths(next_u, next_v);
    
    if (cmp_exponents == 1) return 1;  // Exponente de u es mayor -> u gana
    if (cmp_exponents == -1) return -1; // Exponente de v es mayor -> v gana
    
    // Si los exponentes son estructuralmente idénticos en coste:
    // Deciden las bases.
    int w_u = best_weight[u];
    int w_v = best_weight[v];
    
    if (w_u > w_v) return 1;
    if (w_u < w_v) return -1;
    
    return 0; // Costes idénticos
}

// Función principal de DP para resolver desde el nodo u
void solve_dp(int u) {
    visited[u] = true;
    
    if (u == E) {
        reaches_end[u] = true;
        dp_val[u] = 1; // Valor base neutral
        return;
    }

    reaches_end[u] = false;
    dp_val[u] = 0; // Valor por defecto si no llega
    best_next[u] = -1;

    // Iterar sobre todos los vecinos
    for (const auto& edge : adj[u]) {
        int v = edge.to;
        int w = edge.weight;

        if (!visited[v]) {
            solve_dp(v);
        }

        if (reaches_end[v]) {
            // Candidato: arista (u->v) con peso w.
            // Si es el primer camino válido encontrado, lo tomamos.
            if (!reaches_end[u]) {
                reaches_end[u] = true;
                best_next[u] = v;
                best_weight[u] = w;
                dp_val[u] = saturated_pow(w, dp_val[v]);
            } else {
                // Ya tenemos un camino previo (best_next[u]), comparamos con el nuevo candidato (v).
                // Para comparar, necesitamos ver si: w^val(v) > best_weight[u]^val(best_next[u])
                
                // Calculamos el valor saturado local del candidato actual
                long long current_candidate_val = saturated_pow(w, dp_val[v]);
                long long best_current_val = dp_val[u]; // Ya almacenado
                
                bool update = false;

                // Comparación rápida con valores saturados
                bool cand_inf = (current_candidate_val > LIMIT);
                bool best_inf = (best_current_val > LIMIT);

                if (!cand_inf && !best_inf) {
                    if (current_candidate_val > best_current_val) update = true;
                    else if (current_candidate_val == best_current_val) {
                        // Empate numérico finito: Criterio Lexicográfico (menor ID de nodo primero)
                        if (v < best_next[u]) update = true;
                    }
                } else if (cand_inf && !best_inf) {
                    update = true;
                } else if (!cand_inf && best_inf) {
                    update = false;
                } else {
                    // AMBOS INFINITOS: Comparación recursiva compleja
                    // Comparar Exponentes: Camino desde v VS Camino desde best_next[u]
                    int cmp = compare_paths(v, best_next[u]);
                    
                    if (cmp == 1) { // El exponente del candidato v es mayor
                        update = true;
                    } else if (cmp == -1) { // El exponente actual es mayor
                        update = false;
                    } else {
                        // Exponentes iguales, comparar bases
                        if (w > best_weight[u]) update = true;
                        else if (w < best_weight[u]) update = false;
                        else {
                            // Costes idénticos (bases y exponentes iguales), criterio Lexicográfico
                            if (v < best_next[u]) update = true;
                        }
                    }
                }

                if (update) {
                    best_next[u] = v;
                    best_weight[u] = w;
                    dp_val[u] = current_candidate_val;
                }
            }
        }
    }
}

void solve() {
    if (!(cin >> N >> A_edges)) return;
    cin >> S >> E;

    // Limpiar estructuras
    adj.assign(N + 1, vector<Edge>());
    dp_val.assign(N + 1, 0);
    best_next.assign(N + 1, -1);
    best_weight.assign(N + 1, 0);
    visited.assign(N + 1, false);
    reaches_end.assign(N + 1, false);

    for (int i = 0; i < A_edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // Pre-filtrado: Si hay múltiples aristas u->v, nos quedamos con la de mayor peso.
        // Aunque el problema no especifica multigrafos, es buena práctica.
        // Aquí simplemente las añadimos todas y el algoritmo elegirá la mejor.
        adj[u].push_back({v, w});
    }

    // Ejecutar DP desde el nodo de inicio
    solve_dp(S);

    if (!reaches_end[S]) {
        cout << endl; // Línea en blanco si no hay camino
    } else {
        // Reconstruir camino
        vector<int> path;
        int curr = S;
        while (curr != E) {
            path.push_back(curr);
            curr = best_next[curr];
        }
        path.push_back(E);

        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
}

int main() {
    // Optimización de E/S
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}