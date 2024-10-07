#pragma once
//Librerias estandares de C++
#include<iostream>	
#include <string>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

	using namespace std;

//Clase base del proyecto:

class Producto {
	private://Made by kennygamer17 on github || Lexor_12
		bool producto;
		string ID;
		string nombre;
		float precio;
		long cantidadEnStock;
	public:
		//Constructor
		Producto() : ID("Sin Asignar"), nombre("Sin Asignar"), precio(0.00), cantidadEnStock(0) {  }
		Producto(string ID, string nombre, float precio, long cantidadEnStock) { this->ID = ID; this->nombre = nombre; this->precio = precio; this->cantidadEnStock = cantidadEnStock; 
		}
		//Destructor
		~Producto() {}
		//Funciones polimorficas
		virtual void mostrarDatos() {
			if (!producto) {
				cout << "\nTipo de Producto: PRODUCTO GENERAL" << endl;
			}
			cout << "\tID: " << Producto::getID() << endl;//Indico que me muestra la funcion de la clase
			cout << "\tNombre: " << Producto::getNombre() << endl;
			cout << "\tPrecio: " << Producto::getPrecio() << endl;//Made by kennygamer17 on github || Lexor_12
			cout << "\tCantidad en stock: " << Producto::getCantidadEnStock() << endl;
		};
		virtual void modificar() {
			string ingreso;
			do {
				system("cls");
				cout << "------------MODIFICACIONES BASICAS------------" << endl;
				cout << "(1)-Modificar ID del producto" << endl;
				cout << "(2)-Modificar Nombre del producto" << endl;
				cout << "(3)-Modificar Precio del producto" << endl;
				cout << "(4)-Modificar Cantidad en Stock del producto" << endl;
				cout << "(5)-Volver" << endl;
				getline(cin, ingreso);
				if (ingreso.length() > 1 || (!esNumero(ingreso[0])) || (esNumero(ingreso[0]) && (stof(ingreso) > 5 || (stof(ingreso) < 1)))) {
					cout << "Error de digitacion... Porfavor asegurece de digitar una de las opciones de manera correcta." << endl;
				}
			} while (ingreso.length() > 1 || (!esNumero(ingreso[0])) || (esNumero(ingreso[0]) && (stof(ingreso) > 5 || (stof(ingreso) < 1))));
			switch (ingreso[0]) {
			case '1':
				cout << "\n\n ID actual: " << getID() << endl;
				cout << "Nuevo ID: "; getline(cin, ingreso);
				setID(ingreso);
				cout << "\n\n\t Se ha modificado adecuadamente...." << endl;
				break;//Made by kennygamer17 on github || Lexor_12
			case '2':
				cout << "\n\n Nombre actual: " << getNombre() << endl;
				cout << "Nuevo Nombre: "; getline(cin, ingreso);
				setNombre(ingreso);
				cout << "\n\n\t Se ha modificado adecuadamente...." << endl;
				break;
			case '3':
				do {
					cout << "\n\n Precio actual: " << getPrecio() << endl;
					cout << "Nuevo Precio: "; getline(cin, ingreso);
					if (!esIngresoNumericoCorrecto(ingreso)) {
						cout << "Error de digitacion... Porfavor asegurece de digitar un numero correcto." << endl;
					}
				} while (!esIngresoNumericoCorrecto(ingreso));
				setPrecio(stof(ingreso));
				cout << "\n\n\t Se ha modificado adecuadamente...." << endl;
				break;
			case '4':
				do {
					cout << "\n\n Cantidad en stock disponible actual: " << getCantidadEnStock() << endl;
					cout << "Nuevo Cantidad en stock disponible: "; getline(cin, ingreso);
					if (!esIngresoNumericoCorrecto(ingreso)) {
						cout << "Error de digitacion... Porfavor asegurece de digitar un numero correcto." << endl;
					}//Made by kennygamer17 on github || Lexor_12
				} while (!esIngresoNumericoCorrecto(ingreso));
				setCantidadEnStock(stol(ingreso));
				cout << "\n\n\t Se ha modificado adecuadamente...." << endl;
				break;
			case '5':
				cout << "No se hare ningun cambio.... Volviendo" << endl;
				break;
			default:
				cout << "Lo sentimos, ha ocurrido un error inesperado." << endl;
				break;
			}
		}//Desarrollare esta funcion en cada una, ya que lo veo mejor
		//Setters
		void setProductoGeneral() { if (producto) producto = false; else producto = true; }
		void setProducto(string ID, string nombre, float precio, long cantidadEnStock) { this->ID = ID; this->nombre = nombre; this->precio = precio; this->cantidadEnStock = cantidadEnStock; }
		void setID(string ID) { this->ID = ID;}
		void setNombre(string nombre) { this->nombre = nombre; } //This nos permite llamar al atributo, ya que como usamos nombre en parametro de este metodo, como tal ya no puedo usar el identificador nombre para referenciarme al atributo, asi que tengo que usar this
		void setPrecio(float precio) { this->precio = precio; }
		void setCantidadEnStock(long cantidadEnStock) { this->cantidadEnStock = cantidadEnStock; }
		//Getters
		string getID() { return ID; }
		string getNombre() { return nombre; }
		float getPrecio() { return precio; }
		long getCantidadEnStock() { return cantidadEnStock; }

