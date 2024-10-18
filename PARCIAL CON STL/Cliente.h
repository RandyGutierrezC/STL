#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include<string.h>
#include <iostream>
using namespace std;

class Cliente {
private:
    int idCliente;
    string Nombres;
    string Apellidos;
public:
    Cliente(){
    }
    Cliente(int id, string nombres, string apellidos){
        this->idCliente = id;
        this->Nombres = nombres;
        this->Apellidos = apellidos;
    }
    int getIdCliente(){
        return this->idCliente;
    }
    string getNombres(){
        return this->Nombres;
    }
    void setNombres(string sn){
        this->Nombres = sn;
    }
    string getApellidos(){
        return this->Apellidos;
    }
    void setApellidos(string sa){
        this->Apellidos = sa;
    }
};


#endif // CLIENTE_H_INCLUDED
