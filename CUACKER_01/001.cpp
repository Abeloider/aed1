#include <iostream>
#include <string>
using namespace std;

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
    
int main() {
    int entrada;
    cin >> entrada;
    for(int i=0; i<entrada; i++) {
        int n;
        cin>>n;
        cout<<convertir_num_text(n)<<endl;
    }
}