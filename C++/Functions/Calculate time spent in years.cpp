#include <iostream>
#include <conio.h>
    using namespace std;

void calc_anos(int dias_digitados,int& ano,int&mes,int&dia);

int main(){
    int dias_digitados,ano,mes,dia;
    cout<<"Digite un numero de dias -> ";
    cin>>dias_digitados;

    calc_anos(dias_digitados,ano,mes,dia);


    return 0;
}
void calc_anos(int dias_digitados,int& ano,int&mes,int&dia){
    dia = 1; mes = 1; ano = 2000;

    if(dias_digitados>365){
        ano = ano + (dias_digitados/365);
        dia = dia + (dias_digitados%365);
    }
    else{
        dia = dia + dias_digitados;
    }
    if(dia>30){
        mes = mes + (dia/30);
        dia = dia%30;
    }
    cout<<dia<<"/";
    if(mes<=11){
        cout<<"0"<<mes<<"/"<<ano<<endl;
    }
    else{
        cout<<mes<<"/"<<ano<<endl;
    }
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
