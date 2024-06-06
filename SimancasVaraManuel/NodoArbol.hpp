#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include <iostream>
#include "Aficionado.hpp"

class NodoArbol
{
public:
    NodoArbol(Aficionado a);
    ~NodoArbol();

private:
    Aficionado aficionado;
    NodoArbol *der;
    NodoArbol *izq;
    
    friend class Arbol;
};

#endif // NODOARBOL_HPP
