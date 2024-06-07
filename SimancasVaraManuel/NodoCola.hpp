#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include "Aficionado.hpp"
#include <cstddef>

class NodoCola
{
public:
    NodoCola(Aficionado a, NodoCola* sig= NULL);
    ~NodoCola();
    
private:
    Aficionado aficionado;
    NodoCola* siguiente;
    friend class Cola;

};

#endif // NODOCOLA_HPP
