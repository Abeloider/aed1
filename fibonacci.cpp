#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // n�mero de consultas

    const int periodo = 300;
    int fib[periodo + 1];
    long long pref[periodo + 1];

    // primeros dos valores
    fib[1] = 1;
    fib[2] = 1;

    // generamos la secuencia especial mod 100
    for (int i = 3; i <= periodo; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % 100;
    }

    // suma acumulada
    pref[0] = 0;
    for (int i = 1; i <= periodo; i++) {
        pref[i] = pref[i-1] + fib[i];
    }
    long long totalPeriodo = pref[periodo];

    while (t--) {
        long long a, b;
        cin >> a >> b;

        auto sumaHasta = [&](long long x) -> long long {
            if (x <= 0) return 0;
            long long ciclos = x / periodo;
            int resto = x % periodo;
            return ciclos * totalPeriodo + pref[resto];
        };

        long long resultado = sumaHasta(b) - sumaHasta(a-1);
        cout << resultado << "\n";
    }
    return 0;
}
