#include<iostream>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include <time.h>
#include <unistd.h>
#include "aux1.h"
#include "ArbolBB.h"
#include <sstream>

using namespace std;

//push mete pop saca

void gotoxy(int,int);
Nodo*arbol = NULL;
int tiempo(int);
int esperando, cont, proceso, cont2, tie, pos=10, pos2=70;
string name;
stringstream ss;
ArbolBB q;//aqui
//Nodo*arbol = NULL;//aqui

int main(){
		system("color 80");
		system("mode con: cols=140 lines=40");
		tiempo(10);		
		return 0;
}

int tiempo(int n){
for(int i=0; i<=20; i++){
		
	int longitud = strlen("TAREAS EN esperando");
	int ctext=31-(longitud/2);
	gotoxy(ctext,n+2);
	cout << "TAREAS EN esperando" <<endl;
	
	int longitud2 = strlen("TAREAS EN PROCESAMIENTO");
	int ctext2=100-(longitud2/2);
	gotoxy(ctext2,n+2);
	cout << "TAREAS EN PROCESAMIENTO" <<endl;
	
	int longitud3 = strlen("PROYECTO FINAL");
	int ctext3=70-(longitud3/2);
	gotoxy(ctext3,2);
	cout << "PROYECTO FINAL" <<endl;
	
	int longitud4 = strlen("MEMORIA DE PROCESAMIENTO");
	int ctext4=70-(longitud4/2);
	gotoxy(ctext4,5);
	cout << "MEMORIA DE PROCESAMIENTO" <<endl;
	
	int longitud5 = strlen("La siguiente tarea se creara en: ");
	int ctext5=70-(longitud5/2);
	gotoxy(5,8);
	cout << "La siguiente tarea se creara en: " <<endl;
	
	int longitud6 = strlen("TIEMPO TOTAL DE PROCESAMIENTO:  minutos");
	int ctext6=135-(longitud6+3);
	gotoxy(ctext6,8);
	cout << "Tiempo total de procesamiento: "<<i<<" minutos"<<endl;
	
	for(int i=5; i<135; i++){
			gotoxy(i,n);cout<<"_";	
	}
	for(int i=5; i<135; i++){
			gotoxy(i,n+3);cout<<"_";	
	}
	for(int i=11; i<14; i++){
			gotoxy(65,i);cout<<"|";	
	}
	for(int i=11; i<14; i++){
			gotoxy(4,i);cout<<"|";	
	}
	for(int i=11; i<14; i++){
			gotoxy(135,i);cout<<"|";	
	}	
	
		if(p.colaVacia()){
			nombre();
		}else{
			if(esperando==0){
				esperando=espera();
				nombre();
				cont ++;//saber cuantos estan en espera
			}else{
				esperando--;
			}
		}
		if(proceso==0){
			name=p.pop();
			ss >> name;  
  			ss << n; 
			q.insertar(n);//aqui
			proceso=atencion();
			tie=proceso;
			cont2++;//saber cuantos estuvieron en proceso
		}else{
			proceso --;
		}
		
		gotoxy(pos2,15);cout<<"Tarea:  "<<name;
		gotoxy(pos2,16);cout<<"Tiempo: "<<tie<<" minutos";
		gotoxy(pos2,17);cout<<"Faltan: "<<proceso<<" minutos para cerrar el proceso";
		
		gotoxy(pos2,19);
		
	
		sleep(1);
		system("cls");
		
}
	
	q.mostrarArbol(arbol,0);	
}

void gotoxy(int x, int y){
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon,dwPos);
}


