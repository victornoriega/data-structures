#include "lista_mitad_rep.h"
#include <iostream>
#include <cstdlib>
lista_mitad_rep::lista_mitad_rep()
{
    principio=NULL;
    anterior=NULL;
    mayores=0,menores=0;
    donde=VACIA;
    encontrado=NO;
    mitad=NULL;
    anteriorAux=NULL;
}

lista_mitad_rep::~lista_mitad_rep()
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
    anteriorAux=NULL;
}

int lista_mitad_rep::agregar(int a){
    caja *p;
    buscar(a);
    p=(caja*)malloc(sizeof(caja));
    p->valor=a;
    p->repeticiones=1;
    if(encontrado==SI){
        p->anterior->repeticiones++;
        return 0;
    }

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

void lista_mitad_rep::pintar(){
    caja *p;
    p=principio;
    while(p){
        for(int i = 0 ; i < p->repeticiones; i++) std::cout << p->valor << std::endl;
        p=p->siguiente;
    }
}

int lista_mitad_rep::borrar(int a){
    caja *p;
    buscar(a);
    if(encontrado==NO) return 0;
    if(donde==PRINCIPIO){
        p=principio;
        if(p->repeticiones==1){
            principio=p->siguiente;
            free(p);
        }else p->repeticiones--;
    }else if(donde==ENMEDIO){
        p=anterior->siguiente;
        if(p->repeticiones==1){
            anterior->siguiente=p->siguiente;
            free(p);
        }else p->repeticiones--;
    }else{
        p=anterior->siguiente;
        if(p->repeticiones==1) {
            anterior->siguiente=NULL;
            ultimo=p;
            free(p);
        }else p->repeticiones--;
    }

    return 1;
}

void lista_mitad_rep::buscar(int a){
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