		//Funcion estatica
		static bool esIngresoNumericoCorrecto(string ingreso) {
			bool punto = false;
			if (ingreso.empty() || (!esNumero(ingreso[0]) && (ingreso[0] != '+' && ingreso[0] != '-' && ingreso[0] != '.'))) return false;
			for (int i = 1; i < ingreso.length(); i++) {
				if (!esNumero(ingreso[i])) {
					if (ingreso[i] == '.' && !punto) {
						punto = true;
					}
					else {
						return false;
					}//Made by kennygamer17 on github || Lexor_12
				}
			}
			return true;
		}
		static bool esIngresoNumericoENTEROCorrecto(string ingreso) {
			bool punto = false;
			if (ingreso.empty() || (!esNumero(ingreso[0]) && (ingreso[0] != '+' && ingreso[0] != '-'))) return false;
			for (int i = 1; i < ingreso.length(); i++) {
				if (!esNumero(ingreso[i])) {
						return false;
				}
			}
			return true;
		}
		static bool esNumero(char c) {//Se puede remplazar con isdigit, pero decidi hacer mi propia funcion
			switch (c) {
			case '0'://Made by kennygamer17 on github || Lexor_12
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': return true;
				break;
			default: return false;
				break;
			}
		}
};

class Alimento : public Producto {
private://Atributos
	struct fechaDeCaducidad {
		int year, mes, dia;
		string fecha;
	}fechadeCaducidad; //Variable que funciona como estructura
	int devolverEntero(string cadena, int fu, int lu) {
		if (esIngresoNumericoCorrecto(cadena)) {
			string subcadena = cadena.substr(fu, lu - fu); // Extrae la subcadena
			return stoi(subcadena); // Convierte a entero y retorna;
		}
		return 0;
	}
	string tipoDeAlimento;
public://Metodos
	//Constructores
	Alimento() : Producto(), tipoDeAlimento("Sin Asignar") {
		fechadeCaducidad.fecha = "01/01/2000";
		fechadeCaducidad.year = 2000;
		fechadeCaducidad.mes = 01;
		fechadeCaducidad.dia = 01;
	}//Constructor default
	Alimento(string id, string nombre, float precio, long cantidadDisponible, string fechaCaducidad, string tipoAlimento) : Producto(id, nombre, precio, cantidadDisponible), tipoDeAlimento(tipoAlimento) {
		fechadeCaducidad.fecha = fechaCaducidad;
		if (devolverEntero(fechaCaducidad, 6, 10) > 0 && devolverEntero(fechaCaducidad, 3, 5) > 0 && devolverEntero(fechaCaducidad, 0, 2) > 0) {
			fechadeCaducidad.year = devolverEntero(fechaCaducidad, 6, 10);
			fechadeCaducidad.mes = devolverEntero(fechaCaducidad, 3, 5);
			fechadeCaducidad.dia = devolverEntero(fechaCaducidad, 0, 2);
		}		//Si de plano estan los ingresos mal, pues seguira en deafault por seguridad
	} //Constructor con parametros
	//Destructor//Made by kennygamer17 on github || Lexor_12
	~Alimento() {}

