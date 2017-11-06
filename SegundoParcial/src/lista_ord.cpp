#include "lista_ord.h"
#include <cstdlib>
#include <iostream>

lista_ord::lista_ord()
{
    principio=NULL;
    anterior=NULL;
    cuantos=0;
    donde=VACIA;
    encontrado=NO;
}

lista_ord::~lista_ord()
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
    cuantos=0;
}

void lista_ord::buscar(int a){
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

int lista_ord::agregar(int a){
    caja *p;
    buscar(a);
    if(encontrado==SI) return 0;
    p=(caja*)malloc(sizeof(caja));
    p->valor=a;
    if(donde==VACIA){
        p->siguiente=NULL;
        principio=p;
    }else if(donde==PRINCIPIO){
        p->siguiente=principio;
        principio=p;
    }else if(donde==ENMEDIO){
        p->siguiente=anterior->siguiente;
        anterior->siguiente=p;
    }else{
        p->siguiente=NULL;
        anterior->siguiente=p;
    }
    cuantos++;
    return 1;
}


void lista_ord::pintar(){
    caja *p;
    p=principio;
    while(p){
        std::cout << p->valor << std::endl;
        p=p->siguiente;
    }

}

int lista_ord::borrar(int a){
    caja *p;
    buscar(a);
    if(encontrado==NO) return 0;
    if(donde==PRINCIPIO){
        p=principio;
        principio=p->siguiente;
    }else if(donde==ENMEDIO){
        p=anterior->siguiente;
        anterior->siguiente=p->siguiente;
    }else{
        p=anterior->siguiente;
        anterior->siguiente=NULL;
    }
    free(p);
    cuantos--;
    return 1;
}
