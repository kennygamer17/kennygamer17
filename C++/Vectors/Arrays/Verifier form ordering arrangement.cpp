#include <iostream>
    using namespace std;

void comprobador(int arreglo[],int tamano, bool& acomodado);

int main(){
    int tamano = 0;
    bool acomodado = true;
    cout<<"Digite la cantidad de espacios del arreglo -> ";
    cin>>tamano;
    int arreglo[tamano];
    comprobador(arreglo,tamano,acomodado);




    return 0;
}
void comprobador(int arreglo[],int tamano, bool& acomodado){
    for(int i = 0; i<tamano;i++){
        cout<<"Digit el valor del espacio -> "<<i+1<<" -> ";
        cin>>arreglo[i];
    }
    for(int i = 0; i<tamano-1; i++){
        if(arreglo[i] > arreglo[i+1]){
            acomodado = false;
            break;
        }
    }
    if(acomodado){
       cout<<"El arreglo esta acomdado en orden creciente" <<endl;
    }
    else{
        cout<<"El arreglo No esta acomodado en orden creciente" <<endl;
    }
}
