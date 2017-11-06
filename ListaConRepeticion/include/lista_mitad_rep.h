#ifndef LISTA_MITAD_REP_H
#define LISTA_MITAD_REP_H
#include <lista_ord_rep.h>

class lista_mitad_rep
{
    caja *mitad;
    caja *siguiente;
    caja *anterior;
    caja *principio;
    caja *ultimo, *anteriorAux;
    int mayores,menores;
    donde donde;
    encontrado encontrado;
    public:
        lista_mitad_rep();
        ~lista_mitad_rep();
        void buscar(int a);
        int agregar(int a);
        int borrar(int a);
        void pintar();

};

#endif // LISTA_MITAD_REP_H
