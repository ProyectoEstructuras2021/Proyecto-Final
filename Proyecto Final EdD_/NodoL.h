//Myriam Sánchez Pereyra
//Creación clase Nodo

#include <iostream>
#include <string>

using namespace std;

class NodoL {

private:

	int numero;

public:

	NodoL* siguiente;	// Guardará la posición de memoria, el apuntador

	NodoL* crearNodo(int num) {		//Cada que creemos un nodo nos regresará un elemento de tipo Nodo
		NodoL* nuevo = new NodoL(); 	//Al hacer esto se crea en la memoria dinámica la posición de memoria
		nuevo->numero = num;		//En Nodo nuevo y memoria dinámica se guarda num
		return nuevo;
	}

	int obtieneDato() {
		return numero;
	}

	void conectar(NodoL* next) {		//Recibe posición de memoria del elemento con el que se conectará
		siguiente = next;			//Posición de memoria pasa a apuntador 
	}

	NodoL* obtieneSiguiente() {
		return siguiente;			//Sirve para preguntar si el apuntador del Nodo auxiliar es diferente de nulo
	}
};