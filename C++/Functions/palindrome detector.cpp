#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <cstring>
#include <string.h>

	using namespace std;
	
bool verificador_p(char palabra[]);
void verificador_l(char palabra[],char aux[]);
//Made by lexor_12 || kennygamer17 on github
int main(){
	char palabra[128],aux[1024];
	memset(palabra,'\0',128);
	memset(aux,'\0',1024);
	cout<<"Digite una palabra ->  ";
	cin.getline(aux,1023,'\n');
	verificador_l(palabra,aux);
	return 0;
}//Made by lexor_12 || kennygamer17 on github
bool verificador(char palabra[]){
	bool palindromo = true;
	for(int i = 0;i<strlen(palabra);i++){
		if(palabra[i]!=palabra[strlen(palabra)-1-i]){
			palindromo = false;
			break;
		}
	}//Made by lexor_12 || kennygamer17 on github
	return palindromo;
}
void verificador_l(char palabra[],char aux[]){
	int contador = 0;
	for(int i = 0;contador<128;i++){
		if(aux[i]!=' '){
			palabra[contador] = aux[i];
			contador++;
		}
	}//Made by lexor_12 || kennygamer17 on github
	cout<<palabra<<endl;
	if(verificador(palabra)){
		cout<<"La palabra "<<aux<<" es un palindromo"<<endl;
	}
	else{
			cout<<"La palabra "<<aux<<" NO es un palindromo"<<endl;
	}
	//Made by lexor_12 || kennygamer17 on github
}
