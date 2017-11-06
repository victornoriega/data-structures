#include <iostream>
#include <cola.h>
#include <pila.h>
#include <lista_ord.h>
#include <lista_doble.h>
#include <lista_mitad.h>


int main()
{
    lista_mitad A;
    A.agregar(5);
    A.agregar(9);
    A.agregar(3);
    A.agregar(12);
    A.agregar(17);
    A.agregar(13);
    A.agregar(2);
    A.agregar(1);
    A.pintar();
    std::cout << "Despues de borrar\n";
    A.borrar(5);
    A.borrar(15);
    A.borrar(17);
    A.agregar(18);
    A.pintar();


    return 0;
}
