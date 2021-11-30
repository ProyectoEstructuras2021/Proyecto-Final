#include <iostream>
class Nodo{
    private:
        
    public:
        Nodo *izq;
        Nodo *der;
    
        int dato;

        Nodo *Crear(int n){
            Nodo *nuevo = new Nodo();
            nuevo->dato=n;
            nuevo->izq=NULL;
            nuevo->der=NULL;
    

            return nuevo;
        }

        int getDato(){
            return dato;
        }

        Nodo *getIzq(){
            return izq;
        }

        Nodo *getDer(){
            return der;
        }

        void setIzq(Nodo *next){
            izq=next;
        }

        void setDer(Nodo *next){
            der=next;
        }
        	
};
