#include "lista_doble.h"
#include <cstdlib>
#include <iostream>
#include <windows.h>
lista_doble::lista_doble()
{
    principio=NULL;
    anterior=NULL;
    donde=VACIA;
    encontrado=NO;
}

lista_doble::~lista_doble()
{
    caja *p;
    while(principio){
        p=principio;
        principio=p->siguiente;
        free(p);
    }
    anterior=NULL;
    donde=VACIA;
    encontrado=NO;
}

void lista_doble::buscar(int a){
    caja *p;
    p=principio;

    if(!principio){
        encontrado=NO;
        donde=VACIA;
        return;
    }else{
        while(p){
            if(p->valor==a){
                encontrado=SI;
                if(principio==p){
                    donde=PRINCIPIO;
                }else if(p->siguiente==NULL){
                    donde=FINAL;
                }
                else{
                    donde=ENMEDIO;
                }

                return;
            }else if(p->valor>a){
                encontrado=NO;
                if(principio==p){
                    donde=PRINCIPIO;
                }else{
                    donde=ENMEDIO;
                }
                return;
            }else{
                anterior=p;
                p=p->siguiente;
            }
        }
        encontrado=NO;
        donde=FINAL;
    }
}


int lista_doble::agregar(int a){
    caja *p;
    buscar(a);
    if(encontrado==SI) return 0;
    p=(caja*)malloc(sizeof(caja));
    p->valor=a;

    if(donde==VACIA){
        p->siguiente=NULL;
        principio=p;
        p->anterior=NULL;
        ultimo=p;
    }else if(donde==PRINCIPIO){
        p->siguiente=principio;
        principio=p;
        p->anterior=NULL;
        (p->siguiente)->anterior=p;
    }else if(donde==ENMEDIO){
        p->siguiente=anterior->siguiente;
        anterior->siguiente=p;
        p->anterior=anterior;
        (p->siguiente)->anterior=p;
    }else{
        p->siguiente=NULL;
        anterior->siguiente=p;
        p->anterior=anterior;
        ultimo=p;
    }
    return 1;
}

int lista_doble::borrar(int a){
    caja *p;
    buscar(a);
    if(encontrado==NO) return 0;
    if(donde==PRINCIPIO){
        p=principio;
        principio=p->siguiente;
        if(principio==NULL) ultimo=NULL;
        else principio->anterior=NULL;
    }else if(donde==ENMEDIO){
        p=anterior->siguiente;
        anterior->siguiente=p->siguiente;
        (p->siguiente)->anterior=anterior;
    }else{
        anterior->siguiente=NULL;
        ultimo=anterior;
    }
    free(p);
    return 1;
}

void lista_doble::pintar1(){
    caja *p;
    p=principio;
    while(p){
        std::cout << p->valor << std::endl;
        p=p->siguiente;
    }
}

void lista_doble::pintar2(){
    caja *p;
    p=ultimo;
    while(p){
        std::cout << p->valor << std::endl;
        p=p->anterior;
    }
}
