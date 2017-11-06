#ifndef UTILERIAS2_H
#define UTILERIAS2_H
#include <lista_arcos.h>


struct caja3;
struct caja2{
    int num_nodo;
    caja2 *siguiente,*anterior;
    int bandera;
    lista_arcos salientes, entrantes;
    caja3 *direccion;
    int cuantos;
    int totales;
    int tipo_conectivo;
    int valor_verdad;
};

#endif
