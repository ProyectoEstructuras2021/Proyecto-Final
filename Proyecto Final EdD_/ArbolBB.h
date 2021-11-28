//Myriam Sánchez Pereyra
#include  <iostream>
#include "Nodo.h"
#include <string>
#include <sstream>
#include <stdio.h>  
#include <windows.h>  

using namespace std;

class ArbolBB {

private:

	Nodo* raiz;

	string NodosHermanos;
	string NodosPadres;
	string NodosHijos;
	string NodosHojas;

	bool arbolVacio() {
		if (raiz == NULL)
			return true;
		else
			return false;
	}

public:

	void inicializarArbol() {
		raiz = NULL;
	}

	Nodo* getRaiz() {
		return raiz;
	}

	void insertar(int n) {
		Nodo* nuevo{}, * aux;
		nuevo = nuevo->crear(n);

		if (arbolVacio())	//árbol es vacío
			raiz = nuevo;
		else {
			siguienteNodo(raiz, nuevo);
		}
	}

	void siguienteNodo(Nodo* aux, Nodo* nuevo) {
		if (aux == NULL)
			return;
		else {
			if (nuevo->getIdentificador() < aux->getIdentificador()) {	//RECORRER IZQUIERDA
				if (aux->getApuntadorIzq() != NULL)
					siguienteNodo(aux->getApuntadorIzq(), nuevo);
				else
					aux->setApuntadorIzq(nuevo);
			}
			else if (nuevo->getIdentificador() > aux->getIdentificador()) {	//RECORRER DERECHA
				if (aux->getApuntadorDer() != NULL)
					siguienteNodo(aux->getApuntadorDer(), nuevo);
				else
					aux->setApuntadorDer(nuevo);
			}
		}
	}

	int getLongitudProfundidad(Nodo* aux, int n, int longitud) {
		if (aux != NULL) {
			if (n != aux->getIdentificador()) {		//RECORRE ÁRBOL
				if (n < aux->getIdentificador() && aux->getApuntadorIzq() != NULL)
					getLongitudProfundidad(aux->getApuntadorIzq(), n, longitud + 1);
				else if (aux->getApuntadorDer() != NULL)
					getLongitudProfundidad(aux->getApuntadorDer(), n, longitud + 1);
			}
			else if (n == aux->getIdentificador())
				return longitud;
			else
				return -1;
		}
		else
			return -1;
	}

	int getProfundidad(Nodo* aux) {

	}


	void getAlturaBB(Nodo* aux, int n) {
		if (aux == NULL) {
			return;
		}
		else {
			if (aux->getIdentificador() == n) {
				cout << getAltura(aux) << endl;
			}
			getAlturaBB(aux->getApuntadorIzq(), n);
			getAlturaBB(aux->getApuntadorDer(), n);
		}
	}

	int getAltura(Nodo* aux) {
		if (aux != NULL) {
			int contIzq, contDer;
			contIzq = getLongitudProfundidad(aux->getApuntadorIzq(), 0, 0) + 1;
			contDer = getLongitudProfundidad(aux->getApuntadorDer(), 0, 0) + 1;
			if (contIzq > contDer) {
				return contIzq;
			}
			else {
				return contDer;
			}
		}
		else {
			return -1;
		}
	}

	void eliminarNodoBB(Nodo* aux, int n) {
		if (aux == NULL) {
			return;
		}
		else if (aux->getIdentificador() == n) {
			cout << "Nodo: " << aux->getIdentificador();
			eliminarNodo(aux);
			return;
		}
		else if (n < aux->getIdentificador()) {
			eliminarNodoBB(aux->getApuntadorIzq(), n);
		}
		else {
			eliminarNodoBB(aux->getApuntadorDer(), n);
		}
	}

	void eliminarNodo(Nodo* aux) {
		if (aux == NULL) {
			return;
		}
		else {
			eliminarNodo(aux->getApuntadorIzq());
			eliminarNodo(aux->getApuntadorDer());
			cout << "\n Se eliminaran los nodos: " << aux->getIdentificador();
			delete aux;
		}
	}

	void preOrden(Nodo* aux) {
		if (aux == NULL)
			return;
		else {
			//Paso 1: imprime el dato del nodo actual
			cout << aux->getIdentificador() << endl;
			//Paso 2: recorre el árbol izquierdo
			preOrden(aux->getApuntadorIzq());
			//Paso 3: recorre el árbol derecho
			preOrden(aux->getApuntadorDer());
		}
	}

	void orden(Nodo* aux) {
		if (aux == NULL)
			return;
		else {
			//Paso 1: recorre el árbol izquierdo
			orden(aux->getApuntadorIzq());
			//Paso 2: imprime el nodo
			cout << aux->getIdentificador() << endl;
			//Paso 3: recorre el árbol derecho
			orden(aux->getApuntadorDer());
		}
	}

	void postOrden(Nodo* aux) {
		if (aux == NULL)
			return;
		else {
			//Paso 1: recorre el árbol izquierdo
			orden(aux->getApuntadorIzq());
			//Paso 2: recorre el árbol derecho
			orden(aux->getApuntadorDer());
			//Paso 3: imprime nodo
			cout << aux->getIdentificador() << endl;
		}
	}

