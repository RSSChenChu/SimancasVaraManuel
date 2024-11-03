#include "Arbol.hpp"

Arbol::Arbol()
{
    Aficionado af = *new Aficionado();
    af.setID(50);
    af.setLlgada(0);
    
    NodoArbol *nuevoNodo = new NodoArbol(af);
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    
    raiz = nuevoNodo;
}

void Arbol::insertarAf(Aficionado a){
    
    if(a.getID() <= 50){
        raiz = insertarAficionadoAbb(raiz, a, ordenInsercionIzq);
    } else{
        raiz = insertarAficionadoAbb(raiz, a, ordenInsercionDer);
    }
}

NodoArbol *Arbol::insertarAficionadoAbb(NodoArbol *&arbol, Aficionado a, vector<Aficionado> orden){
    if(arbol == NULL){ //Si está vacío creamos un nuevo nodo y se lo asignamos
        NodoArbol *nodo = new NodoArbol(a);
        nodo->izq = NULL;
        nodo->der = NULL;
        
        arbol = nodo;
    } else{
        int idRaiz = arbol->aficionado.getID();
        if(a.getID() <= idRaiz){ //Si es menor que la raíz, insertamos por la izq
            insertarAficionadoAbb(arbol->izq, a, ordenInsercionIzq);
        } else{ //en caso contrario insertamos por la der
            insertarAficionadoAbb(arbol->der, a, ordenInsercionDer);
        }
    }
    
    return arbol;
}

void Arbol::obtenerPyUSocio(){
    cout << "El primer Socio en entrar fue " << ordenInsercionIzq.front().getID() << " a las 18:" << ordenInsercionIzq.front().getLlegada()
    << " y el ultimo fue " << ordenInsercionIzq.back().getID() << " a las 18:" << ordenInsercionIzq.back().getLlegada() <<  endl;
}

void Arbol::obtenerPyUSimp(){
    cout << "El primer Socio en entrar fue " << ordenInsercionDer.front().getID() << " a las 18:" << ordenInsercionDer.front().getLlegada()
    << " y el ultimo fue " << ordenInsercionDer.back().getID() << " a las 18:" << ordenInsercionDer.back().getLlegada() <<  endl;
}

void Arbol::pintar()
{
    pintarArbol(raiz);
    cout << '\n';
}

void Arbol::pintarArbol(NodoArbol *nodo){
    if(!nodo)
        return;
    pintarArbol(nodo->izq);
    cout << nodo->aficionado.getID() << " ";
    pintarArbol(nodo->der);
}

int Arbol::altura(NodoArbol *nodo){
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, NodoArbol *nodo, int nivel, int p, char linkChar){
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        int num = nodo->izq->aficionado.getID(); 
        string izqdato = SP + to_string(num) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int num = nodo->aficionado.getID();
    string nododato = SP + to_string(num) + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}

void Arbol::dibujar(){
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

list<Aficionado> Arbol::recorrerIzq(NodoArbol *arbol){
    list<Aficionado> listIzq;
    NodoArbol *socio = raiz->izq;
    if(socio){
        recorridoInorden(socio->izq);
        listIzq.push_back(socio->aficionado);
        recorridoInorden(socio->der);
    }
    return listIzq;
}

list<Aficionado> Arbol::recorrerDer(NodoArbol *arbol){
    list<Aficionado> listDer;
    NodoArbol *simp = raiz->der;
    if(simp){
        recorridoInorden(simp->izq);
        listDer.push_back(simp->aficionado);
        recorridoInorden(simp->der);
    }
    return listDer;
}

void Arbol::reestablecerArbol(NodoArbol *&arbol){
    if(arbol){
        reestablecerArbol(arbol->izq); //Eliminamos el subárbol izq
        reestablecerArbol(arbol->der); //Eliminamos el subárboll der
        delete arbol; //Eliminamos el nodo actual
    }
}

void Arbol::restablecerAbb(){
    reestablecerArbol(raiz);
}

void Arbol::recorridoInorden(NodoArbol *arbol){
    if(arbol){
        recorridoInorden(arbol->izq);
        cout << arbol->aficionado.getID() << "|" << arbol->aficionado.getLlegada() << "  ";
        recorridoInorden(arbol->der);
    }
}

void Arbol::recorridoInordenRaiz(){
    if(raiz){
        recorridoInorden(raiz->izq);
        cout << raiz->aficionado.getID() << "|" << raiz->aficionado.getLlegada() << "  ";
        recorridoInorden(raiz->der);
    }
}

void Arbol::recorridoInordenSocios(){
    NodoArbol *socio = raiz->izq;
    if(socio){
        recorridoInorden(socio->izq);
        cout << socio->aficionado.getID() << "|" << socio->aficionado.getLlegada() << "  ";
        recorridoInorden(socio->der);
    }
}

void Arbol::recorridoInordenSimp(){
    NodoArbol *simp = raiz->der;
    if(simp){
        recorridoInorden(simp->izq);
        cout << simp->aficionado.getID() << "|" << simp->aficionado.getLlegada() << "  ";
        recorridoInorden(simp->der);
    }
}

NodoArbol *Arbol::encontrarSucesor(NodoArbol *nodo){
    while (nodo->izq != NULL) { //Mientras haya nodos a la izq nos seguiremos desplazando por la izq
        nodo = nodo->izq;
    }
    return nodo;
}

void Arbol::eliminarAficionado(NodoArbol *&nodo){
    if (nodo->izq == NULL) { //Si no tiene hijo izq guardamos el hijo derecho en una variable temp y luego lo asignamos como el nuevo nodo
        NodoArbol *temp = nodo->der;
        delete nodo;
        nodo = temp;
    } else if (nodo->der == NULL) { //Realizamos la misma acción en caso de que no tenga hijo der
        NodoArbol *temp = nodo->izq;
        delete nodo;
        nodo = temp;
    } else { //En caso de que tenga los dos buscamos al sucesor en inorden
        NodoArbol *sucesor = encontrarSucesor(nodo->der); //Copiamos los datos del sucesor al nodo actual
        nodo->aficionado = sucesor->aficionado;
        eliminarAficionado(sucesor);
    }
}

void Arbol::eliminarAficionadoAbb(NodoArbol *nodo, int id) {
    if (nodo != NULL) {
        if (id < nodo->aficionado.getID() ){
            eliminarAficionadoAbb(nodo->izq, id); 
        }else if (id > nodo->aficionado.getID()){
           eliminarAficionadoAbb(nodo->der, id); 
        }else {
            eliminarAficionado(nodo);
            return;
        }
    }
}

NodoArbol *Arbol::getRaiz(){
    return raiz;
}

Arbol::~Arbol()
{
}

