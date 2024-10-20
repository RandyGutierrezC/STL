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
        List<Producto*> productosVendidos;

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
        void agregarProducto(Producto *p) {
            /*
            productosVendidos.push_back(p); // Usar la función push_back de List
            */
            if (p != nullptr) {
                productosVendidos.push_back(p);  // Agregar el puntero a la lista
                cout << "Producto agregado: " << p->getDescripcion() << endl;
            } else {
                cout << "Error: Intentando agregar un puntero nulo a la lista de productos." << endl;
            }
        }
        void setProductosVendidos(List<Producto*> spv) {
            /*
            this->productosVendidos = spv;
            */
            productosVendidos.clear();  // Limpiar la lista actual antes de reemplazarla
            this->productosVendidos = spv;
        }
        List<Producto*> getListaProducto() { // Devolver la referencia a la lista de productos
            // Verificar si la lista tiene punteros válidos
    for (auto it = productosVendidos.begin(); it != productosVendidos.end(); ++it) {
        if (*it == nullptr) {
            cout << "Error: La lista contiene un puntero nulo." << endl;
        }
    }
    return this->productosVendidos;  // Devolver la referencia a la lista original
        }
};


#endif // VENTA_H_INCLUDED
