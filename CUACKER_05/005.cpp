#include "005.h"
#include "004.h"
#include <iostream>
using namespace std;

// inicializamos las variables globales
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

