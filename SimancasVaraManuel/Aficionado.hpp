#ifndef AFICIONADO_HPP
#define AFICIONADO_HPP

using namespace std;

class Aficionado
{
public:
    
    Aficionado();
    
    bool esSocioQ();
    void setID(int n);
    void setLlgada(int n);
    int getID();
    int getLlegada();
    
    ~Aficionado();

private:
    
    bool esSocio;
    int ID;
    int Llegada;
    
};

#endif // AFICIONADO_HPP
