#include <iostream>
#include <string.h>
    using namespace std;
//Made by Lexor_12 || kennygamer17 on github
const char operadores[6] = "+-*/=";
void calculador(char tipo,char cadena[], float& resultado);
//Made by Lexor_12 || kennygamer17 on github
int main(){
    int contador;
    char anterior_signo = '+';
    int longitud2;
  //Made by Lexor_12 || kennygamer17 on github
    bool primeravez = true;
    char operacion[1000];
    char cambiador[1000];
    float resultado = 0;
    char tipo;
    cout<<"Digite una operacion a calcular -> ";
    cin.getline(operacion,1000,'\n');
    int longitud = strlen(operacion);
    operacion[longitud] = '=';
    int contador1 = 0;
  //Made by Lexor_12 || kennygamer17 on github
    for(int i = 0; i<=longitud;i++){
        contador++;
        for(int j = 0; j<6;j++){
            if(operacion[i] == operadores[j]){
                tipo = operadores[j];
                for(int k = 0; k<contador;k++){
                    cambiador[k] = operacion[contador1];
                    contador1++;
                }
                longitud2 = strlen(cambiador);
                if(primeravez){
                    float valor = atof(cambiador);
                    resultado = valor;
                    for(int k = 0; k<longitud2;k++){
                        cambiador[k] = ' ';
                    }
                    contador1 = i+1;
                    primeravez = false;
                    break;
                }
                else{
                    calculador(anterior_signo,cambiador,resultado);               
                for(int k = 0; k<longitud2;k++){
                    cambiador[k] = ' ';
                }
                contador1 = i+1;
                }
            }
            anterior_signo = tipo;
        }
      //Made by Lexor_12 || kennygamer17 on github
        if(operacion[i] == '='){
            cout<<"El resultado es -> "<<resultado<<endl;
            break;
        }
        contador = 0;    
    }
    return 0;
}
void calculador(char tipo,char cadena[], float& resultado){
    float valor = atof(cadena);
    switch(tipo){
        case '+':
          //Made by Lexor_12 || kennygamer17 on github
        resultado +=valor;
        break;
        case '-':
        resultado -=valor;
        break;
        case '*':
        resultado *=valor;
        break;
        case '/':
        resultado /=valor;
        break;
    }
}
//Made by Lexor_12 || kennygamer17 on github
