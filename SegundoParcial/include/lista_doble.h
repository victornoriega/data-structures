#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H
#include "pila.h"

class lista_doble
{
    caja *siguiente, *anterior, *principio, *ultimo;
    encontrado encontrado;
    donde donde;
    public:
        lista_doble();
        ~lista_doble();
        void buscar(int a);
        int agregar(int a);
        int borrar(int);
        void pintar1();
        void pintar2();

};

#endif // LISTA_DOBLE_H
