#include <iostream>
#include <time.h>
#include <stdlib.h>
    using namespace std;

void primo(int numero);

int main(){
    srand(time(NULL));
    cout<<"."<<endl;
    int numero;
    for(int i = 0; i<10;i++){
        numero = 1+rand()%100;
        primo(numero);
        cout<<"----------------------------------------------------------------------"<<endl;
    }
    return 0;
}
void primo(int numero){
    int valores[numero];
    int contador = 0;
    for(int i = 1; i<=numero;i++){
        if((numero%i) == 0){
            valores[contador] = i;
            contador++;
        }
    }
    if(contador >=3){
        cout<<"El numero -> "<<numero<<" No es primo....";
        cout<<"Los numeros que dividien al numero "<<numero<<" son: ";
        for(int i = 0; i<contador;i++){
            cout<<"\t"<<valores[i];
        }
    }
    else{
        if(contador ==2){
        cout<<"El numero -> "<<numero<<" Si es primo. ";
        cout<<"Los numeros que dividien al numero "<<numero<<" son: ";
        for(int i = 0; i<contador;i++){
            cout<<"\t"<<valores[i];
        }
    }
    }
    cout<<"\n"<<endl;
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
