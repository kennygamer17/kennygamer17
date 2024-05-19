#include <iostream>
    using namespace std;

struct fecha{
    int num_dia;
    int num_mes;
    int num_ano;
}fechas[100];

void comparador(int);
void imprimidor(int);

int main(){
    int cantidad;
    cout<<"Cuantas fechas desea comparar -> "; cin>>cantidad;
    for(int i = 0; i<cantidad;i++){
        cout<<"Digite el numero del dia de la fecha "<<i+1<<"-> ";cin>>fechas[i].num_dia;
        cout<<"Digite el numero del mes de la fecha "<<i+1<<"-> ";cin>>fechas[i].num_mes;
        cout<<"Digite el numero del ano de la fecha "<<i+1<<"-> ";cin>>fechas[i].num_ano;
    }
    imprimidor(cantidad);
    comparador(cantidad);
}
void imprimidor(int cantidad){
    cout<<"Fechas ingresadas:"<<endl;
    for(int i = 0; i<cantidad;i++){
        cout<<"\t*"<<fechas[i].num_dia<<"/"<<fechas[i].num_mes<<"/"<<fechas[i].num_ano<<endl;
    }
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
void comparador(int cantidad){
    int mayor = 0;
    for(int i = 0; i<cantidad;i++){
        if(fechas[mayor].num_ano<fechas[i].num_ano){
            mayor = i;
        }
        else{
            if(fechas[mayor].num_ano==fechas[i].num_ano){
                if(fechas[mayor].num_mes<fechas[i].num_mes){
                    mayor = i;
                }
                else{
                    if(fechas[mayor].num_mes==fechas[i].num_mes){
                        if(fechas[mayor].num_dia<fechas[i].num_dia){
                            mayor = i;
                        }
                }
                }
            }
        }
    }
    cout<<"La fecha mas grande es -> "<<fechas[mayor].num_dia<<"/"<<fechas[mayor].num_mes<<"/"<<fechas[mayor].num_ano<<endl;
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
