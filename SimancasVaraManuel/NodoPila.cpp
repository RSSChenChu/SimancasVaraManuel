#include "NodoPila.hpp"

NodoPila::NodoPila(int num, NodoPila* sig)
{
    valor = num;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
}

