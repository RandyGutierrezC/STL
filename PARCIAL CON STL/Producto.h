#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include<string.h>
#include "Medida.h"
using namespace std;

class Producto {
private:
    int idProducto;
    string descripcion;
    float precioUnitario;
    Medida unidadMedida;
    float existencia;

public:
    Producto(){
    }

    Producto(int id, string desc, float precio, float exist){
        this->idProducto = id;
        this->descripcion = desc;
        this->precioUnitario = precio;
        this->existencia = exist;
    }

    void setIdProducto(int id) {
        idProducto = id;
    }

    void setDescripcion(string desc) {
        descripcion = desc;
    }

    void setPrecioUnitario(float precio) {
        precioUnitario = precio;
    }

    void setExistencia(float exist) {
        existencia = exist;
    }

    void setUnidadMedida(Medida medida) {
        unidadMedida = medida;
    }

    int getIdProducto(){
        return idProducto;
    }

    string getDescripcion(){
        return descripcion;
    }

    float getPrecioUnitario(){
        return precioUnitario;
    }

    float getExistencia(){
        return existencia;
    }

    Medida getUnidadMedida(){
        return unidadMedida;
    }
};

#endif // PRODUCTO_H_INCLUDED