	//Setters
	void setAlimento(string id, string nombre, float precio, long cantidadDisponible, string fechaCaducidad, string tipoAlimento) {
		setID(id);
		setNombre(nombre);
		setPrecio(precio);
		setCantidadEnStock(cantidadDisponible);
		tipoDeAlimento = tipoAlimento;
		if (setfechaDeCaducidad(fechaCaducidad)) {
			fechaCaducidad = fechaCaducidad;
			cerr << "Error al ingresar la fecha, formato incorrecto" << endl;
		}
	}
	bool setfechaDeCaducidad(string fechaDeCaducidad) {
		fechadeCaducidad.fecha = fechaDeCaducidad;
		if (devolverEntero(fechaDeCaducidad, 6, 10) > 0 && devolverEntero(fechaDeCaducidad, 3, 5) > 0 && devolverEntero(fechaDeCaducidad, 0, 2) > 0) {
			fechadeCaducidad.year = devolverEntero(fechaDeCaducidad, 6, 10);
			fechadeCaducidad.mes = devolverEntero(fechaDeCaducidad, 3, 5);
			fechadeCaducidad.dia = devolverEntero(fechaDeCaducidad, 0, 2);
		}
		else return false;

		return true;
		//Si esta mal, de plano no se actualiza y envia error
	}
	void setTipoDeAlimento(string tipoDeAlimento) { this->tipoDeAlimento = tipoDeAlimento; }
	//Getters
	string getFechaDeCaducidadString() { return fechadeCaducidad.fecha; }
	int getYearCaducidad() { return fechadeCaducidad.year; }
	int getMesCaducidad() { return fechadeCaducidad.mes; }
	int getDiaCaducidad() { return fechadeCaducidad.dia; }
	string gettipoDealimento() { return tipoDeAlimento; }

	//Metodos Normales
	void mostrarDatos() {
		cout << "\nTipo de Producto: ALIMENTO" << endl;
		Producto::mostrarDatos();//Usamos poimorfismo y herencia para que se muestre los datos generales, y en este caso se muestre distinto que los demas subproductos
		cout << "\tTipo de alimento: " << tipoDeAlimento << endl;//Made by kennygamer17 on github || Lexor_12
		cout << "\tFecha de caducidad: " << fechadeCaducidad.fecha << endl;
	}
	void modificar() {
		string ingreso = "\0";
		bool continuar = true;
		while (continuar) {
			do {
				cout << "------------MENU PARA MODIFICAR EL PRODUCTO------------" << endl;
				cout << "(1)- Modificaciones basicas (ID,Nombre,Precio,Stock)  " << endl;
				cout << "(2)- Modificaciones avanzadas (Fecha de caducidad, Tipo de Alimento)" << endl;
				cout << "(3)-Volver" << endl;
				if (ingreso.length() > 1 || !esNumero(ingreso[0])) {
					cout << "Error al ingresar la opcion, recuerde usar numeros, sin espacios o caracteres extras" << endl;
				}
			} while (ingreso.length() > 1 || !esNumero(ingreso[0]));
			switch (ingreso[0]) {
			case '1':
				Producto::modificar();
				break;
			case '2':
				do {
					cout << "------------MODIFICACIONES BASICAS------------" << endl;
					cout << "(1)-Modificar la fecha del alimento" << endl;
					cout << "(2)-Modificar el tipo de alimento" << endl;
					cout << "(3)-Volver" << endl;//Made by kennygamer17 on github || Lexor_12
					if (ingreso.length() > 1 || !esNumero(ingreso[0])) {
						cout << "Error al ingresar la opcion, recuerde usar numeros, sin espacios o caracteres extras" << endl;
					}
				} while (ingreso.length() > 1 || !esNumero(ingreso[0]));
				switch (ingreso[0]) {
				case '1':
					do {
						cout << "\n\n Fecha de caducidad actual: " << getFechaDeCaducidadString() << endl;
						cout << "\nDigite la fecha de ingreso en el siguiente formato: dd/mm/yyyy: ";
						getline(cin, ingreso);
						if (!setfechaDeCaducidad(ingreso)) {
							cout << "Digito la fecha de manera incorrecta, siga el formato sin agregar caracteres extras" << endl;
						}
					} while (!setfechaDeCaducidad(ingreso));
					fechadeCaducidad.fecha = ingreso;
					cout << endl;
					break;
				case '2':
					cout << "\n\n Tipo de alimento actual: " << gettipoDealimento() << endl;
					cout << "Nuevo tipo de alimento: "; getline(cin, tipoDeAlimento);
					cout << endl;
					break;
				case '3':
					cout << "Saliendo......" << endl;
					break;
				default:
					cout << "Oh, ha ocurrido un error inhesperado, no se hara ningun cambio" << endl;
					break;//Made by kennygamer17 on github || Lexor_12
				}
				break;
			case '3':
				cout << "Regresando......" << endl;
				continuar = false;
				break;
			default:
				cout << "Oh, ha ocurrido un error inhesperado, no se hara ningun cambio" << endl;
				break;
			}
		}
	}
};

