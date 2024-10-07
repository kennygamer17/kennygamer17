//Clase padre
//Made by kennygamer17 on github || Lexor_12
#include "Producto.h"
#include <conio.h>
#include <string.h>
#include <string>

void actualizarValoresGenerales(int& idProducto,string& id, string& nombre, float& precio, int& cantidadEnStick) {
    id = to_string(idProducto);
    idProducto++;//Made by kennygamer17 on github || Lexor_12
    cout << "Digite el Nombre:"; getline(cin, nombre);
    string aux;
    do {
        cout << "Digite el Precio: "; getline(cin, aux);
        if (!Producto::esIngresoNumericoCorrecto(aux)) {
            cout << "Error, formato incorrecto, recuerde escribir el precio sin $ y otros caracteres, puede usar valores numericos con decimales" << endl;
        }
    } while (!Producto::esIngresoNumericoCorrecto(aux));
    precio = stof(aux);
    do {
        cout << "Digite el numero disponible en stock: "; getline(cin, aux);
        if (!Producto::esIngresoNumericoENTEROCorrecto(aux)) {
            cout << "Error, formato incorrecto, recuerde escribir el precio sin $ y otros caracteres, puede usar valores numericos con decimales" << endl;
        }
    } while (!Producto::esIngresoNumericoENTEROCorrecto(aux));
    precio = stof(aux);
}
bool validadFechaIngreso(string& ingreso) {
    if (ingreso.length() != 10) {
        return false;
    }
    if (ingreso[2] != '/' && ingreso[5] != '/') {
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5) {
            if (!Producto::esNumero(ingreso[i])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Crear la lista de productos
    int idProducto = 0;
    string ingreso = "\0";
    ListadeProductos lista;//Variable general, de esta se hara 1 sola lista     //Made by kennygamer17 on github || Lexor_12
    bool programaContinuar = true;
    cout << "\tBIENVENIDO AL PROGRAMA PARA GESTIONAR PRODUCTOS" << endl;
    while (programaContinuar) {
        ingreso = '\0';
        do {
            cout << "\n\n--------------------------MENU GENERAL--------------------------" << endl;
            cout << "(1)-Mostrar Lista" << endl;
            cout << "(2)-Opciones avanzadas (buscar,agregar,modificar,eliminar un producto)" << endl;
            cout << "(3)-Salir" << endl;//Made by kennygamer17 on github || Lexor_12
            cout << "\n\tDigite la opcion a realizar: "; getline(cin, ingreso);
            if (ingreso.length() > 1 || !Producto::esNumero(ingreso[0])) {
                cout << "Lo sentimos, esa opcion no existe" << endl;
            }
        } while (ingreso.length() > 1 || !Producto::esNumero(ingreso[0]));
        switch (ingreso[0]) {
        case '1':
            lista.mostrarLista();
            break;
        case '2':
            do {
                cout << "\n\n--------------------------Opciones avanzadas--------------------------" << endl;
                cout << "(1)-Buscar un Producto" << endl;
                cout << "(2)-Agregar un Producto" << endl;
                cout << "(3)-Modificar un Producto" << endl;
                cout << "(4)-Eliminar un Producto" << endl;
                cout << "(5)-Salir" << endl;//Made by kennygamer17 on github || Lexor_12
                cout << "\n\tDigite la opcion a realizar: "; getline(cin, ingreso);
                if (ingreso.length() > 1 || !Producto::esNumero(ingreso[0])) {
                    cout << "Lo sentimos, esa opcion no existe" << endl;
                }
            } while (ingreso.length() > 1 || !Producto::esNumero(ingreso[0]));
            switch (ingreso[0]) {
            case '1':
                if (lista.estaVacia()) cout << "La lista se encuentra vacia" << endl;
                else {
                    cout << "Digite la ID del producto a buscar" << endl;
                    getline(cin, ingreso);
                    if (lista.isProductInList(ingreso)) {
                        cout << "\n\tPRODUCTO ENCONTRADO CON EXITO. MOSTRANDO DATOS" << endl;
                        lista.getProducto(ingreso)->mostrarDatos();
                    }
                    break;
                }
                break;
            case '2':
                Producto * nuevo_nodo;
                do {
                    cout << "\n\n--------------------------Agregar nuevo producto--------------------------" << endl;
                    cout << "(1)-Agregar un Electronico" << endl;
                    cout << "(2)-Agregar un Alimento" << endl;
                    cout << "(3)-Agregar una Ropa" << endl;
                    cout << "(4)-Agregar un Producto en general" << endl;
                    cout << "(5)-Salir" << endl;
                    cout << "\n\tDigite la opcion a realizar: "; getline(cin, ingreso);
                    if (ingreso.length() > 1 || !Producto::esNumero(ingreso[0])) {
                        cout << "Lo sentimos, esa opcion no existe" << endl;
                    }
                } while (ingreso.length() > 1 || !Producto::esNumero(ingreso[0]));
                if (ingreso[0] != '5') {
                    string id, nombre, marca, fechaDeCaducidad, tipoDeAlimento, talla, color, tipoDeRopa, aux;
                    float precio = 0.00;
                    int cantidadEnStock = 0, garantia = 0;
                    actualizarValoresGenerales(idProducto,id, nombre, precio, cantidadEnStock);
                    switch (ingreso[0]) {
                    case '1':
                        do {
                            cout << "Digite la garantia en meses del electronico: "; getline(cin, aux);
                            if (!Producto::esIngresoNumericoENTEROCorrecto(aux)) {
                                cout << "Error al ingresar los meses, recuerde ingresar un valor totalmente numerico" << endl;
                            }
                        } while (!Producto::esIngresoNumericoENTEROCorrecto(aux));
                        garantia = stoi(aux);
                        cout << "Digite la marca del electronico: "; getline(cin, marca);
                        //Made by kennygamer17 on github || Lexor_12
                        nuevo_nodo = new Electronico(id, nombre, precio, cantidadEnStock, garantia, marca);
                        lista.addProducto(nuevo_nodo);
                        break;
                    case '2':
                        do {
                            cout << "Digite la fecha de caducidad del alimento en el formato dd/mm/yyyy: "; getline(cin, fechaDeCaducidad);
                            if (!validadFechaIngreso(fechaDeCaducidad)) {
                                cout << "Error, el formato debe ser dd/mmmm/yyyy     ejemplo: 01/01/2000" << endl;
                            }
                        } while (!validadFechaIngreso(fechaDeCaducidad));
                        cout << "Digite el tipo de alimento: "; getline(cin, tipoDeAlimento);
                        nuevo_nodo = new Alimento(id, nombre, precio, cantidadEnStock, fechaDeCaducidad, tipoDeAlimento);
                        lista.addProducto(nuevo_nodo);
                        break;
                    case '3':
                        cout << "Digite la talla de la ropa: "; getline(cin, talla);
                        cout << "Digite la marca de la ropa: "; getline(cin, marca);
                        cout << "Digite el color de la ropa: "; getline(cin, color);
                        cout << "Digite el tipo de ropa: "; getline(cin, tipoDeRopa);
                        nuevo_nodo = new Ropa(id, nombre, precio, cantidadEnStock, talla, marca, color, tipoDeRopa);
                        lista.addProducto(nuevo_nodo);
                        break;
                    case '4':
                        nuevo_nodo = new Producto(id, nombre, precio, cantidadEnStock);
                        nuevo_nodo->setProductoGeneral();
                        lista.addProducto(nuevo_nodo);
                        break;
                    }

                }
                break;
            case '3':
                if (lista.estaVacia()) cout << "La lista se encuentra vacia" << endl;
                else {
                    cout << "Digite la ID del producto a buscar" << endl;
                    getline(cin, ingreso);
                    if (lista.isProductInList(ingreso)) {
                        cout << "\n\tPRODUCTO ENCONTRADO CON EXITO. MODO MODIFICACION" << endl;
                        lista.getProducto(ingreso)->modificar();
                    }
                }
                break;
            case '4':
                if (lista.estaVacia()) cout << "La lista se encuentra vacia" << endl;
                else {
                    cout << "Digite la ID del producto a eliminar" << endl;
                    getline(cin, ingreso);
                    if (lista.isProductInList(ingreso)) {
                        cout << "\n\tPRODUCTO ENCONTRADO CON EXITO. AHORA SERA ELIMINADO" << endl;
                        lista.deleteProducto(ingreso);
                    }
                }//Made by kennygamer17 on github || Lexor_12

                break;
            case '5':
                cout << "Volviendo..." << endl;
                break;
            default:
                cout << "Error, esa opcion no existe, recuerde usar valores numericos" << endl;
                break;
            }
            break;
        case '3':
            cout << "Saliendo del programa. todos los datos seran borrados. gracias por usarme" << endl;
            programaContinuar = false;//Made by kennygamer17 on github || Lexor_12
            break;
        default:
            cout << "Error, esa opcion no existe, recuerde usar valores numericos" << endl;
            break;
        }//Made by kennygamer17 on github || Lexor_12
    }
    return 0;
}
