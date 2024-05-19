#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h> //<---- S.O Unix
#include <string.h>
#include <time.h>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
    using namespace std;
//ESTRUCTURAS DEL JUEGO
//ITEMS
struct items{
    char nombre_del_item[40];
    int golpe;
    int usos;
    int cantidad;
};
//ENEMIGOS
struct enemigos{
    char nombre[30];
    int golpe;
    int vida;
};

//PERSONAJE
struct inventario_personaje
{
    struct items item;
};
struct estadisticas_personaje
{
    bool estado = true;
    int vida = 0;
    int vida_maxima = 0;
    int vidas = 0;
    int oleadas_sobrevividas = 0;
    int enemigos_matados = 0;
    int enemigos_sobrevividos = 0;
    double golpe_total_efectuado = 0;
    double golpe_total_recibido = 0;
};
struct info_personajes
{
    char nombre[25];
    char apellido[25];
    char apodo[15] ;
};
struct personaje
{
    bool creado = false;
    struct info_personajes informacion;
    struct estadisticas_personaje estadisticas;
};
struct eventos{
    string texto_de_evento;
    int numero_de_enemigo = 0;
    int numero_de_item = 0;
    struct enemigos enemigo;
    struct items item;
};

struct modos{
    char modo[30];
    struct items item[10];
    struct enemigos enemigo[10];
    struct inventario_personaje espacio[10];
    struct estadisticas_personaje estadisticas_personaje;
    struct info_personajes info_personajes;
    struct personaje personaje;
    struct eventos evento[10];
}modo[2];

//FUNCIONES
void leerinfousuario();
void guardarinfousuario();
void creacion_del_personaje(int modo_seleccionado);
void puntos_de_carga();
void creativo_configuracion(int modo_seleccionado);
void impresion_enemigos(int modo_seleccionado);
void impresion_items(int modo_seleccionado);
void impresion_eventos(int modo_seleccionado);
void aleatorio_enemigos(int modo_seleccionado);
void aleatorio_items(int modo_seleccionado);
void aleatorio_eventos(int modo_seleccionado);
void modo_historia(int modo_seleccionado);
void avanzar(int modo_seleccionado);
void avanzar_enemigo(int modo_seleccionado);
void avanzar_item(int modo_seleccionado);
bool gestor_vida(int modo_seleccionado);
void imprimir_estadisticas(int modo_seleccionado);
void inventario_verificador(int modo_seleccionado);
void inventario(int modo_seleccionado);
void imprimir_inventario(int modo_seleccionado);
void configuracion_creativo_juego_empezado(int modo_seleccionado);
void correr_escapar(int modo_seleccionado, int aleatorio, int aleatorio2);

//MAIN
int main(){
    srand(time(NULL));
    bool lobby = true,creativo = true,historia = true;
    int modo_seleccionado;
    leerinfousuario();
    while(lobby){
        guardarinfousuario();
        historia = true;
        creativo = true;
        char eleccion = ' ';
        system("cls");
        cout<<"\tBIENVENIDO NUEVO JUGADOR A THE ADVENTURE\t\n"<<endl;
        cout<<"\n\nQUE MODO DESEA JUGAR"<<endl;
        cout<<"\n\t(1)-Modo Historia"<<endl;
        cout<<"\n\t(2)-Creativo"<<endl;
        cout<<"\n\t(3)-Salir del Juego"<<endl;
        cin>>eleccion;
        cin.ignore();
        switch(eleccion){
            case '1':
            modo_seleccionado = 0;
            cout<<"Cargando Modo Historia";
            puntos_de_carga();
            if(!modo[modo_seleccionado].personaje.creado){
                creacion_del_personaje(modo_seleccionado);
                modo[modo_seleccionado].personaje.creado = true;
            }
            while(historia){
                guardarinfousuario();
                inventario_verificador(modo_seleccionado);
                modo[modo_seleccionado].personaje.estadisticas.estado = gestor_vida(modo_seleccionado);
                gestor_vida(modo_seleccionado);
                modo_historia(modo_seleccionado);
                system("cls");
                cout<<"[--------------MENU--------------]"<<endl;
                cout<<"(1)-Avanzar"<<endl;
                cout<<"(2)-Ver inventario"<<endl;
                cout<<"(3)-Ver datos/vida/informacion"<<endl;
                cout<<"(4)-Configuracion"<<endl;
                cin>>eleccion;
                cin.ignore();
                switch(eleccion){
                    case '1':
                    if(modo[modo_seleccionado].personaje.estadisticas.estado){
                        avanzar(modo_seleccionado);
                    }
                    else{
                        if(!modo[modo_seleccionado].personaje.estadisticas.estado){
                            cout<<"Tu personaje a muerto"<<endl;
                            system("pause");
                    }
                    }
                    break;
                    case '2':
                        inventario(modo_seleccionado);
                    break;
                    case '3':
                    imprimir_estadisticas(modo_seleccionado);
                    break;
                    case '4':
                    cout<<"[--------------CONFIGURACION--------------]"<<endl;
                    cout<<"(1)-Salir al lobby"<<endl;
                    cout<<"(2)-Regresar(seguir jugando)"<<endl;
                    cin>>eleccion;
                    cin.ignore();
                    switch(eleccion){
                        case '1':
                        cout<<"Volviendo al inicio";
                        puntos_de_carga();
                        historia = false;
                        break;
                        case '2':
                        cout<<"Regresando";
                        puntos_de_carga();
                        break;
                    }
                    break;
                    default: cout<<"Esa opcion no existe"<<endl;
                    sleep(1);
                    break;
                }
            }

            break;
            case '2':
            modo_seleccionado = 1;
            cout<<"Cargando Modo Creativo";
            puntos_de_carga();
            if(!modo[modo_seleccionado].personaje.creado){
                creacion_del_personaje(modo_seleccionado);
                creativo_configuracion(modo_seleccionado);
                modo[modo_seleccionado].personaje.creado = true;
            }
            while(creativo){
                guardarinfousuario();
                inventario_verificador(modo_seleccionado);
                modo[modo_seleccionado].personaje.estadisticas.estado = gestor_vida(modo_seleccionado);
                gestor_vida(modo_seleccionado);
                system("cls");
                cout<<"[--------------MENU--------------]"<<endl;
                cout<<"(1)-Avanzar"<<endl;
                cout<<"(2)-Ver inventario"<<endl;
                cout<<"(3)-Ver datos/vida/informacion"<<endl;
                cout<<"(4)-Configuracion"<<endl;
                cin>>eleccion;
                cin.ignore();
                switch(eleccion){
                    case '1':
                    if(modo[modo_seleccionado].personaje.estadisticas.estado){
                        avanzar(modo_seleccionado);
                    }
                    else{
                        if(!modo[modo_seleccionado].personaje.estadisticas.estado){
                            cout<<"Tu personaje a muerto, para cambiar esto, configura las vidas y vida en configuracion de modo creativo...."<<endl;
                            system("pause");
                    }
                    }

                    break;
                    case '2':
                        inventario(modo_seleccionado);
                    break;
                    case '3':
                    imprimir_estadisticas(modo_seleccionado);
                    break;
                    case '4':
                    cout<<"[--------------CONFIGURACION--------------]"<<endl;
                    cout<<"(1)-Modificar-Modo-creativo"<<endl;
                    cout<<"(2)-Salir al Lobby"<<endl;
                    cout<<"(3)-Regresar(seguir jugando)"<<endl;
                    cin>>eleccion;
                    cin.ignore();
                    switch(eleccion){
                        case '1':
                        configuracion_creativo_juego_empezado(modo_seleccionado);
                        break;
                        case '2':
                        cout<<"Volviendo al inicio";
                        puntos_de_carga();
                        creativo = false;
                        break;
                        case '3':
                        cout<<"Regresando";
                        puntos_de_carga();
                        break;
                    }
                    break;
                    default: cout<<"Esa opcion no existe"<<endl;
                    sleep(1);
                    break;
                }
            }
            break;
            case '3': 
            cout<<"Saliendo del juego";
            puntos_de_carga();
            cout<<"[-----DESAROLLADO POR: kennygamer17 || Lexor_12-----]"<<endl;
            lobby = false;
            guardarinfousuario();
            break;
            default: cout<<"Esa opcion no existe..."<<endl;
            sleep(1);
            break;
        }
    }
    return 0;
}
//FUNCIONES DE IMPRESION
void impresion_enemigos(int modo_seleccionado){
    cout<<"\n\n\n\nENEMIGOS\n\n"<<endl;
    for(int i = 0; i<10;i++){
        cout<<"\t";
        cout<<"\tENEMIGO -> "<<i+1<<endl;
        cout<<"Nombre -> "<<modo[modo_seleccionado].enemigo[i].nombre<<endl;
        cout<<"Vida -> "<<modo[modo_seleccionado].enemigo[i].vida<<endl;
        cout<<"golpe -> "<<modo[modo_seleccionado].enemigo[i].golpe<<endl;
        cout<<"\n"<<endl;
    }
}
void impresion_items(int modo_seleccionado){
    cout<<"\n\n\n\nITEMS\n\n"<<endl;
    for(int i = 0; i<10;i++){
        cout<<"\tITEM -> "<<i+1<<endl;
        cout<<"Nombre -> "<<modo[modo_seleccionado].item[i].nombre_del_item<<endl;
        cout<<"golpe -> "<<modo[modo_seleccionado].item[i].golpe<<endl;
        cout<<"Cantidad de usos -> "<<modo[modo_seleccionado].item[i].usos<<endl;
        cout<<"\n"<<endl;
    }
}
void impresion_eventos(int modo_seleccionado){
    cout<<"\n\n\n\nEVENTOS\n\n"<<endl;
    for(int i = 0; i<10;i++){
        cout<<"\tEVENTO -> "<<i+1<<endl;
        cout<<"Mensaje del evento: "<<modo[modo_seleccionado].evento[i].texto_de_evento<<endl;
        cout<<"Enemigo -> "<<modo[modo_seleccionado].evento[i].enemigo.nombre<<endl;
        cout<<"Item -> "<<modo[modo_seleccionado].evento[i].item.nombre_del_item<<endl;
        cout<<"\n"<<endl;
    }
}

