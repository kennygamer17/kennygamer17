#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char cadena_ascii[73] = "1234567890AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVbWwXxYyZz_.!#|,$~·";
    char cadena_usuario[1000];
    int longitud = 0;
    int llave;
    int eleccion;
    bool continuar = true;
    int ayudantedesanta;


    while (continuar) {
        cout << "(1)-Ingresar cadena" << endl;
        cout << "(2)-Desencriptar cadena" << endl;
        cin >> eleccion;
        cin.ignore();

        switch (eleccion) {
            case 1:
                cout << "Ingrese la llave: "<<endl;
                cin >> llave;
                cout << "Ingrese el texto: "<<endl;
                cin.ignore(); 
                cin.getline(cadena_usuario, 1000, '\n');

                

                longitud = strlen(cadena_usuario);

                for(int i = 0; i<longitud;i++){
                    if(cadena_usuario[i] == NULL){
                        cadena_usuario[i] = '_';
                    }

                }
                longitud = strlen(cadena_usuario);
                

                for (int i = 0; i <longitud; i++) {
                    for (int j = 0; j <73; j++) {
                        if (cadena_usuario[i] == cadena_ascii[j]) {
                            ayudantedesanta = j+llave;
                            while(ayudantedesanta >72){
                                if(ayudantedesanta >72){
                                ayudantedesanta = (ayudantedesanta-72);
                                }
                            }
                            cadena_usuario[i] = cadena_ascii[(ayudantedesanta)];
                            break;
                        }
                    }
                }
                cout << "Texto encriptado: " << cadena_usuario << endl;
                break;

            case 2:
                cout << "Ingrese la llave -> ";
                cin >> llave;
                cout << "Ingrese el texto encriptado: ";
                cin.ignore();
                cin.getline(cadena_usuario, 1000, '\n');

                longitud = strlen(cadena_usuario);
                


                for (int i = 0; i <longitud; i++) {
                    for (int j = 0; j < 73; j++) {
                        if (cadena_usuario[i] == cadena_ascii[j]) {
                            ayudantedesanta = j-llave;
                            while(ayudantedesanta <0){
                                if(ayudantedesanta <0){
                                ayudantedesanta = (ayudantedesanta+72);
                            }
                            }
                            
                            cadena_usuario[i] = cadena_ascii[(ayudantedesanta)];
                            break;
                        }
                    }
                }

                cout << "Texto desencriptado: " << cadena_usuario << endl;
                break;

            default:
                cout << "Opción no válida" << endl;
        }
    }

    return 0;
}