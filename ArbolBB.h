#include  <iostream>
#include "Nodo.h"
#include <string>
#include <sstream>

using namespace std;

class ArbolBB{
	
	private:
		
		Nodo *raiz;
		
        string NodosHermanos;
		string NodosPadres;
		string NodosHijos;
		string NodosHojas;
		
		bool arbolVacio(){
			if(raiz == NULL)
				return true;
			else 
				return false;
		}
		
	public:
		
		void inicializarArbol(){
			raiz = NULL;
		}
		
		Nodo *getRaiz(){
			return raiz;
		}
		
		void insertar(int n){
			Nodo *nuevo, *aux;
			nuevo = nuevo->Crear(n);
		
			if(arbolVacio())	//árbol es vacío
				raiz = nuevo;
			else {
				siguienteNodo(raiz, nuevo);
			}
		}
		
		void siguienteNodo(Nodo *aux, Nodo *nuevo){
			if(aux == NULL)
				return;
			else {
				if(nuevo->getDato() < aux->getDato()){	//RECORRER IZQUIERDA
					if(aux->getIzq() != NULL)
						siguienteNodo(aux->getIzq(), nuevo);
					 else 
						aux->setIzq(nuevo);
				} 
				else if(nuevo->getDato() > aux->getDato()) {	//RECORRER DERECHA
						if(aux->getDer() != NULL)
							siguienteNodo(aux->getDer(), nuevo);
						else
							aux->setDer(nuevo);
					}
			}
		}
		
		void mostrarArbol(Nodo *aux, int cont){
			if(aux==NULL){	//Si el arbol está vacío
				return;
			}
			else{
				mostrarArbol(aux->der, cont+1);
				for(int i=0; i<cont; i++){
					cout<<"   ";
				}
				cout<<aux->getDato();
				mostrarArbol(aux->izq, cont+1);
			}
		}
};
