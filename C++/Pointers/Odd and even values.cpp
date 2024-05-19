#include <iostream>
#include <windows.h>
#include <stdlib.h>
    using namespace std;

//Funciones
void recorrer(int& contador, int);
void iniciador();
void agregar_num(int& contador);
void eliminar_num(int& contador);
void comparar_num(int& contador);
void imprimir_num(int& contador);

int arreglo[100],*dir_num[100];
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
int main(){
    int contador = 0;
    iniciador();
    bool continuar = true;
    do{
        system("cls");
    char eleccion = ' ';
    cout<<"[--------Menu--------]"<<endl;
    cout<<"|(1)-Agregar Num     ]"<<endl;
    cout<<"|(2)-Eliminar Num    ]"<<endl;
    cout<<"|(3)-Comparar Nums   ]"<<endl;
    cout<<"|(4)-Salir           ]"<<endl;
    cout<<"[--------------------]"<<endl;
    cin>>eleccion;
    cin.ignore();
    switch (eleccion){
        case '1':
            agregar_num(contador);
        break;
        case '2':
        eliminar_num(contador);
        break;
        case '3':
            comparar_num(contador);
        break;
        case '4':
            cout<<"Saliendo...."<<endl;
            Sleep(1000);
            continuar = false;
        break;
        default:
        cout<<"Esa opcion no existe...."<<endl;
        Sleep(1550);
        break;
    }
    }while(continuar);
    return 0;
}
void iniciador(){
    for(int i = 0; i<100;i++){
        arreglo[i] = 0;
        dir_num[i] = &arreglo[i];
    }
}
void agregar_num(int& contador){
    int cantidad;
    cout<<"Cuantos valores desea agregar -> ";
    cin>>cantidad;
    for(int i = contador; i<(contador+cantidad);i++){
        cout<<"Digite el valor "<<i<<" -> "; cin>>arreglo[i];
    }
    contador += cantidad;;
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
void eliminar_num(int& contador){
    char eleccion = ' ';
    cout<<"[--------Menu--------]"<<endl;
    cout<<"|(1)-Eliminar Todos  ]"<<endl;
    cout<<"|(2)-Eliminar uno    ]"<<endl;
    cout<<"|(Otro)-Regresar     ]"<<endl;
    cout<<"[--------------------]"<<endl;
    cin>>eleccion;
    cin.ignore();
    switch(eleccion){
        case '1':
        iniciador();
        break;
        case '2':
        imprimir_num(contador);
        int espacio;
        cout<<"\n\nDIGITE EL ESPACIO A BORRAR -> ";
        cin>>espacio;
        if(espacio <=contador && espacio>=0){
            arreglo[espacio] = 0;
            cout<<"Espacio borrado correctamente "<<endl;
            recorrer(contador, espacio);
            imprimir_num(contador);
            Sleep(1550);

        }
        else{
            cout<<"Espacio no existente... Regresando....."<<endl;
            Sleep(1550);
        }
        break;
        default:
        cout<<"Regresando...."<<endl;
            Sleep(1000);
        break;
    }
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
void recorrer(int& contador, int espacio){
    int aux;
    for(int i = espacio; i<contador-1;i++){
        aux = arreglo[i];
        arreglo[i] = arreglo[i+1];
        arreglo[i+1] = aux;

    }
    contador--;
}
void comparar_num(int& contador){
    for(int i = 0; i<contador;i++){
        if(*dir_num[i]%2 == 0){
            cout<<"\nEspacio "<<i<<endl;
            cout<<"PAR:"<<endl;
            cout<<"\tValor"<<" -> "<<*dir_num[i]<<endl;
            cout<<"\tDireccion "<<i<<" -> "<<dir_num[i]<<endl;
        }
        else{
         if(*dir_num[i]%2 != 0){
            cout<<"\nEspacio "<<i<<endl;
            cout<<"IMPAR:"<<endl;
            cout<<"\tValor"<<" -> "<<*dir_num[i]<<endl;
            cout<<"\tDireccion "<<i<<" -> "<<dir_num[i]<<endl;
        }   
        }
    }
    system("pause");
}
void imprimir_num(int& contador){
    for(int i = 0; i<contador;i++){
        cout<<"\nEspacio "<<i<<endl;
        cout<<"\tValor"<<" -> "<<*dir_num[i]<<endl;
        cout<<"\tEspacio "<<i<<" -> "<<dir_num[i]<<endl;
    }
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
