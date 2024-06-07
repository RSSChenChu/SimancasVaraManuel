#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include "Aficionado.hpp"
#include <iostream>

class NodoLista
{
public:
    NodoLista(Aficionado a, NodoLista* sig = NULL);
    ~NodoLista();
    
private:
    Aficionado aficionado;
    NodoLista* siguiente;
    friend class Lista;
    friend class Cola;

};

#endif // NODOLISTA_HPP
