#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    int periodo = 300; // ya que cada 300 se repite los terminos
    int fib[periodo + 1];

    // primeros dos valores
    fib[0] = 1;
    fib[1] = 1;

    // generamos la cadena de fibonnaci hasta 100 numeros 
    for (int i = 2; i <= periodo; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % 100;
    }

    // suma de un ciclo completo
    int suma_ciclos = 0;
    for (int i = 1; i <= periodo; i++) {
        suma_ciclos += fib[i];
    }

    int i=0;
    while (i<t) { // uso long long ya que si no lo hago las variables muy altas no me las reconoce o me las pone elvado a un numero
        long long N, M; 
        cin >> N >> M; // escribimos los valores de de principio y final (1 9999)

        // primero calculamos los ciclos completos

        long long cantidad = M - N + 1; // cantidad de términos a sumar (9999 - 1 + 1 = 9999)
        long long ciclos_completos = cantidad / periodo; // ciclos completos de 300 (9999 / 300 = 33)
        long long resto = cantidad % periodo; // nos sobran (9999 % 300 = 99) que no llegan a completar un ciclo
        long long inicio = (N - 1) % periodo; //posicion de inicio (1 - 1) % 300 = 0

        long long sumatotal = ciclos_completos * suma_ciclos; // sumamos todos los ciclos completos

        // calculamos la suma del resto
        for (int i = 0; i < resto; i++) {
            int rest = (inicio + i) % periodo ; //calculamos la posicion sin pasarse
            sumatotal += fib[rest];
        }
        cout << sumatotal << endl; 
        i++;
    }
    return 0;
}