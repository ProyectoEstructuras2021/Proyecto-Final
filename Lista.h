#include <iostream>
#include "NodoL.h"

using namespace std;
class Lista {

private:

    NodoL* inicio;


public:
	
	
	
int memoria=0;

    void inicializar() {
        inicio = NULL; //Pone el inicio en nulo para poder trabajarlo
    }

    bool listaVacia() {
        if (inicio == NULL)
            return true;
        else
            return false;
    }

    void insertar(string n, int tatencion, int memo) {
        NodoL* nuevo{};
        NodoL* aux;
        nuevo = nuevo->crearNodo(n, tatencion, memo);
        if (listaVacia()) {    //Lista está vacía
            nuevo->siguiente = NULL;
            inicio = nuevo;
            nuevo = NULL;
        }
        else {                //Lista no vacía        
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
    
    

    bool buscar(string n, int tatencion, int memo) {            //Recibirá elemento de tipo entero y lo buscará en la lista

        bool bandera = false;
        NodoL* nuevo;
        nuevo = inicio;

        while ((nuevo != NULL) && (nuevo->obtienetarea() != n) && (nuevo->obtienetproceso() != tatencion) && (nuevo->obtienememori() != memo)) {
            if ((nuevo->obtienetarea() == n) && (nuevo->obtienetproceso() == tatencion) && (nuevo->obtienememori() == memo)) {///
                bandera = true;
            }
            nuevo = nuevo->obtieneSiguiente();
        }

        return bandera;
    }

    void desplegar(int x) {                //Mostrará toda la información de la lista
        NodoL* aux;
        if (listaVacia()){
		}
        else if(listaLlena()==false){
            
			aux = inicio;
            
            while(aux != NULL) {		//Revisar por qué no funciona el aux, ya que se repite
            
				//AQUI AGREGAR GOTXY EN LA POSICION QUE DEBE ESTAR

				cout<<"\n"<< endl;
            	cout<<x<<endl;
                cout<<"Tarea: " << aux->obtienetarea() << endl;
                cout<<"Porcentaje de procesamiento de memoria: "<<aux->obtienememori()<< endl;
                memoria=memoria+aux->obtienememori();
				cout<<"Tiempo: "<<aux->obtienetproceso()<<" minutos"<< endl;				
                x = x+1;
				aux = aux->obtieneSiguiente();        //Recorrerá Nodo por Nodo e irá imprimiendo la información que se pide
            
			}
        }
    }

	 bool listaLlena() {
        if (memoria>8000)
            return true;
        else
            return false;
    }
};


