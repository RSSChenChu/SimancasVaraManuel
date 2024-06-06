#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Aficionado a)
{
    this->aficionado = a;
    this->der = NULL;
    this->izq = NULL;
}

NodoArbol::~NodoArbol()
{
}

