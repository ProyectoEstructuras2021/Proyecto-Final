#include<iostream>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<unistd.h>
#include"aux1.h"
#include"ArbolBB.h"
#include"Lista.h"
#include<sstream>

using namespace std;

//push mete pop saca

void gotoxy(int,int);
Nodo*arbol = NULL;
int tiempo();
int esperando, cont, proceso, cont2, tie, pos=10, pos2=70, memoria2, posCol, poss, mpros;
string name,str,str1;
stringstream ss,sa;
ArbolBB a;
Lista l;
aux1 aux;

int main(){
		system("color 85");
		system("mode con: cols=140 lines=40");
		tiempo();		
		return 0;
}

int tiempo(){
for(int i=0; i<=180; i++){
		
	int longitud = strlen("TAREAS EN esperando");
	int ctext=31-(longitud/2);
	gotoxy(ctext,12);
	cout << "TAREAS EN ESPERANDO" <<endl;
	
	int longitud2 = strlen("TAREAS EN PROCESAMIENTO");
	int ctext2=100-(longitud2/2);
	gotoxy(ctext2,12);
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
			gotoxy(i,10);cout<<"_";	
	}
	for(int i=5; i<135; i++){
			gotoxy(i,13);cout<<"_";	
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
	for(int i=11; i<40; i++){
			gotoxy(135,i);cout<<"|";	
	}	
	for(int i=11; i<40; i++){
			gotoxy(4,i);cout<<"|";	
	}
	for(int i=11; i<40; i++){
			gotoxy(65,i);cout<<"|";	
	}


	if(tie==0){
		esperando=aux.espera();
		tie=esperando;
		name=aux.nombre();
		proceso=aux.atencion();
		mpros=aux.memoria();
	
	}else{
				tie--;
	}	
		if(l.listaVacia()){
			l.insertar(name,proceso,mpros); 	
			cont ++;
		}else if(!l.listaVacia()){
			if(l.buscar(tie)==true){
				aux.insertarCola(name);
			}
			if(l.listaLlena()){
				aux.insertarCola(name);	
				cont2 ++;
			}else{
				l.insertar(name,proceso,mpros);
				cont ++;
			}
		}
		name = "";
		proceso = NULL;
		mpros = NULL;

					
		
		for(int i=esperando; i>0; i--){
		
		gotoxy(pos2,15);cout<<"Tarea:  "<<name;
		gotoxy(pos2,16);cout<<"Tiempo: "<<tie<<" minutos";
		gotoxy(pos2,17);cout<<"Faltan: "<<esperando<<" minutos para cerrar el proceso";
		}

		cout<<" \n lista"<<endl;
		l.desplegar(1);
		
	
		sleep(1);
	//	system("pause");
		system("cls");
		

}
	cout << " - - - - - - > R E P O R T E  F I N A L < - - - - - -" << endl;
	cout << " > Tareas que se quedaron en Cola de Espera:" << endl;
	aux.mostrar(cont2);
	cout << " > Tareas que se quedaron en Lista de Procesamiento:" << endl;
	l.desplegar(1);
	cout << " > Veces que se llego al tope de procesamiento de la memoria RAM:" << endl;
	
	cout << " > Arbol de Tareas atendidas: " << endl;
	
	cout << " > Tareas del Arbol (inorden)" << endl;


}

void gotoxy(int x, int y){
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon,dwPos);
}



