#include <iostream>
#include <cstdlib>
#include <lista_ord_rep.h>
#include <lista_doble_rep.h>
#include <lista_mitad_rep.h>
#include <lista_ord_poca_rep.h>

int main()
{
    lista_ord_poca_rep A;
    A.agregar(12);
    A.agregar(12);
    A.agregar(12);
    A.agregar(15);
    A.agregar(18);
    A.agregar(15);


    A.pintar();

    return 0;
}
