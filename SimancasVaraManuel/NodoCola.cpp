#include "NodoCola.hpp"

NodoCola::NodoCola(int num, NodoCola* sig)
{
    valor = num;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
}

