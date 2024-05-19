#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
    using namespace std;
int main(){
    char palabra[30];
    bool palindromo = false;
    while(true){
        cout<<"Digite una palabra sin espacios -> ";
    cin>>palabra;
    if(strcmp(palabra, "salir")==0){
        break;
    }
    int tamano = strlen(palabra);
    for(int i = 0; i<tamano; i++){
        if(palabra[i] == palabra[tamano-1-i]){
            palindromo = true;
        }
        else{
            if(palabra[i] != palabra[tamano-1-i]){
            palindromo = false;
        }
        }
    }
    if(palindromo){
        cout<<" Es palindromo"<<endl;
    }
    if(!palindromo){
        cout<<"No es palindromo"<<endl;
    }
    }
    return 0;
}