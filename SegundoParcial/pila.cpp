#include "pila.h"
#include <iostream>
#include <cstdlib>


pila::pila()
{
    principio=NULL;
    cuantos=0;
}

pila::~pila()
{
    caja *p;
    while(principio){
        p=principio;
        principio=p->siguiente;
        free(p);
    }
}

void pila::agregar(int a){
    caja *p;
    p=(caja *) malloc(sizeof(caja));
    p->valor=a;
    if(!principio){
        p->siguiente=NULL;
        principio=p;
    }else{
        p->siguiente=principio;
        principio=p;
    }
    cuantos++;

}

void pila::pintar(){
    caja *p;
    while(p){
        std::cout << p->valor << std::endl;
        p=p->siguiente;
    }
}

int pila::sacar(void){
    caja *p;
    int valor;

    if(principio){
        p=principio;
        principio = p->siguiente;
        valor = p->valor;
        free(p);
        cuantos--;
        return valor;
    }else return VACIO;
}

