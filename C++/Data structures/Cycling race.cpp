#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
    using namespace std;


struct tiempo
{   
    int horas  = 0;
    int minutos  = 0;
    int segundos  = 0;
};

struct etapa
{
    char nombre_de_la_etapa[60];
    struct tiempo tiempo_etapa;
}etapa[100];

struct ciclista
{
    char nombre[80];
    int registro;
    int horas_totales = 0;
    int minutos_totales  = 0;
    int segundos_totales  = 0;
    int numero_de_etapa = 0;
    struct etapa etapa_actual[100];
}ciclista[10];

void impresion_informacion_del_ciclista(int i);
void agregar_etapa(int i);
void agregar_ciclista(int i);
void cambio_de_etapa(int i);

int main(){
    int contador_ciclistas = 0, contador_etapas = 0,valor;
    bool continuar = true, verificador = false;
    char eleccion = ' ';

    while(continuar){
        verificador = false;
        system("cls");
        cout<<"\t----INICIO----"<<endl;
        cout<<"|(1)-Agregar Ciclista\t\t|"<<endl;
        cout<<"|(2)-Agregar Etapa\t\t|"<<endl;
        cout<<"|(3)-Imprimir ciclista\t\t|"<<endl;
        cout<<"|(4)-Ciclista-Cambio-Etapa\t|"<<endl;
        cout<<"|(5)-Salir\t\t\t|"<<endl;
        cin>>eleccion;
        cin.ignore();

        switch(eleccion){
            case '1':
            if(contador_ciclistas>=11){
                cout<<"Se llego al maximo de concursantes...."<<endl;
            }
            else{
                agregar_ciclista(contador_ciclistas);
                cout<<" Se agrego con exito..."<<endl;
                sleep(2);
                contador_ciclistas++;
                
            }
            break;
            case '2':
                if(contador_etapas>=101){
                    cout<<"Se llego al maximo de etapas disponibles...."<<endl;
                }
                else{
                    agregar_etapa(contador_etapas);
                    cout<<" Se agrego con exito..."<<endl;
                    sleep(2);
                    contador_etapas++;
                    
                }

            break;
            case '3':
                cout<<"Digite el numero/registro del ciclista -> ";
                cin>>valor;
                for(int i = 0; i<contador_ciclistas;i++){
                    if(valor == ciclista[i].registro){
                        impresion_informacion_del_ciclista(i);
                        verificador = true;
                        system("pause");
                    }
                }
                if(!verificador){
                    cout<<"Ciclista NO encontrado...."<<endl;
                    sleep(1);
                }
            break;
            case '4':
                cout<<"Digite el numero/registro del ciclista -> ";
                cin>>valor;
                for(int i = 0; i<contador_ciclistas;i++){
                    if(valor == ciclista[i].registro){
                        if(ciclista[i].numero_de_etapa == contador_etapas){
                            cout<<"No hay mas etapas a las que se puede alcanzar"<<endl;
                        }
                        else{
                            cambio_de_etapa(i);
                            
                            system("pause");    
                        }
                        verificador = true;
                        
                    }
                }
                if(!verificador){
                    cout<<"Ciclista NO encontrado...."<<endl;
                    sleep(1);
                }
                sleep(1);
            break;

            break;
            case '5':
                cout<<"Saliendo...."<<endl;
                sleep(1.5);
                continuar = false;
            break;
            default: cout<<"Esa opcion no existe...."<<endl;
            sleep(1);
            break;
        
        }
    }
    return 0;
}


void cambio_de_etapa(int i){
    cout<<"Nombre del ciclista -> "<<ciclista[i].nombre;
    ciclista[i].etapa_actual[ciclista[i].numero_de_etapa] = etapa[ciclista[i].numero_de_etapa];
    cout<<"Etapa actual -> "<<ciclista[i].etapa_actual[ciclista[i].numero_de_etapa].nombre_de_la_etapa<<endl;
    ciclista[i].horas_totales += etapa[ciclista[i].numero_de_etapa].tiempo_etapa.horas;
    ciclista[i].minutos_totales += etapa[ciclista[i].numero_de_etapa].tiempo_etapa.minutos;
    ciclista[i].segundos_totales += etapa[ciclista[i].numero_de_etapa].tiempo_etapa.segundos;
    do{
        if(ciclista[i].segundos_totales >=60){
        ciclista[i].minutos_totales +=1;
        ciclista[i].segundos_totales = ciclista[i].segundos_totales -60;
        }
        if(ciclista[i].minutos_totales >=60){
            ciclista[i].horas_totales +=1;
            ciclista[i].minutos_totales = ciclista[i].minutos_totales -60;
        }
    }while(ciclista[i].segundos_totales >=60 || ciclista[i].minutos_totales >=60);
    
    ciclista[i].numero_de_etapa++;
}


void agregar_etapa(int i){
    cout<<"Digite el nombre de la etapa -> ";
    cin.getline(etapa[i].nombre_de_la_etapa,50,'\n');
    cout<<"\nDigite las horas de la etapa ";
    cin>>etapa[i].tiempo_etapa.horas;
    cout<<"\nDigite los minutos de la etapa ";
    cin>>etapa[i].tiempo_etapa.minutos;
    cout<<"\nDigite los segundos de la etapa ";
    cin>>etapa[i].tiempo_etapa.segundos;
}

void agregar_ciclista(int i){
    cout<<"Digite el nombre del ciclista ";
    cin.getline(ciclista[i].nombre,30,'\n');
    ciclista[i].registro = i;
    cout<<"Numero de registro -> "<<ciclista[i].registro<<endl;
}

void impresion_informacion_del_ciclista(int i){
    cout<<"Nombre del ciclista -> "<<ciclista[i].nombre<<endl;
    cout<<"Horas del ciclista -> "<<ciclista[i].horas_totales<<endl;
    cout<<"Minutos del ciclista -> "<<ciclista[i].minutos_totales<<endl;
    cout<<"Segundos del ciclista -> "<<ciclista[i].segundos_totales<<endl;
    cout<<"Etapa actual ->  "<<ciclista[i].etapa_actual[ciclista[i].numero_de_etapa-1].nombre_de_la_etapa<<endl;
    cout<<"\tHoras de la etapa actual ->  "<<etapa[ciclista[i].numero_de_etapa-1].tiempo_etapa.horas<<endl;
    cout<<"\tMinutos de la etapa actual ->->  "<<etapa[ciclista[i].numero_de_etapa-1].tiempo_etapa.minutos<<endl;
    cout<<"\tSegundos de la etapa actual ->"<<etapa[ciclista[i].numero_de_etapa-1].tiempo_etapa.segundos<<endl;
}
