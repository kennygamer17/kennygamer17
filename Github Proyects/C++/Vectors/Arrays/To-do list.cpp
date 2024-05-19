#include <iostream>
#include <stdlib.h>
    using namespace std;

int main(){
    string tareas[100];
    string tarea;
    bool continuar = true;
    int eleccion;
    int i = 0;
    int tareas_agregadas = false;
    int borrar = 0;
    int numero = 0;
    for(int j = 0; j<100; j++){
        tareas[j] = "Vacio";
    }    
    do{
        tareas_agregadas = false;
        for(int j = 0; j<100; j++){
            if(tareas[j] != "Vacio"){
                tareas_agregadas = true;
            }
        }

    do{
    cout<<"\n[-------Menu-------]"<<endl;
    cout<<"Que desea hacer ->"<<endl;
    cout<<"(1)-Agregar tarea"<<endl;
    cout<<"(2)-Ver tareas"<<endl;
    cout<<"(3)-Borrar tarea"<<endl;
    cout<<"(4)-Editar tarea"<<endl;
    cout<<"(5)-Salir"<<endl;
    cin>>eleccion;
    cin.ignore();
    if(eleccion>5 || eleccion<1){
        cout<<"Error, esa accion no fue encontrada\n"<<endl;
        system("pause");
    }
    }while(eleccion>5 || eleccion<1);

    switch(eleccion){
        case 1: cout<<"Escriba la tarea -> "<<endl;
                getline(cin, tareas[i]);
                i += 1;
                cout<<"Se ha agregado una tarea"<<endl;
                tareas_agregadas = true;
                break;

        case 2: if(!tareas_agregadas){
            cout<<"No hay tareas "<<endl;
        }
        else{
            if(tareas_agregadas){
                cout<<"\n\n";
                for(int j = 0; j < 100; j++){
                    if(tareas[j] != "Vacio"){
                    cout<<j+1<<". "<<tareas[j]<<endl;
                    }

                }
                system("pause");
            }
        }
        break;
        case 3: if(!tareas_agregadas){
                cout<<"No hay tareas..."<<endl;
                }
                else{
                cout<<"Digite el numero de la tarea a borrar -> ";
                cin>>borrar;
                if(tareas[borrar-1] == "Vacio"){
                    cout<<"Tarea no existente"<<endl;
                }
                else{
                cout<<"Se va a eiminar la tarea ->"<<borrar<<" "<<tareas[borrar-1]<<endl;
                tareas[borrar-1] = "Vacio";
                system("pause");
                }
                }
        break;
        case 4: if(!tareas_agregadas){
            cout<<"No hay tareas..."<<endl;
        }
        else{

            if(tareas_agregadas){
                cout<<"Digite el numero de la tarea a editar "<<endl;
                cin>>numero;
                if(tareas[numero-1]=="Vacio"){
                    cout<<"Esa tarea no existe"<<endl;
                }
                else{
                    cout<<"\nTarea encontrada ";
                    cout<<numero<<". ->"<<tareas[numero-1]<<endl;
                    cout<<"\nDigiete el valor a modificar "<<endl;
                    cin.ignore();
                    getline(cin, tarea);
                    tareas[numero-1] = tarea;
                    cout<<"\nSe ha editado correctamente... "<<endl;
                    system("pause");
                }
            }
        }
        break;
        case 5: 
            cout<<"Saliendo del programa....... "<<endl;
            continuar = false;
            break;

        default: break;
    } 
    }while(continuar);
    return 0;
}
