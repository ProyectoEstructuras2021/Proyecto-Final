#include <iostream>
#include <string>

using namespace std;

class NodoL {

private:

	string name;
	int at, mem;

public:

	NodoL* siguiente;	// Guardar� la posici�n de memoria, el apuntador

	NodoL* crearNodo(string n, int tatencion, int memo) {		//Cada que creemos un nodo nos regresar� un elemento de tipo Nodo
		NodoL* nuevo = new NodoL(); 	//Al hacer esto se crea en la memoria din�mica la posici�n de memoria
		nuevo->name = n;		//En Nodo nuevo y memoria din�mica se guarda num
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

	void conectar(NodoL* next) {		//Recibe posici�n de memoria del elemento con el que se conectar�
		siguiente = next;			//Posici�n de memoria pasa a apuntador 
	}

	NodoL* obtieneSiguiente() {
		return siguiente;			//Sirve para preguntar si el apuntador del Nodo auxiliar es diferente de nulo
	}
};
