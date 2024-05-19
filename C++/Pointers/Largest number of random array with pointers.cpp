// TRANSMICION DE ARREGLOS 

#include <iostream>
    using namespace std;

void random(int *, int,int,int);
int elderly(int *,int);


int main(){
    srand(time(NULL));
    const int longitud = 5;
    int arreglo[longitud];
    random(arreglo,longitud,10,1);
    int mayor = elderly(arreglo,longitud);
    cout<<"Mayor Num Arreglo: "<<mayor;
    return 0;
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
void random(int *arreglo, int longitud,int max,int min){
    #include <time.h>
        srand(time(NULL));
    for(int i = 0;i<longitud;i++){
        *arreglo = min+rand()%(max-(min-1));
        cout<<*arreglo<<endl;
        arreglo++;
    }
}
int elderly(int *array,int l){
    int value = *array;
    for(int i = 0;i<l;i++){
        if(value<*(array+i)){
            value = *(array+i);
        }
    }
    return value;
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
