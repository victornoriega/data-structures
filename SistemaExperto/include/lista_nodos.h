#ifndef LISTA_NODOS_H
#define LISTA_NODOS_H
#include <utilerias2.h>


class lista_nodos
{
    caja2 *principio, *anterior,*lugar_encontrado;
    encontrado encontrado;
    donde donde;
    public:
        lista_nodos();
        void nuevo();
        ~lista_nodos();
        void borrar();
        caja2 *lugarEncontrado();
        void buscar(int);
        int agregar(int);
        int borrar(int);
        void pintar();

};

#endif // LISTA_NODOS_H
