#include "NodoLista.hpp"

NodoLista::NodoLista(int num, NodoLista* sig)
{
    valor = num;
    siguiente = sig;
}

NodoLista::~NodoLista()
{
}

