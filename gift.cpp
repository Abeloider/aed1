#include <iostream> 

using namespace std; 

int main () {
    int n;
    int continuar = 1; // sin break 1 continuamos y 0 paramos
    while (continuar && cin >> n) { //leemos 
        cout << n*2 << endl; // multiplicamos 
        // palindromo: que se lea igual de  izquierda a derecha que de derecha a izquierda
        // primero sacamos el resto 
        // segundo sumamos sumamos el invertido mas el resto 
        // tercero dividimos hasta que no podamos o hasta llegar a 0 si no se llega seguimos escribiendo numeros
        int p=n; 
        int digito;
        int invertido=0;
        int original = n;  
        while (p>0) {
            digito= p%10;
            invertido = (invertido * 10) + digito; 
            p = p / 10; 
        }
        // primo: divisible por si mimo y por 1
        int x=n;
        int i=2;
        while (i*i <= n && n%i != 0) {
            i++;
        }
        // comprobamos si el digito es igual al numero 
        // comprobamos que sea primo
        if (invertido == original && n > 1 && i * i > n) {
            continuar=0;
        }
    }
    return 0; 
}