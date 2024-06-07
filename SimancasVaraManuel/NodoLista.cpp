#include "NodoLista.hpp"

NodoLista::NodoLista(Aficionado a, NodoLista* sig)
{
    aficionado = a;
    siguiente = sig;
}

Aficionado NodoLista::getAficionado(){
    return aficionado;
}

NodoLista::~NodoLista()
{
}

