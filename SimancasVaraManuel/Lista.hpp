#ifndef LISTA_HPP
#define LISTA_HPP
#include "Aficionado.hpp"
#include "NodoLista.hpp"

using namespace std;

class Lista
{
public:
    
    Lista();
    
    void annadirAficionado(NodoLista *&, Aficionado);
    void mostrarLista(NodoLista *);
    void eliminarLista(NodoLista *&);
    
    ~Lista();

private:
    int dato;
    NodoLista *siguiente;
};

#endif // LISTA_HPP
