//SNAKE EN TERMINAL XDDDD
#include <conio.h> 
#include <iostream> //-> _kbhit() Sirve para comprobar rapidamente si hay una tecla precionada
#include <windows.h>// -> Para Sleep() hacer los tiempos de carga
#include <vector>
#include <stdio.h>
#include <stdlib.h>//Made by Lexor_12 || kennygamer17 on github -> https://github.com/kennygamer17
#include<time.h>
    using namespace std;

#define FILAS 15
#define COLUMNAS 15//Made by Lexor_12 || kennygamer17 on github -> https://github.com/kennygamer17
#define tamano FILAS*COLUMNAS

class Snake{
    private:
        //Tablero
        vector<char> tablero; //Guardamos todo el juego
        vector<int> serpiente; //Guardamos posiciones donde iran los valores de la serpiente
        vector<int> paredes;
        int puntaje;
        
    public:
        //Constructor
        Snake(){
            puntaje = 0;
            tablero.resize(tamano,'*');//Inicializamos el tablero
            serpiente.push_back(96);//Iniciamos con la cabeza//Made by Lexor_12 || kennygamer17 on github -> https://github.com/kennygamer17
            paredes.push_back(0);
            for(int i = 0;i<COLUMNAS-1;i++){
                paredes.push_back((FILAS*i));
                paredes.push_back((FILAS*i)-1);
            }
            for(int i = 0;i<COLUMNAS;i++){
                paredes.push_back(i);
                paredes.push_back(FILAS*(COLUMNAS-1)+i);
            }
            paredes.push_back(224);
            paredes.push_back(FILAS*(COLUMNAS)-1);
        }
        //Metodos
        void imprimirTabla(int dirManzana){
            int contador = 0;
            fill(tablero.begin(),tablero.end(),'*');
            tablero[dirManzana] = '@';
            actualizarSerpiente();
            for(int i =0;i<tamano;i++){
                if(contador==15){cout<<endl;contador=0;}
                cout<<tablero[i]<<" ";//Made by Lexor_12 || kennygamer17 on github -> https://github.com/kennygamer17
                contador++;
            }
            cout<<endl;
        }
        int posicionDisponibleManzana(){
            int numero = 15 +rand() % 100; // Rango correcto: [0, tamano-1]
            while(tablero[numero] != '*' || esUbicacionPared(numero)){
                numero = 15 +rand() % 100;
            }
            return numero;
        }
        void actualizarSerpiente(){//Actualiza con respecto a la serpiente y el tablero
            for(const auto& u : serpiente){
                tablero[u] = '#';
            }
            tablero[serpiente[0]] = '$';

        }//Made by Lexor_12 || kennygamer17 on github -> https://github.com/kennygamer17
        bool esUbicacionPared(int dirMatriz){
            for(const int p :paredes ){
                if(dirMatriz == p)return true;
            }
            return false;
        }
        bool aunPuedeContinuar(){
            if(esUbicacionPared(getPositionIndexHead())) return false;
            for(int i = 1;i<serpiente.size();i++){
                if(getPositionIndexHead() == serpiente[i]) return false;
            }
            return true;
        }
        void moverSerpiente(int nuevaUbicacion){
            /* int n = serpiente.size();
            for(int i =0;i<n;i++){
                int aux = serpiente[i];
                serpiente[i] = nuevaUbicacion;
                nuevaUbicacion= aux;
            } */
            serpiente.insert(serpiente.begin(),nuevaUbicacion);
            serpiente.pop_back();
        }
        void aumentarTamanoSerpiente(int dir, char lastInput){
            dir = calcularNuevaDireccion(dir,lastInput);
            serpiente.insert(serpiente.begin(),dir);
            puntaje++;
        }
        int calcularNuevaDireccion(int dir, char lastInput){
            if(lastInput==87 || lastInput==119)//W
            {
                dir-=15;
            }
            if(lastInput==97 || lastInput==65)//A
            { 
                dir-=1;
            }
            if(lastInput==83 || lastInput==115)//S
            {
                dir+=15;
            }
            if(lastInput==68 || lastInput==100)//D
            {
                dir+=1;
            } 
            return dir;
        }
        bool comioManzana(int dir){
            if(tablero[dir] == '@') return true;
            return false;
        }
        void juegadorMuertoFinal(){
            cout<<"\n\n\tEL JUEGO HA TERMINADO, TU PUNTUACION ES DE: "<<puntaje<<endl;
        }
        //Getters
        int getPositionIndexHead(){return serpiente[0];}
        vector<int> getSerpiente(){return serpiente;}


};//Made by Lexor_12 || kennygamer17 on github -> https://github.com/kennygamer17

int main(){
    srand(time(nullptr));
    Snake juego;
    cout<<"\n\nBIENVENIDO A SNAKE 2.0 EN TERMINAL HECHO POR LEXOR_12\tA continuacion, preciona cualquier tecla para continuar, en caso contrario sal de la ventana."<<endl;
    cout<<"INSTRUCCIONES: \n\tPULSA UNA TECLA PARA MOVERTE SI PULAS MUCHAS, ESTAS UNA POR UNA SE PROCESARA\n\tLAS PAREDES SON LOS BORDES de *\n\tEL MOVIMIENTO ES CON WASD\n\tDIVIERTETE"<<endl;
    getch();
    //Made by Lexor_12 || kennygamer17 on github -> https://github.com/kennygamer17
    char lastInput = 87;
    int ubiManzana = juego.posicionDisponibleManzana();
    while(juego.aunPuedeContinuar()){
        juego.imprimirTabla(ubiManzana);
        char input = '\0';
        int dir = juego.getPositionIndexHead();//Made by Lexor_12 || kennygamer17 on github -> https://github.com/kennygamer17
        _flushall();
        if(_kbhit()){//Si se esta precionando una tecla
            input = getch();
            dir = juego.calcularNuevaDireccion(dir,input);
            lastInput = input;    //Made by Lexor_12 || kennygamer17 on github -> https://github.com/kennygamer17
        }else{
            dir = juego.calcularNuevaDireccion(dir,lastInput);
        }
        if(juego.comioManzana(dir)) {juego.aumentarTamanoSerpiente(dir,input); ubiManzana = juego.posicionDisponibleManzana();}//Actualizamos ubi
        else juego.moverSerpiente(dir);
        juego.actualizarSerpiente();
        system("cls");//Made by Lexor_12 || kennygamer17 on github -> https://github.com/kennygamer17
        juego.imprimirTabla(ubiManzana);
        int velocidad = 500 - (juego.getSerpiente().size() * 5);
        velocidad = max(velocidad, 100); // Para que no sea demasiado rápido
        Sleep(velocidad);
        system("cls");
    }
    juego.juegadorMuertoFinal();

    return 0;
}
//Made by Lexor_12 || kennygamer17 on github -> https://github.com/kennygamer17
