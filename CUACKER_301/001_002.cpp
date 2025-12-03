#include "001_002.h"

//EJERCICIO 001
// Funcion que convierte un numero en su texto correspondiente 
string convertir_num_text (int n) {
 switch(n) {
        case 1: return "Afirmativo.";
        case 2: return "Negativo.";
        case 3: return "Estoy de viaje en el extranjero.";
        case 4: return "Muchas gracias a todos mis seguidores por vuestro apoyo.";
        case 5: return "Enhorabuena, campeones!";
        case 6: return "Ver las novedades en mi pagina web.";
        case 7: return "Estad atentos a la gran exclusiva del siglo.";
        case 8: return "La inteligencia me persigue pero yo soy mas rapido.";
        case 9: return "Si no puedes convencerlos, confundelos.";
        case 10: return "La politica es el arte de crear problemas.";
        case 11: return "Donde estan las llaves, matarile, rile, rile...";
        case 12: return "Si no te gustan mis principios, puedo cambiarlos por otros.";
        case 13: return "Un dia lei que fumar era malo y deje de fumar.";
        case 14: return "Yo si se lo que es trabajar duro, de verdad, porque lo he visto por ahi.";
        case 15: return "Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.";
        case 16: return "Mi vida no es tan glamurosa como mi pagina web aparenta.";
        case 17: return "Todo tiempo pasado fue anterior.";
        case 18: return "El azucar no engorda... engorda el que se la toma.";
        case 19: return "Solo los genios somos modestos.";
        case 20: return "Nadie sabe escribir tambien como yo.";
        case 21: return "Si le molesta el mas alla, pongase mas aca.";
        case 22: return "Me gustaria ser valiente. Mi dentista asegura que no lo soy.";
        case 23: return "Si el dinero pudiera hablar, me diria adios.";
        case 24: return "Hoy me ha pasado una cosa tan increible que es mentira.";
        case 25: return "Si no tienes nada que hacer, por favor no lo hagas en clase.";
        case 26: return "Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon y salio una calabaza.";
        case 27: return "Me despido hasta la proxima. Buen viaje!";
        case 28: return "Cualquiera se puede equivocar, inclusivo yo.";
        case 29: return "Estoy en Egipto. Nunca habia visto las piramides tan solas.";
        case 30: return "El que quiera saber mas, que se vaya a Salamanca.";
        default: return "Error";
    }
}

// EJERCIO 002
// Funcion que convierte un texto en su numero correspondiente
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

