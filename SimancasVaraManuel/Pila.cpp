#include "Pila.hpp"

Pila::Pila()
{
}

void Pila::insertaPila(int n, NodoPila *&pila){
    NodoPila *nuevo_nodo = new NodoPila(n);
    nuevo_nodo ->siguiente = pila;
    pila = nuevo_nodo;
}

Pila::~Pila()
{
}

