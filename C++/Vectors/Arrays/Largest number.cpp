#include <iostream>
#include <conio.h>
#include <windows.h>//<--- Para funcion Sleep(TIEMPO EN MILISGUNDOS)
    using namespace std;

template <class TipoDeDato> //Sirve para definir la plantilla de la funcion, cuando desconocemos el tipo de arreglo que usaremos
void maximo(TipoDeDato valores[], int);

int main(){
    
    int contador = 0;
    int valores[100];
    bool continuar = true;
    while(continuar){
        //Menu el cual se estar redigitando
        system("cls");
        char eleccion = ' ';
        cout<<"(1)-Agregar valor"<<endl;
        cout<<"(2)-Comparar valores"<<endl;
        cout<<"(3)-Borrar valores"<<endl;
        cout<<"(4)-Mostrar valores"<<endl;
        cout<<"(5)-Salir"<<endl;
        cin>>eleccion;
        cin.ignore();//Ignora el Enter
        switch(eleccion){
            case '1':
            cout<<"Digite un valor -> ";
            cin>>valores[contador];
            cin.ignore();
            contador++;
            break;
            case '2':
            maximo(valores, contador);
            break;
            case '3':
            for(int i = 0; i<contador;i++){
                valores[i] = ' ';
            }
            contador = 0;
            break;
            case '4':
            if(contador<=0){
                cout<<"No hay valores para mostrar aun...."<<endl;
                Sleep(1000);
                break;
            }
            for(int i = 0; i<contador;i++){
                cout<<"Espacio "<<i<<" -> "<<valores[i]<<endl;
            }
            system("pause");
            break;
            case '5':
            cout<<"Saliendo...."<<endl;
            Sleep(2000);
            continuar = false;
            break;
            default:
            cout<<"Esa opcion no existe...."<<endl;
            Sleep(1000);
            break;
        }
    }
    return 0;
}
template <class TipoDeDato>
void maximo(TipoDeDato arreglo[], int contador){
    int repetido = 0;
    int valor_maximo = 0;

    for(int i = 0; i<contador; i++){
        if(arreglo[valor_maximo]< arreglo[i]){
            valor_maximo = i;
        }
    }
    for(int i = 0; i<contador; i++){
        if(arreglo[valor_maximo] == arreglo[i]){
            repetido++;
        }
    }
    if(contador>0){
        cout<<"El valor mas grande es -> "<<arreglo[valor_maximo]<<" cantidad de veces repetida -> "<<repetido<<endl;
        system("pause");

    }
    else{
        if(contador<=0){
        cout<<"No hay valores para comparar aun...."<<endl;
        Sleep(1000);

    }
    }
}
//Made by: kennygamer17 || Lexor_12