#include <iostream>
#include<sstream>
#include<string>
using namespace std;
class Cola{
    	
	private:
		
		//Variables
		
		string cola[150];
		int fondo;
		int tope;
		int cima;
		int indice;
		stringstream sb,sc;

		

		
	public:

		//Métodos
		
		void inicializar(){
			cima = 0;
			fondo = 0;
			indice = 0;
			tope = 100;
		}
		
		int push(string dato){
			if(colaLlena() != true){
				cola[cima] = dato;
				cima = cima+1;
				return 0;
			} else
				return -1;
		}
		
		string pop(){
			if(colaVacia() != true){
				string dato;
				dato = cola[fondo];
				cima--;
				reorganizar(indice);
				return dato;
			} else{
			}
		}
		
		void limpiarCola() {
			if(colaVacia()) // caso base
				return;
			else {
				cima--;
				limpiarCola();
			}
		}
		bool colaLlena(){
			if(cima > tope)
				return true;
			else
				return false;
		}
		
		bool colaVacia(){
			if (cima == fondo)
				return true;
			else
				return false;
		}
		
		void reorganizar (int indice){
			//Caso base
			if(indice == cima){
				cola[cima] = -1;
				indice = 0;
				return;
			}
			//Caso general
			else{
				cola[indice] = cola[indice+1];
				reorganizar(indice+1);
			}
		}
		void mostrar(int cont){
			if(cont == cima){
				return;
			}else{
				cout<<"	"<<cola[cont]<<", ";
				mostrar(cont+1);
			}
		}
		int mostrarcima(){
			return cima;
		}
		string mosper(int num){
			return cola[num];
		}
};
