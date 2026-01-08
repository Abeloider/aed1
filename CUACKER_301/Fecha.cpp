#include "Fecha.h"
#include <iostream>
using namespace std;

// iniclializamos el constructor a 0; 
Fecha::Fecha()
{
    dia=0; mes=0; ano=0; hora=0; minuto=0; segundo=0;
}

// comprobamos si la fecha esta en el formato correcto
bool Fecha::leer() {
   char barra1, barra2, puntos1, puntos2;
   // leemos la fecha con el formato indicado
   if (!(cin >> dia >> barra1 >> mes >> barra2 >> ano >> hora >> puntos1 >> minuto >> puntos2 >> segundo)) { 
    return false;
   } else 
    return barra1 =='/' && barra2=='/' && puntos1==':' && puntos2==':'; 
}

// escribimos la fecha 
void Fecha::escribir(){
    cout << dia << '/' << mes << '/' << ano << ' ';
   if (hora<10) { // nos ha demorado mucho tiempo en encotrar este fallo 
        cout << '0'; 
    } cout << hora << ':';
    if (minuto<10) {
        cout << '0'; 
    } cout << minuto << ':';
    if (segundo<10) {
        cout << '0'; 
    } cout << segundo;
}

// Comprobamos si la fecha es menor 
// primero comprobamos que no sean iguales y observamos que este es menor
bool Fecha::esMenor(Fecha &f) {
    if (ano != f.ano) return ano < f.ano; // f1<f2? si es que si entonces true si no entonces pasamos al mes
    if (mes != f.mes) return mes < f.mes;
    if (dia != f.dia) return dia < f.dia;
    if (hora != f.hora) return hora < f.hora;
    if (minuto != f.minuto) return minuto < f.minuto;
    if (segundo != f.segundo) return segundo < f.segundo;
    else 
        return false; 
}

// Comprobamos si las fechas son iguales
bool Fecha::esIgual(Fecha &f){
    if (segundo==f.segundo && minuto==f.minuto && hora==f.hora && dia==f.dia && mes==f.mes && ano==f.ano){
        return true;
    } else
        return false;
}
