#include <iostream>
#include <conio.h>
    using namespace std;

int main(){
    int factorial;

    cout<<"Digite el factorial a obtener -> ";
    cin>>factorial;

    for(int i=factorial-1; i>=1; i--){
        factorial *=i;
    }
    cout<<"\n"<<factorial<<endl;
    return 0;
}