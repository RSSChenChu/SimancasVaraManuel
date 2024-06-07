#include "Arbol.hpp"

Arbol::Arbol()
{
    Aficionado af = *new Aficionado();
    af.setID(50);
    af.setLlgada(0);
    
    NodoArbol *nuevoNodo = new NodoArbol(af);
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    
    raiz = nuevoNodo;
}

void Arbol::insertarAf(Aficionado a){
    
    if(a.getID() <= 50){
        raiz = insertarAficionadoAbb(raiz, a, ordenInsercionIzq);
    } else{
        raiz = insertarAficionadoAbb(raiz, a, ordenInsercionDer);
    }
}

NodoArbol *Arbol::insertarAficionadoAbb(NodoArbol *&arbol, Aficionado a, vector<Aficionado> orden){
    if(arbol == NULL){ //Si está vacío creamos un nuevo nodo y se lo asignamos
        NodoArbol *nodo = new NodoArbol(a);
        nodo->izq = NULL;
        nodo->der = NULL;
        
        arbol = nodo;
    } else{
        int idRaiz = arbol->aficionado.getID();
        if(a.getID() <= idRaiz){ //Si es menor que la raíz, insertamos por la izq
            insertarAficionadoAbb(arbol->izq, a, ordenInsercionIzq);
        } else{ //en caso contrario insertamos por la der
            insertarAficionadoAbb(arbol->der, a, ordenInsercionDer);
        }
    }
    
    return arbol;
}

void Arbol::obtenerPyUSocio(){
    cout << "El primer Socio en entrar fué " << ordenInsercionIzq.front().getID() << " a las 18:" << ordenInsercionIzq.front().getLlegada()
    << " y el último fué " << ordenInsercionIzq.back().getID() << " a las 18:" << ordenInsercionIzq.back().getLlegada() <<  endl;
}

void Arbol::obtenerPyUSimp(){
    cout << "El primer Socio en entrar fué " << ordenInsercionDer.front().getID() << " a las 18:" << ordenInsercionDer.front().getLlegada()
    << " y el último fué " << ordenInsercionDer.back().getID() << " a las 18:" << ordenInsercionDer.back().getLlegada() <<  endl;
}

void Arbol::mostrarAbb(NodoArbol *arbol, int cont){ //La variable cont sirve únicamente para separar correctamente el arbol
    if (arbol == NULL){
        cout << "El árbol está vacío" << endl;
    } else{
        mostrarAbb(arbol->der, cont+1);
        for(int i = 0; i < cont; i++){ //este for es únicamente para apicar los espacios correspondientes
            cout << "     ";
        }
        cout << arbol->aficionado.getID() << "|" << arbol->aficionado.getLlegada() << endl; //Se imprimirá de la siguiente forma: id|llegada
        mostrarAbb(arbol->izq, cont+1);
    }
}

list<Aficionado> Arbol::recorrerIzq(NodoArbol *arbol){
    list<Aficionado> listIzq;
    if(arbol){
        list<Aficionado> izquierda = recorrerIzq(arbol->izq);
        listIzq.splice(listIzq.end(), izquierda);
        listIzq.push_back(arbol->aficionado);
    }
    return listIzq;
}

list<Aficionado> Arbol::recorrerDer(NodoArbol *arbol){
    list<Aficionado> listDer;
    if(arbol){ //Recorrido del subárbol izquierdo en inorden
        list<Aficionado> derecha = recorrerIzq(arbol->der);
        listDer.splice(listDer.end(), derecha); //Agregamos los valores del subárbol izq a la lista
        listDer.push_back(arbol->aficionado); //Agregamos el nodo actual
    }
    return listDer;
}

void Arbol::reestablecerArbol(NodoArbol *&arbol){
    if(arbol){
        reestablecerArbol(arbol->izq); //Eliminamos el subárbol izq
        reestablecerArbol(arbol->der); //Eliminamos el subárboll der
        delete arbol; //Eliminamos el nodo actual
    }
}

void Arbol::restablecerAbb(){
    reestablecerArbol(raiz);
}

void Arbol::recorridoInorden(NodoArbol *arbol){
    if(arbol){
        recorridoInorden(arbol->izq);
        cout << arbol->aficionado.getID() << "|" << arbol->aficionado.getLlegada() << "  ";
        recorridoInorden(arbol->der);
    }
}

void Arbol::recorridoInordenRaiz(){
    if(raiz){
        recorridoInorden(raiz->izq);
        cout << raiz->aficionado.getID() << "|" << raiz->aficionado.getLlegada() << "  ";
        recorridoInorden(raiz->der);
    }
}

void Arbol::recorridoInordenSocios(){
    NodoArbol *socio = raiz->izq;
    if(socio){
        recorridoInorden(socio->izq);
        cout << socio->aficionado.getID() << "|" << socio->aficionado.getLlegada() << "  ";
        recorridoInorden(socio->der);
    }
}

void Arbol::recorridoInordenSimp(){
    NodoArbol *simp = raiz->der;
    if(simp){
        recorridoInorden(simp->izq);
        cout << simp->aficionado.getID() << "|" << simp->aficionado.getLlegada() << "  ";
        recorridoInorden(simp->der);
    }
}

NodoArbol *Arbol::encontrarSucesor(NodoArbol *nodo){
    while (nodo->izq != NULL) { //Mientras haya nodos a la izq nos seguiremos desplazando por la izq
        nodo = nodo->izq;
    }
    return nodo;
}

void Arbol::eliminarAficionado(NodoArbol *&nodo){
    if (nodo->izq == NULL) { //Si no tiene hijo izq guardamos el hijo derecho en una variable temp y luego lo asignamos como el nuevo nodo
        NodoArbol *temp = nodo->der;
        delete nodo;
        nodo = temp;
    } else if (nodo->der == NULL) { //Realizamos la misma acción en caso de que no tenga hijo der
        NodoArbol *temp = nodo->izq;
        delete nodo;
        nodo = temp;
    } else { //En caso de que tenga los dos buscamos al sucesor en inorden
        NodoArbol *sucesor = encontrarSucesor(nodo->der); //Copiamos los datos del sucesor al nodo actual
        nodo->aficionado = sucesor->aficionado;
        eliminarAficionado(sucesor);
    }
}

void Arbol::eliminarAficionadoAbb(NodoArbol *nodo, int id) {
    if (nodo != NULL) {
        if (id < nodo->aficionado.getID() ){
            eliminarAficionadoAbb(nodo->izq, id); 
        }else if (id > nodo->aficionado.getID()){
           eliminarAficionadoAbb(nodo->der, id); 
        }else {
            eliminarAficionado(nodo);
            return;
        }
    }
}

NodoArbol *Arbol::getRaiz(){
    return raiz;
}

Arbol::~Arbol()
{
}

