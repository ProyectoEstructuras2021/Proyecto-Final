//Myriam S�nchez Pereyra
//Creaci�n clase Nodo

#include <iostream>
#include <string>

using namespace std;

class NodoL {

private:

	int numero;

public:

	NodoL* siguiente;	// Guardar� la posici�n de memoria, el apuntador

	NodoL* crearNodo(int num) {		//Cada que creemos un nodo nos regresar� un elemento de tipo Nodo
		NodoL* nuevo = new NodoL(); 	//Al hacer esto se crea en la memoria din�mica la posici�n de memoria
		nuevo->numero = num;		//En Nodo nuevo y memoria din�mica se guarda num
		return nuevo;
	}

	int obtieneDato() {
		return numero;
	}

	void conectar(NodoL* next) {		//Recibe posici�n de memoria del elemento con el que se conectar�
		siguiente = next;			//Posici�n de memoria pasa a apuntador 
	}

	NodoL* obtieneSiguiente() {
		return siguiente;			//Sirve para preguntar si el apuntador del Nodo auxiliar es diferente de nulo
	}
};