#include "Lista.hpp"

Lista::Lista()
{
    lst = NULL;
}

void Lista::annadirAficionado(Aficionado a){
    NodoLista *nodo = new NodoLista(a);
    NodoLista *aux1 = lst;
    NodoLista *aux2;
    
    while((aux1 != NULL) && (aux1 -> aficionado.getLlegada() < a.getLlegada())){ //para mantener siempre ordenada nuestra lista
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    
    if(lst == aux1){ //se cumple siempre y cuando el elemento vaya al principio de la lista
        lst = nodo;
    } else{
        aux2->siguiente = nodo;
    }
    
    nodo->siguiente = aux1;
}

void Lista::mostrarLista(){
    NodoLista *actual = lst;
    while(actual!=NULL){
        cout << actual->aficionado.getID() << "es socio: " << (actual->aficionado.esSocioQ() ? "Sí" : "No") << " -> ";
        actual = actual->siguiente;
    }
    cout << "null" << endl;
}

void Lista::eliminarLista(){
    if(lst==NULL){
        cout << "La lista ya está vacía" << endl;
    } else{
        NodoLista *aux = lst;
        lst = aux->siguiente;
        delete aux;
    }
}

NodoLista *Lista::getLst(){
    return lst;
}

Lista::~Lista()
{
}

