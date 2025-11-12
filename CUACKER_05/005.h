#ifndef INTERPRETE_H
#define INTERPRETE_H


#include "004.h"
#include <string>
using namespace std;

// definimos las funciones del comando de interpretes del ejercicio 5 

void procesar_pcuac();
void procesar_mcuac();
void procesar_last();
void procesar_follow();
void procesar_date();
void procesar_tag();
void Interprete(string comando);


#endif