class Electronico : public Producto {//uso : public Producto, para heredar las funciones de productos tal cual
private:
	int garantia;//Variable que guarda garantia en años
	string marca;
public:
	//Constructor
	Electronico() : Producto(), garantia(0), marca("Sin Marca Registrada") {}
	Electronico(string id, string nombre, float precio, long stock, int garantia, string marca) : Producto(id, nombre, precio, stock), garantia(garantia), marca(marca) {}
	//Destructor
	~Electronico() {}

	//Setters
	void setElectronico(string id, string nombre, float precio, long stock, int garantia, string marca) {
		setID(id);
		setNombre(nombre);
		setPrecio(precio);
		setCantidadEnStock(stock);
		this->garantia = garantia; this->marca = marca;
	}
	void setGarantia(int garantia) { this->garantia = garantia; }
	void setMarca(string marca) { this->marca = marca; }
	//Getters
	int getGarantia() { return garantia; }
	string getMarca() { return marca; }

	//Funciones heredadas
	void mostrarDatos() {
		cout << "\nTipo de Producto: ELECTRONICO" << endl;
		Producto::mostrarDatos();
		cout << "\tGarantia: " << Electronico::getGarantia()<<" Meses" << endl;
		cout << "\tMarca: " << Electronico::getMarca() << endl;
	}

	void modificar() {
		string ingreso;
		bool continuar = true;
		while (continuar) {
			do {
				cout << "------------MENU PARA MODIFICAR EL PRODUCTO------------" << endl;
				cout << "(1)- Modificaciones basicas (ID,Nombre,Precio,Stock)  " << endl;
				cout << "(2)- Modificaciones avanzadas (Garantia, Marca)" << endl;
				cout << "(3)-Volver" << endl;
				getline(cin, ingreso);
				if (ingreso.length() > 1 || (!esNumero(ingreso[0])) || (esNumero(ingreso[0]) && (stof(ingreso) > 3 || (stof(ingreso) < 1)))) {
					cout << "Error de digitacion... Porfavor asegurece de digitar una de las opciones de manera correcta." << endl;
				}
			} while (ingreso.length() > 1 || (!esNumero(ingreso[0])) || (esNumero(ingreso[0]) && (stof(ingreso) > 5 || (stof(ingreso) < 1))));
			switch (ingreso[0]) {
			case '1': Producto::modificar();
				break;
			case '2':
				do {
					cout << "------------MODIFICACIONES BASICAS------------" << endl;
					cout << "(1)-Modificar garantia del producto" << endl;
					cout << "(2)-Modificar marca del producto" << endl;
					cout << "(3)-Volver" << endl;
					getline(cin, ingreso);
				} while (ingreso.length() > 1 || (!esNumero(ingreso[0])) || (esNumero(ingreso[0]) && (stof(ingreso) > 3 || (stof(ingreso) < 1))));
				switch (ingreso[0]) {
				case '1':
					do {
						cout << "\n\n Garantia actual (en years): " << getGarantia() << endl;
						cout << "Nueva Garantia (en years): "; getline(cin, ingreso);
						if (!esIngresoNumericoCorrecto(ingreso) || (esIngresoNumericoCorrecto(ingreso) && stoi(ingreso) < 0)) {
							cout << "Error de digitacion... Porfavor asegurece de digitar un numero entero positivo" << endl;
						}
					} while (!esIngresoNumericoCorrecto(ingreso) || (esIngresoNumericoCorrecto(ingreso) && stoi(ingreso) < 0));
					setGarantia(stoi(ingreso));
					cout << "\n\n\t Se ha modificado adecuadamente...." << endl;
					break;
				case '2':
					cout << "\n\n Marca actual: " << getMarca() << endl;
					cout << "Nueva Marca: "; getline(cin, ingreso);
					setMarca(ingreso);
					cout << "\n\n\t Se ha modificado adecuadamente...." << endl;
					break;
				case '3':
					break;
				default:
					cout << "Lo sentimos, ha ocurrido un error inesperado." << endl;
					break;
				}

				break;
			case '3':
				cout << "Volviendo....." << endl;
				continuar = false;
				break;
			default:
				cout << "Lo sentimos, ha ocurrido un error inesperado." << endl;
				break;
			}

		}
	}

};

