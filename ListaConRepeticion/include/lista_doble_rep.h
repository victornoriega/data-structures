#ifndef LISTA_DOBLE_REP_H
#define LISTA_DOBLE_REP_H
#include <lista_ord_rep.h>
class lista_doble_rep
{
    caja *siguiente, *anterior, *principio, *ultimo,*anteriorAux;
    encontrado encontrado;
    donde donde;
    public:
        lista_doble_rep();
        ~lista_doble_rep();
        void buscar(int a);
        int agregar(int a);
        int borrar(int);
        void pintar1();
        void pintar2();
};

#endif // LISTA_DOBLE_REP_H
