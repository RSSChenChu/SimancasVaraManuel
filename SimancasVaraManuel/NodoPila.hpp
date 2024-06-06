#ifndef NODOPILA_HPP
#define NODOPILA_HPP
#include <iostream>

class NodoPila
{
public:
    NodoPila(int num, NodoPila *sig = NULL);
    ~NodoPila();
    
private:
    int valor;
    NodoPila* siguiente;
    friend class Pila;

};

#endif // NODOPILA_HPP