//FUNCIONES ALEATORIAS DE CREACION
void aleatorio_enemigos(int modo_seleccionado){
    
    string nombres_posibles[10] = {"Lobo Salvaje","Duende armado","Serpiente Venenosa","Golem de Piedra","Insecto Venenosa","Gigante Armado","Ladron","Dragon de Fuego","Dragon de Hielo","Culebra"};
    for(int i = 0; i<10;i++){
        int aleatorio = rand()%10;
        strcpy(modo[modo_seleccionado].enemigo[i].nombre, nombres_posibles[aleatorio].c_str()); 
    }
    for(int i = 0; i<10;i++){
        int aleatorio = 1+rand()%170;
        modo[modo_seleccionado].enemigo[i].vida = aleatorio;
    }
    for(int i = 0; i<10;i++){
        int aleatorio = 1+rand()%120;
        modo[modo_seleccionado].enemigo[i].golpe = aleatorio;
    }
}
void aleatorio_items(int modo_seleccionado){
    
    string nombres_posibles[12] = {"Cuchillo Filoso","Palo de madera","Piedra filosa","Pistola","Espada Antigua","Arco Antiguo","Lanza filosa","Arco Moderno","Daga Afilada","Hacha Antigua","Pocima Curativa","Vida Extra"};
    for(int i = 0; i<10;i++){
        int aleatorio = rand()%12;
        strcpy(modo[modo_seleccionado].item[i].nombre_del_item, nombres_posibles[aleatorio].c_str()); 
    }
    for(int i = 0;i<10;i++){
        if(strcmp(modo[modo_seleccionado].item[i].nombre_del_item,"Pocima Curativa") == 0){
            int aleatorio = -1 - rand() % 200;
            modo[modo_seleccionado].item[i].golpe = aleatorio;
        }else{
            if(strcmp(modo[modo_seleccionado].item[i].nombre_del_item,"Vida Extra") == 0){
            modo[modo_seleccionado].item[i].golpe = 0;
            }        
            else{
                int aleatorio = 1+rand()%200;
                modo[modo_seleccionado].item[i].golpe = aleatorio;
            }
        }
    }
    for(int i = 0;i<10;i++){
        int aleatorio = 1+rand()%5;
        modo[modo_seleccionado].item[i].usos = aleatorio;
    }
}
void aleatorio_eventos(int modo_seleccionado){
    for(int i = 0; i<10;i++){
        int aleatorio = rand()%10;;
        modo[modo_seleccionado].evento[i].texto_de_evento = "Cuidado Aventurero te has encontrado con un: ";
        modo[modo_seleccionado].evento[i].numero_de_enemigo = aleatorio;
        modo[modo_seleccionado].evento[i].enemigo = modo[modo_seleccionado].enemigo[modo[modo_seleccionado].evento[i].numero_de_enemigo];
    }
    for(int i = 0; i<10;i++){
        int aleatorio = rand()%10;
        modo[modo_seleccionado].evento[i].numero_de_item = aleatorio;
        modo[modo_seleccionado].evento[i].item = modo[modo_seleccionado].item[modo[modo_seleccionado].evento[i].numero_de_item];
    }
}

void modo_historia(int modo_seleccionado){
    aleatorio_enemigos(modo_seleccionado);
    aleatorio_items(modo_seleccionado);
    aleatorio_eventos(modo_seleccionado);
}

