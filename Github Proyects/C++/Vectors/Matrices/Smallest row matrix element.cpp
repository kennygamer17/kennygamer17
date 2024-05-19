#include <iostream>
    using namespace std;

int matriz[100][100],filas,columnas;
void menor_elemento();

int main(){
    cout<<"Digite la cantidad de filas -> ";cin>>filas;
    cout<<"Digite la cantidad de columnas -> ";cin>>columnas;
    for(int i = 0; i<filas;i++){
        for(int j = 0; j<columnas;j++){
            cout<<"Digite el valor de ["<<i<<"]["<<j<<"] -> ";
            cin>>matriz[i][j];
        }
    }
    menor_elemento();
    return 0;
}
void menor_elemento(){
    for(int i = 0; i<filas;i++){
        int valor = matriz[i][0];
        for(int j = 0; j<columnas;j++){
            if(valor>matriz[i][j]){
                valor = matriz[i][j];
            }
        }
        cout<<"fila "<<i<<" menor valor -> "<<valor<<endl;
    }
}