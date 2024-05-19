#include <iostream>
    using namespace std;

int matriz[100][100],filas,columnas;

void pedir_datos_matriz();
void calculador_simetria_matriz();


int main(){
    pedir_datos_matriz();
    calculador_simetria_matriz();
    return 0;
}/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
void pedir_datos_matriz(){
    cout<<"Digite la cantidad de filas -> "; cin>>filas;
    cout<<"Digite la cantidad de columnas -> "; cin>>columnas;
    for(int i = 0; i<filas; i++){
        for(int j = 0;j<columnas;j++){
            cout<<"Digite el valor de ["<<i<<"]["<<j<<"] -> ";
            cin>>matriz[i][j];
        }
    }/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
}
void calculador_simetria_matriz(){
    bool simetrico = true;
    for(int i = 0; i<filas; i++){
        for(int j = 0;j<columnas;j++){
            if(matriz[i][j] != matriz[j][i]){
                simetrico = false;
            }
        }
    }
    if(simetrico){
        cout<<"\nLa matriz es simetrica "<<endl;
    }
    else{
        if(!simetrico){
            cout<<"\nLa matriz NO es simetrica "<<endl;
        }
    }
}/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
