#include "004.cpp"


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
