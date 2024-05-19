#include <iostream>
#include <stdlib.h>
    using namespace std;

int main(){
    //Definimos las variables que ocupamos de manera local
    int espacios = 0;
    int intermediario = 0;
    //Pedimos que nos indique cuantos valores desea agregar en el arreglo para no gastar demasiada memoria
    cout<<"Cuantos valores desea agregar? ->";
    cin>>espacios;
    //Declaramos la variable arreglo como arreglo de tipo int, con el tamano maximo dado al inicio
    int arreglo[espacios];

    //Pedimos que nos ingrese los valores de cada espacio de memoria
    for(int i = 0; i<espacios;i++){
        cout<<"Digite el valor del espacio "<<i+1<<" -> ";
        cin>>arreglo[i];
    }
    //usamos la libreria stdlib.h para hacer uso de la funcion pause para esperar tiempo
    system("pause");
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
    //Ordenamos por metodo BURBUJA los valores de el arreglo
    for(int j = 0; j<espacios; j++){
        for(int i = 0; i<espacios; i++){
        if(arreglo[i] > arreglo[i+1]){
            intermediario = arreglo[i];
            arreglo[i] = arreglo[i+1];
            arreglo[i+1] = intermediario;
        }
    }
    }
    //Los imprimimos de manera ascendente
    cout<<"Se acomodaron de orden ascendente: "<<endl;
    for(int i = 0; i<espacios; i++){
        cout<<"Espacio "<<i+1<<" -> "<<arreglo[i]<<endl;
    }
    system("pause");
    //los imprimimos de manera descendente
    cout<<"Se acomodaron de orden ascendente: "<<endl;
    for(int i = espacios; i>0; i--){
        cout<<"Espacio "<<i<<" -> "<<arreglo[i-1]<<endl;
        //Colocamos -1, ya que i vale la cantidad de espacios que hay, y este for se va restando, por lo que al llegar al ultimo valor el 0, este no se puede imprimir porque termina el bucle
        //por lo que pusimos un -1, y en la i no se agrego +1 ya que empieza desde el 5.

    }
    //Si todo el codigo se ejecuto regresamos valor 0
    return 0;
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