//MODO CREATIVO Y CONFIGURACION POR PARTE DEL USUARIO
void creativo_configuracion(int modo_seleccionado){
    system("cls");
    char eleccion = ' ';
    cout<<"[----------------MODO CREATIVO AJUSTES----------------]"<<endl;
    do{
        cout<<"Desea modificar los ajustes de dificultad? Y/N -> ";
        cin>>eleccion;
        cin.ignore();
        switch(eleccion){
            case 'Y':
                cout<<"Dijite la vida maxima -> ";
                cin>>modo[modo_seleccionado].personaje.estadisticas.vida_maxima;
                do{
                    cout<<"Dijite la vida al comenzar -> ";
                    cin>>modo[modo_seleccionado].personaje.estadisticas.vida;
                    if(modo[modo_seleccionado].personaje.estadisticas.vida>modo[modo_seleccionado].personaje.estadisticas.vida_maxima){
                    cout<<"No puede usar ese valor, supera a la vida maxima"<<endl;
                    sleep(1);
                    }
                }while(modo[modo_seleccionado].personaje.estadisticas.vida>modo[modo_seleccionado].personaje.estadisticas.vida_maxima);
                cout<<"Dijite la cantidad de vidas al comenzar -> ";
                cin>>modo[modo_seleccionado].personaje.estadisticas.vidas;
            break;
            case 'N':
            
            break;
            default: cout<<"Esa opcion no existe, digite Y o N EN MAYUSCULAS, segun su eleccion"<<endl;
            sleep(1);
            break;
        }
    }while(eleccion != 'Y' && eleccion != 'N');
    system("cls");
    cout<<"[----------------MODO CREATIVO AJUSTES----------------]"<<endl;
    do{
        cout<<"Desea modificar crear sus propios items? Y/N -> ";
        cin>>eleccion;
        cin.ignore();
        switch(eleccion){
            case 'Y':
            cout<<"A continuacion, tendra que crear 10 items"<<endl;
            for(int i = 0; i<10;i++){
                cout<<"\tITEM -> "<<i+1<<endl;
                cout<<"Nombre -> ";
                cin.getline(modo[modo_seleccionado].item[i].nombre_del_item,40,'\n');
                cout<<"Digite el golpe -> ";
                cin>>modo[modo_seleccionado].item[i].golpe;
                cin.ignore();
                cout<<"Digite la cantidad de usos -> ";
                cin>>modo[modo_seleccionado].item[i].usos;
                cin.ignore();
            }
            break;
            case 'N':
            aleatorio_items(modo_seleccionado);
            break;
            default: cout<<"Esa opcion no existe, digite Y o N EN MAYUSCULAS, segun su eleccion"<<endl;
            sleep(1);
            break;
        }
    }while(eleccion != 'Y' && eleccion != 'N');
    system("cls");
    cout<<"[----------------MODO CREATIVO AJUSTES----------------]"<<endl;
    do{
        cout<<"Desea modificar a los enemigos? Y/N-> ";
        cin>>eleccion;
        cin.ignore();
        switch(eleccion){
            case 'Y':
            cout<<"A continuacion, tendra que crear 10 enemigos"<<endl;
            for(int i = 0; i<10;i++){
                cout<<"\tENEMIGO -> "<<i+1<<endl;
                cout<<"Nombre -> ";
                cin.getline(modo[modo_seleccionado].enemigo[i].nombre,30,'\n');
                cout<<"Vida -> ";
                cin>>modo[modo_seleccionado].enemigo[i].vida;
                cin.ignore();
                cout<<"golpe -> ";
                cin>>modo[modo_seleccionado].enemigo[i].golpe;
                cin.ignore();
            }
            break;
            case 'N':
            aleatorio_enemigos(modo_seleccionado);
            break;
            default: cout<<"Esa opcion no existe, digite Y o N EN MAYUSCULAS, segun su eleccion"<<endl;
            sleep(1);
            break;
        }
    }while(eleccion != 'Y' && eleccion != 'N');
    system("cls");
    cout<<"[----------------MODO CREATIVO AJUSTES----------------]"<<endl;
    do{
        cout<<"Desea crear sus propios eventos? Y/N -> ";
        cin>>eleccion;
        cin.ignore();
        switch(eleccion){
            case 'Y':
                for(int i = 0; i<10;i++){
                    system("cls");
                    cout<<"SE IMPRIMIRAN TODOS LOS ENEMIGOS Y ITEMS"<<endl;
                    impresion_enemigos(modo_seleccionado);
                    impresion_items(modo_seleccionado);
                    cout<<"\n\n"<<endl;
                    cout<<"[--------------------------------------]\n"<<endl;
                    cout<<"\n\tEVENTO -> "<<i+1<<endl;
                    cout<<"Digite el mensaje del evento: "<<endl;
                    getline(cin, modo[modo_seleccionado].evento[i].texto_de_evento);
                    cout<<"Digite el numero del enemigo -> ";
                    cin>>modo[modo_seleccionado].evento[i].numero_de_enemigo;
                    modo[modo_seleccionado].evento[i].numero_de_enemigo -=1;
                    cin.ignore();
                    modo[modo_seleccionado].evento[i].enemigo = modo[modo_seleccionado].enemigo[modo[modo_seleccionado].evento[i].numero_de_enemigo];
                    cout<<"Digite el numero del item -> ";
                    cin>>modo[modo_seleccionado].evento[i].numero_de_item;
                    modo[modo_seleccionado].evento[i].numero_de_item -=1;
                    modo[modo_seleccionado].evento[i].item = modo[modo_seleccionado].item[modo[modo_seleccionado].evento[i].numero_de_enemigo];
                    cin.ignore();
                }
            break;
            case 'N':
            aleatorio_eventos(modo_seleccionado);
            break;
            default: cout<<"Esa opcion no existe, digite Y o N EN MAYUSCULAS, segun su eleccion"<<endl;
            sleep(1);
            break;
        }

    }while(eleccion != 'Y' && eleccion != 'N');
    system("cls");
    cout<<"\nIMPRIMIENDO TODO LA CONFIGURACION DEL JUEGO"<<endl;
    sleep(2);
    impresion_eventos(modo_seleccionado);
    sleep(2);
    cout<<"\n\n"<<endl;
    impresion_enemigos(modo_seleccionado);
    sleep(2);
    cout<<"\n\n"<<endl;
    impresion_items(modo_seleccionado);
    sleep(2);
    cout<<"\n\n"<<endl;
}
void configuracion_creativo_juego_empezado(int modo_seleccionado){
    bool continuar = true;
    while(continuar){
        int valor2;
        int valor;
        char seleccion = ' ';
        system("cls");
        cout<<"[------BIENVENIDO AL MENU DE AJUSTES DE MODO CREATIVO------]"<<endl;
        cout<<"[(1)-Modificar Vida/Vidas/Dificultad                       ]"<<endl;
        cout<<"[(2)-Items                                                 ]"<<endl;
        cout<<"[(3)-Enemigos                                              ]"<<endl;
        cout<<"[(4)-Eventos                                               ]"<<endl;
        cout<<"[(5)-Inventario                                            ]"<<endl;
        cout<<"[(6)-Imprimir Enemigos/Eventos/Items                       ]"<<endl;
        cout<<"[(7)-Salir de Configuracion                                ]"<<endl;
        cout<<"[----------------------------------------------------------]\n"<<endl;
        cin>>seleccion;
        cin.ignore();
        switch(seleccion){
            case '1':
                cout<<"Dijite la vida maxima -> ";
                cin>>modo[modo_seleccionado].personaje.estadisticas.vida_maxima;
                do{
                    cout<<"Dijite la vida al comenzar -> ";
                    cin>>modo[modo_seleccionado].personaje.estadisticas.vida;
                    if(modo[modo_seleccionado].personaje.estadisticas.vida>modo[modo_seleccionado].personaje.estadisticas.vida_maxima){
                    cout<<"No puede usar ese valor, supera a la vida maxima"<<endl;
                    sleep(1);
                    }
                }while(modo[modo_seleccionado].personaje.estadisticas.vida>modo[modo_seleccionado].personaje.estadisticas.vida_maxima);
                cout<<"Dijite la cantidad de vidas al comenzar -> ";
                cin>>modo[modo_seleccionado].personaje.estadisticas.vidas;
            break;
            case '2':
                system("cls");
                cout<<"[----------Menu Item----------]"<<endl;
                cout<<"(1)-Cambiar Item especifico"<<endl;
                cout<<"(2)-Cambiar todos los items\n"<<endl;
                cin>>seleccion;
                cin.ignore();
                switch(seleccion){
                    case '1':
                    do{
                        system("cls");
                        impresion_items(modo_seleccionado);
                    cout<<"Digit el numero del item -> ";
                    cin>>valor;
                    cin.ignore();
                    valor -=1;
                    cin.ignore();
                    if(valor<0 || valor>9){
                        cout<<"No existe ese espacio"<<endl;
                    }
                    else{
                        cout<<"\tITEM -> "<<valor<<endl;
                        cout<<"Nombre -> ";
                        cin.getline(modo[modo_seleccionado].item[valor].nombre_del_item,40,'\n');
                        cout<<"Digite el golpe -> ";
                        cin>>modo[modo_seleccionado].item[valor].golpe;
                        cin.ignore();
                        cout<<"Digite la cantidad de usos -> ";
                        cin>>modo[modo_seleccionado].item[valor].usos;
                        cin.ignore();
                    }
                    }while(valor<0 || valor>9);
                    
                    break;
                    case '2':
                    cout<<"A continuacion, tendra que crear 10 items"<<endl;
                        for(int i = 0; i<10;i++){
                            cout<<"\tITEM -> "<<i+1<<endl;
                            cout<<"Nombre -> ";
                            cin.getline(modo[modo_seleccionado].item[i].nombre_del_item,40,'\n');
                            cout<<"Digite el golpe -> ";
                            cin>>modo[modo_seleccionado].item[i].golpe;
                            cin.ignore();
                            cout<<"Digite la cantidad de usos -> ";
                            cin>>modo[modo_seleccionado].item[i].usos;
                            cin.ignore();
                        }
                    break;
                    default:
                    cout<<"Opcion no encontrada, regresando..."<<endl;
                    sleep(1);
                    break;
                }


            break;
            case '3':
                system("cls");
                cout<<"[----------Menu Enemigo----------]"<<endl;
                cout<<"(1)-Cambiar enemigo especifico"<<endl;
                cout<<"(2)-Cambiar todos los enemigos\n"<<endl;
                cin>>seleccion;
                cin.ignore();
                switch(seleccion){
                    case '1':
                    do{
                        system("cls");
                        impresion_enemigos(modo_seleccionado);
                    cout<<"Digit el numero del enemigo -> ";
                    cin>>valor;
                    cin.ignore();
                    valor -=1;
                    if(valor<0 || valor>9){
                        cout<<"No existe ese espacio"<<endl;
                    }
                    else{
                        cout<<"\tENEMIGO -> "<<valor<<endl;
                        cout<<"Nombre -> ";
                        cin.getline(modo[modo_seleccionado].enemigo[valor].nombre,30,'\n');
                        cout<<"Vida -> ";
                        cin>>modo[modo_seleccionado].enemigo[valor].vida;
                        cin.ignore();
                        cout<<"golpe -> ";
                        cin>>modo[modo_seleccionado].enemigo[valor].golpe;
                        cin.ignore();
                    }
                    }while(valor<0 || valor>9);
                    
                    break;
                    case '2':
                    cout<<"A continuacion, tendra que crear 10 eventos"<<endl;
                        for(int i = 0; i<10;i++){
                            system("cls");
                            cout<<"SE IMPRIMIRAN TODOS LOS ENEMIGOS Y ITEMS"<<endl;
                            impresion_enemigos(modo_seleccionado);
                            impresion_items(modo_seleccionado);
                            cout<<"\n\n"<<endl;
                            cout<<"[--------------------------------------]\n"<<endl;
                            cout<<"\n\tEVENTO -> "<<i+1<<endl;
                            cout<<"Digite el mensaje del evento: "<<endl;
                            getline(cin, modo[modo_seleccionado].evento[i].texto_de_evento);
                            cout<<"Digite el numero del enemigo -> ";
                            cin>>modo[modo_seleccionado].evento[i].numero_de_enemigo;
                            modo[modo_seleccionado].evento[i].numero_de_enemigo -=1;
                            cin.ignore();
                            modo[modo_seleccionado].evento[i].enemigo = modo[modo_seleccionado].enemigo[modo[modo_seleccionado].evento[i].numero_de_enemigo];
                            cout<<"Digite el numero del item -> ";
                            cin>>modo[modo_seleccionado].evento[i].numero_de_item;
                            modo[modo_seleccionado].evento[i].numero_de_item -=1;
                            modo[modo_seleccionado].evento[i].item = modo[modo_seleccionado].item[modo[modo_seleccionado].evento[i].numero_de_enemigo];
                            cin.ignore();
                }
                    break;
                    default:
                    cout<<"Opcion no encontrada, regresando..."<<endl;
                    sleep(1);
                    break;
                }


            break;
            case '4':
                
                system("cls");
                cout<<"[----------Menu Evento----------]"<<endl;
                cout<<"(1)-Cambiar evento especifico"<<endl;
                cout<<"(2)-Cambiar todos los eventos\n"<<endl;
                cin>>seleccion;
                cin.ignore();
                switch(seleccion){
                    case '1':
                    do{
                        system("cls");
                        impresion_enemigos(modo_seleccionado);
                        impresion_items(modo_seleccionado);
                    cout<<"Digit el numero del evento -> ";
                    cin>>valor;
                    cin.ignore();
                    valor -=1;
                    if(valor<0 || valor>9){
                        cout<<"No existe ese espacio"<<endl;
                    }
                    else{
                        cout<<"\n\n"<<endl;
                    cout<<"[--------------------------------------]\n"<<endl;
                    cout<<"\n\tEVENTO -> "<<valor<<endl;
                    cout<<"Digite el mensaje del evento: "<<endl;
                    getline(cin, modo[modo_seleccionado].evento[valor].texto_de_evento);
                    cout<<"Digite el numero del enemigo -> ";
                    cin>>modo[modo_seleccionado].evento[valor].numero_de_enemigo;
                    modo[modo_seleccionado].evento[valor].numero_de_enemigo -=1;
                    cin.ignore();
                    modo[modo_seleccionado].evento[valor].enemigo = modo[modo_seleccionado].enemigo[modo[modo_seleccionado].evento[valor].numero_de_enemigo];
                    cout<<"Digite el numero del item -> ";
                    cin>>modo[modo_seleccionado].evento[valor].numero_de_item;
                    modo[modo_seleccionado].evento[valor].numero_de_item -=1;
                    modo[modo_seleccionado].evento[valor].item = modo[modo_seleccionado].item[modo[modo_seleccionado].evento[valor].numero_de_enemigo];
                    cin.ignore();
                    }
                    }while(valor<0 || valor>9);
                    
                    break;
                    case '2':
                    cout<<"A continuacion, tendra que crear 10 enemigos"<<endl;
                        for(int i = 0; i<10;i++){
                            cout<<"\tENEMIGO -> "<<i+1<<endl;
                            cout<<"Nombre -> ";
                            cin.getline(modo[modo_seleccionado].enemigo[i].nombre,30,'\n');
                            cout<<"Vida -> ";
                            cin>>modo[modo_seleccionado].enemigo[i].vida;
                            cin.ignore();
                            cout<<"golpe -> ";
                            cin>>modo[modo_seleccionado].enemigo[i].golpe;
                            cin.ignore();
                        }
                    break;
                    default:
                    cout<<"Opcion no encontrada, regresando..."<<endl;
                    sleep(1);
                    break;
                }


            break;
            case '5':
            system("cls");
            system("cls");
            impresion_items(modo_seleccionado);
            cout<<"\n\nDigite el item que desea guardar -> ";
            cin>>valor;
            system("cls");
            imprimir_inventario(modo_seleccionado);
            cout<<"\n\nDigite el espacio donde desea guardarlo -> ";
            cin>>valor2;
            modo[modo_seleccionado].espacio[valor2].item = modo[modo_seleccionado].item[valor-1];
            break;

            case '6':
            system("cls");
            cout<<"IMPRIMIENDO TODOS LOS ITEMS/ENEMIGOS/EVENTOS"<<endl;
            impresion_eventos(modo_seleccionado);
            sleep(2);
            cout<<"\n\n"<<endl;
            impresion_enemigos(modo_seleccionado);
            sleep(2);
            cout<<"\n\n"<<endl;
            impresion_items(modo_seleccionado);
            sleep(2);
            cout<<"\n\n"<<endl;
            break;
            case '7':
                cout<<"Regresando...."<<endl;
                sleep(1);
                continuar = false;
            break;
            default:
            cout<<"Esa opcion no existe...."<<endl;
            sleep(1);
            break;
        }
    }
    
} 

