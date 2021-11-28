//Myriam Sánchez Pereyra
#include <iostream>
class Nodo {

private:
	int identificador;
public:
	Nodo* apuntadorIzq;
	Nodo* apuntadorDer;

	Nodo* crear(int n) {
		Nodo* nuevo = new Nodo();
		nuevo->identificador = n;
		nuevo->apuntadorIzq = NULL;
		nuevo->apuntadorDer = NULL;
		return nuevo;
	}

	int getIdentificador() {
		return this->identificador;
	}

	Nodo* getApuntadorIzq() {
		return apuntadorIzq;
	}

	Nodo* getApuntadorDer() {
		return apuntadorDer;
	}

	void setApuntadorIzq(Nodo* next) {
		apuntadorIzq = next;
	}

	Nodo* crearTarea(string tarea, int pProcesamiento) {

	}

	void setApuntadorDer(Nodo* next) {
		apuntadorDer = next;
	}
};

