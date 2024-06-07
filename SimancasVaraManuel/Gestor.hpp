#ifndef GESTOR_HPP
#define GESTOR_HPP
#include <cstdlib>
#include <ctime>
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Arbol.hpp"



class Gestor
{
public:
    
    Gestor();
    
    void llenarPilas();
    void mostrarPilas();
    void borrarPilas();
    void generarAficionados();
    void dibujarAbb();
    void insertarEnListas();
    void mostrarListas();
    void borrarListas();
    void insertarEnColas();
    void mostrarColas();
    void borrarColas();
    void mostrarAficionadosEnAbb();
    void mostrarSociosEnAbb();
    void mostrarSimpEnAbb();
    void mostrar4Abb();
    void eliminarAficionadoEnAbb(int);
    void mostrar4Cola();
    void reiniciar();
    
    ~Gestor();

private:
    
    Lista listaSocio;
    Lista listaSimp;
    Arbol abb;
    Cola cola;
    Pila pilaA;
    Pila pilaB;
};

#endif // GESTOR_HPP
