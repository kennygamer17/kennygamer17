#include <iostream>
    using namespace std;

void impares(int arreglo[], int tamano);
void pares(int arreglo[], int tamano);

int main(){
    int tamano;
    cout<<"Digite la cantidad de espacios que contendra el arreglo -> ";
    cin>>tamano;
    int arreglo[tamano];
    for(int i = 0; i<tamano;i++){
        cout<<"Digite el valor del espacio "<<i+1<<" -> ";
        cin>>arreglo[i];
    }
    impares(arreglo,tamano);
    pares(arreglo,tamano);
}
void impares(int arreglo[], int tamano){
    cout<<"\nImprimiento valores impares"<<endl;
    for(int i = 0; i<tamano; i++){
        if(arreglo[i]%2 != 0){
            cout<<arreglo[i]<<" ";
        }
    }
}
void pares(int arreglo[], int tamano){
    cout<<"\nImprimiento valores pares"<<endl;
    for(int i = 0; i<tamano; i++){
        if(arreglo[i]%2 == 0){
            cout<<arreglo[i]<<" ";
        }
    }
}