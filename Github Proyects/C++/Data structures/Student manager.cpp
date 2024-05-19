#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
    using namespace std;
#define mini 3
#define regular 10
#define normal 30
#define mediano 60

struct calificacion{
    float parciales[mini];
    float promedio;
};
struct materias{
    char nombre[normal];
    struct calificacion calificaciones;
    bool aprobado = false;
};

struct alumno{
    char nombre[normal];
    char apellido[mediano];
    int edad;
    char sexo[regular];
    int registro;
    int cantidad_materias_asignadas = 0;
    struct materias materia[15];
    bool activo;
}alumnos[normal];

void agregar_alumno(int& contador);
void buscar_alumno(int& contador);
void editar_alumno(int& contador);
void eliminar_alumno(int& contador);
void imprimir_alumnos(int& contador);
void Agregarmateriaalumno(int& contador);
int buscador(int& contador);

int main(){
    int contador = 0;
    bool continuar = true;
    do{
        char eleccion = ' ';
        system("cls");
        cout<<"\tMENU"<<endl;
        cout<<"(1)-Agregar alumno"<<endl;
        cout<<"(2)-Agregar materia alumno"<<endl;
        cout<<"(3)-Gestion de alumnos"<<endl;
        cout<<"(4)-Salir"<<endl;
        cin>>eleccion;
        cin.ignore();
        switch(eleccion){
            case '1':
            agregar_alumno(contador);
            break;
            case '2':
            Agregarmateriaalumno(contador);
            break;
            case '3':
            cout<<"\tMENU"<<endl;
            cout<<"(1)-Ver info alumno"<<endl;
            cout<<"(2)-Editar alumno"<<endl;
            cout<<"(3)-Eliminar alumno"<<endl;
            cout<<"(4)-Imprimir alumnos"<<endl;
            cout<<"(5)-Salir"<<endl;
            cin>>eleccion;
            cin.ignore();
            switch(eleccion){
               case '1':
                buscar_alumno(contador);
                break;
                case '2':
                editar_alumno(contador);
                break; 
                case '3':
                eliminar_alumno(contador);
                break;
                case '4':
                imprimir_alumnos(contador);
                break;
                default:
                break;
            }
            break;
            case '4':
            cout<<"Saliendo del programa...."<<endl;
            Sleep(1550);
            continuar = false;
            break;
            default:
            cout<<"Opcion incorrecta....."<<endl;
            Sleep(1550);
            break;
        }
        system("pause");

    }while(continuar);
}
void agregar_alumno(int& contador){
    char aux = ' ';
    cout<<"\tAGREGAR ALUMNO"<<endl;
    cout<<"Nombre: \t";
    cin.getline(alumnos[contador].nombre,normal,'\n');
    cout<<"\nApellido: \t";
    cin.getline(alumnos[contador].apellido,mediano,'\n');
    cout<<"\nEdad: \t";
    cin>>alumnos[contador].edad;
    cin.ignore();
    do{
        cout<<"\nSexo: (1)-Masculino (2)-Femenino \t";
        cin>>aux;
        if(aux=='1'){
            strcpy(alumnos[contador].sexo,"Masculino");
        }
        else if(aux=='2'){
            strcpy(alumnos[contador].sexo,"Femenino");
        }
        else{
            cout<<"\nEleccion incorrecta"<<endl;
        }
    }while(aux != '1' && aux != '2' );
    cin.ignore();
    alumnos[contador].registro = contador;
    cout<<"\nRegistro: \t"<<alumnos[contador].registro<<endl;
    system("cls");
    cout<<"\n\nDATOS"<<endl;
    cout<<"Nombre: \t"<<alumnos[contador].nombre;
    cout<<"\nApellido: \t"<<alumnos[contador].apellido;
    cout<<"\nEdad: \t"<<alumnos[contador].edad;
    cout<<"\nSexo: \t"<<alumnos[contador].sexo;
    cout<<"\nRegistro: \t"<<alumnos[contador].registro<<endl;
    alumnos[contador].activo = true;
    contador++;
}
void buscar_alumno(int& contador){
    int numero_alumno = buscador(contador);
    if(numero_alumno >=0){
        cout<<"\tALUMNO ENCONTRADO"<<endl;
        cout<<"Nombre: \t"<<alumnos[numero_alumno].nombre<<endl;
        cout<<"Apellido: \t"<<alumnos[numero_alumno].apellido<<endl;
        cout<<"Sexo: \t"<<alumnos[numero_alumno].sexo<<endl;
        cout<<"Edad: \t"<<alumnos[numero_alumno].edad<<endl;
        cout<<"Registro: \t"<<alumnos[numero_alumno].registro<<endl;
        cout<<"Estado: \t";
        if(alumnos[numero_alumno].activo){
            cout<<"ACTIVO"<<endl;
        }
        else if(!alumnos[numero_alumno].activo){
            cout<<"INACTIVO"<<endl;
        }
        cout<<"\n\tCALIFICACIONES Y MATERIAS PERTENECIENTES:"<<endl;
        for(int i = 0;i<alumnos[numero_alumno].cantidad_materias_asignadas;i++){
            cout<<"\nNombre: \t"<<alumnos[numero_alumno].materia[i].nombre<<endl;
            cout<<"Calificaciones: \t";
            for(int j = 0;j<3;j++){
                cout<<"\n\tParcial "<<j+1<<": "<<alumnos[numero_alumno].materia[i].calificaciones.parciales[j]<<endl;
            }
            cout<<"\nEstado: \t";
            if(alumnos[numero_alumno].materia[i].aprobado){
                cout<<"APROBADO"<<endl;
            }
            else if(!alumnos[numero_alumno].materia[i].aprobado){
                cout<<"REPROBADO"<<endl;
            }
        }
    }
    else{
        cout<<"Alumno no encontrado....."<<endl;
    }
}
int buscador(int& contador){
    int numero_alumno =-1;
    bool encontrado = false,correcto;
    int apellidos[contador],contador2 = 0;
    char buscador[mediano];
    int buscador_registro;
    cout<<"\tBUSCAR ALUMNO"<<endl;
    cout<<"Digite el nombre, registro o apellido: "<<endl;
    cin.getline(buscador,mediano,'\n');
    for(int i = 0;i<contador;i++){
        if(strcasecmp(buscador,alumnos[i].nombre)==0){
            apellidos[contador2] = i;
            contador2++;
            encontrado = true;
        }
    }
    if(contador2>=1){
            cout<<"\nPERSONAS CON EL NOMBRE"<<endl;
            for(int i = 0;i<contador2;i++){
                cout<<i+1<<".- "<<alumnos[i].nombre<<" "<<alumnos[i].apellido<<endl;
            }
            do{
            cout<<"Digite el numero de la persona buscada: ";
            cin>>numero_alumno;
            numero_alumno -=1;
            for(int i = 0;i<contador2;i++){
                if(numero_alumno==apellidos[i]){
                correcto = true;
            }
            }
            }while(!correcto);
            encontrado = true;
        }
    if(!encontrado){
        for(int i = 0;i<contador;i++){
            if(strcasecmp(buscador,alumnos[i].apellido)==0){
                apellidos[contador2] = i;
                contador2++;
                encontrado = true;
            }
        }
        if(contador2>=1){
            cout<<"\nPERSONAS CON EL APELLIDO"<<endl;
            for(int i = 0;i<contador2;i++){
                cout<<i+1<<".- "<<alumnos[i].nombre<<" "<<alumnos[i].apellido<<endl;
            }
            do{
            cout<<"Digite el numero de la persona buscada: ";
            cin>>numero_alumno;
            numero_alumno -=1;
            for(int i = 0;i<contador2;i++){
                if(numero_alumno==apellidos[i]){
                correcto = true;
            }
            }
            }while(!correcto);
            encontrado = true;
        }
        
    }
        if(!encontrado){
            buscador_registro = atof(buscador);
            for(int i = 0;i<contador;i++){
                if(buscador_registro==alumnos[i].registro){
                    numero_alumno = i;
                }
            } 
        }
    return numero_alumno;
}
void editar_alumno(int& contador){
    int numero_alumno = buscador(contador);
    char eleccion = ' ';
    bool continuar;
    if(numero_alumno>=0){
        cout<<"\tALUMNO ENCONTRADO"<<endl;
        cout<<"Nombre: \t"<<alumnos[numero_alumno].nombre<<endl;
        cout<<"Apellido: \t"<<alumnos[numero_alumno].apellido<<endl;
        cout<<"Sexo: \t"<<alumnos[numero_alumno].sexo<<endl;
        cout<<"Edad: \t"<<alumnos[numero_alumno].edad<<endl;
        cout<<"Registro: \t"<<alumnos[numero_alumno].registro<<endl;
        cout<<"Estado: \t";
        if(alumnos[numero_alumno].activo){
            cout<<"ACTIVO"<<endl;
        }
        else if(!alumnos[numero_alumno].activo){
            cout<<"INACTIVO"<<endl;
        }
        do{
        cout<<"\n\tMENU MODIFICAR ALUMNO" <<endl;
        cout<<"(1)-Nombre" <<endl;
        cout<<"(2)-Apellido" <<endl;
        cout<<"(3)-Edad" <<endl;
        cout<<"(4)-Guardar y Salir" <<endl;
        cin>>eleccion;
        cin.ignore();
        switch(eleccion){
            case '1':
            cout<<"Nombre Actual:\t"<<alumnos[numero_alumno].nombre<<endl;
            cout<<"Nuevo Nombre:\t";
            cin.getline(alumnos[numero_alumno].nombre,normal,'\n');
            break;
            case '2':
            cout<<"Apellido Actual:\t"<<alumnos[numero_alumno].apellido<<endl;
            cout<<"Nuevo Apellido:\t";
            cin.getline(alumnos[numero_alumno].apellido,mediano,'\n');
            break;
            case '3':
            cout<<"Edad Actual:\t"<<alumnos[numero_alumno].edad<<endl;
            cout<<"Nueva Edad:\t";
            cin>>alumnos[numero_alumno].edad;
            cin.ignore();
            break;
            case '4':
                continuar = false;
                cout<<"Volviendo....."<<endl;
                Sleep(1550);
            break;
            default:
            cout<<"Opcion incorrecta....."<<endl;
            Sleep(1550);
            break;
        }
        }while(continuar);   
    }
    else{
       cout<<"Alumno no encontrado...."<<endl; 
    }
}
void eliminar_alumno(int& contador){
    //Al eliminar un alumno podria ser peligroso, por lo que es mejor marcarlo como inactivo....(por temas legales o por si ocurre algun problema)
    int numero_alumno = buscador(contador);
    char eleccion = ' ';
    if(numero_alumno >=0){
        cout<<"\tALUMNO ENCONTRADO"<<endl;
        cout<<"Nombre: \t"<<alumnos[numero_alumno].nombre<<endl;
        cout<<"Apellido: \t"<<alumnos[numero_alumno].apellido<<endl;
        cout<<"Sexo: \t"<<alumnos[numero_alumno].sexo<<endl;
        cout<<"Edad: \t"<<alumnos[numero_alumno].edad<<endl;
        cout<<"Registro: \t"<<alumnos[numero_alumno].registro<<endl;
        cout<<"Estado: \t";
        if(alumnos[numero_alumno].activo){
            cout<<"ACTIVO"<<endl;
        }
        else if(!alumnos[numero_alumno].activo){
            cout<<"INACTIVO"<<endl;
        }
        cout<<"\n\n¿Desea marcarlo como Inactivo? (1)-Sí\t(2)-No\t "<<endl;
        cin>>eleccion;
        if(eleccion=='1'){
            alumnos[numero_alumno].activo = false;
        }
        else if(eleccion=='2'){
            cout<<"Volviendo...."<<endl;
        }
        else{
            cout<<"Error....."<<endl;
        }
        
    }
    else{
        cout<<"Alumno no encontrado...."<<endl;
    }
}
void imprimir_alumnos(int& contador){
    for(int i = 0;i<contador;i++){
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"\tALUMNO"<<alumnos[i].registro<<endl;
        cout<<"Nombre: \t"<<alumnos[i].nombre<<endl;
        cout<<"Apellido: \t"<<alumnos[i].apellido<<endl;
        cout<<"Sexo: \t"<<alumnos[i].sexo<<endl;
        cout<<"Edad: \t"<<alumnos[i].edad<<endl;
        cout<<"Registro: \t"<<alumnos[i].registro<<endl;
        cout<<"Estado: \t";
        if(alumnos[i].activo){
            cout<<"ACTIVO"<<endl;
        }
        else if(!alumnos[i].activo){
            cout<<"INACTIVO"<<endl;
        }
    }
    cout<<"------------------------------------------------------------"<<endl;
}
void Agregarmateriaalumno(int& contador){
    int numero_alumno = buscador(contador);
    int sumador = 0;
    if(numero_alumno >=0){
        cout<<"\tALUMNO ENCONTRADO"<<endl;
        cout<<"Nombre: \t"<<alumnos[numero_alumno].nombre<<endl;
        cout<<"Apellido: \t"<<alumnos[numero_alumno].apellido<<endl;
        cout<<"Sexo: \t"<<alumnos[numero_alumno].sexo<<endl;
        cout<<"Edad: \t"<<alumnos[numero_alumno].edad<<endl;
        cout<<"Registro: \t"<<alumnos[numero_alumno].registro<<endl;
        cout<<"Estado: \t";
        if(alumnos[numero_alumno].activo){
            cout<<"ACTIVO"<<endl;
        }
        else if(!alumnos[numero_alumno].activo){
            cout<<"INACTIVO"<<endl;
        }
        if(alumnos[numero_alumno].activo){
        cout<<"\n\n"<<endl;
        cout<<"Nombre Materia: \t";
        cin.getline(alumnos[numero_alumno].materia[alumnos[numero_alumno].cantidad_materias_asignadas].nombre,normal,'\n');
        for(int i = 0;i<3;i++){
            cout<<"\nParcial "<<i+1<<" calificacion: \t";
            cin>>alumnos[numero_alumno].materia[alumnos[numero_alumno].cantidad_materias_asignadas].calificaciones.parciales[i];
            sumador += alumnos[numero_alumno].materia[alumnos[numero_alumno].cantidad_materias_asignadas].calificaciones.parciales[i];
        }
        alumnos[numero_alumno].materia[alumnos[numero_alumno].cantidad_materias_asignadas].calificaciones.promedio = sumador/3;
        cout<<"\nPromedio: \t"<<alumnos[numero_alumno].materia[alumnos[numero_alumno].cantidad_materias_asignadas].calificaciones.promedio;
        if(alumnos[numero_alumno].materia[alumnos[numero_alumno].cantidad_materias_asignadas].calificaciones.promedio>=70){
            cout<<"Estado: \tAPROBADO"<<endl;
            alumnos[numero_alumno].materia[alumnos[numero_alumno].cantidad_materias_asignadas].aprobado = true;
        }
        else if(alumnos[numero_alumno].materia[alumnos[numero_alumno].cantidad_materias_asignadas].calificaciones.promedio<=69){
            cout<<"\nEstado: \tREPROBADO"<<endl;
            alumnos[numero_alumno].materia[alumnos[numero_alumno].cantidad_materias_asignadas].aprobado = false;
        }
        alumnos[numero_alumno].cantidad_materias_asignadas++;
        }
        else{
            cout<<"Este alumno ya no esta activo en la institucion...."<<endl;
        }
    }
    else{
        cout<<"Alumno no encontrado...."<<endl;
    }
}