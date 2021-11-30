#include <iostream>
#include <string>

using namespace std;

class NodoL {

private:

	string name;
	int at, mem;

public:

	NodoL* siguiente;	// Guardará la posición de memoria, el apuntador

	NodoL* crearNodo(string n, int tatencion, int memo) {		//Cada que creemos un nodo nos regresará un elemento de tipo Nodo
		NodoL* nuevo = new NodoL(); 	//Al hacer esto se crea en la memoria dinámica la posición de memoria
		nuevo->name = n;		//En Nodo nuevo y memoria dinámica se guarda num
		nuevo->at=tatencion;
		nuevo->mem=memo;
		return nuevo;
	}

	string obtienetarea() {
		return name;
	}
	
	int obtienetproceso() {
		return at;
	}
	
	int obtienememori() {
		return mem;
	}

	void conectar(NodoL* next) {		//Recibe posición de memoria del elemento con el que se conectará
		siguiente = next;			//Posición de memoria pasa a apuntador 
	}

	NodoL* obtieneSiguiente() {
		return siguiente;			//Sirve para preguntar si el apuntador del Nodo auxiliar es diferente de nulo
	}
};
