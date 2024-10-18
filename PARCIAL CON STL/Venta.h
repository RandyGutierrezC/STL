#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include<string.h>
#include"Producto.h"
#include "Cliente.h"
#include "STL.h"
using namespace std;

class Venta{
    private:
        int noFactura;
        string fechaVenta;
        Cliente *cliente;
        List<Producto> productosVendidos;

    public:
        Venta(){
        }
        Venta(int nF,string fV, Cliente *c){
            this->noFactura=nF;
            this->fechaVenta=fV;
            this->cliente=c;
        }
        void setNumeroFactura(int nf) {
        this->noFactura = nf;
        }

        int getNumeroFactura() {
            return this->noFactura;
        }

        void setFecha(string fv) {
            this->fechaVenta = fv;
        }

        string getFecha() {
            return this->fechaVenta;
        }

        void setCliente(Cliente* c) {
            this->cliente = c;
        }

        Cliente* getCliente() {
            return this->cliente;
        }

        void agregarProducto(Producto p) {
            productosVendidos.push_back(p); // Usar la función push_back de List
        }

        List<Producto> getListaProducto() { // Devolver la referencia a la lista de productos
            return this->productosVendidos;
        }

        int getNumeroProducto() {
            return productosVendidos.get_size(); // Obtener el tamaño con tu lista STL
        }

};


#endif // VENTA_H_INCLUDED
