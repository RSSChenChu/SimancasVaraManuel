#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
#include "NodoLista.hpp"

using namespace std;

class Cola
{
public:
    
    Cola();
    
    void insertarAficionado(Aficionado);
    void insertarEnCola(NodoLista *);
    void mostrarCola();
    void eliminarCola();
    NodoCola *getPrimero();
    
    ~Cola();

private:
    
    Aficionado aficionado;
    NodoCola *primero, *ultimo;

};

#endif // COLA_HPP
