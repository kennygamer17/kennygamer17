#include <iostream>
#include <stdlib.h>
    using namespace std;

int main(){
    //Declaramos las maxima de opciones del switch/menu
    int maximo_opciones = 7, minimo_opciones = 1,lugar_guardado;
    //Declaramos la matriz principal con un maximo de 100 espacios... lamentablemente si no se usa los 100, el espacio de memoria sea gastado
    float matriz_principal[100][100];
    float copia_matriz_1[100][100],copia_matriz_2[100][100],copia_matriz_3[100][100],copia_matriz_4[100][100],copia_matriz_5[100][100];
    int filas_copias[5];
    int columnas_copias[5];
    string espacios_arreglo_disponibilidad[] = {"disponible","disponible","disponible","disponible","disponible"};
    //Estas "Filas y columnas" solo sirven para que las matrices guarden datos hasta ciertos valores
    int filas, columnas,eleccion,editar_fila,editar_columna,aux;
    //Variables boleanas para comprobaciones
    bool continuar = true,matriz_principal_creada = false,matrices_guardadas = false;
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
    while(continuar){
        cout<<"\n[----------Menu----------]"<<endl;
        cout<<"(1)-Crear Matriz/Agregar valores"<<endl;
        cout<<"(2)-Ver matriz"<<endl;
        cout<<"(3)-Borrar datos"<<endl;
        cout<<"(4)-Editar datos"<<endl;
        cout<<"(5)-Guardar matriz"<<endl;
        cout<<"(6)-Gestionar Matrices guardadas"<<endl;
        /*cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        *//*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
        cout<<"(7)-Salir"<<endl;
        //Si un valor ingresado sobrepasa las opciones, manda error
       do{
       cin>>eleccion;
       if(eleccion>maximo_opciones || eleccion<minimo_opciones){
        cout<<"Esa opcion no fue encontrada..."<<endl;
        system("pause");
       }
       }while(eleccion>maximo_opciones || eleccion<minimo_opciones);

       switch(eleccion){
        case 1: 
            cout<<"Ustedes eligio la opcion (1)"<<endl;
            //Si un valor ingresado sobrepasa la cantidad maxima de memoria de la matriz manda error
            if(!matriz_principal_creada){
                do{
            cout<<"Digite la cantidad de columnas -> ";
            cin>>columnas;
            cout<<"Digite la cantidad de filas -> ";
            cin>>filas;
            if((columnas >100 || columnas <1) || (filas>100 || filas<1)){
                cout<<"El limite de filas y columnas es de 100"<<endl;
                system("pause");
            }
            }while((columnas >100 || columnas <1) || (filas>100 || filas<1));
            matriz_principal_creada = true;
            }/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
            //Esta vez no usamos else if, ya que puede que la matriz apenas se cree y necesite agregar valor
            if(matriz_principal_creada){
                for(int i = 0; i<filas; i++){
                for(int j = 0; j<columnas; j++){
                    cout<<"Digite el valor numerico del espacio -> "<<"["<<i+1<<"]["<<j+1<<"] -> ";
                    cin>>matriz_principal[i][j];
                    matriz_principal_creada = true;
                    //Si se creo la matriz correctamente se agrega booleana que nos lo indica
                }
            }
            //Si se ejecuto pero no se creo nos manda error
            if(!matriz_principal_creada){
                cout<<"La matriz No fue creada... Error Inesperado"<<endl;
            }
            }
            system("pause");
        break;
        case 2:
            cout<<"Usted eligio la opcion (2)"<<endl;
            if(matriz_principal_creada){
                
            cout<<"imprimiendo matriz............"<<endl;
            //For anidado que imprime la matriz
            for(int i = 0; i<filas; i++){
                cout<<"\n| ";
                for(int j = 0; j<columnas; j++){
                    cout<<"\t"<<matriz_principal[i][j]<<" \t|";
                }
            }
            }
            else{
                if(!matriz_principal_creada){
                    cout<<"No hay ninguna matriz creada...."<<endl;
                }
            }
            system("pause");
        break;
        case 3: 
            cout<<"Usted eligio la opcion (3)"<<endl;
            if(matriz_principal_creada){
                do{/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
            //Si no selecciona repitira la misma indicacion
            cout<<"\nSeguro que quiere borrar la matriz? al borrarla tendr que volver a indicar las filas y columnas\npuede guardar la matriz, ¿Esta seguro? (1)-Si (2)-No"<<endl;
            cin>>eleccion;
            }while(eleccion>2 || eleccion<1);

            if(eleccion == 1){
                for(int i = 0; i<filas; i++){
                    for(int j = 0; j<columnas; j++){
                        matriz_principal[i][j] = 0;
                    //Si se creo la matriz correctamente se agrega booleana que nos lo indica
                    }
                    matriz_principal_creada = false;
                }
            }
            else{
                if(eleccion == 2){
                    cout<<"regresando...."<<endl;
                    system("pause");
                }
            }
            }/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
            else{
                if(!matriz_principal_creada){
                    cout<<"No hay ninguna matriz creada...."<<endl;
                }
            }
            system("pause");
        break;
        case 4: 
            cout<<"Eligio la opcion (4)"<<endl;
            if(matriz_principal_creada){
                cout<<"imprimiendo matriz............"<<endl;
            //For anidado que imprime la matriz
            for(int i = 0; i<filas; i++){
                cout<<"\n| ";
                for(int j = 0; j<columnas; j++){
                    cout<<"\t\t\t"<<"["<<i+1<<"]"<<"["<<j+1<<"] -> "<<matriz_principal[i][j]<<" \t\t\t|";
                }
            }
            do{
                //Pedimos que ingrese el numero de la matriz, si este es mayor al la cantidad de filas y columnas marca error
            cout<<"\nDigite la fila de la matriz a editar(primer valor) ->";
            cin>>editar_fila;
            cout<<"Digite la columna de la matriz a editar(segundo valor) ->";
            cin>>editar_columna;
            }while((editar_fila>filas || editar_fila<1) || (editar_columna>columnas || editar_columna<1));
            //Imprimimos el valor encontrado de la matriz
            cout<<"Valor encontrado -> |\t"<<matriz_principal[editar_fila-1][editar_columna-1]<<"\t|"<<endl;
            cout<<"\nDigite el valor a cambiar ->";
            cin>>matriz_principal[editar_fila-1][editar_columna-1];
            cout<<"El valor se ha cambiado....."<<endl;
            system("pause");
            }/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
            else{
                if(!matriz_principal_creada){
                    cout<<"No hay ninguna matriz creada...."<<endl;
                }
            }
            system("pause");
        break;
        case 5: 
            cout<<"Usted eligio la opcion (5)"<<endl;
            if(matriz_principal_creada){
                //Se imprime si los espacios de guardar estan disponibles o no
                for(int i = 0; i<5; i++){
                cout<<"Espacio -> "<<i+1<<" -> "<<espacios_arreglo_disponibilidad[i]<<endl;
            }
            do{
            cout<<"En que espacio desea guardar la matriz actual ->";
            cin>>lugar_guardado;
            //Si desea guardar la matriz en un espacio que no existe marca error y pide dato otra vez
            }while(lugar_guardado>5 || lugar_guardado<1);
            //si un espacio para guardar ya fue usado comprobamos que tenga el "no disponible" para no sobreescribir los datos
            if(espacios_arreglo_disponibilidad[lugar_guardado-1] == "No_disponible"){
                //Si tiene algo ya guardado y quiere sobreescribirlo
                cout<<"Ya hay una matriz guardada en ese espacio ...."<<endl;
                cout<<"Desea sobrescribir el espacio guardado? "<<endl;
                cout<<"(1)-Si"<<endl;
                cout<<"(2)-No,quiero volver"<<endl;
                cin>>aux;
            }/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
            else{
                if(espacios_arreglo_disponibilidad[lugar_guardado-1] == "disponible"){
                    aux =1;
                }
                //este es por si no tiene nada guardado
            }
            if(aux == 1){
                //Si se continuo el guardar se procede al codigo
                
                    switch(lugar_guardado){
                        case 1: 
                        cout<<"Guardando...."<<endl;
                        system("pause");
                            for(int i = 0; i<filas; i++){
                                for(int j = 0; j<columnas; j++){
                                    copia_matriz_1[i][j] = matriz_principal[i][j];
                                    
                    
                                }
                            }
                            filas_copias[lugar_guardado-1] = filas;
                            columnas_copias[lugar_guardado-1] = columnas;
                            espacios_arreglo_disponibilidad[lugar_guardado-1] = "No_disponible";
                        break;
                        case 2: /*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                        cout<<"Guardando...."<<endl;
                        system("pause");
                        for(int i = 0; i<filas; i++){
                                for(int j = 0; j<columnas; j++){
                                    copia_matriz_2[i][j] = matriz_principal[i][j];
                    
                                }
                            }
                            filas_copias[lugar_guardado-1] = filas;
                            columnas_copias[lugar_guardado-1] = columnas;
                            espacios_arreglo_disponibilidad[lugar_guardado-1] = "No_disponible";
                        break;
                        case 3: 
                        cout<<"Guardando...."<<endl;
                        system("pause");
                        for(int i = 0; i<filas; i++){
                                for(int j = 0; j<columnas; j++){
                                    copia_matriz_3[i][j] = matriz_principal[i][j];
                    
                                }
                            }
                            filas_copias[lugar_guardado-1] = filas;
                            columnas_copias[lugar_guardado-1] = columnas;
                            espacios_arreglo_disponibilidad[lugar_guardado-1] = "No_disponible";
                        break;
                        case 4: 
                        cout<<"Guardando...."<<endl;
                        system("pause");
                        for(int i = 0; i<filas; i++){
                                for(int j = 0; j<columnas; j++){
                                    copia_matriz_4[i][j] = matriz_principal[i][j];
                    
                                }
                            }/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                            filas_copias[lugar_guardado-1] = filas;
                            columnas_copias[lugar_guardado-1] = columnas;
                            espacios_arreglo_disponibilidad[lugar_guardado-1] = "No_disponible";
                        break;
                        case 5: 
                        cout<<"Guardando...."<<endl;
                        system("pause");
                        for(int i = 0; i<filas; i++){
                                for(int j = 0; j<columnas; j++){
                                    copia_matriz_5[i][j] = matriz_principal[i][j];
                    
                                }
                            }
                            filas_copias[lugar_guardado-1] = filas;
                            columnas_copias[lugar_guardado-1] = columnas;
                            espacios_arreglo_disponibilidad[lugar_guardado-1] = "No_disponible";
                        break;
                    }
            }
            else{
                cout<<"Regresando..."<<endl;
                system("pause");
            }          
                
                
            

            for(int i = 0; i<6; i++){
                if(espacios_arreglo_disponibilidad[i] == "No_disponible"){
                    matrices_guardadas = true;
                }
            }
            }
            else{/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                if(!matriz_principal_creada){
                    cout<<"No se ha creado ninguna matriz...."<<endl;
                }
            }
            system("pause");
        break;
        case 6: 
            cout<<"Usted eligio la opcion (6)"<<endl;
            if(matrices_guardadas){

                
                cout<<"----Que desea hacer----"<<endl;
                cout<<"(1)-Ver matriz"<<endl;
                cout<<"(2)-Usar matriz"<<endl;
                cin>>eleccion;

                switch(eleccion){
                    //Si elije la opcion 1, se ejecutara todo el codigo para imprimir
                    case 1: 
                //Creamos otro mini menu para imprimir las matrices guardadas
                cout<<"-----Menu de Guardados-----"<<endl;
                for(int i= 0; i<5; i++){
                    cout<<"Espacio -> "<<i+1;
                    if(espacios_arreglo_disponibilidad[i] == "No_disponible"){
                        cout<<" Activo"<<endl;
                    }/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                    else{
                        cout<<" No Activo"<<endl;
                    }
                }
                cout<<"Que espacio desea ver?"<<endl;
                cin>>eleccion;
                //Usamos siempre la variable eleccion, ya que su unico uso es usarla en menus, y siempre adquiere valor nuevo al usar una opcion del menu
                switch(eleccion){
                    //este switch sirve para los espacios guardados, el al seleccionar el lugar a guardar se guardara directamente
                    case 1: 
                        if(espacios_arreglo_disponibilidad[eleccion-1] == "disponible"){
                            cout<<"No hay una matriz guardada en este espacio..."<<endl;
                        }
                        else{
                            if(espacios_arreglo_disponibilidad[eleccion-1] == "No_disponible"){
                                cout<<"imprimiendo matriz............"<<endl;
                                //For anidado que imprime la matriz
                                for(int i = 0; i<filas_copias[eleccion-1]; i++){
                                cout<<"\n| ";
                                for(int j = 0; j<columnas_copias[eleccion-1]; j++){
                                    cout<<"\t"<<copia_matriz_1[i][j]<<" \t|";
                                    }
                                }
                            }
                        }
                        system("pause");
                        break;
                    case 2: 
                        if(espacios_arreglo_disponibilidad[eleccion-1] == "disponible"){
                            cout<<"No hay una matriz guardada en este espacio..."<<endl;
                        }/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                        else{
                            if(espacios_arreglo_disponibilidad[eleccion-1] == "No_disponible"){
                                cout<<"imprimiendo matriz............"<<endl;
                                //For anidado que imprime la matriz
                                for(int i = 0; i<filas_copias[eleccion-1]; i++){
                                cout<<"\n| ";
                                for(int j = 0; j<columnas_copias[eleccion-1]; j++){
                                    cout<<"\t"<<copia_matriz_2[i][j]<<" \t|";
                                    }
                                }
                            }
                        }
                        system("pause");
                        break;
                    case 3: 
                        if(espacios_arreglo_disponibilidad[eleccion-1] == "disponible"){
                            cout<<"No hay una matriz guardada en este espacio..."<<endl;
                        }
                        else{
                            if(espacios_arreglo_disponibilidad[eleccion-1] == "No_disponible"){
                                cout<<"imprimiendo matriz............"<<endl;
                                //For anidado que imprime la matriz
                                for(int i = 0; i<filas_copias[eleccion-1]; i++){
                                cout<<"\n| ";
                                for(int j = 0; j<columnas_copias[eleccion-1]; j++){
                                    cout<<"\t"<<copia_matriz_3[i][j]<<" \t|";
                                    }
                                }
                            }
                        }
                        system("pause");
                        break;
                    case 4: 
                        if(espacios_arreglo_disponibilidad[eleccion-1] == "disponible"){
                            cout<<"No hay una matriz guardada en este espacio..."<<endl;
                        }/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                        else{
                            if(espacios_arreglo_disponibilidad[eleccion-1] == "No_disponible"){
                                cout<<"imprimiendo matriz............"<<endl;
                                //For anidado que imprime la matriz
                                for(int i = 0; i<filas_copias[eleccion-1]; i++){
                                cout<<"\n| ";
                                for(int j = 0; j<columnas_copias[eleccion-1]; j++){
                                    cout<<"\t"<<copia_matriz_4[i][j]<<" \t|";
                                    }
                                }
                            }
                        }
                        system("pause");
                        break;
                    case 5: 
                        if(espacios_arreglo_disponibilidad[eleccion-1] == "disponible"){
                            cout<<"No hay una matriz guardada en este espacio..."<<endl;
                        }
                        else{
                            if(espacios_arreglo_disponibilidad[eleccion-1] == "No_disponible"){
                                cout<<"imprimiendo matriz............"<<endl;
                                //For anidado que imprime la matriz
                                for(int i = 0; i<filas_copias[eleccion-1]; i++){
                                cout<<"\n| ";
                                for(int j = 0; j<columnas_copias[eleccion-1]; j++){
                                    cout<<"\t"<<copia_matriz_5[i][j]<<" \t|";
                                    }
                                }
                            }
                        }
                        system("pause");
                        break;/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                    default: cout<<"Este espacio no existe..."<<endl; break;
                }
                    break;
                    case 2:/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                    //este es para la opcion 2, si queremos que la matriz principal adquiera el valor de una guardada aqui esta el codigo
                        cout<<"Que matriz desea copiar?"<<endl;
                        for(int i = 0; i<5; i++){
                            cout<<"Espacio "<<i+1<<" -> ";
                            if(espacios_arreglo_disponibilidad[i]== "disponible"){
                                cout<<" No activo"<<endl;
                            }
                            else{
                                if(espacios_arreglo_disponibilidad[i]== "No_disponible"){
                                    cout<<" Activo"<<endl;
                                }
                            }
                        }
                        cin>>eleccion;/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                        if(espacios_arreglo_disponibilidad[eleccion-1] == "No_disponible"){
                            switch(eleccion){
                                case 1: /*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                    aux = eleccion;
                                    if(matriz_principal_creada){
                                        cout<<"---PRECAUCION---"<<endl;
                                        cout<<"Si usted no guardo la matriz actual, esta se perdera...."<<endl;
                                        cout<<"Seguro que quiere copiar esta matriz, y usarla como principal?..."<<endl;
                                        cout<<"(1)-Si, estoy seguro"<<endl;
                                        cout<<"(2)-No, quiero regresar"<<endl;
                                        cin>>eleccion;
                                    }
                                    else{
                                        cout<<"copiando matriz....."<<endl;
                                        eleccion = 1;
                                        system("pause");
                                        matriz_principal_creada = true;/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                        //ponemos como activa, porque puede que se haya borrado la matriz principal anteriormente, ents para que
                                        //se ejecuten todas las funciones la ponemos como activa
                                        //dato podriamos hacer una funcion al principio del bucle que detecte si la matriz principal tiene valores >0, por lo que
                                        //si o si estaria en uso
                                        //pero luego lo hago xd
                                    }
                                        if(eleccion == 1){/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                            filas = filas_copias[aux-1];
                                            columnas = columnas_copias[aux-1];
                                            for(int i = 0; i<filas; i++){
                                                for(int j = 0; j<columnas; j++){
                                                    matriz_principal[i][j] = copia_matriz_1[i][j];
                                                }
                                            }
                                            cout<<"Ahora la matriz principal se ha actualizado....."<<endl;
                                            system("pause");
                                        }
                                        else{
                                            cout<<"Regresando...."<<endl;
                                            system("pause");
                                        }
                                    
                                    
                                    
                                break;
                                case 2: 
                                    aux = eleccion;
                                    if(matriz_principal_creada){
                                        cout<<"---PRECAUCION---"<<endl;
                                        cout<<"Si usted no guardo la matriz actual, esta se perdera...."<<endl;
                                        cout<<"Seguro que quiere copiar esta matriz, y usarla como principal?..."<<endl;
                                        cout<<"(1)-Si, estoy seguro"<<endl;
                                        cout<<"(2)-No, quiero regresar"<<endl;/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                        cin>>eleccion;
                                    }
                                    else{
                                        cout<<"copiando matriz....."<<endl;
                                        eleccion = 1;/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                        system("pause");
                                        matriz_principal_creada = true;
                                        //ponemos como activa, porque puede que se haya borrado la matriz principal anteriormente, ents para que
                                        //se ejecuten todas las funciones la ponemos como activa
                                        //dato podriamos hacer una funcion al principio del bucle que detecte si la matriz principal tiene valores >0, por lo que
                                        //si o si estaria en uso
                                        //pero luego lo hago xd
                                    }
                                        if(eleccion == 1){
                                            filas = filas_copias[aux-1];
                                            columnas = columnas_copias[aux-1];
                                            for(int i = 0; i<filas; i++){
                                                for(int j = 0; j<columnas; j++){
                                                    matriz_principal[i][j] = copia_matriz_2[i][j];
                                                }
                                            }
                                            cout<<"Ahora la matriz principal se ha actualizado....."<<endl;
                                            system("pause");/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                        }
                                        else{
                                            cout<<"Regresando...."<<endl;
                                            system("pause");/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                        }
                                break;
                                case 3:    
                                    aux = eleccion;
                                    if(matriz_principal_creada){
                                        cout<<"---PRECAUCION---"<<endl;
                                        cout<<"Si usted no guardo la matriz actual, esta se perdera...."<<endl;
                                        cout<<"Seguro que quiere copiar esta matriz, y usarla como principal?..."<<endl;
                                        cout<<"(1)-Si, estoy seguro"<<endl;
                                        cout<<"(2)-No, quiero regresar"<<endl;/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                        cin>>eleccion;
                                    }
                                    else{
                                        cout<<"copiando matriz....."<<endl;
                                        eleccion = 1;/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                        system("pause");
                                        matriz_principal_creada = true;
                                        //ponemos como activa, porque puede que se haya borrado la matriz principal anteriormente, ents para que
                                        //se ejecuten todas las funciones la ponemos como activa
                                        //dato podriamos hacer una funcion al principio del bucle que detecte si la matriz principal tiene valores >0, por lo que
                                        //si o si estaria en uso
                                        //pero luego lo hago xd
                                    }
                                        if(eleccion == 1){
                                            filas = filas_copias[aux-1];
                                            columnas = columnas_copias[aux-1];
                                            for(int i = 0; i<filas; i++){
                                                for(int j = 0; j<columnas; j++){
                                                    matriz_principal[i][j] = copia_matriz_3[i][j];
                                                }
                                            }
                                            cout<<"Ahora la matriz principal se ha actualizado....."<<endl;
                                            system("pause");
                                        }/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                        else{
                                            cout<<"Regresando...."<<endl;
                                            system("pause");
                                        }
                                break;
                                case 4: 
                                    aux = eleccion;
                                    if(matriz_principal_creada){
                                        cout<<"---PRECAUCION---"<<endl;
                                        cout<<"Si usted no guardo la matriz actual, esta se perdera...."<<endl;
                                        cout<<"Seguro que quiere copiar esta matriz, y usarla como principal?..."<<endl;
                                        cout<<"(1)-Si, estoy seguro"<<endl;
                                        cout<<"(2)-No, quiero regresar"<<endl;
                                        cin>>eleccion;
                                    }
                                    else{/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                        cout<<"copiando matriz....."<<endl;
                                        eleccion = 1;
                                        system("pause");
                                        matriz_principal_creada = true;
                                        //ponemos como activa, porque puede que se haya borrado la matriz principal anteriormente, ents para que
                                        //se ejecuten todas las funciones la ponemos como activa
                                        //dato podriamos hacer una funcion al principio del bucle que detecte si la matriz principal tiene valores >0, por lo que
                                        //si o si estaria en uso
                                        //pero luego lo hago xd
                                    }
                                        if(eleccion == 1){
                                            filas = filas_copias[aux-1];
                                            columnas = columnas_copias[aux-1];
                                            for(int i = 0; i<filas; i++){
                                                for(int j = 0; j<columnas; j++){
                                                    matriz_principal[i][j] = copia_matriz_4[i][j];
                                                }
                                            }
                                            cout<<"Ahora la matriz principal se ha actualizado....."<<endl;
                                            system("pause");
                                        }
                                        else{
                                            cout<<"Regresando...."<<endl;
                                            system("pause");
                                        }/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                break;
                                case 5: 
                                    aux = eleccion;
                                    if(matriz_principal_creada){
                                        cout<<"---PRECAUCION---"<<endl;
                                        cout<<"Si usted no guardo la matriz actual, esta se perdera...."<<endl;
                                        cout<<"Seguro que quiere copiar esta matriz, y usarla como principal?..."<<endl;
                                        cout<<"(1)-Si, estoy seguro"<<endl;
                                        cout<<"(2)-No, quiero regresar"<<endl;
                                        cin>>eleccion;
                                    }
                                    else{
                                        cout<<"copiando matriz....."<<endl;
                                        eleccion = 1;
                                        system("pause");
                                        matriz_principal_creada = true;
                                        //ponemos como activa, porque puede que se haya borrado la matriz principal anteriormente, ents para que
                                        //se ejecuten todas las funciones la ponemos como activa
                                        //dato podriamos hacer una funcion al principio del bucle que detecte si la matriz principal tiene valores >0, por lo que
                                        //si o si estaria en uso
                                        //pero luego lo hago xd
                                    }
                                        if(eleccion == 1){
                                            filas = filas_copias[aux-1];
                                            columnas = columnas_copias[aux-1];
                                            for(int i = 0; i<filas; i++){
                                                for(int j = 0; j<columnas; j++){
                                                    matriz_principal[i][j] = copia_matriz_5[i][j];
                                                }
                                            }
                                            cout<<"Ahora la matriz principal se ha actualizado....."<<endl;
                                            system("pause");
                                        }
                                        else{/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                                            cout<<"Regresando...."<<endl;
                                            system("pause");
                                        }
                                break;/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/

                                default: cout<<"Ese espacio no existe...."<<endl; break;

/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/

                            }
                        }
                        else{
                            if(espacios_arreglo_disponibilidad[eleccion-1] == "disponible"){
                                cout<<"No hay ninguna matriz guardada en ese espacio...."<<endl,
                                system("pause");
                            }
                        }
                        
                    break;
                }
                /*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
                
                

            }/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
            else{
                if(!matrices_guardadas){
                    cout<<"No tiene ninguna matriz guardada aun...."<<endl;
                    system("pause");
                }
            }
        break;/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
        case 7: 
            cout<<"|--------\tGracias por usar mi programa!!!!!!!! Made by:Lexor_12\t--------|"<<endl;
            continuar = false;
        break;

        default: 
        cout<<"Error inesperado.... Cerrando programa";
        continuar = false;
       }
    }
    return 0;
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
