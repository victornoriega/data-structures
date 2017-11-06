#include "lista_ord_rep.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>

lista_ord_rep::lista_ord_rep()
{
    principio=NULL;
    anterior=NULL;
    cuantos=0;
    donde=VACIA;
    encontrado=NO;
    anteriorAux=NULL;
}

lista_ord_rep::~lista_ord_rep()
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

void lista_ord_rep::buscar(int a){
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
                anteriorAux=p;
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

int lista_ord_rep::agregar(int a){
    caja *p;
    buscar(a);
    p=(caja*)malloc(sizeof(caja));
    p->valor=a;
    p->repeticiones=1;
    if(encontrado==SI){
        anteriorAux->repeticiones++;
        return 0;
    }
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


void lista_ord_rep::pintar(){
    caja *p;
    p=principio;
    while(p){
        for(int i = 0 ; i < p->repeticiones; i++){
            std::cout << p->valor << std::endl;
            Sleep(800);
        }
         p=p->siguiente;
    }

}

int lista_ord_rep::borrar(int a){
    caja *p;
    buscar(a);
    if(encontrado==NO) return 0;
    if(donde==PRINCIPIO){
        p=principio;
        if(p->repeticiones==1) {
            principio=p->siguiente;
            free(p);
        }
        else p->repeticiones--;
    }else if(donde==ENMEDIO){
        p=anterior->siguiente;
        if(p->repeticiones==1) {
            anterior->siguiente=p->siguiente;
            free(p);
        }
        else p->repeticiones--;
    }else{
        p=anteriorAux;
        if(p->repeticiones==1) {
            p->siguiente=NULL;
            free(p);
        }
        else p->repeticiones--;
    }

    cuantos--;
    return 1;
}
