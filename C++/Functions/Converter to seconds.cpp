#include <iostream>
#include <conio.h>
    using namespace std;

void tiempo(int total_seg, int&horas, int&minutos,int& segundos);

int main(){
    int total_seg,horas,minutos,segundos;
    cout<<"Digite un total en segundos -> "<<endl;
    cin>>total_seg;
    tiempo(total_seg,horas,minutos,segundos);
    return 0;
}
void tiempo(int total_seg, int&horas, int&minutos,int& segundos){
    horas = 0; minutos = 0; segundos = 0;
    minutos = total_seg/60;
    segundos = total_seg%60;
    if(minutos>0){
        horas = minutos/60;
        minutos = minutos%60;
    }
    cout<<"Total de horas -> "<<horas<<endl;
    cout<<"Total de minutos -> "<<minutos<<endl;
    cout<<"Total de segundos -> "<<segundos<<endl;
}