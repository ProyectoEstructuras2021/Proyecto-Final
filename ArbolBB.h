#include  <iostream>
#include "Nodo.h"
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

class ArbolBB{
	
	int ar;
	string str;//agregue sto
	stringstream ss;//y esto
	
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
			ar=nuevo->dato;
			ss >> ar;  //de aqui
  			ss << str;
			cout<<"ar "<<str;//a aqui
		
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
		
		void getArbol(Nodo* aux, int cont) {  //Árbol acostado
  			if (aux == NULL){
   			   return;
   			}
  			else {
   				getArbol(raiz->der, cont + 1);
   				cout << aux->getDato() << endl;
   				for (int i = 0; i < cont; i++) {

   				}
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
   cout << aux->getDato();
   switch (level) {
    case 0:
     Show(aux->getIzq(), x - 30, y + 3, level + 1);
     Show(aux->getDer(), x + 30, y + 3, level + 1);
     break;
    case 1:
     Show(aux->getIzq(), x - 12, y + 3, level + 1);
     Show(aux->getDer(), x + 12, y + 3, level + 1);
     break;
    case 2:
     Show(aux->getIzq(), x - 7, y + 3, level + 1);
     Show(aux->getDer(), x + 7, y + 3, level + 1);
     break;
    case 3:
     Show(aux->getIzq(), x - 4, y + 3, level + 1);
     Show(aux->getDer(), x + 4, y + 3, level + 1);
     break;
    case 4:
     Show(aux->getIzq(), x - 2, y + 3, level + 1);
     Show(aux->getDer(), x + 2, y + 3, level + 1);
     break;
    case 5:
     Show(aux->getIzq(), x - 2, y + 3, level + 1);
     Show(aux->getDer(), x + 2, y + 3, level + 1);
     break;
   }
  }
 }
	
};
