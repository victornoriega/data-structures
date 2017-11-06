#include "lista_nodos.h"
#include <lista_arcos.h>
#include <utilerias.h>
#include <cstdlib>

lista_nodos::lista_nodos()
{
    nuevo();
}

lista_nodos::~lista_nodos()
{
    borrar();
}

void lista_nodos::nuevo(){
    principio=NULL;
    anterior=NULL;
    lugar_encontrado=NULL;
}

void lista_nodos::borrar(){
    caja2 *p;
    while(principio){
        p=principio;
        principio=p->siguiente;
        free(p);
    }
    anterior=NULL;
    donde=VACIO;
    encontrado=NO;
}


int lista_nodos::agregar(int a){
    caja2 *p;
    buscar(a);
    if(encontrado==SI) return 0;

    p=(caja2*)malloc(sizeof(caja2));
    p->num_nodo=a;
    p->bandera=0;
    p->ruta_corta=0.0;
    p->anterior=NULL;
    p->direccion=NULL;
    (p->salientes).nuevo();
    (p->entrantes).nuevo();

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

void lista_nodos::buscar(int a){
    caja2 *p;
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

caja2* lista_nodos::lugarEncontrado(){
    return lugar_encontrado;
}
