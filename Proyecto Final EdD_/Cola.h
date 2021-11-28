//Myriam Sánchez Pereyra
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
class Cola
{

private:

    //Variables

    string cola[150];
    int fondo;
    int tope;
    int cima;
    int indice;



public:

    //Métodos

    void inicializar() {
        cima = 0;
        fondo = 0;
        indice = 0;
        tope = 150;
    }

    int push(int dato) {
        if (colaLlena() != true) {
            cola[cima] = dato;
            cima = cima + 1;
            return 0;
        }
        else
            return -1;
    }

    int pop() {
        if (colaVacia() != true) {
            string dato;
            dato = cola[fondo];
            cima--;
            reorganizar(indice);
        }
        else
            return -1;
    }

    void limpiarCola() {
        if (colaVacia()) // caso base
            return;
        // caso general
        else {
            cola[cima - 1] = "";
            cima--;
            limpiarCola();
        }
    }
    bool colaLlena() {
        if (cima > tope)
            return true;
        else
            return false;
    }

    bool colaVacia() {
        if (cima == fondo)
            return true;
        else
            return false;
    }

    void reorganizar(int indice) {
        //Caso base
        if (indice == cima) {
            //    cola[cima] = -1;
            //    indice = 0;
            return;
        }
        //Caso general
        else {
            cola[indice] = cola[indice + 1];
            reorganizar(indice + 1);
        }
    }

    int mostrarCima() {
        return cima;
    }

    string mostrarPersona(int num) {
        return cola[num];
    }

    //MUESTRA LAS TAREAS QUE SE QUEDARON EN LA COLA DE ESPERA

    string mostrarCola() {
        string salida = "";
        for (int i = 0; i < mostrarCima(); i++) {
            salida = salida + cola[i] + ", ";
        }
        return salida;
    }


};
