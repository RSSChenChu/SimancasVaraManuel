#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include <iostream>

class NodoCola
{
public:
    NodoCola(int num, NodoCola* sig = NULL);
    ~NodoCola();
    
private:
    int valor;
    NodoCola* siguiente;
    friend class Cola;

};

#endif // NODOCOLA_HPP