//EXTRA
void puntos_de_carga(){
    for(int i=0; i<5;i++){
        cout<<".";
        sleep(1);
    }
    cout<<"\n\n"<<endl;
}

//CREACION DEL PERSONAJE
void creacion_del_personaje(int modo_seleccionado){
    system("cls");
    char valor = ' ';
    cout<<"[-------------BIENVENIDO---------------]"<<endl;
    cout<<"Es momento de crear a su personaje\n"<<endl;
    cout<<"\tNOMBRE -> ";
    cin.getline(modo[modo_seleccionado].personaje.informacion.nombre,25,'\n');
    cout<<"\tAPELLIDO -> ";
    cin.getline(modo[modo_seleccionado].personaje.informacion.apellido,25,'\n');
    cout<<"\tAPODO -> ";
    cin.getline(modo[modo_seleccionado].personaje.informacion.apodo,15,'\n');
    cout<<"[---------DIFICULTAD---------]"<<endl;
    cout<<"(1)-Facil"<<endl;
    cout<<"(2)-Intermedio"<<endl;
    cout<<"(3)-Dificil"<<endl;
    cin>>valor;
    cin.ignore();
    switch(valor){
        case '1':
            modo[modo_seleccionado].personaje.estadisticas.vida_maxima = 150;
            modo[modo_seleccionado].personaje.estadisticas.vida = 150;
            modo[modo_seleccionado].personaje.estadisticas.vidas = 5;

        break;
        case '2':
            modo[modo_seleccionado].personaje.estadisticas.vida_maxima = 120;
            modo[modo_seleccionado].personaje.estadisticas.vida = 120;
            modo[modo_seleccionado].personaje.estadisticas.vidas = 3;
        break;
        case '3':
            modo[modo_seleccionado].personaje.estadisticas.vida_maxima = 90;
            modo[modo_seleccionado].personaje.estadisticas.vida = 90;
            modo[modo_seleccionado].personaje.estadisticas.vidas = 1;
        break;
        case 'K':
            modo[modo_seleccionado].personaje.estadisticas.vida_maxima = 100000;
            modo[modo_seleccionado].personaje.estadisticas.vida = 100000;
            modo[modo_seleccionado].personaje.estadisticas.vidas = 100;
        break;
        default: cout<<" Esa opcion no existe....."<<endl;
        break;
    }
    modo[modo_seleccionado].personaje.estadisticas.golpe_total_efectuado = 0;
    modo[modo_seleccionado].personaje.estadisticas.golpe_total_recibido = 0;
    modo[modo_seleccionado].personaje.estadisticas.oleadas_sobrevividas = 0;
    modo[modo_seleccionado].personaje.estadisticas.enemigos_matados = 0;
    modo[modo_seleccionado].personaje.estadisticas.enemigos_sobrevividos = 0;
    for(int i = 0; i<10;i++){
        strcpy(modo[modo_seleccionado].espacio[i].item.nombre_del_item, "Vacio") ;
        modo[modo_seleccionado].espacio[i].item.usos = 0;
        modo[modo_seleccionado].espacio[i].item.cantidad = 0;
        modo[modo_seleccionado].espacio[i].item.golpe = 0;
    }
    cout<<"\n\n"<<endl;
}
//FUNCION DE REGULADOR DE VIDA
bool gestor_vida(int modo_seleccionado){
    bool personaje_vivo_muerto = true;
    if(modo[modo_seleccionado].personaje.estadisticas.vida <=0){
        if(modo[modo_seleccionado].personaje.estadisticas.vidas>=1){
            modo[modo_seleccionado].personaje.estadisticas.vidas -=1;
            modo[modo_seleccionado].personaje.estadisticas.vida = modo[modo_seleccionado].personaje.estadisticas.vida_maxima;
        }
        else{
            if(modo[modo_seleccionado].personaje.estadisticas.vidas==0){
            for(int i = 0; i<10;i++){
                if(strcmp(modo[modo_seleccionado].espacio[i].item.nombre_del_item, "Vida Extra" ) == 0){
                    if( modo[modo_seleccionado].espacio[i].item.usos >=1){
                        modo[modo_seleccionado].personaje.estadisticas.vida = modo[modo_seleccionado].personaje.estadisticas.vida_maxima;
                        modo[modo_seleccionado].espacio[i].item.usos--;
                    }
                }

            }
            }
        }
    }
    if(modo[modo_seleccionado].personaje.estadisticas.vida >modo[modo_seleccionado].personaje.estadisticas.vida_maxima){
        modo[modo_seleccionado].personaje.estadisticas.vida = modo[modo_seleccionado].personaje.estadisticas.vida_maxima;
    }
    if(modo[modo_seleccionado].personaje.estadisticas.vida <= 0 && modo[modo_seleccionado].personaje.estadisticas.vidas <= 0){
        personaje_vivo_muerto = false;
    }
    return personaje_vivo_muerto;
}
//FUNCIONES DE AVANZAR
void avanzar(int modo_seleccionado){
    int probabilidad = 0+rand()%10;
    if(probabilidad>=4){
        avanzar_enemigo(modo_seleccionado);
    }
    else{
    if(probabilidad<=3){
        avanzar_item(modo_seleccionado);
    }
    }
}
void avanzar_enemigo(int modo_seleccionado){
    int valor;
    char eleccion = ' ';
    int aleatorio = 0+rand()%10;
    int aleatorio2 = 0+rand()%20;
    cout<<"AVANZANDO";
    puntos_de_carga();
    do{
    system("cls");
    cout<<"[---------INFORMACION---------]"<<endl;
    cout<<modo[modo_seleccionado].evento[aleatorio].texto_de_evento<<endl;
    cout<<modo[modo_seleccionado].evento[aleatorio].enemigo.nombre<<endl;
    cout<<"Vida -> "<<modo[modo_seleccionado].evento[aleatorio].enemigo.vida<<endl;
    cout<<"Golpe -> "<<modo[modo_seleccionado].evento[aleatorio].enemigo.golpe<<endl;
    cout<<"\n\n\t(1)-Atacar\t(2)-Correr"<<endl;
    cin>>eleccion;
    cin.ignore();
    switch(eleccion){
        case '1':
        
        do{
            inventario_verificador(modo_seleccionado);
            system("cls");
            cout<<"[---------INFORMACION---------]"<<endl;
            cout<<modo[modo_seleccionado].evento[aleatorio].texto_de_evento<<endl;
            cout<<modo[modo_seleccionado].evento[aleatorio].enemigo.nombre<<endl;
            cout<<"Vida -> "<<modo[modo_seleccionado].evento[aleatorio].enemigo.vida<<endl;
            cout<<"Golpe -> "<<modo[modo_seleccionado].evento[aleatorio].enemigo.golpe<<endl;
            
            imprimir_inventario(modo_seleccionado);
            cout<<"\n\nDigite un item a usar -> ";
            cin>>valor;
            if(valor<0 || valor>9){
            cout<<"Ese espacio no existe "<<endl;
            sleep(1);
            }
            else{
                if(strcmp(modo[modo_seleccionado].espacio[valor].item.nombre_del_item, "Vacio" ) == 0){
                    cout<<"En ese espacio no hay un item, obtaste por correr"<<endl;
                    sleep(1);
                    correr_escapar(modo_seleccionado, aleatorio, aleatorio2);
                    break;

                }
                else{
                    modo[modo_seleccionado].evento[aleatorio].enemigo.vida -= modo[modo_seleccionado].espacio[valor].item.golpe;
                    modo[modo_seleccionado].espacio[valor].item.usos--;
                    cout<<"Se ha usado -> "<<modo[modo_seleccionado].espacio[valor].item.nombre_del_item<<endl;
                    cout<<"La cantidad de usos restantes es de -> "<<modo[modo_seleccionado].espacio[valor].item.usos<<endl;
                    sleep(1);
                    cout<<"La vida del enemigo ahora es de -> "<<modo[modo_seleccionado].evento[aleatorio].enemigo.vida<<endl;
                    sleep(1);
                    modo[modo_seleccionado].personaje.estadisticas.golpe_total_efectuado += modo[modo_seleccionado].espacio[valor].item.golpe;
                    if(modo[modo_seleccionado].evento[aleatorio].enemigo.vida<=0){
                        modo[modo_seleccionado].personaje.estadisticas.enemigos_matados++;
                        modo[modo_seleccionado].personaje.estadisticas.enemigos_sobrevividos++;
                        modo[modo_seleccionado].personaje.estadisticas.oleadas_sobrevividas++;
                        cout<<"Has matado al enemigo...."<<endl;
                        sleep(2);
                    }
                }
            }
            
        }while(valor<0 || valor>9 || strcmp(modo[modo_seleccionado].espacio[valor].item.nombre_del_item, "Vacio" ) == 0 || modo[modo_seleccionado].evento[aleatorio].enemigo.vida >0);
        

        
        
        break;
        case '2':
        correr_escapar(modo_seleccionado, aleatorio, aleatorio2);
        break;
        default: cout<<"Esa opcion no existe, vuelva a intentarlo"<<endl;
        sleep(1);
        break;
    }
    }while(eleccion != '1' && eleccion != '2');
}
void correr_escapar(int modo_seleccionado, int aleatorio, int aleatorio2){
    cout<<"Estas corriendo";
        puntos_de_carga();
        
        if(aleatorio2>=8){
            cout<<"Oh no, al tratar de escapar el enemigo "<<modo[modo_seleccionado].evento[aleatorio].enemigo.nombre<<" te ha logrado acertar un leve golpe"<<endl;
            int aleatorio3 = 1+rand()%modo[modo_seleccionado].evento[aleatorio].enemigo.golpe;
            cout<<"Has recibido de golpe -> "<<aleatorio3<<endl;
            cout<<"Vida actual, antes del golpe -> "<<modo[modo_seleccionado].personaje.estadisticas.vida<<endl;
            sleep(1);
            modo[modo_seleccionado].personaje.estadisticas.vida -=aleatorio3;
            modo[modo_seleccionado].personaje.estadisticas.golpe_total_recibido +=aleatorio3;
            modo[modo_seleccionado].personaje.estadisticas.oleadas_sobrevividas++;
            modo[modo_seleccionado].personaje.estadisticas.enemigos_sobrevividos++;
            cout<<"Vida actual, despues del golpe -> "<<modo[modo_seleccionado].personaje.estadisticas.vida<<endl;
        }
        else{
            cout<<"Lograste correr, y salir con vida"<<endl;
            modo[modo_seleccionado].personaje.estadisticas.oleadas_sobrevividas++;
            modo[modo_seleccionado].personaje.estadisticas.enemigos_sobrevividos++;
        }
        system("pause");
}
void avanzar_item(int modo_seleccionado){
    modo[modo_seleccionado].personaje.estadisticas.oleadas_sobrevividas++;
    int valor;
    char eleccion = ' ';
    int aleatorio = 0+rand()%10;
    cout<<"AVANZANDO";
    puntos_de_carga();
    system("cls");
    do{
        cout<<"[---------INFORMACION---------]"<<endl;
        cout<<"Te has encontrado con un objeto desconocido...."<<endl;
        cout<<"Nombre -> "<<modo[modo_seleccionado].evento[aleatorio].item.nombre_del_item<<endl;
        cout<<"Golpe -> "<<modo[modo_seleccionado].evento[aleatorio].item.golpe<<endl;
        cout<<"Usos -> "<<modo[modo_seleccionado].evento[aleatorio].item.usos<<endl;
        cout<<"\n\n\t(1)-Revisar/Tomar\t(2)-Irse"<<endl;
        cin>>eleccion;
        cin.ignore();
        switch(eleccion){
            case '1':
                imprimir_inventario(modo_seleccionado);
                cout<<"\n\nDigite el espacio donde guardara el item"<<endl;
                cin>>valor;
                if(valor>9 || valor<0){
                    cout<<"Espacio No existente"<<endl;
                    sleep(1);
                }
                else{
                    if(strcmp(modo[modo_seleccionado].espacio[valor].item.nombre_del_item, "Vacio") == 0){
                        modo[modo_seleccionado].espacio[valor].item = modo[modo_seleccionado].evento[aleatorio].item;
                        cout<<"Se guardo correctamente...."<<endl;
                        sleep(1);
                    }
                    else{
                        if(strcmp(modo[modo_seleccionado].espacio[valor].item.nombre_del_item, "Vacio") != 0){
                        cout<<"En ese espacio ya hay un item....Desea borrarlo?"<<endl;
                        cout<<"(1)-Si (2)-2"<<endl;
                        cin>>eleccion;
                        cin.ignore();
                        switch(eleccion){
                            case '1': 
                            modo[modo_seleccionado].espacio[valor].item = modo[modo_seleccionado].evento[aleatorio].item;
                            cout<<"Se guardo correctamente...."<<endl;
                            sleep(1);
                            break;
                            case '2':
                            cout<<"Regresando..."<<endl;
                            sleep(1);
                            break;
                            default: cout<<"Esa opcion no existe, Regresando automaticamente"<<endl;
                            sleep(1);
                            break;

                        }

                    }
                    }
                }
                
            break;
            case '2':
            cout<<"Te retiras sin dejar rastro";
            puntos_de_carga();
            break;
            default: cout<<"Esa opcion no existe, vuelva a intentarlo"<<endl;
            sleep(1);
            break;
        }

    }while(eleccion != '1' && eleccion != '2');

    
}