//Clase Hija o subclase
class Ropa : public Producto {
private://Atributos o caracteristicas
	string talla, marca, color, tipoDeRopa;
public://Metodos o acciones
	//Constructor
	Ropa() : talla("Sin Asignar"), marca("Sin Asignar"), color("Sin Asignar"), tipoDeRopa("Sin Asignar") {}
	Ropa(string id, string nombre, float precio, long cantidadDisponible, string talla, string marca, string color, string tipoDeRopa) {
		Producto::setProducto(id, nombre, precio, cantidadDisponible);
		this->talla = talla;
		this->marca = marca;
		this->color = color;
		this->tipoDeRopa = tipoDeRopa;
	}
	//Destructor
	~Ropa() {}

	//Setters
	void crearRopa(string id, string nombre, float precio, long cantidadDisponible, string talla, string marca, string color, string tipoDeRopa) {
		Producto::setProducto(id, nombre, precio, cantidadDisponible);
		this->talla = talla;
		this->marca = marca;
		this->color = color;
		this->tipoDeRopa = tipoDeRopa;
	}
	void setTalla(string talla) { this->talla = talla; }
	void setMarca(string marca) { this->marca = marca; }
	void setColor(string color) { this->color = color; }
	void setTipodeRopa(string tipoDeRopa) { this->tipoDeRopa = tipoDeRopa; }
	//Getters
	string getTalla() { return talla; }
	string getMarca() { return marca; }
	string getColor() { return color; }
	string gettipoDeRopa() { return tipoDeRopa; }

	//Metodos Normales
	void mostrarDatos() {
		cout << "\nTipo de Producto: ROPA" << endl;
		Producto::mostrarDatos();
		cout << "\tTipo de ropa: " << tipoDeRopa << endl;
		cout << "\tTalla: " << talla << endl;
		cout << "\tMarca: " << marca << endl;
		cout << "\tColor: " << color << endl;
	}

	void modificar() {
		bool continuar = true;
		string ingreso = "\0";
		while (continuar) {
			do {
				cout << "------------MENU PARA MODIFICAR EL PRODUCTO------------" << endl;
				cout << "(1)- Modificaciones basicas (ID,Nombre,Precio,Stock)  " << endl;
				cout << "(2)- Modificaciones avanzadas (Talla, Marca, Color, Tipo de ropa)" << endl;
				cout << "(3)-Volver" << endl;
				if (ingreso.length() > 1 || !esNumero(ingreso[0])) {
					cout << "Error al ingresar la opcion, recuerde usar numeros, sin espacios o caracteres extras" << endl;
				}
			} while (ingreso.length() > 1 || !esNumero(ingreso[0]));
			switch (ingreso[0]) {
			case '1':
				Producto::modificar();
				break;
			case '2':
				do {
					cout << "------------MODIFICACIONES AVANZADAS------------" << endl;
					cout << "(1)-Modificar la talla de la ropa" << endl;
					cout << "(2)-Modificar la marca de la ropa" << endl;
					cout << "(3)-Modificar el color de la ropa" << endl;
					cout << "(4)-Modificar el tipo de ropa" << endl;
					cout << "(5)-Volver" << endl;
					if (ingreso.length() > 1 || !esNumero(ingreso[0])) {
						cout << "Error al ingresar la opcion, recuerde usar numeros, sin espacios o caracteres extras" << endl;
					}
				} while (ingreso.length() > 1 || !esNumero(ingreso[0]));
				switch (ingreso[0]) {
				case '1':
					cout << "\n\n Talla actual: " << getTalla() << endl;
					cout << "Nueva talla de la ropa: "; getline(cin, talla);
					cout << endl;
					break;
				case '2':
					cout << "\n\n Marca actual: " << getMarca() << endl;
					cout << "Nueva Marca de la ropa: "; getline(cin, marca);
					cout << endl;
					break;
				case '3':
					cout << "\n\n Color actual: " << getColor() << endl;
					cout << "Nuevo Color de la ropa: "; getline(cin, color);
					cout << endl;
					break;
				case '4':
					cout << "\n\n Tipo de ropa actual: " << getTalla() << endl;
					cout << "Nuevo Tipo de ropa: "; getline(cin, tipoDeRopa);
					cout << endl;
					break;
				case '5':
					cout << "Volviendo...." << endl;
					break;
				default:
					cout << "Opcion incorrecta, recuerde que las opciones van de la 1-5" << endl;
					break;
				}
				break;
			case '3':
				cout << "Regresando......." << endl;
				continuar = false;
				break;
			default:
				cout << "Opcion incorrecta, recuerde que las opciones van de la 1-3" << endl;
				break;
			}
		}

	}

};

