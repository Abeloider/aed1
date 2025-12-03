#include "004.h"
#include "001_002.h"
#include <iostream>
using namespace std;

// Función que lee un mcuac 
bool Cuac::leer_mcuac(){
    cin>>usuario;
    if (!fecha.leer()) return false;
    cin.ignore(); // ignora el salto de linea que va despues de la fecha
    getline (cin, texto); // lee todo el texto hasta presionar enter
    return true;
}

// Función que lee un pcuac
bool Cuac::leer_pcuac(){    
    cin>>usuario;
    if(!fecha.leer()) return false;
    int n;
    cin>>n;
    texto=convertir_num_text(n);
    return true;
}

// Función que escribe un cuac
void Cuac::escribir() {
    cout<<usuario<<' ';
    fecha.escribir();
    cout<<"\n   "; //nos ha llevado tiempo ya que en vez de 3 espacios teniamos "\n\t" donde por culpa de eso nos daba error;
    cout<<texto<<endl;
}

// modificacion para realizar el ejercicio 6 debido a si las fechas, texto, usuario son iguales
bool Cuac::es_anterior(Cuac &otro){
    // comparamos de mas antiguo a mas reciente
    if (!fecha.esIgual(otro.fecha)) {
        return fecha.esMenor(otro.fecha);
    }
    // en el caso de tengamos la misma fecha entonces comparamos por texto 
    if (texto != otro.texto) {
        return texto > otro.texto; 
    }
    // en el caso de que tambien el texto sea igual entonces por usuairob
    return usuario > otro.usuario;
}
