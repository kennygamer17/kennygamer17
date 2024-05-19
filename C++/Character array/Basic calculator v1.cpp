#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h> //<--- Para funcion Sleep(TIEMPO EN MILISGUNDOS)
    using namespace std;

void calculadora(char);
//Made by kennygamer17 || Lexor_12
int main(){
    bool continuar = true;
    char eleccion = ' ';
    char eleccion2 = ' ';
    while(continuar){
        //Menu el cual se redigitara constantemente
        system("cls");
        cout<<"[---------MENU--------]"<<endl;
        cout<<"[(1)-Suma             ]"<<endl;
        cout<<"[(2)-Resta            ]"<<endl;
        cout<<"[(3)-Multiplicacion   ]"<<endl;
        cout<<"[(4)-Division         ]"<<endl;
        cout<<"[(5)-Salir            ]"<<endl;
        cin>>eleccion;
        cin.ignore(); // Eliminamos el Enter
        switch(eleccion){
            case '1':
                eleccion2 = '+';
                calculadora(eleccion2);
            break;
            case '2':
                eleccion2 = '-';
                calculadora(eleccion2);
            break;
            case '3':
                eleccion2 = '*';
                calculadora(eleccion2);
            break;
            case '4':
                eleccion2 = '/';
                calculadora(eleccion2);
            break;
            case '5':
                cout<<"Saliendo...."<<endl;
                Sleep(1000);
            break;
            default:
            cout<<"Esa opcion no existe, vuelva a intentarlo...."<<endl;
            Sleep(1000);
            break;
        }
    }
    return 0;
}
void calculadora(char tipo){
    char ingreso[100];
    float valores[100];
    int longitud;
    float resultado = 0;
    int contador1 = 0,contador2 = 0,contador3 = 0;
    //Se solicita un ingreso de los datos, se guarda en formato cadena de caracteres para poder manipularlo
    cout<<"Digite la operacion en formato "<<endl;
    cin.getline(ingreso,100,'\n');
    longitud = strlen(ingreso);//Variable que guarda la cantidad de longitud de lo que se digito
    char proceso1[longitud]; //Variable de tipo Cadena de Caracter, con un maximo de la longitud del ingreso
    ingreso[longitud] = ' ';//Definimos esto,para que el usuario no tenga que poner constantemnte "="
   
    for(int i = 0;i<=longitud;i++){
        for(int i = 0; i<longitud;i++){
            proceso1[i] = ' ';
        }
        if(ingreso[i] == tipo || ingreso[i] == '=' || ingreso[i] == ':' || ingreso[i] == ' '){//Si no se ingresa el tipo adecuado, no entra en el if, y no se contara al momento de realizar el calculo
            for(int j = contador2; j<i;j++){
                proceso1[contador1] = ingreso[j];
                contador1++;
            }
            contador1 = 0;
            contador2 = i+1;
            valores[contador3] = atof(proceso1);//Guardamos en un arreglo los valores de caracter en formato float con la funcion atof()
            contador3++;
            if(ingreso[i] == '=' || ingreso[i] == ':'){
                //No se puede sumar con igual, al hacerlo se vuelve una ecuacion
                break;
            }
        }
    }
    //Made by kennygamer17 || Lexor_12
    switch(tipo){
        //switch encargado de realizar la operacion correspondiente, con los valores ingresados
        case '+':
            for(int i = 0; i<contador3;i++){
                resultado += valores[i];
            }
        break;
        case '-':
            resultado = valores[0];
            for(int i = 1; i<contador3;i++){
                resultado -= valores[i];
            }
        break;
        case '*':
            resultado = 1;
            for(int i = 0; i<contador3;i++){
                resultado *= valores[i];
            }
        break;
        case '/':
            resultado = valores[0];
            for(int i = 1; i<contador3;i++){
                resultado /= valores[i];
            }
        break;
    }
    cout<<"El resultado es -> "<<resultado<<endl;
    system("pause");
}
//Made by kennygamer17 || Lexor_12