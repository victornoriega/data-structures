#include "lista_arcos.h"
#include <cstdlib>
#include <iostream>

lista_arcos::lista_arcos()
{
    nuevo();
}

lista_arcos::~lista_arcos()
{
    caja1 *p;
    while(principio){
        p=principio;
        principio=p->siguiente;
        free(p);
    }
    anterior=NULL;
    donde=VACIO;
    encontrado=NO;
    lugar_agregado=NULL;
}

void lista_arcos::nuevo(){
    principio=NULL;
    anterior=NULL;
    lugar_agregado=NULL;
    donde =VACIO;
    encontrado=NO;
}

int lista_arcos::agregar(int a){
    caja1 *p;
    buscar(a);
    if(encontrado==SI) return 0;

    p=(caja1*)malloc(sizeof(caja1));
    p->num_nodo=a;
    p->direccion_nodo=NULL;
    lugar_agregado=p;
    p->longitud=0;

    if(donde==VACIO){
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
    return 1;

}

void lista_arcos::buscar(int a){
    caja1 *p;
    p=principio;

    if(!principio){
        encontrado=NO;
        donde=VACIO;
        return;
    }else{
        while(p){
            if(p->num_nodo==a){
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
            }else if(p->num_nodo>a){
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

int lista_arcos::borrar(int a){
    caja1 *p;
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
    return 1;

}

void lista_arcos::pintar(){
    caja1 *p;
    p=principio;
    while(p){
        std::cout << p->num_nodo<< std::endl;
        p=p->siguiente;
    }

}

caja1* lista_arcos::lugarAgregado(){
    return lugar_agregado;
}

caja1* lista_arcos::obtenerPrincipio(){
    return principio;
}
