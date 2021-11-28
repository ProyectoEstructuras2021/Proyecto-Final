/*
	->Myriam Sánchez Pereyra
	Clase creada para almacenar los métodos necesarios
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

	Se requiere la codificación de una solución basada en C++ para el modelado de 3 horas de
	operación de una memoria RAM la cuál tendrá como máximo 8 GB de procesamiento de información
	para todas las tareas que se estén ejecutando.

*/

using namespace std;

class Procesos {

private:

	//Arreglo de tareas aleatorias

	string nombresTareas[20] = { "Spotify","Navegador Opera GX","Discord","Steam Client","GIMP 2","PainTool Sai","Access",
	"Visual Studio Code","Oracle VM Virtual Box","BlueStacks","Google Chrome","Microsoft Edge","Excel","Cortana","Xbox",
	"Microsoft Teams","Zoom Meetings","Word","Calculadora","Microsoft Store" };

	//Arreglo de porcentajes de procesamiento de Memoria

	int porcentajesProcesamiento[3] = { 1024,2048,5120 };


public:

	//Tarea generada de manera aleatoria en un lapso de 2,3 o 4 minutos de un arreglo (private) el cual debe tener 20 tareas diferentes

	string tareasAleatorias() {
		srand(time(NULL));
		int tarea = 1 + rand() % 20;
		return nombresTareas[tarea];
	}

	//Lapso de creación de tarea de 2,3 o 4 minutos

	int tiempoCreacionTarea() {
		srand(time(NULL));
		int tCreacionTarea = 2 + rand() % 4;
		return tCreacionTarea;
	}

	//Porcentaje de memoria aleatorio entre 1024, 2048, 5120

	int porcentajeAleatorios() {
		srand(time(NULL));
		int porcentaje = 1 + rand() % 3;
		return porcentajesProcesamiento[porcentaje];
	}

	//Tiempo de procesamiento aleatorio entre 2 y 10 minutos

	int tiempoProcesamiento() {
		srand(time(NULL));
		int tProcesamiento = 2 + rand() % 10;
		return tProcesamiento;
	}
	/*
	int creacionTarea() {
		string tarea;
		int tCreacion_;
		tarea = tareasAleatorias();
		tCreacion_ = tiempoCreacionTarea();
	}
	*/

};
