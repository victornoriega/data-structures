#ifndef LISTA_ORD_POCA_REP_H
#define LISTA_ORD_POCA_REP_H
#define VACIO 99999999999
#include <lista_ord_rep.h>



class lista_ord_poca_rep
{
    caja *principio, *anterior,*anteriorAux;
    int cuantos;
    donde donde;
    encontrado encontrado;

    public:
        lista_ord_poca_rep();
        ~lista_ord_poca_rep();
        void buscar(int a);
        int agregar(int a);
        int borrar(int a);
        void pintar();

};

#endif // LISTA_ORD_H
