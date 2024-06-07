#include "Aficionado.hpp"

Aficionado::Aficionado()
{
}

void Aficionado::setID(int n){
    this->ID = n;
    if(n <= 50){
        this->esSocio = true;
    } else{
        this->esSocio = false;
    }
}

int Aficionado::getID(){
    return this->ID;
}

void Aficionado::setLlgada(int n){
    this->Llegada = n;
}

int Aficionado::getLlegada(){
    return this->Llegada;
}

bool Aficionado::esSocioQ(){
    return this->esSocio;
}

Aficionado::~Aficionado()
{
}

