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

void Grafica::calcular_ruta_corta(int a, int b){
    caja2 *p;
    caja1 *q;
    A.agregar(a);
    p=A.lugarEncontrado();

    while(p){
        p->bandera=2;
        if(p->num_nodo==b){
            //existe_ruta=1;
            L.nuevo();
            while(p){
                L.agregar(p,p->ruta_corta);
                p=p->anterior;
            }
        }else{
            q =(p->salientes).obtenerPrincipio();
            while(q){
                if((q->direccion_nodo)->bandera==0){
                    q->direccion_nodo->bandera=1;
                    q->direccion_nodo->ruta_corta=p->ruta_corta+q->longitud;
                    L.agregar( q->direccion_nodo,p->ruta_corta+q->longitud);
                    q->direccion_nodo->direccion=L.obtenerLugarAgregado();
                }else if( q->direccion_nodo->bandera==1 && (p->ruta_corta+q->longitud) < q->direccion_nodo->ruta_corta){
                    q->direccion_nodo->ruta_corta=p->ruta_corta+q->longitud;
                    q->direccion_nodo->anterior=p;
                    L.ajustar(q->direccion_nodo->direccion,p->ruta_corta+q->longitud);
                    q=q->siguiente;
                }
            }
            p=L.sacar();
        }
    }


}
