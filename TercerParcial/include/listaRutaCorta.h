#ifndef LISTARUTACORTA_H
#define LISTARUTACORTA_H
#include <utilerias.h>
#include <utilerias3.h>

class listaRutaCorta
{
    caja3 *siguiente, *anterior, *principio, *ultimo,*anteriorAux, *lugarAgregado;
    encontrado encontrado;
    donde donde;
    public:
        listaRutaCorta();
        ~listaRutaCorta();
        int agregar(caja2*, float );
        void nuevo();
        void buscar(int a);
        int borrar(int);
        void borrar(); //Destructor llamado desde otra clase
        caja3 * obtenerLugarAgregado();
        void ajustar(caja3*, float);
        caja2* sacar();




};

#endif // LISTARUTACORTA_H
