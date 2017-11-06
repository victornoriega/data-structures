#include "listaRutaCorta.h"
#include <cstdlib>
#include "utilerias.h"

listaRutaCorta::listaRutaCorta()
{
    principio=NULL;
    anterior=NULL;
    donde=VACIO;
    encontrado=NO;
    anteriorAux=NULL;
}

listaRutaCorta::~listaRutaCorta()
{
    caja3 *p;
    while(principio){
        p=principio;
        principio=p->siguiente;
        free(p);
    }
    anterior=NULL;
    donde=VACIO;
    encontrado=NO;
    anteriorAux=NULL;
}

void listaRutaCorta::buscar(int a){
    caja3 *p;
    p=principio;

    if(!principio){
        encontrado=NO;
        donde=VACIO;
        return;
    }else{
        while(p){
            if(p->longitud==a){
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
            }else if(p->longitud>a){
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

int listaRutaCorta::borrar(int a){
    caja3 *p;
    p=principio;

    if(!principio){
        encontrado=NO;
        donde=VACIO;
        return 0;
    }else{
        while(p){
            if(p->longitud==a){
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
                return 1;
            }else if(p->longitud>a){
                encontrado=NO;
                if(principio==p){
                    donde=PRINCIPIO;
                }else{
                    donde=ENMEDIO;
                }
                return 1;
            }else{
                anterior=p;
                p=p->siguiente;
            }
        }
        encontrado=NO;
        donde=FINAL;
    }
    return 1;
}

void listaRutaCorta::borrar(){


}

caja3* listaRutaCorta::obtenerLugarAgregado(){
    return lugarAgregado;
}

caja2* listaRutaCorta::sacar(){
    caja3* p=principio;
    return p->direccion_nodo;
}

void listaRutaCorta::nuevo(){
    principio=NULL;
    anterior=NULL;
    donde=VACIO;
    encontrado=NO;
    anteriorAux=NULL;
}

int listaRutaCorta::agregar(caja2*, float ){

    return 1;
}

void listaRutaCorta::ajustar(caja3*, float){
}