class Nodo {
private://Atributos
	Producto* producto;
	Nodo* siguiente;
public://Metodos
	//Constructor
	Nodo() : siguiente(nullptr) {}
	//Destructor
	~Nodo() {}
	//Setters
	void setProducto(Producto* producto) { this->producto = producto; }
	void setSiguiente(Nodo* siguiente) { this->siguiente = siguiente; }
	//Getters
	Producto* getProducto() { return producto; }
	Nodo* getSiguiente() { return siguiente; }
};//Made by kennygamer17 on github || Lexor_12

class ListadeProductos {
private://Atributos
	Nodo* Inicio;
public://Metodos
	//Constructor
	ListadeProductos() : Inicio(nullptr) {}//Igualamos a nullptr para saber que al crearse el objeto nos sirva como identificador de si es el primer nod
	//Destructor
	~ListadeProductos() {
		Nodo* aux1 = Inicio;
		while (aux1 != nullptr) {
			Nodo* aux2 = aux1;
			aux1 = aux1->getSiguiente();
			delete aux2;
		}
		Inicio = nullptr;
	}
	//Metodos de clase normales
	bool estaVacia() {//Made by kennygamer17 on github || Lexor_12
		if (Inicio == nullptr) return true;
		return false;
	}
	void addProducto(Producto* productoNuevo) {
		Nodo* nuevo = new Nodo();
		nuevo->setProducto(productoNuevo);
		nuevo->setSiguiente(nullptr);
		if (Inicio == nullptr) {
			Inicio = nuevo;
		}
		else {
			Nodo* aux = Inicio;
			while (aux->getSiguiente() != nullptr) {
				aux = aux->getSiguiente();
			}
			aux->setSiguiente(nuevo);
		}
	}
	void deleteProducto(string id) {
		if (Inicio == nullptr) { cout << "\n\tLa lista se encuentra vacia." << endl; return; }
		Nodo* aux = Inicio;
		if (aux->getProducto()->getID() == id) {
			if (aux->getSiguiente() == nullptr) {
				Inicio = nullptr;
			}
			else {
				Inicio = aux->getSiguiente();
				delete aux;
			}
		}//Made by kennygamer17 on github || Lexor_12
		else {
			while (aux->getSiguiente() != nullptr) {
				if (aux->getSiguiente()->getProducto()->getID() == id) {
					Nodo* borrar = aux->getSiguiente();
					aux->setSiguiente(aux->getSiguiente()->getSiguiente());
					delete borrar;
				}
				aux = aux->getSiguiente();
			}
		}
	}
	void mostrarLista() {
		if (Inicio == nullptr) { cout << "\n\tLa lista se encuentra vacia." << endl; return; }
		Nodo* temp = Inicio;
		while (temp != nullptr) {
			temp->getProducto()->mostrarDatos();
			temp = temp->getSiguiente();
		}
	}
	bool isProductInList(string id) {
		if (Inicio == nullptr) { cout << "\n\tLa lista se encuentra vacia." << endl; return false; }
		Nodo* aux = Inicio;
		while (aux != nullptr) {
			if (aux->getProducto()->getID() == id) {
				return true;
			}
			aux = aux->getSiguiente();
		}
		return false;
	}
	Producto* getProducto(string id) {
		Nodo* aux = Inicio;//Made by kennygamer17 on github || Lexor_12
		while (aux != nullptr) {
			if (aux->getProducto()->getID() == id) {
				return aux->getProducto();
			}
			aux = aux->getSiguiente();
		}
		return nullptr; //Para indicar que no se encontro
	}
};

