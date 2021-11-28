#include <iostream>
#include "Procesos.h"
#include "Lista.h"
#include "Cola.h"
#include <sstream>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <locale.h>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include "ArbolBB.h"

using namespace std;

/* Mostrar en pantalla durante el procesamiento de 3 horas, en cuanto tiempo se genera la siguiente tarea, la cola de espera
y la lista de procesamiento. También se deberá mostrar una alerta cuando el procesamiento de tareas alcance o supere el 90%
de la memoria RAM*/

Procesos pro;

string tarea;
int tareaAleatoria;

int pProcesamiento;
int tCreacion, tProcesamiento;

int cont_ListProcesamientos = 0;
int cont_vecesTopeRAM = 0;

int creacionTarea() {

	tarea = pro.tareasAleatorias();

	stringstream tareaL(tarea);
	int tareaN = 0;
	tareaL >> tareaN;

	tCreacion = pro.tiempoCreacionTarea();
	pProcesamiento = pro.porcentajeAleatorios();
	tProcesamiento = pro.tiempoProcesamiento();

	return tareaN;
}
int main() {

	Cola cola;
	ArbolBB arbol;
	Lista lista;
	
	cola.inicializar();
	lista.inicializar();
	arbol.inicializarArbol();

	for (int i = 0; i < 180; i++) {

		system("cls");

		//Genera la tarea aleatoria

		tareaAleatoria = creacionTarea();

		//Agregar a Lista de Procesamiento o Cola de Espera

		if (lista.listaVacia()) {	//Si la lista está vacía se agrega la tarea
			lista.insertar(tareaAleatoria);
			cont_ListProcesamientos += pProcesamiento;
			cout << "AQUI" << endl;
		}
		else if (!lista.listaVacia()) {				//Comprobar que la lista no pase de 8GB de procesamiento
			//lista.buscar(tCreacion);
			cont_ListProcesamientos > 8000;
			cola.push(tareaAleatoria);
			cout << "AQUI 2" << endl;
		}
		if (/*lista.buscar(tCreacion) == true || */cont_ListProcesamientos > 8000) {
			cola.push(tareaAleatoria);		// Se agrega la tarea a la cola de espera
			cout << "AQUI 3" << endl;
		}
		else {
			lista.insertar(tareaAleatoria);
			cont_ListProcesamientos += pProcesamiento;
			cout << "AQUI 4" << endl;
		}

		tProcesamiento--;

		//Tarea termina su tiempo de procesamiento
		if (tProcesamiento == 0) {
			cout << "AQUI 5" << endl;
			arbol.insertar(tareaAleatoria);
		}

		// AGREGAR PANTALLA QUE SE IMPRIMIRA

	//-------------------------------------------------------------------

		arbol.mostrarArbol(arbol.getRaiz(), 0);

	//-------------------------------------------------------------------

		//sleep(1);
	}
	/*

	DESPLEGAR EN PANTALLA:
	-> ¿Cuáles fueron las tareas que se quedaron en la cola de espera?
	-> ¿Cuáles fueron las tareas que se quedaron en la lista de procesamiento?
	-> ¿Cuántas veces se llego el tope de procesamiento de la memoria RAM de procesamiento?
	-> Desplegar árbol de tareas atendidas
	-> Mostrar las tareas del árbol en modo inorden

	*/

	cout << " - - - - - - > R E P O R T E  F I N A L < - - - - - -" << endl;
	cout << " > Tareas que se quedaron en Cola de Espera:" << endl;

	cout << " > Tareas que se quedaron en Lista de Procesamiento:" << endl;
	
	cout << " > Veces que se llego al tope de procesamiento de la memoria RAM:" << endl;
	
	cout << " > Arbol de Tareas atendidas: " << endl;
	
	cout << " > Tareas del Arbol (inorden)" << endl;
}

