#include <iostream>
#include"Venta.h"
#include"Cliente.h"
#include"Producto.h"
#include"STL.h"

using namespace std;

int main() {
    List<Cliente*> listaClientes; // Usamos List para clientes con punteros
    List<Producto*> listaProductos; // Usamos List para productos con punteros
    List<Venta*> listaVentas; // Usamos List para ventas con punteros

    int opcion = 0;
    while (opcion != 8) {

        // Menú de opciones
        cout << "\nMENU DE OPCIONES" << endl;
        cout << "1. Agregar Clientes" << endl;
        cout << "2. Agregar Productos" << endl;
        cout << "3. Hacer Ventas" << endl;
        cout << "4. Ver lista de clientes" << endl;
        cout << "5. Ver lista de productos" << endl;
        cout << "6. Ver lista de ventas" << endl;
        cout << "7. Ver detalles de la venta" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                system("cls");
                // Agregar cliente
                int id;
                string nombre, apellido;
                cout << "\nIngrese ID del cliente: ";
                cin >> id;
                cout << "Ingrese nombre del cliente: ";
                cin >> nombre;
                cout << "Ingrese apellido del cliente: ";
                cin >> apellido;
                listaClientes.push_back(new Cliente(id, nombre, apellido)); // Crear cliente dinámicamente
                cout << "Cliente agregado exitosamente.\n";
                break;
            }
            case 2: {
                system("cls");
                // Agregar producto
                int id;
                string descripcion;
                float precio;
                int existencias;
                cout << "\nIngrese ID del producto: ";
                cin >> id;
                cout << "Ingrese descripcion del producto: ";
                cin >> descripcion;
                cout << "Ingrese precio unitario del producto: ";
                cin >> precio;
                cout << "Ingrese existencias del producto: ";
                cin >> existencias;
                listaProductos.push_back(new Producto(id, descripcion, precio, existencias)); // Crear producto dinámicamente
                cout << "Producto agregado exitosamente.\n";
                break;
            }
            case 3: {
                system("cls");
                // Hacer una venta
                int idVenta, idCliente;
                cout << "\nIngrese el numero de factura: ";
                cin >> idVenta;
                cout << "Ingrese el ID del cliente que realiza la compra: ";
                cin >> idCliente;

                Cliente* cliente = nullptr;
                for (List<Cliente*>::Iterator it = listaClientes.begin(); it != listaClientes.end(); ++it) {
                    if ((*it)->getIdCliente() == idCliente) {
                        cliente = *it; // Cliente encontrado, tomar el puntero
                        break;
                    }
                }

                if (cliente == nullptr) {
                    cout << "Cliente no encontrado.\n";
                } else {
                    Venta* nuevaVenta = new Venta(idVenta, "2023-09-01", cliente); // Crear venta dinámicamente
                    int idProducto, cantidad;
                    char agregarOtroProducto;

                    do {
                        cout << "Ingrese el ID del producto a vender: ";
                        cin >> idProducto;

                        Producto* producto = nullptr;
                        for (List<Producto*>::Iterator it = listaProductos.begin(); it != listaProductos.end(); ++it) {
                            if ((*it)->getIdProducto() == idProducto) {
                                producto = *it; // Producto encontrado, tomar el puntero
                                break;
                            }
                        }

                        if (producto == nullptr) {
                            cout << "Producto no encontrado.\n";
                        } else {
                            cout << "Ingrese la cantidad a vender: ";
                            cin >> cantidad;

                            if (producto->getExistencia() >= cantidad) {
                                producto->setExistencia(producto->getExistencia() - cantidad);  // Actualizar existencias
                                nuevaVenta->agregarProducto(producto);  // Agregar producto a la venta
                                cout << "Producto agregado a la venta.\n";
                            } else {
                                cout << "No hay suficientes existencias para este producto.\n";
                            }
                        }

                        cout << "¿Desea agregar otro producto? (s/n): ";
                        cin >> agregarOtroProducto;

                    } while (agregarOtroProducto == 's' || agregarOtroProducto == 'S');
                    listaVentas.push_back(nuevaVenta);  // Guardar la venta
                    cout << "Venta realizada exitosamente.\n";
                }
                break;
            }
            case 4: {
                system("cls");
                // Ver lista de clientes
                cout << "\nLista de clientes:\n";
                for (auto it = listaClientes.begin(); it != listaClientes.end(); ++it) {
                    cout << "ID: " << (*it)->getIdCliente() << ", Nombre: " << (*it)->getNombres() << " " << (*it)->getApellidos() << endl;
                }
                break;
            }
            case 5: {
                system("cls");
                // Ver lista de productos
                cout << "\nLista de productos:\n";
                for (auto it = listaProductos.begin(); it != listaProductos.end(); ++it) {
                    cout << "ID: " << (*it)->getIdProducto() << ", Descripcion: " << (*it)->getDescripcion() << ", Precio Unitario: " << (*it)->getPrecioUnitario() << ", Existencias: " << (*it)->getExistencia() << endl;
                }
                break;
            }
            case 6: {
                system("cls");
                // Ver lista de ventas
                cout << "\nLista de ventas:\n";
                for (auto it = listaVentas.begin(); it != listaVentas.end(); ++it) {
                    cout << "Factura No: " << (*it)->getNumeroFactura() << ", Fecha: " << (*it)->getFecha() << endl;
                }
                break;
            }
            case 7: {
                system("cls");
                // Ver detalles de una venta específica
                int idVenta;
                cout << "\nIngrese el numero de factura para ver detalles: ";
                cin >> idVenta;

                Venta* venta = nullptr;
                for (List<Venta*>::Iterator it = listaVentas.begin(); it != listaVentas.end(); ++it) {
                    if ((*it)->getNumeroFactura() == idVenta) {
                        venta = *it; // Venta encontrada
                        break;
                    }
                }

                if (venta != nullptr) {
                    cout << "\nDetalles de la venta:\n";
                    cout << "Factura No: " << venta->getNumeroFactura() << endl;
                    cout << "Fecha de Venta: " << venta->getFecha() << endl;
                    Cliente* cliente = venta->getCliente();
                    cout << "Cliente: " << cliente->getNombres() << " " << cliente->getApellidos() << endl;

                    cout << "Productos vendidos:\n";
                    List<Producto*> productos = venta->getListaProducto();
                    for (auto it = productos.begin(); it != productos.end(); ++it) {
                        cout << "Producto: " << (*it)->getDescripcion() << ", Precio: " << (*it)->getPrecioUnitario() << endl;
                    }
                } else {
                    cout << "Venta no encontrada.\n";
                }
                break;
            }
            case 8: {
                system("cls");
                cout << "Saliendo del programa...\n";
                break;
            }
            default: {
                cout << "Opción no válida. Intente de nuevo.\n";
            }
        }
    }

    return 0;
}
