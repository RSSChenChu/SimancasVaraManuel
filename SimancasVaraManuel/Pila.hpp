#ifndef PILA_HPP
#define PILA_HPP
#include "NodoPila.hpp"

using namespace std;

class Pila
{
public:
    Pila();
    
    void insertaPila(int, NodoPila *&);
    void muestraPila(NodoPila *&);
    void borraPila(NodoPila *&);
    
    ~Pila();
    
private:
    int dato;
    NodoPila *siguiente;
    int numDatos;
};

#endif // PILA_HPP
