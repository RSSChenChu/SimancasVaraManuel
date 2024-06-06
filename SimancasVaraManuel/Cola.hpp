#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"

using namespace std;

class Cola
{
public:
    
    Cola();
    
    void insertarAficionado(NodoCola *&, NodoCola *&, Aficionado);
    void mostrarCola(NodoCola *&);
    void eliminarCola(NodoCola *&, NodoCola *&);
    
    ~Cola();

private:
    
    Aficionado aficionado;
    NodoCola *siguiente;

};

#endif // COLA_HPP
