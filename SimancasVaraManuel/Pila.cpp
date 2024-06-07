#include "Pila.hpp"

Pila::Pila()
{
    cima = NULL;
}

void Pila::insertarPila(int n){
    NodoPila *nuevo_nodo = new NodoPila(n);
    nuevo_nodo->siguiente = cima;
    cima = nuevo_nodo;
}

void Pila::mostrarPila(){
    if(cima==NULL){
        cout << "La pila esta vacia" << endl;
    } else{
        NodoPila *aux = cima;
        cout << "Los datos de la pila son los siguientes: ";
        while(aux!=NULL){
            cout << dato << ", ";
            aux = aux->siguiente;
        }
        cout << "." << endl;
    }
}

void Pila::borrarPila(){
    while(cima!=NULL){
        NodoPila *aux = cima;
        cima = aux->siguiente;
        delete aux;
    }
}

int Pila::getCima(){
    return cima->valor;
}

int Pila::extraer(){
    NodoPila *temp;
    int n;
    temp = cima;
    cima = temp->siguiente;
    n = temp->valor;
    delete temp;
    return n;
}

Pila::~Pila()
{
}