	string getNodosHermanos(Nodo* aux) {
		if (aux == NULL)
			return "";
		else {
			if (aux->getApuntadorIzq() != NULL && aux->getApuntadorDer() != NULL) {
				stringstream ssizq, ssder;
				ssizq << aux->getApuntadorIzq()->getIdentificador();
				ssder << aux->getApuntadorDer()->getIdentificador();
				if (NodosHermanos == "")
					NodosHermanos = "{" + ssizq.str() + " y " + ssder.str() + "}";
				else
					NodosHermanos = NodosHermanos + ", " + "{" + ssizq.str() + " y " + ssder.str() + "}";
			}
			getNodosHermanos(aux->getApuntadorIzq());
			getNodosHermanos(aux->getApuntadorDer());
		}
		return NodosHermanos;
	}

	string getNodosPadres(Nodo* aux) {
		if (aux == NULL)
			return "";
		else {
			if (aux->getApuntadorIzq() != NULL || aux->getApuntadorDer() != NULL) {
				stringstream ssnopa;
				ssnopa << aux->getIdentificador();
				if (NodosPadres == "")
					NodosPadres = ssnopa.str();
				else
					NodosPadres = NodosPadres + ", " + ssnopa.str();
			}
			getNodosPadres(aux->getApuntadorIzq());
			getNodosPadres(aux->getApuntadorDer());
		}
		return NodosPadres;
	}

	string getNodosHijos(Nodo* aux) {
		if (aux == NULL)
			return "";
		else {
			stringstream ssizq, ssder;
			if (aux->getApuntadorIzq() != NULL) {
				ssizq << aux->getApuntadorIzq()->getIdentificador();
				if (NodosHijos == "")
					NodosHijos = ssizq.str() + " " + ssder.str() + "}";
				else
					NodosHijos = NodosHijos + ", " + ssizq.str();
			}
			if (aux->getApuntadorDer() != NULL) {
				ssder << aux->getApuntadorDer()->getIdentificador();
				if (NodosHijos == "")
					NodosHijos = ssizq.str() + " " + ssder.str();
				else
					NodosHijos = NodosHijos + ", " + ssder.str();
			}
			getNodosHijos(aux->getApuntadorIzq());
			getNodosHijos(aux->getApuntadorDer());
		}
		return NodosHijos;
	}

	string getNodosHojas(Nodo* aux) {
		if (aux == NULL)
			return "";
		else {
			if (aux->getApuntadorIzq() == NULL && aux->getApuntadorIzq() == NULL) {
				stringstream sshojas;
				sshojas << aux->getIdentificador();
				if (NodosHojas == "")
					NodosHojas = sshojas.str();
				else
					NodosHojas = NodosHojas + ", " + sshojas.str();
			}
			getNodosHojas(aux->getApuntadorIzq());
			getNodosHojas(aux->getApuntadorDer());
		}
		return NodosHojas;
	}

	//T E R M I N A R  V I E N D O  E L  V I D E O

	void getArbol(Nodo* aux, int cont) {		//Árbol acostado
		if (aux == NULL)
			return;
		else {
			getArbol(raiz->apuntadorDer, cont + 1);
			cout << aux->getIdentificador() << endl;
			for (int i = 0; i < cont; i++) {

			}
		}
	}

	void mostrarArbol(Nodo* aux, int cont) {
		if (aux == NULL) {	//Si el arbol está vacío
			return;
		}
		else {
			mostrarArbol(aux->apuntadorDer, cont + 1);
			for (int i = 0; i < cont; i++) {
				cout << "   ";
			}
			cout << aux->getIdentificador();
			mostrarArbol(aux->apuntadorIzq, cont + 1);
		}
	}

	void gotoxy(int x, int y) {
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}

	void background() {
		int i = 2;
		for (int y = 0; y < 7; y++) {
			gotoxy(0, i);
			cout << " Nivel " << y;
			for (int x = 8; x < 135; x++) {
				gotoxy(x, i);
				cout << "- ";
			}
			i = i + 3;
		}
	}

	void Show(Nodo* aux, int x, int y, int level) {
		if (aux == NULL)
			return;
		else {
			gotoxy(x, y);
			cout << aux->getIdentificador();
			switch (level) {
			case 0:
				Show(aux->getApuntadorIzq(), x - 30, y + 3, level + 1);
				Show(aux->getApuntadorDer(), x + 30, y + 3, level + 1);
				break;
			case 1:
				Show(aux->getApuntadorIzq(), x - 12, y + 3, level + 1);
				Show(aux->getApuntadorDer(), x + 12, y + 3, level + 1);
				break;
			case 2:
				Show(aux->getApuntadorIzq(), x - 7, y + 3, level + 1);
				Show(aux->getApuntadorDer(), x + 7, y + 3, level + 1);
				break;
			case 3:
				Show(aux->getApuntadorIzq(), x - 4, y + 3, level + 1);
				Show(aux->getApuntadorDer(), x + 4, y + 3, level + 1);
				break;
			case 4:
				Show(aux->getApuntadorIzq(), x - 2, y + 3, level + 1);
				Show(aux->getApuntadorDer(), x + 2, y + 3, level + 1);
				break;
			case 5:
				Show(aux->getApuntadorIzq(), x - 2, y + 3, level + 1);
				Show(aux->getApuntadorDer(), x + 2, y + 3, level + 1);
				break;
			}
		}
	}

};

