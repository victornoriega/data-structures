#ifndef LISTA_ORD_H
#define LISTA_ORD_H
#include <pila.h>


class lista_ord
{
    caja *principio, *anterior;
    int cuantos;
    donde donde;
    encontrado encontrado;

    public:
        lista_ord();
        ~lista_ord();
        void buscar(int a);
        int agregar(int a);
        int borrar(int a);
        void pintar();

};

#endif // LISTA_ORD_H
