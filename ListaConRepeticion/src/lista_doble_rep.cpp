#include "lista_doble_rep.h"
#include <cstdlib>
#include <iostream>
#include <windows.h>

lista_doble_rep::lista_doble_rep()
{
    principio=NULL;
    anterior=NULL;
    donde=VACIA;
    encontrado=NO;
    anteriorAux=NULL;
}

lista_doble_rep::~lista_doble_rep()
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
    anteriorAux=NULL;
}

void lista_doble_rep::buscar(int a){
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

int lista_doble_rep::agregar(int a){
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

int lista_doble_rep::borrar(int a){
    caja *p;
    buscar(a);
    if(encontrado==NO) return 0;
    if(donde==PRINCIPIO){
        p=principio;
        if(p->repeticiones==1){
            principio=p->siguiente;
            if(principio==NULL) ultimo=NULL;
            else principio->anterior=NULL;
            free(p);
        }else p->repeticiones--;
    }else if(donde==ENMEDIO){
        p=anterior->siguiente;
        if(p->repeticiones==1){
            anterior->siguiente=p->siguiente;
            (p->siguiente)->anterior=anterior;
            free(p);
        }else p->repeticiones--;
    }else{
        p=anteriorAux;
        if(p->repeticiones==1){
            anterior->siguiente=NULL;
            ultimo=anterior;
            free(p);
        }else p->repeticiones--;

    }
    return 1;
}


void lista_doble_rep::pintar1(){
    caja *p;
    p=principio;
    while(p){
        for(int i = 0 ; i < p->repeticiones;i++) std::cout << p->valor << std::endl;
        p=p->siguiente;
    }
}

void lista_doble_rep::pintar2(){
    caja *p;
    p=ultimo;
    while(p){
        for(int i = 0 ; i < p->repeticiones;i++) std::cout << p->valor << std::endl;
        p=p->anterior;
    }
}
