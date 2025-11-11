#include <iostream>
using namespace std;

//EJERCICIO 001
string convertir_num_text (int n) {
    string lista[30];
    lista[0]="Afirmativo.";
    lista[1]="Negativo.";
    lista[2]="Estoy de viaje en el extranjero.";
    lista[3]="Muchas gracias a todos mis seguidores por vuestro apoyo.";
    lista[4]="Enhorabuena, campeones!";
    lista[5]="Ver las novedades en mi pagina web.";
    lista[6]="Estad atentos a la gran exclusiva del siglo.";
    lista[7]="La inteligencia me persigue pero yo soy mas rapido.";
    lista[8]="Si no puedes convencerlos, confundelos.";
    lista[9]="La politica es el arte de crear problemas.";
    lista[10]="Donde estan las llaves, matarile, rile, rile...";
    lista[11]="Si no te gustan mis principios, puedo cambiarlos por otros.";
    lista[12]="Un dia lei que fumar era malo y deje de fumar.";
    lista[13]="Yo si se lo que es trabajar duro, de verdad, porque lo he visto por ahi.";
    lista[14]="Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.";
    lista[15]="Mi vida no es tan glamurosa como mi pagina web aparenta.";
    lista[16]="Todo tiempo pasado fue anterior.";
    lista[17]="El azucar no engorda... engorda el que se la toma.";
    lista[18]="Solo los genios somos modestos.";
    lista[19]="Nadie sabe escribir tambien como yo.";
    lista[20]="Si le molesta el mas alla, pongase mas aca.";
    lista[21]="Me gustaria ser valiente. Mi dentista asegura que no lo soy.";
    lista[22]="Si el dinero pudiera hablar, me diria adios.";
    lista[23]="Hoy me ha pasado una cosa tan increible que es mentira.";
    lista[24]="Si no tienes nada que hacer, por favor no lo hagas en clase.";
    lista[25]="Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon y salio una calabaza.";
    lista[26]="Me despido hasta la proxima. Buen viaje!";
    lista[27]="Cualquiera se puede equivocar, inclusivo yo.";
    lista[28]="Estoy en Egipto. Nunca habia visto las piramides tan solas.";
    lista[29]="El que quiera saber mas, que se vaya a Salamanca.";
    if (n>=1 && n<=30){
        return lista[n-1];
    }
    return "Error";
    }

// EJERCIO 002
void convertir_text_num(string& s, int& n) {
    if (s == "Afirmativo.")n= 1;
    else if (s == "Negativo.")n= 2;
    else if (s == "Estoy de viaje en el extranjero.")n= 3;
    else if (s == "Muchas gracias a todos mis seguidores por vuestro apoyo.")n= 4;
    else if (s == "Enhorabuena, campeones!")n= 5;
    else if (s == "Ver las novedades en mi pagina web.")n= 6;
    else if (s == "Estad atentos a la gran exclusiva del siglo.")n= 7;
    else if (s == "La inteligencia me persigue pero yo soy mas rapido.")n= 8;
    else if (s == "Si no puedes convencerlos, confundelos.")n= 9;
    else if (s == "La politica es el arte de crear problemas.") n= 10;
    else if (s == "Donde estan las llaves, matarile, rile, rile...") n= 11;
    else if (s == "Si no te gustan mis principios, puedo cambiarlos por otros.") n= 12;
    else if (s == "Un dia lei que fumar era malo y deje de fumar.") n= 13;
    else if (s == "Yo si se lo que es trabajar duro, de verdad, porque lo he visto por ahi.") n= 14;
    else if (s == "Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.") n= 15;
    else if (s == "Mi vida no es tan glamurosa como mi pagina web aparenta.") n= 16;
    else if (s == "Todo tiempo pasado fue anterior.") n= 17;
    else if (s == "El azucar no engorda... engorda el que se la toma.") n= 18;
    else if (s == "Solo los genios somos modestos.") n= 19;
    else if (s == "Nadie sabe escribir tambien como yo.") n= 20;
    else if (s == "Si le molesta el mas alla, pongase mas aca.") n= 21;
    else if (s == "Me gustaria ser valiente. Mi dentista asegura que no lo soy.") n= 22;
    else if (s == "Si el dinero pudiera hablar, me diria adios.") n= 23;
    else if (s == "Hoy me ha pasado una cosa tan increible que es mentira.") n= 24;
    else if (s == "Si no tienes nada que hacer, por favor no lo hagas en clase.") n= 25;
    else if (s == "Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon y salio una calabaza.") n= 26;
    else if (s == "Me despido hasta la proxima. Buen viaje!") n= 27;
    else if (s == "Cualquiera se puede equivocar, inclusivo yo.") n= 28;
    else if (s == "Estoy en Egipto. Nunca habia visto las piramides tan solas.") n= 29;
    else if (s == "El que quiera saber mas, que se vaya a Salamanca.") n= 30;
    else s= "ERROR. Cadena no encontrada: [" + s + "]";
}

// EJERCICIO 003

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

// comprobamos si la fecha esta en el formato correcto
bool Fecha::leer() {
   char barra1, barra2, puntos1, puntos2;
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

// comprobamos si la fecha es menor 
// primero comprobamos que no sean iguales y obserbamos que este es moner
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

bool Fecha::esIgual(Fecha &f){
    if (segundo==f.segundo && minuto==f.minuto && hora==f.hora && dia==f.dia && mes==f.mes && ano==f.ano){
        return true;
    } else
        return false;
}

int main() {
    int n;
    cin>>n;
    Fecha f1;
    f1.leer(); // 6/8/2001 12:31:55
    for(int i=0; i<n-1; i++){
        Fecha f2;
        f2.leer(); // 6/8/2002 09:32:22
        if(f1.esIgual(f2)){
            f1.escribir();
            cout<<" ES IGUAL A ";
            f2.escribir();
            cout<<endl;
        }
        else if(f1.esMenor(f2)){
            f2.escribir();
            cout<<" ES POSTERIOR A ";
            f1.escribir();
            cout<<endl;
        } else if (f2.esMenor(f1))
        {
            f2.escribir();
            cout<<" ES ANTERIOR A ";
            f1.escribir();
            cout<<endl;
        }
        f1=f2;
    }
}
