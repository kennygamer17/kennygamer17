#include <iostream>
#include <windows.h>
#include <stdlib.h>
    using namespace std;

void cambio(int,int,int cambios[]);

int main(){
    int total_dinero,cantidad;
    while(true) {
        cout<<"Digite el total de dinero -> ";
        cin>>total_dinero;
        cout<<"En cuantos distintos POSIBLES tipos de cambio desea repartir el dinero? -> ";
        cin>>cantidad;
        int cambios[cantidad];
        for(int i = 0; i<cantidad;i++){
            cout<<"Digite el cambio, ejemplo billetes de '100', escriba solo el numero -> ";
            cin>>cambios[i];
        }
        cambio(cantidad,total_dinero,cambios);

    }
    return 0;
}
void cambio(int cantidad, int total_dinero,int cambios[]){
    int aux;
    int cantidades_cambios[cantidad];
    for(int i = 0; i<cantidad;i++){
        cantidades_cambios[i] = 0;
    }
    for(int i = 0; i<cantidad;i++){
        for(int j = 0; j<cantidad;j++){
            if(cambios[i]>cambios[j]){
                aux = cambios[i];
                cambios[i] = cambios[j];
                cambios[j] = aux;
            }
        }
    }
    for(int i = 0; i<cantidad;i++){
        if(total_dinero >= cambios[i]){
            cantidades_cambios[i] = total_dinero/cambios[i];
            total_dinero = total_dinero%cambios[i];
        }
    }
    for(int i = 0; i<cantidad;i++){
        cout<<"Cambio en monedas/billetes de -> "<<cambios[i]<<" -> "<<cantidades_cambios[i]<<endl;
    }
    if(total_dinero>0){
        cout<<"Cambio en monedas/billetes de -> 1 -> "<<total_dinero<<endl;
    }
    system("pause");
}