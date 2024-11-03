#ifndef ARBOL_HPP
#define ARBOL_HPP
#include <list>
#include <vector>
#include "NodoArbol.hpp"

using namespace std;

class Arbol
{
public:
    
    Arbol();
    void insertarAf(Aficionado);
    NodoArbol *insertarAficionadoAbb(NodoArbol *&, Aficionado, vector<Aficionado>);
    void pintar();
    void pintarArbol(NodoArbol *);
    int altura(NodoArbol *);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, NodoArbol *nodo, int nivel, int p, char linkChar);
    void dibujar();
    list<Aficionado> recorrerIzq(NodoArbol *);
    list<Aficionado> recorrerDer(NodoArbol *);
    void reestablecerArbol(NodoArbol *&);
    void restablecerAbb();
    void recorridoInorden(NodoArbol *);
    void recorridoInordenRaiz();
    void recorridoInordenSocios();
    void recorridoInordenSimp();
    NodoArbol *encontrarSucesor(NodoArbol *);
    void eliminarAficionado(NodoArbol *&);
    void eliminarAficionadoAbb(NodoArbol *, int);
    NodoArbol *getRaiz();
    void obtenerPyUSocio();
    void obtenerPyUSimp();
    
    ~Arbol();

private:
    
    NodoArbol *raiz;
    vector<Aficionado> ordenInsercionIzq;
    vector<Aficionado> ordenInsercionDer;
};

#endif // ARBOL_HPP
