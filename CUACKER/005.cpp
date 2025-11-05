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
void convertir_text_num( string& s, int& n) {
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

   if (hora<10) {
        cout << '0'; 
    } cout << hora << ':';
    if (minuto<10) {
        cout << '0'; 
    } cout << minuto << ':';
    if (segundo<10) {
        cout << '0'; 
    } cout << segundo;}


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

bool Cuac::leer_mcuac(){
    cin>>usuario;
    if (!fecha.leer()) return false;
    cin.ignore(); // ignora el salto de linea que va despues de la fecha
    getline (cin, texto); // lee todo el texto hasta presionar enter
    return true;
}

bool Cuac::leer_pcuac(){    
    cin>>usuario;
    if(!fecha.leer()) return false;
    int n;
    cin>>n;
    texto=convertir_num_text(n);
    return true;
}

void Cuac::escribir() {
    cout<<usuario<<' ';
    fecha.escribir();
    cout<<"\n   "; //comentario: hemoe demorado mucho tiempo ya que en vez de 3 espacios teniamos "\n\t" donde por culpa de eso nos daba error;
    cout<<texto<<endl;
}

bool Cuac::es_anterior(Cuac &otro){
    return fecha.esMenor(otro.fecha);
}


/// EJERCICIO 5: interprete de comandos
// variables globales
    int contador= 0; 
    Cuac actual;

void procesar_pcuac(){
    actual.leer_pcuac();
    contador++;
    cout<<contador<<" cuac"<<endl;
}

void procesar_mcuac(){
    actual.leer_mcuac();
    contador++;
    cout<<contador<<" cuac"<<endl;
}

void procesar_last() { 
    int n; 
    cin >> n; // 5
    int total
    cout << "last " << n << endl;  // last 5
    cout << "1. "; 
    actual.escribir();  // 1. RafaelNaval 28/11/2011 11:27:08
                        // Enhorabuena, campeones!
    cout << "Total: 1 cuac" << endl;  // Total: 1 cuac
     
}

void procesar_follow(){ 
    string usuario; 
    cin >> usuario; // Perico
    cout<<"follow "<< usuario <<endl; // follow Perico
    cout << "1. "; 
    actual.escribir();   // 1. RafaelNaval 28/11/2011 11:27:08
                         // Enhorabuena, campeones!
    cout<<"Total: 1 cuac"<< endl;
}

void procesar_date(){
    Fecha minimo, maximo;
    minimo.leer();
    maximo.leer();
    cout<<"date ";
    minimo.escribir();
    cout<<" ";
    maximo.escribir();
    cout << endl;
    cout << "1. "; 
    actual.escribir();
    cout<<"Total: 1 cuac" << endl;
}

void procesar_tag(){
    string tag;
    cin>>tag;
    cout<<"tag "<<tag<<endl;
    cout << "1. "; 
    actual.escribir();
    cout<<"Total: 1 cuac"<< endl;
}

void Interprete(string comando){
    if (comando=="pcuac") procesar_pcuac();
    else if (comando=="mcuac") procesar_mcuac();
    else if (comando=="last") procesar_last();
    else if(comando=="follow") procesar_follow();
    else if(comando=="date") procesar_date();
    else if(comando=="tag") procesar_tag();
}
  

int main() {
   string comando;
   while (cin >> comando && comando!="exit")
      Interprete(comando); 
}




