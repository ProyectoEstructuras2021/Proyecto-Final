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
		//Métodos
		

		
	public:

		//Métodos
		
		void inicializar(){
			cima = 0;
			fondo = 0;
			indice = 0;
		//	int longitud = sizeof(cola)/sizeof(*cola);
			tope = 100;
		//	cout<<cima<<endl;
		//	cout<<tope;
		}
		
		int push(string dato){
		//	cout<<cima<<endl;
		//	cout<<tope;
			if(colaLlena() != true){
				cola[cima] = dato;
				cima = cima+1;
				//cout<<"push"<<cima<<endl;
				return 0;
			} else
				return -1;
		}
		
		string pop(){
			if(colaVacia() != true){
				string dato;
					
				dato = cola[fondo];
				//cout<<dato;
				//cout<<"Cliente en atencion: "<<dato<<endl;
				cima--;
				reorganizar(indice);
				return dato;
			} else{
			}
			//	return -1;
		}
		
		void limpiarCola() {
			if(colaVacia()) // caso base
				return;
			// caso general
			else {
				//cola[cima-1] = 0;
				cima--;
				limpiarCola();
			}
		}
		bool colaLlena(){
		//	cout<<cima<<endl;
		//	cout<<tope;
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
