#ifndef PILA_HPP
#define PILA_HPP
#include "NodoPila.hpp"

using namespace std;

class Pila
{
public:
    Pila();
    
    ~Pila();
    
    void insertaPila(int, NodoPila *&);
    void muestraPila();
    void borraPila();

private:
    int dato;
    NodoPila *siguiente;
    
};

#endif // PILA_HPP
