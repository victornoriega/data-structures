#include "lista_mitad.h"
#include <cstdlib>
#include <iostream>

lista_mitad::lista_mitad()
{
    principio=NULL;
    anterior=NULL;
    mayores=0,menores=0;
    donde=VACIA;
    encontrado=NO;
    mitad=NULL;
}

lista_mitad::~lista_mitad()
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
    mitad=NULL;
}

int lista_mitad::agregar(int a){
    caja *p;
    buscar(a);
    if(encontrado==SI) return 0;
    p=(caja*)malloc(sizeof(caja));
    p->valor=a;
    if(donde==VACIA){
        p->siguiente=NULL;
        p->anterior=NULL;
        mitad=p;
        principio=p;
        mayores++;

    }else if(donde==PRINCIPIO){
        p->siguiente=principio;
        p->anterior=NULL;
        (p->siguiente)->anterior=p;
        principio=p;
        menores++;
    }else if(donde==ENMEDIO){
        p->siguiente=anterior->siguiente;
        anterior->siguiente=p;
        (p->siguiente)->anterior=p;
        p->anterior=anterior;
    }else{
        p->siguiente=NULL;
        anterior->siguiente=p;
        p->anterior=anterior;
        mayores++;
    }

    if(menores-mayores==3){
        mitad=mitad->anterior;
        mayores++;
        menores--;
    }else if(mayores-menores==3){
        mitad=mitad->siguiente;
        mayores--;
        menores++;
    }
    return 1;
}

void lista_mitad::pintar(){
    caja *p;
    p=principio;
    while(p){
        std::cout << p->valor << std::endl;
        p=p->siguiente;
    }

}

int lista_mitad::borrar(int a){
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
        ultimo=p;
    }
    free(p);
    return 1;
}

void lista_mitad::buscar(int a){
    caja *p;
    p=mitad;

    if(!mitad){
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
                    anterior=p->anterior;
                }
                return;
            }else if(p->valor>a){
                encontrado=NO;
                if(principio==p){
                    donde=PRINCIPIO;
                }else if(p->siguiente==NULL){
                    donde=ENMEDIO;
                    anterior=p->anterior;
                }else{
                    p=p->anterior;
                    continue;
                }
                return;
            }else{
                encontrado=NO;

                if(mitad==p){
                    if(mitad->siguiente==NULL) {
                        donde=FINAL;
                        anterior=mitad;
                    }else{
                        anterior=p;
                        p=p->siguiente;
                        continue;
                    }
                }else {
                    if(p->siguiente==NULL){
                        donde=FINAL;
                        anterior=p;
                    }else{
                        anterior=p;
                        p=p->siguiente;
                        continue;
                    }
                }
                break;
            }
            encontrado=NO;
        }
    }
}
