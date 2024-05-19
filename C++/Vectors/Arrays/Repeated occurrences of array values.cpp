#include <iostream>
#include <time.h>
    using namespace std;

int main(){
    int arreglo[100];
    int veces[100];
    int ya_digitados[100];
    int ya_digitados_veces[100];
    srand(time(NULL));
    
    for(int i = 0; i<100;i++){
        arreglo[i] = 1+rand()%10;
        veces[i] = 0;
        ya_digitados_veces[i] = 0;
        ya_digitados[i] = 0;
    }

    for(int i = 0; i<100;i++){
        for(int j = 0; j<100;j++){
            if(arreglo[i] == arreglo[j]){
                veces[i]++;
            }
        }
    }
    int contador = 0;
    for(int i = 0; i<100;i++){
        bool yadigitados = false;
        for(int j = 0; j<=contador;j++){
            if(arreglo[i] == ya_digitados[j]){
                yadigitados = true;
                break;
            }
        }
        if(!yadigitados){
            ya_digitados[contador] = arreglo[i];
            ya_digitados_veces[contador] = veces[i];
            contador++;
            
        }
    }
    int arreglo_final[contador];
    int arreglo_final_veces[contador];
    for(int i = 0; i<contador;i++){
        arreglo_final[i] = ya_digitados[i];
        arreglo_final_veces[i] = ya_digitados_veces[i];
        cout<<"Valor: ["<<arreglo_final[i]<<"]"<<" veces -> "<<"["<<arreglo_final_veces[i]<<"]"<<endl;
    }
    return 0;
}