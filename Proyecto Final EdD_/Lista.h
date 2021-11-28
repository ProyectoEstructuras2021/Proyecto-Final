//Myriam S�nchez Pereyra
//Creaci�n de la Lista
#include <iostream>
#include "NodoL.h"
using namespace std;
class Lista {

private:

    NodoL* inicio;


public:

    void inicializar() {
        inicio = NULL; //Pone el inicio en nulo para poder trabajarlo
    }

    bool listaVacia() {
        if (inicio == NULL)
            return true;
        else
            return false;
    }

    void insertar(int num) {
        NodoL* nuevo{};
        NodoL* aux;
        nuevo = nuevo->crearNodo(num);
        if (listaVacia()) {    //Lista est� vac�a
            nuevo->siguiente = NULL;
            inicio = nuevo;
            nuevo = NULL;
        }
        else {                //Lista no vac�a        
            aux = inicio;    //Auxiliar toma valor de Nodo inicio
            while (aux->obtieneSiguiente() != NULL) {
                aux = aux->obtieneSiguiente();
            }
            nuevo->siguiente = NULL;
            aux->conectar(nuevo);     //Se manda el puntero, nodo que se acaba de crear
            aux = NULL;
            nuevo = NULL;
        }
    }

    bool buscar(int num) {            //Recibir� elemento de tipo entero y lo buscar� en la lista

        bool bandera = false;
        NodoL* nuevo;
        nuevo = inicio;

        while ((nuevo != NULL) && (nuevo->obtieneDato() <= num)) {
            if (nuevo->obtieneDato() == num) {
                bandera = true;
            }
            nuevo = nuevo->obtieneSiguiente();
        }

        if (bandera == true) {
            cout << endl;
            cout << "El elemento " << num << " ha sido encontrado" << endl;
            cout << "Posicion de memoria: " << nuevo << endl;
            if (nuevo->obtieneSiguiente() != NULL) {
                cout << "Apunta a: " << nuevo->obtieneSiguiente() << endl;
            }
            else {
                cout << "Final de la lista" << endl;
                nuevo = nuevo->obtieneSiguiente();
            }
        }
        else {
            cout << "El elemento " << num << " no ha sido encontrado" << endl;
        }

        return bandera;
    }

    void desplegar() {                //Mostrar� toda la informaci�n de la lista
        NodoL* aux;
        if (listaVacia())
            cout << "La lista esta vacia" << endl;
        else {
            aux = inicio;
            while (aux != NULL) {
                cout << "Posicion de memoria: " << aux << endl;
                cout << "Dato guardado: " << aux->obtieneDato() << endl;
                if (aux->obtieneSiguiente() != NULL)
                    cout << "El auxiliar apunta a: " << aux->obtieneSiguiente() << endl << endl;
                else
                    cout << "Fin de la lista" << endl << endl;
                aux = aux->obtieneSiguiente();        //Recorrer� Nodo por Nodo e ir� imprimiendo la informaci�n que se pide
            }
        }
    }


};
