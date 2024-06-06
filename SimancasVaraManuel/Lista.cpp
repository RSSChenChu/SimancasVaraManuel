#include "Lista.hpp"

Lista::Lista()
{
}

void Lista::annadirAficionado(NodoLista *&lista, Aficionado a){
    NodoLista *nodo = new NodoLista(a);
    NodoLista *aux1 = lista;
    NodoLista *aux2;
    
    while((aux1 != NULL) && (aux1 -> aficionado.getLlegada() < a.getLlegada())){ //para mantener siempre ordenada nuestra lista
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    
    if(lista == aux1){ //se cumple siempre y cuando el elemento vaya al principio de la lista
        lista = nodo;
    } else{
        aux2->siguiente = nodo;
    }
    
    nodo->siguiente = aux1;
}

void Lista::mostrarLista(NodoLista *lista){
    NodoLista *actual = lista;
    while(actual!=NULL){
        cout<<actual->aficionado.getID()<<" -> ";
        actual = actual->siguiente;
    }
    cout << "null" << endl;
}

void Lista::eliminarLista(NodoLista *&lista){
    if(lista==NULL){
        cout << "La lista ya está vacía" << endl;
    } else{
        while (lista!=NULL){
            NodoLista *aux_borrar = lista;
            lista = lista->siguiente;
            delete aux_borrar;
        }
    }
}

Lista::~Lista()
{
}

