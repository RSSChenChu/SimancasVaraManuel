#include "Pila.hpp"

Pila::Pila()
{
}

void Pila::insertaPila(int n, NodoPila *&pila){
    NodoPila *nuevo_nodo = new NodoPila(n);
    nuevo_nodo ->siguiente = pila;
    pila = nuevo_nodo;
}

void Pila::muestraPila(NodoPila *&pila){
    if(pila==NULL){
        cout << "La pila está vacía" << endl;
    } else{
        NodoPila *aux = pila;
        cout << "Los datos de la pila son los siguientes: "
        while(aux!=NULL){
            cout << dato << ", ";
            aux = aux->siguiente;
        }
        cout << "." << endl;
    }
}

void Pila::borraPila(NodoPila *&pila){
    while(pila!=NULL){
        NodoPila *aux = pila;
        n = aux-> valor;
        pila = aux->siguiente;
        delete aux;
    }
}

Pila::~Pila()
{
}

