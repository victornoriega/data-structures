#include "cola.h"
#include <cstdlib>
#include <iostream>

cola::cola()
{
    principio=NULL;
    ultimo=NULL;
    cuantos=0;

    //ctor
}

cola::~cola()
{
    caja *p;
    while(principio){
        p=principio;
        principio=p->siguiente;
        free(p);
    }
}

void cola::agregar(int a){
    caja *p;
    p=(caja*)malloc(sizeof(caja));
    p->valor=a;
    if(!principio){
        p->siguiente=NULL;
        principio=p;
        ultimo=p;
    }else{
        p->siguiente=NULL;
        ultimo->siguiente=p;
        ultimo=p;
    }
    cuantos++;
}

int cola::sacar(){
    caja *p;
    int valor;

    if(!principio){
        return VACIO;
    }else{
        p=principio;
        principio=p->siguiente;
        valor=p->valor;
        free(p);
        cuantos--;
    }
    if(cuantos==0) ultimo=NULL;
    return valor;
}

void cola::pintar(){
    caja *p;
    p=principio;
    while(p){
        std::cout << p->valor << std::endl;
        p=p->siguiente;
    }
}
