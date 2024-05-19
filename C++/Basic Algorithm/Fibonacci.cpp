#include <iostream>
#include <conio.h>
    using namespace std;

int main(){
    int num_llegar;
    int a = 0,b = 1,c;

    cout<<"Cuantas vueltas quieres hacer? -> ";
    cin>>num_llegar;
    
    for(int i=0; i<num_llegar; i++){
        cout<<a<<endl;
        c = a+b;
        a=b;
        b=c;
    }


    getch();
    return 0;
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
