#include "Cola.hpp"

Cola::Cola()
{
}

void Cola::insertarAficionado(NodoCola *&primero, NodoCola*&ultimo, Aficionado a){
    NodoCola *nuevo_nodo = new NodoCola(a);
    nuevo_nodo->siguiente = NULL;
    
    if(primero == NULL){
        primero = nuevo_nodo;
    } else{
        ultimo->siguiente = nuevo_nodo;
    }
}

void Cola::mostrarCola(NodoCola *& cola){
    if (cola==NULL){
        cout << "La cola está vacía" << endl;
    } else{
        NodoCola *aux = cola;
        cout << "Los datos de la cola son los siguientes: ";
        while(aux!=NULL){
            cout << "ID: " << aficionado.getID() << "Hora de llegada: " << ", ";
            aux = aux->siguiente;
        }
        cout << "." << endl;
    }
}

void Cola::eliminarCola(NodoCola *&primero, NodoCola*&ultimo){
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

Cola::~Cola()
{
}

