#ifndef CUAC_H
#define CUAC_H

#include "001_002.h"
#include "003.h"
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
    bool leer_mcuac();
    bool leer_pcuac();
    void escribir();
    bool es_anterior(Cuac &otro);
};

#endif