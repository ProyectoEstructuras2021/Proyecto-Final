#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "Cola.h"

using namespace std;
Cola p;

string nombres[] = {

	"Dev C++","Google Chrome","Microsoft Teams","Explorador de Windows","Simbolo de sistema","Antimalware","AppHelperCap",

	"Adobe Pothoshop","Adobe Lightroom","Autodesk Desktop","Microsoft Word","Microsoft Excel","Opera","Mozila Firefox","Paint","Xampp Control","Netflix Desktop","MIcrosoft PowerPoint","VPN Sistem","Fotos"

};

int memori[3]={
	1024,2048,5120
};

void colaVacia(){
	p.colaVacia();
}

string nombre(){
	int x;
	string nom;
	srand(time(NULL));
	x=rand()%20;
	nom=nombres[x];
	return nom;
}

int atencion(){
	srand(time(NULL));
	int aten=rand()%(10-2+1)+2;
	return aten;
}

int espera(){
	srand(time(NULL));
	int esp=rand()%(4-2+1)+2;
	return esp;
}

int memoria(){
	int mu;
	srand(time(NULL));
	int mem=rand()%3;
	mu=memori[mem];
	return mu;
}

void insertarCola(string nom){
		p.push(nom);
}

string obtenernodocola(string tarea){
	tarea = p.pop();
	return tarea;
}


int mostrar(int pos){
		p.mostrar(pos);
}
