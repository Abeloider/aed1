#include "005.h"
#include "006.h"
#include <iostream>
using namespace std;


// hemos tenido que rehacer el ejerccio 5 ya que a la hora de compilarlo con el make nos daba error 
// por lo que aqui esta hecho de otra forma para poder compilarlo y ejecutar el programa    
// nos hemos dado cuenta que lo hicimos en el anterior ejercicio un poco a la fuerza para que nos diera el resultado correcto
// este paso nos llevo demasiado tiempo en resolverlo  
DiccionarioCuacs diccionario;

void procesar_pcuac(){
    Cuac nuevo; // cramos un cuac nuevo temporal
    nuevo.leer_pcuac(); // leemos el pcuac con todos sus parametors
    diccionario.insertar(nuevo); // insertamos el cuac en la lista ordenada del diciocnario 
    cout << diccionario.numElem() << " cuac" << endl; // imprimimos el cuac
}

void procesar_mcuac(){
    Cuac nuevo;
    nuevo.leer_mcuac();
    diccionario.insertar(nuevo);
    cout << diccionario.numElem() << " cuac" << endl;
}

void procesar_last() { 
    int n; 
    cin >> n;
    diccionario.last(n);
}

void procesar_follow(){ 
    string usuario; 
    cin >> usuario;
    diccionario.follow(usuario);
}

void procesar_date(){
    Fecha f1, f2;
    f1.leer();
    f2.leer();
    diccionario.date(f1, f2);
}

void procesar_tag(){
    string tag;
    cin >> tag;
    cout << "tag " << tag << endl;
    cout << "Total: 0 cuac" << endl;
}

void Interprete(string comando){
    if (comando == "pcuac") procesar_pcuac();
    else if (comando == "mcuac") procesar_mcuac();
    else if (comando == "last") procesar_last();
    else if (comando == "follow") procesar_follow();
    else if (comando == "date") procesar_date();
    else if (comando == "tag") procesar_tag();
}