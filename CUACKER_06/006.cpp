#include "006.h"
#include "005.h"


// IMPLEMENTAMOS EL CONSTRUCTOR FUERA DE LA CLASE
DiccionarioCuacs::DiccionarioCuacs() {
    contador = 0;
}

void DiccionarioCuacs::insertar(Cuac nuevo) {
    list<Cuac>::iterator itLista = lista.begin();
    // a la hora de realizar la prueba no me daban las fechas correctas ya que no consideraban el orden 
    // para corregir este error hemos añadido al nuevo.es_anterior(*itLista) que avanzamos mientras 
    // que el nuevo sea anterior que *itlista
    while (itLista != lista.end() && nuevo.es_anterior(*itLista)) {
        itLista++;
    }
    lista.insert(itLista, nuevo);
    contador++;
}


// listar los ultimos n cuacs
void DiccionarioCuacs::last (int n) {
    cout<<"last "<< n <<endl;
    int count=0;
    list<Cuac>::iterator it;
    for (it = lista.begin(); it != lista.end() && count < n; it++) {
        count++;
        cout << count << ". ";
        it->escribir();
    }
    cout << "Total: " << count << " cuac" << endl;
}


// listamos todos los cuacs del usuario 
void DiccionarioCuacs::follow(string nombre) {
    cout<<"follow "<<nombre<<endl;
    list<Cuac>::iterator it = lista.begin();
    int count=0;
    for (it= lista.begin(); it!=lista.end(); it++) {
        // ya que necesitamos el valor del usuario y como el usuario esta en privado hemos declarado un metodo getUsuario.
        if (it->getUsuario() == nombre) { // hago que el it coja el usuario y compruebe si es el mismo usuario en caso de que si:
            count++; // sumamos al contador 1
            cout << count << ". ";
            it->escribir();
        }
    }
    cout << "Total: " << count << " cuac" << endl;
}


// listamos los cuacs entre dos fechass
void DiccionarioCuacs::date(Fecha f1, Fecha f2) {
    cout<<"date ";
    f1.escribir();
    cout<<" ";
    f2.escribir();
    cout<<endl;
    
    list<Cuac>::iterator it = lista.begin();
    int count=0;
    for(it=lista.begin(); it!=lista.end(); it++) {
    Fecha aux= it->getFecha();
     if((f1.esMenor(aux)&&aux.esMenor(f2))||aux.esIgual(f1)||aux.esIgual(f2)) {
        count++;
        cout << count << ". ";
        it->escribir();
     }
    }
    cout << "Total: " << count << " cuac" << endl;
}
