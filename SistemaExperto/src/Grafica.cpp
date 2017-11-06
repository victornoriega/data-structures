#include "Grafica.h"

Grafica::Grafica()
{
    A.nuevo();
}

Grafica::~Grafica()
{
    A.borrar();
}

void Grafica::agregar_arco(int a, int b, float c){
    caja2 *p1,*p2;
    caja1 *q;
    A.agregar(a);
    p1=A.lugarEncontrado();
    (p1->salientes).agregar(b);
    q=(p1->salientes).lugarAgregado();
    q->longitud=c;

    A.agregar(b);
    p2=A.lugarEncontrado();
    p2->entrantes.agregar(a);
    q->direccion_nodo=p2;
    q=p2->entrantes.lugarAgregado();
    q->direccion_nodo=p1;
    q->longitud=c;

}


