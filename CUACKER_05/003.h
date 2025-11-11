#ifndef FECHA_H
#define FECHA_H

#include <iostream>
using namespace std;

class Fecha {
	private:
		int dia, mes, ano;
		int hora, minuto, segundo;
	public:
		Fecha();
		bool leer();
		void escribir();
        bool esMenor(Fecha &fecha);
		bool esIgual(Fecha &otra);
};
// iniclializamos el constructor a 0
Fecha::Fecha()
{
    dia=0; mes=0; ano=0; hora=0; minuto=0; segundo=0;
}

#endif