//FUNCIONES DE INVENTARIO
void imprimir_inventario(int modo_seleccionado){
    cout<<"IMPRIMIENDO INVENTARIO";
    puntos_de_carga();
    for(int i = 0; i<10; i++){
        cout<<"\tEspacio -> "<<i<<endl;
        cout<<"Item -> "<<modo[modo_seleccionado].espacio[i].item.nombre_del_item<<endl;
        cout<<"Golpe -> "<<modo[modo_seleccionado].espacio[i].item.golpe<<endl;
        cout<<"Usos -> "<<modo[modo_seleccionado].espacio[i].item.usos<<endl;
    }
}

void inventario_verificador(int modo_seleccionado){
    for(int i = 0; i<10;i++){
        if(modo[modo_seleccionado].espacio[i].item.usos <= 0){
            strcpy(modo[modo_seleccionado].espacio[i].item.nombre_del_item, "Vacio") ;
                modo[modo_seleccionado].espacio[i].item.usos = 0;
                modo[modo_seleccionado].espacio[i].item.cantidad = 0;
                modo[modo_seleccionado].espacio[i].item.golpe = 0;
        }
    }
}

void inventario(int modo_seleccionado){
    int valor;
    char eleccion = ' ';
    imprimir_inventario(modo_seleccionado);
    cout<<"\n\t(1)-Consumir Cierto Item\t(2)-Eliminar Cierto Item (Otro)-Salir"<<endl;
    cin>>eleccion;
    cin.ignore();
    switch(eleccion){
        case '1':
        cout<<"Digite el numero de espacio -> ";
        cin>>valor;
        if(valor>9 || valor<0){
            cout<<"Espacio No existente"<<endl;
            sleep(1);
        }
        else{
            if(strcmp(modo[modo_seleccionado].espacio[valor].item.nombre_del_item, "Vida Extra") == 0){
                modo[modo_seleccionado].espacio[valor].item.usos--;
                modo[modo_seleccionado].personaje.estadisticas.vidas++;
            }
            else{
                if(strcmp(modo[modo_seleccionado].espacio[valor].item.nombre_del_item, "Pocima Curativa") == 0){
                    modo[modo_seleccionado].espacio[valor].item.usos--;
                    modo[modo_seleccionado].personaje.estadisticas.vida = modo[modo_seleccionado].personaje.estadisticas.vida - (modo[modo_seleccionado].espacio[valor].item.golpe);
                }
                else{
                cout<<"Ese objeto no es un consumible"<<endl;
                sleep(1);
                }
            }
            
        }


        break;
        case '2':
        cout<<"Digite el numero de espacio -> ";
        cin>>valor;
        if(valor>9 || valor<0){
            cout<<"Espacio No existente"<<endl;
            sleep(1);
        }
        else{
            if(strcmp(modo[modo_seleccionado].espacio[valor].item.nombre_del_item, "Vacio") == 0){
                cout<<"No hay ningun item guardado"<<endl;
                sleep(1);
                
            }
            else{
                if(strcmp(modo[modo_seleccionado].espacio[valor].item.nombre_del_item, "Vacio") != 0){
                strcpy(modo[modo_seleccionado].espacio[valor].item.nombre_del_item, "Vacio") ;
                modo[modo_seleccionado].espacio[valor].item.usos = 0;
                modo[modo_seleccionado].espacio[valor].item.cantidad = 0;
                modo[modo_seleccionado].espacio[valor].item.golpe = 0;
                cout<<"Item eliminado";
                puntos_de_carga();
            }
            }
        }

        break;
        default:
            cout<<"Regresando..."<<endl;
            sleep(1);
        break;
    }

}

