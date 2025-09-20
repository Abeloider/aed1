#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // n�mero de consultas

    int x = 300; 

    int fib[x + 1];

    // primeros dos valores
    fib[1] = 1; // cogemos la primera posicion e lo igualamos a 1
    fib[2] = 1; // cogemos la segunda posicion e lo igualamos a 1

    // generamos fibonnacci
    for (int i = 3; i <= x; i++) {
        fib[i] = (fib[i-1] + fib[i-2])%100; // llegamos hasta la posicion 100
    }

    int pos1;
    int pos2;
    double sumatotal;
    
    while (t--) {
        cin >> pos1 >> pos2 ;
        sumatotal = 0;
        if (pos1 > 100 || pos2 > 100) {
            pos1 = pos1 % 100;
            pos2 = pos2 % 100;  
        }
        for (int i = pos1; i <= pos2; i++) {
            sumatotal += fib[i];  
    }
    cout << sumatotal << endl; 
    }
    return 0;
}