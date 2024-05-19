#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
    using namespace std;

int main(){
    int arreglo[100];
    int repetir[100];
    float contador = 0;
    int sumador = 0;
    float promedio = 0;

    srand(time(NULL));

    for(int i = 0; i<100; i++){
        arreglo[i] = 0;
        repetir[i] = 0;
    }
    for(int i = 0; i<100; i++){
        arreglo[i] = 1+rand()%100;
    }
    printf("---------------------------Valores---------------------------\n");
    for(int i = 0; i<100; i++){
        cout<<arreglo[i]<<"\t";
    }
    for(int i = 0; i<100; i++){
        if(arreglo[i] >= 50){
            contador++;
        }
    }
    cout<<" la cantidad de numeros mayores a 50 es de -> "<<contador<<endl;
    contador = 0;
    for(int i = 0; i<100; i++){
        if(arreglo[i] <= 49){
            contador++;
        }
    }
    cout<<" la cantidad de numeros menores a 50 es de -> "<<contador<<endl;
    contador = 0;
    for(int i = 0; i<100; i++){
        contador++;
        sumador += arreglo[i];
    }
    promedio = sumador/contador;
    cout<<"El promedio es de -> "<<promedio<<endl;

    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            if(arreglo[i] == arreglo[j]){
                repetir[i]++;
            }
        }
    }
    int numero = 0;
    for(int i = 0; i<100; i++){
        if(repetir[numero] < repetir[i]){
            numero = i;
        }
    }
    printf("\n---------------------------Numero con mayor repeticiones---------------------------\n\n");
    cout<<"El numero con mayor repeticiones es -> "<<arreglo[numero]<<" con -> "<<repetir[numero]<<" veces"<<endl;

    int num_menor = repetir[numero];
    for(int i = 0; i<100; i++){
        if(num_menor> repetir[i]){
            num_menor = repetir[i];
        }
    }
    printf("\n---------------------------Numeros con menor repeticiones---------------------------\n\n");
     for(int i = 0; i<100; i++){
        if(repetir[i] == num_menor){
            cout<<arreglo[i]<<"\t";
        }
    }
     printf("\n\n---------------------------Gracias por ver || Lexor_12 ---------------------------\n\n");
    return 0;
}