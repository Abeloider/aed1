#ifndef CUAC_H
#define CUAC_H

#include "003.h" // Fecha
#include <string>
#include <iostream>

using namespace std;

//EJERCICIO 4 

class Cuac {
  private:
    Fecha fecha;
    string usuario;
    string texto;
  public:
    string getUsuario() {return usuario;} // añadimos metodo get para poder usarlos en el ejercicio 6
    Fecha getFecha() {return fecha;} // añadimos metodo get para poder usarlos en el ejercicio 6
    string getTexto() {return texto;} // casos en los que los textos 
    bool leer_mcuac();
    bool leer_pcuac();
    void escribir();
    bool es_anterior(Cuac &otro);
};

#endif