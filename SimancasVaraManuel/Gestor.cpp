#include <Gestor.hpp>

using namespace std;

Gestor::Gestor()
{
    listaSocio = *new Lista();
    listaSimp = *new Lista();
    abb = *new Arbol();
    cola = *new Cola();
    pilaA = *new Pila();
    pilaB = *new Pila();
}

void Gestor::llenarPilas(){
    if((pilaA.getDato() != NULL) || (pilaB.getDato() != NULL)){
        pilaA.borrarPila();
        pilaB.borrarPila();
    }
        
    srand(time(0)); //Inicializamos el generador de número aleatorios basada en el tiempo actual para que no se repitan
    
    for(int i = 0; i < 20; ++i){
        int n = (rand() % 100) + 1; //Generamos un número entre 1 a 100
        pilaA.insertarPila(n);
    }
    
    for(int i = 0; i < 20; ++i){
        int m = (rand() % 60); //Generamos un número entre 0 a 59
        pilaB.insertarPila(m);
    }
}

void Gestor::mostrarPilas(){
    pilaA.mostrarPila();
    pilaB.mostrarPila();
}

void Gestor::borrarPilas(){
    pilaA.borrarPila();
    pilaB.borrarPila();
}

void Gestor::generarAficionados(){
    for(int i = 0; i < 20; ++i){
        Aficionado af = *new Aficionado();
        af.setID(pilaA.extraer());
        af.setLlgada(pilaB.extraer());
        
        cout << af.getID() << " - ";
        
        abb.insertarAf(af);
    }
}

void Gestor::dibujarAbb(){
    
    abb.dibujar();
    
}

void Gestor::insertarEnListas(){
    if((listaSimp.getLst() != NULL) || (listaSocio.getLst() != NULL)){
        borrarListas();
    } else{
        list<Aficionado> l1 = abb.recorrerIzq(abb.getRaiz());
        list<Aficionado> l2 = abb.recorrerDer(abb.getRaiz());
        abb.restablecerAbb();
        
        for(auto it = l1.begin(); it != l1.end(); ++it){
            listaSocio.annadirAficionado(*it);
        }
        
        for(auto it = l2.begin(); it != l2.end(); ++it){
            listaSimp.annadirAficionado(*it);
        }
    }
}

void Gestor::mostrarListas(){
    listaSocio.mostrarLista();
    listaSimp.mostrarLista();
}

void Gestor::borrarListas(){
    listaSocio.eliminarLista();
    listaSimp.eliminarLista();
}

void Gestor::insertarEnColas(){
    if(cola.getPrimero() != NULL){
        borrarColas();
    } else{
        cola.insertarEnCola(listaSocio.getLst());
        cola.insertarEnCola(listaSimp.getLst());
    }
}

void Gestor::mostrarColas(){
    cola.mostrarCola();
}

void Gestor::borrarColas(){
    cola.eliminarCola();
}

void Gestor::mostrarAficionadosEnAbb(){
    abb.recorridoInordenRaiz();
}

void Gestor::mostrarSociosEnAbb(){
    abb.recorridoInordenSocios();
}

void Gestor::mostrarSimpEnAbb(){
    abb.recorridoInordenSimp();
}

void Gestor::mostrar4Abb(){
    abb.obtenerPyUSocio();
    abb.obtenerPyUSimp();
}

void Gestor::eliminarAficionadoEnAbb(int id){
    abb.eliminarAficionadoAbb(abb.getRaiz(), id);
}

void Gestor::mostrar4Cola(){
    
}

void Gestor::reiniciar(){
    pilaA.borrarPila();
    pilaB.borrarPila();
    abb.restablecerAbb();
    listaSocio.eliminarLista();
    listaSimp.eliminarLista();
    cola.eliminarCola();
}

Gestor::~Gestor()
{
}