//FUNCIONES DE ESTADISTICAS E INFORMACION DEL PERSONAJE
void imprimir_estadisticas(int modo_seleccionado){
    cout<<"IMPRIMIENDO DATOS ESTADISTICOS";
    puntos_de_carga();
    cout<<"\n\n"<<endl;
    cout<<"\n[--------------Informacion del Personaje--------------]"<<endl;
    cout<<"Nombre -> "<<modo[modo_seleccionado].personaje.informacion.nombre<<endl;
    cout<<"Apellido -> "<<modo[modo_seleccionado].personaje.informacion.apellido<<endl;
    cout<<"Apodo -> "<<modo[modo_seleccionado].personaje.informacion.apodo<<endl;
    cout<<"\n[--------------Estadisticas del Personaje--------------]"<<endl;
    cout<<"Vida Maxima -> "<<modo[modo_seleccionado].personaje.estadisticas.vida_maxima<<endl;
    cout<<"Vidas Actuales -> "<<modo[modo_seleccionado].personaje.estadisticas.vidas<<endl;
    cout<<"Vida Actual -> "<<modo[modo_seleccionado].personaje.estadisticas.vida<<endl;
    if(modo[modo_seleccionado].personaje.estadisticas.estado){
        cout<<"Estado -> VIVO"<<endl;
    }
    else{
        if(!modo[modo_seleccionado].personaje.estadisticas.estado){
        cout<<"Estado -> MUERTO"<<endl;
    }
    }
    cout<<"Oleadas Sobrevividas -> "<<modo[modo_seleccionado].personaje.estadisticas.oleadas_sobrevividas<<endl;
    cout<<"Golpe Total Efectuado -> "<<modo[modo_seleccionado].personaje.estadisticas.golpe_total_efectuado<<endl;
    cout<<"Enemigos Abatidos -> "<<modo[modo_seleccionado].personaje.estadisticas.enemigos_matados<<endl;
    cout<<"Golpe Total Recibido -> "<<modo[modo_seleccionado].personaje.estadisticas.golpe_total_recibido<<endl;
    cout<<"Enemigos Sobrevividos -> "<<modo[modo_seleccionado].personaje.estadisticas.enemigos_sobrevividos<<endl;
    system("pause");
}
//GUARDADO DE DATOS
void guardarinfousuario(){
    fs::create_directory("TheAdventure");

    ofstream archivo;
    int modo_seleccionado;
    modo_seleccionado = 0;
    archivo.open("TheAdventure/historia.txt",ios::out);
    archivo<<modo[modo_seleccionado].personaje.estadisticas.estado<<endl;
    archivo<<modo[modo_seleccionado].personaje.creado<<endl;
    archivo<<modo[modo_seleccionado].personaje.informacion.nombre<<endl;
    archivo<<modo[modo_seleccionado].personaje.informacion.apellido<<endl;
    archivo<<modo[modo_seleccionado].personaje.informacion.apodo<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.vida_maxima<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.vidas<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.vida<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.oleadas_sobrevividas<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.golpe_total_efectuado<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.enemigos_matados<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.golpe_total_recibido<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.enemigos_sobrevividos<<endl;
    modo_seleccionado = 1;

    archivo.close();
    archivo.open("TheAdventure/creativo.txt",ios::out);
    archivo<<modo[modo_seleccionado].personaje.estadisticas.estado<<endl;
    archivo<<modo[modo_seleccionado].personaje.creado<<endl;
    archivo<<modo[modo_seleccionado].personaje.informacion.nombre<<endl;
    archivo<<modo[modo_seleccionado].personaje.informacion.apellido<<endl;
    archivo<<modo[modo_seleccionado].personaje.informacion.apodo<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.vida_maxima<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.vidas<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.vida<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.oleadas_sobrevividas<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.golpe_total_efectuado<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.enemigos_matados<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.golpe_total_recibido<<endl;
    archivo<<modo[modo_seleccionado].personaje.estadisticas.enemigos_sobrevividos<<endl;
    archivo.close();

    
}
void leerinfousuario() {
    ifstream archivo;
    bool creado,estado;
    int modo_seleccionado;
    char nombre[25], apellido[25], apodo[15];
    int vida_maxima, vidas, vida, oleadas_sobrevividas, golpe_total_efectuado, enemigos_matados, golpe_total_recibido, enemigos_sobrevividos;

    modo_seleccionado = 0;
    archivo.open("TheAdventure/historia.txt", ios::in);

    archivo >> estado >> creado >> nombre >> apellido >> apodo >> vida_maxima >> vidas >> vida >> oleadas_sobrevividas >> golpe_total_efectuado >> enemigos_matados >> golpe_total_recibido >> enemigos_sobrevividos;
    archivo.close();

    // Ahora, puedes asignar los valores a la estructura o variables que deseas
    modo[modo_seleccionado].personaje.estadisticas.estado = estado;
    modo[modo_seleccionado].personaje.creado = creado;
    strcpy(modo[modo_seleccionado].personaje.informacion.nombre,nombre);
    strcpy(modo[modo_seleccionado].personaje.informacion.apellido,apellido);
    strcpy(modo[modo_seleccionado].personaje.informacion.apodo,apodo);
    modo[modo_seleccionado].personaje.estadisticas.vida_maxima = vida_maxima;
    modo[modo_seleccionado].personaje.estadisticas.vidas = vidas;
    modo[modo_seleccionado].personaje.estadisticas.vida = vida;
    modo[modo_seleccionado].personaje.estadisticas.oleadas_sobrevividas = oleadas_sobrevividas;
    modo[modo_seleccionado].personaje.estadisticas.golpe_total_efectuado = golpe_total_efectuado;
    modo[modo_seleccionado].personaje.estadisticas.enemigos_matados = enemigos_matados;
    modo[modo_seleccionado].personaje.estadisticas.golpe_total_recibido = golpe_total_recibido;
    modo[modo_seleccionado].personaje.estadisticas.enemigos_sobrevividos = enemigos_sobrevividos;

    modo_seleccionado = 1;
    archivo.open("TheAdventure/creativo.txt", ios::in);

    archivo >> estado >> creado >> nombre >> apellido >> apodo >> vida_maxima >> vidas >> vida >> oleadas_sobrevividas >> golpe_total_efectuado >> enemigos_matados >> golpe_total_recibido >> enemigos_sobrevividos;
    archivo.close();

    // Ahora, puedes asignar los valores a la estructura o variables que deseas
    modo[modo_seleccionado].personaje.estadisticas.estado = estado;
    modo[modo_seleccionado].personaje.creado = creado;
    strcpy(modo[modo_seleccionado].personaje.informacion.nombre,nombre);
    strcpy(modo[modo_seleccionado].personaje.informacion.apellido,apellido);
    strcpy(modo[modo_seleccionado].personaje.informacion.apodo,apodo);
    modo[modo_seleccionado].personaje.estadisticas.vida_maxima = vida_maxima;
    modo[modo_seleccionado].personaje.estadisticas.vidas = vidas;
    modo[modo_seleccionado].personaje.estadisticas.vida = vida;
    modo[modo_seleccionado].personaje.estadisticas.oleadas_sobrevividas = oleadas_sobrevividas;
    modo[modo_seleccionado].personaje.estadisticas.golpe_total_efectuado = golpe_total_efectuado;
    modo[modo_seleccionado].personaje.estadisticas.enemigos_matados = enemigos_matados;
    modo[modo_seleccionado].personaje.estadisticas.golpe_total_recibido = golpe_total_recibido;
    modo[modo_seleccionado].personaje.estadisticas.enemigos_sobrevividos = enemigos_sobrevividos;
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/