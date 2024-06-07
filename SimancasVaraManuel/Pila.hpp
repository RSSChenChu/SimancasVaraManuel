#ifndef PILA_HPP
#define PILA_HPP
#include "Aficionado.hpp"
#include "NodoPila.hpp"

using namespace std;

class Pila
{
public:
    Pila();
    
    void insertarPila(int);
    void mostrarPila();
    void borrarPila();
    int getCima();
    int extraer();
    
    ~Pila();
    
private:
    int dato;
    NodoPila *cima;
    int numDatos;
};

#endif // PILA_HPP
