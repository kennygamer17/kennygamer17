#include <iostream>
    using namespace std;

struct info_direccion
{
    char direccion[30];
    char ciudad[20];
    char provincia[20];
    char numero[10];
};


struct empleado
{
    int codigo;
    char nombre[20];
    struct info_direccion dir_empleado;
    double salario;
    char fecha_ingreso[11];
}empleado[10];

int main(){
    int cantidad,empleados_registrados = 0;
    bool continuar = true, encontrado = false;
    while(continuar){

        cout<<"[----MENU-----]"<<endl;
        cout<<"(1)-Agregar empleados "<<endl;
        cout<<"(2)-Ver empleados "<<endl;
        cout<<"(3)-Salir "<<endl;
        cin>>cantidad;

        switch(cantidad){
            case 1:
                cout<<"Cuantos empleados desea ingresar? ->";
                cin>>cantidad;

                //Guardando los datos correspondientes....
                for(int i = 0; i<cantidad;i++){
                empleados_registrados +=1;
                cout<<"-----------INGRESO_DE_DATOS-----------"<<endl;
                fflush(stdin);//Vaciar buffer y permitir digitar los valores
                empleado[i].codigo = i;
                cout<<"Digite su nombre ->"<<endl;
                cin.getline(empleado[i].nombre,20,'\n');
                fflush(stdin);
                cout<<"Digite su direccion ->"<<endl;
                cin.getline(empleado[i].dir_empleado.direccion,30,'\n');
                fflush(stdin);
                cout<<"Digite la ciudad -> "<<endl;
                cin.getline(empleado[i].dir_empleado.ciudad,20,'\n');
                fflush(stdin);
                cout<<"Digite la provincia -> "<<endl;
                cin.getline(empleado[i].dir_empleado.provincia,20,'\n');
                fflush(stdin);
                cout<<"Digite su numero telefonico -> +52 ";
                cin.getline(empleado[i].dir_empleado.numero,10,'\n');
                fflush(stdin);
                cout<<"Digite el salario -> ";
                cin>>empleado[i].salario;
                fflush(stdin);
                cout<<"Digite la fecha de ingreso del empleado -> dd/mm/yyyy"<<endl;
                cin.getline(empleado[i].fecha_ingreso,11,'\n');
                fflush(stdin);
                cout<<"-----------INGRESO_DE_DATOS-----------"<<endl;
                cout<<"\n";
                fflush(stdin);
                }
                break;
            case 2: 
                if(empleados_registrados>=1){
                    //Imprimiendo los datos correspondintes.....
                cout<<"Escriba el codigo del usuario a imprimir"<<endl;
                cout<<"Codigos disponibles: "<<endl;
                for(int i = 0; i<empleados_registrados;i++){
                    cout<<empleado[i].nombre<<" -> "<<empleado[i].codigo<<endl;
                }
                cin>>cantidad;
                for(int i = 0; i<empleados_registrados; i++){
                    if(empleado[i].codigo == cantidad){
                        encontrado = true;
                        cout<<"----------IMPRIMIENDO_EMPLEADO----------"<<endl;
                        cout<<"Codigo -> "<<empleado[i].codigo<<endl;
                        cout<<"Nombre -> "<<empleado[i].nombre<<endl;
                        cout<<"Salario -> "<<empleado[i].salario<<endl;
                        cout<<"Fecha de ingreso -> "<<empleado[i].fecha_ingreso<<endl;
                        cout<<"Direccion -> "<<empleado[i].dir_empleado.direccion<<endl;
                        cout<<"Ciudad -> "<<empleado[i].dir_empleado.ciudad<<endl;
                        cout<<"Provincia -> "<<empleado[i].dir_empleado.provincia<<endl;
                        cout<<"Numero -> "<<empleado[i].dir_empleado.numero<<endl;
                        cout<<"\n";
                        cout<<"----------IMPRIMIENDO_EMPLEADO----------"<<endl;
                        
                    }
                    }
                    if(!encontrado){
                        cout<<"Codigo -> "<<cantidad<<" no encontrado"<<endl;
                    }
                    encontrado = false;
                }
                else{
                    cout<<"No hay empleados"<<endl;
                }
                break;
            default: cout<<"saliendo...."<<endl;
            continuar = false;
            break;
            }   
    }
    return 0;
}