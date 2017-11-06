#ifndef LISTA_MITAD_H
#define LISTA_MITAD_H
#include <pila.h>


class lista_mitad
{
    caja *mitad;
    caja *siguiente;
    caja *anterior;
    caja *principio;
    caja *ultimo;
    int mayores,menores;
    donde donde;
    encontrado encontrado;
    public:
        lista_mitad();
        ~lista_mitad();
        void buscar(int a);
        int agregar(int a);
        int borrar(int a);
        void pintar();

};

#endif // LISTA_MITAD_H
