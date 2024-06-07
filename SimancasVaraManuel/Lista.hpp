#ifndef LISTA_HPP
#define LISTA_HPP
#include "Aficionado.hpp"
#include "NodoLista.hpp"

using namespace std;

class Lista
{
public:
    
    Lista();
    
    void annadirAficionado(Aficionado);
    void mostrarLista();
    void eliminarLista();
    NodoLista *getLst();
    
    ~Lista();

private:
    Aficionado aficionado;
    NodoLista *lst;
};

#endif // LISTA_HPP
