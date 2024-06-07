#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
}

void Cola::insertarAficionado(Aficionado a){
    NodoCola *nuevo_nodo = new NodoCola(a);
    nuevo_nodo->siguiente = NULL;
    
    if(primero == NULL){
        primero = nuevo_nodo;
    } else{
        ultimo->siguiente = nuevo_nodo;
    }
}

void Cola::insertarEnCola(NodoLista *l){
    NodoLista *actual = l;
    while(actual!=NULL){
        insertarAficionado(actual->aficionado);
        actual = actual->siguiente;
    }
}

void Cola::mostrarCola(){
    if (primero==NULL){
        cout << "La cola esta vacia" << endl;
    } else{
        NodoCola *aux = primero;
        cout << "Los datos de la cola son los siguientes: ";
        while(aux!=NULL){
            cout << "ID: " << aficionado.getID() << "Hora de llegada: " << ", ";
            aux = aux->siguiente;
        }
        cout << "." << endl;
    }
}

void Cola::eliminarCola(){
    while(primero!=NULL){
        NodoCola *aux = primero;
        if(primero == ultimo){
            primero = NULL;
            ultimo = NULL;
        } else{
            primero = primero->siguiente;
        }
        delete aux;
    }
}

NodoCola *Cola::getPrimero(){
    return primero;
}

Cola::~Cola()
{
}

