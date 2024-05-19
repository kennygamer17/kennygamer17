#include <iostream>
#include <conio.h>
#include <stdlib.h>
    using namespace std;

int main(){
    string arreglo[9] = {"1","2","3","4","5","6","7","8","9"};
    int k = 0;
    string lugar;
    bool continuar = true;
    bool persona1 = true;
    bool borrar_datos = false;
    int juegos_realizados = 0;
    string valores[] = {"X", "O"};
    bool ganador = false;
    string usuarios[2];
    int puntos[2] = {0,0};
    string numerosposibles[9] = {"1","2","3","4","5","6","7","8","9"};
    bool empate = false;

    for(int i = 0; i<2; i++){
        puntos[i] = 0;
    }

    cout<<"Bienvenido"<<endl;
            cout<<"\n Digite el nombre del jugador 1 -> ";
            getline(cin, usuarios[0]);
            cout<<"\n Digite el nombre del jugador 2 -> ";
            getline(cin, usuarios[1]);
            while(continuar)
    {
        //Aqui imprimimos los valores como tabla
        if(!borrar_datos){
            for(int i = 0; i<3; i++){
            cout<<"|";
            for(int j= 0; j<3; j++){
            cout<<" "<<arreglo[k]<<" |";
            k +=1;
            }
            cout<<endl;
        }
        k = 0;    //igualamos a 0 para que en el for se vuelva a imprimir desde 0, u no desde 10
        cout<<"---------------"<<endl;
        }
        //Aqui vamos a poner todas las formas de ganar
        
        for(int i = 0; i<1; i++){

            if(arreglo[0] == valores[i] && arreglo[1] == valores[i] && arreglo[2] == valores[i]){
                puntos[i] +=1;
                cout<<"Ha ganado el jugador -> "<<usuarios[i]<<endl;
                cout<<"Puntos actuales -> "<<puntos[i]<<endl;
                system("pause");
                borrar_datos = true;
                ganador = true;
                
                
                if(valores[i] == "X"){
                    persona1 = true;
                }
                else{
                    persona1 = false;
                }
            }
            if(arreglo[3] == valores[i] && arreglo[4] == valores[i] && arreglo[5] == valores[i]){
                puntos[i] +=1;
                cout<<"Ha ganado el jugador -> "<<usuarios[i]<<endl;
                cout<<"Puntos actuales -> "<<puntos[i]<<endl;
                system("pause");
                borrar_datos = true;
                ganador = true;
                
                if(valores[i] == "X"){
                    persona1 = true;
                }
                else{
                    persona1 = false;
                }
            }
            if(arreglo[6] == valores[i] && arreglo[7] == valores[i] && arreglo[8] == valores[i]){
                puntos[i] +=1;
                cout<<"Ha ganado el jugador -> "<<usuarios[i]<<endl;
                cout<<"Puntos actuales -> "<<puntos[i]<<endl;
                system("pause");
                borrar_datos = true;
                ganador = true;
                
                if(valores[i] == "X"){
                    persona1 = true;
                }
                else{
                    persona1 = false;
                }
            }
            if(arreglo[0] == valores[i] && arreglo[3] == valores[i] && arreglo[6] == valores[i]){
                puntos[i] +=1;
                cout<<"Ha ganado el jugador -> "<<usuarios[i]<<endl;
                cout<<"Puntos actuales -> "<<puntos[i]<<endl;
                system("pause");
                borrar_datos = true;
                ganador = true;
                puntos[i] +=1;
                
                if(valores[i] == "X"){
                    persona1 = true;
                }
                else{
                    persona1 = false;
                }
            }
            if(arreglo[1] == valores[i] && arreglo[4] == valores[i] && arreglo[7] == valores[i]){
                 puntos[i] +=1;
                cout<<"Ha ganado el jugador -> "<<usuarios[i]<<endl;
                cout<<"Puntos actuales -> "<<puntos[i]<<endl;
                system("pause");
                borrar_datos = true;
                ganador = true;
               
                
                if(valores[i] == "X"){
                    persona1 = true;
                }
                else{
                    persona1 = false;
                }
            }
            if(arreglo[2] == valores[i] && arreglo[5] == valores[i] && arreglo[8] == valores[i]){
                puntos[i] +=1;
                cout<<"Ha ganado el jugador -> "<<usuarios[i]<<endl;
                cout<<"Puntos actuales -> "<<puntos[i]<<endl;
                system("pause");
                borrar_datos = true;
                ganador = true;
                if(valores[i] == "X"){
                    persona1 = true;
                }
                else{
                    persona1 = false;
                }
            }
            if(arreglo[0] == valores[i] && arreglo[4] == valores[i] && arreglo[8] == valores[i]){
                puntos[i] +=1;
                cout<<"Ha ganado el jugador -> "<<usuarios[i]<<endl;
                cout<<"Puntos actuales -> "<<puntos[i]<<endl;
                system("pause");
                borrar_datos = true;
                ganador = true;
                if(valores[i] == "X"){
                    persona1 = true;
                }
                else{
                    persona1 = false;
                }
            }
            if(arreglo[2] == valores[i] && arreglo[4] == valores[i] && arreglo[6] == valores[i]){
                puntos[i] +=1;
                cout<<"Ha ganado el jugador -> "<<usuarios[i]<<endl;
                cout<<"Puntos actuales -> "<<puntos[i]<<endl;
                system("pause");
                borrar_datos = true;
                ganador = true;
                if(valores[i] == "X"){
                    persona1 = true;
                }
                else{
                    persona1 = false;
                }
            }
            else{
                for(int j = 0; j<9;j++){
                    if(arreglo[j] == numerosposibles[j]){
                        empate = false;
                        break;
                    }
                    else{
                        if(arreglo[j] != numerosposibles[j]){
                            empate = true;
                        }
                    }
                }
                if(empate){
                    cout<<"Ups, que lamentable.... Quedo empate"<<endl;
                    ganador = true;
                    borrar_datos = true;
                    break;   
                }  
            }   
        }
        
        //Apartado reiniciar exclusivo mio xd
        if(borrar_datos){
                   arreglo[0] = "1";
                   arreglo[1] = "2";
                   arreglo[2] = "3";
                   arreglo[3] = "4";
                   arreglo[4] = "5";
                   arreglo[5] = "6";
                   arreglo[6] = "7";
                   arreglo[7] = "8";
                   arreglo[8] = "9";
                   borrar_datos  = false;
                   ganador = true;
                   cout<<"-------Se ha empezado un nuevo juego-------"<<endl;
                }
        //Sirve para por si se gano que aparezca y continue y etc, si lo borras esto te daras cuenta de que pasa
        if(ganador){
        for(int i = 0; i<3; i++){
            cout<<"|";
                for(int j= 0; j<3; j++){
                    cout<<" "<<arreglo[k]<<" |";
                    k +=1;
                }
                cout<<endl;
        }
        k = 0;    
        cout<<"---------------"<<endl;
        ganador = false;
        }
    //Ponemos un if, con una bool, persona1, que hace referencia a persona1 = true, significa que es jugador x, o si fuera false, seria jugador O
    if(persona1){
        cout<<"Donde desea agregar la x? -> ";
        cin>>lugar;
        if(lugar == "27"){
            borrar_datos = true;
        }
        if(lugar == "29"){
            cout<<"Juegos realizados: "<<juegos_realizados<<endl;
            cout<<"Ganador: "<<ganador<<endl;
            cout<<"Puntos jugador 1"<<(puntos[0])<<endl;
            cout<<"Puntos jugador 2"<<(puntos[1])<<endl;
        }
        else{
            if(lugar != "27"){
        for(int i = 0; i<9; i++){
                if(arreglo[i] == lugar){
                    if(arreglo[i] == "O" || arreglo[i] == "X" ){
                        cout<<"Ese espacio ya esta ocupado"<<endl;
                        system("pause");
                    }
                    else{
                        if(arreglo[i] != "O" || arreglo[i] != "X" ){
                            arreglo[i] = "X";
                            juegos_realizados +=1;
                            persona1 = false;
                        }
                    }
            }
        }
        }
        }
    }
    else{
        if(!persona1){
            cout<<"Donde desea agregar la O? -> ";
            cin>>lugar;
            if(lugar == "27"){
                borrar_datos = true;
        }
        if(lugar == "29"){
            cout<<"Juegos realizados: "<<juegos_realizados<<endl;
            cout<<"Ganador: "<<ganador<<endl;
            cout<<"Puntos jugador 1"<<puntos[0]<<endl;
            cout<<"Puntos jugador 2"<<puntos[1]<<endl;
        }
        else{
            for(int i = 0; i<9; i++){
                if(arreglo[i] == lugar){
                    if(arreglo[i] == "X" || arreglo[i] == "O"){
                        cout<<"Ese espacio ya esta ocupado"<<endl;
                        system("pause");
                    }
                    else{
                        if(arreglo[i] != "O" || arreglo[i] != "X" ){
                            arreglo[i] = "O";
                            juegos_realizados +=1;
                            persona1 = true;
                        }
                    }
                }
            }   
        }
        }  
    }
    }
    getch();
    return 0;
}
