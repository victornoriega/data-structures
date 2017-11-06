#ifndef COLA_H
#define COLA_H
#include <pila.h>

class cola
{
    caja *principio;
    int cuantos;
    caja *ultimo;
    public:
        cola();
        ~cola();
        void agregar(int a);
        int sacar();
        void pintar();
};

#endif // COLA_H
