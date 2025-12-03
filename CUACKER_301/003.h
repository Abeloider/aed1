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

#endif