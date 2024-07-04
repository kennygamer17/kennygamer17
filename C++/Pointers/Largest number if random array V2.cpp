#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
    using namespace std;

int* MAXIMO_VALOR(int arreglo[]);//Made by Lexor_12 || kennygamer17 on github

int main(){
    int *arreglo;
    const int nElementos =5;
    arreglo = new int[nElementos];
    cout<<"VALORES: ";
    for(int i=0;i<nElementos;i++){
        arreglo[i] = 1+rand()%10;
        cout<<arreglo[i]<<"\t";
    }
    cout<<endl;
    int *posicion_memoria_mayor=MAXIMO_VALOR(arreglo);

    cout<<"Posicion de memoria del mayor valor: "<<posicion_memoria_mayor<<endl;
    cout<<"Valor de la posicion: "<<*posicion_memoria_mayor<<endl;

    delete[] arreglo;
    return 0;
}//Made by Lexor_12 || kennygamer17 on github
//Made by Lexor_12 || kennygamer17 on github
int* MAXIMO_VALOR(int arreglo[]){//Podemos remplazar [] por *, haciendo referencia pues a la memoria
    int *mayor = arreglo;
    for(int i=0;i<5;i++){
        if(*mayor<arreglo[i]){
            mayor=&arreglo[i];
        }
    }
    return mayor;
}
//Made by Lexor_12 || kennygamer17 on github
