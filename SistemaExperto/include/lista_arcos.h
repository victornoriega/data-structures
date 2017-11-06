#ifndef LISTA_ARCOS_H
#define LISTA_ARCOS_H
#include <utilerias.h>

class lista_arcos
{
    caja1 *principio,*anterior,*lugar_agregado;
    donde donde;
    encontrado encontrado;
    public:
        lista_arcos();
        ~lista_arcos();
        void nuevo();
        void borrar();
        void buscar(int);
        int agregar(int);
        int borrar(int);
        void pintar();
        caja1 *lugarAgregado(void);
        caja1 *obtenerPrincipio();

};

#endif // LISTA_ARCOS_H
