#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include <iostream>

class NodoLista
{
public:
    NodoLista(int num, NodoLista* sig = NULL);
    ~NodoLista();
    
private:
    int valor;
    NodoLista* siguiente;
    friend class Lista;

};

#endif // NODOLISTA_HPP
