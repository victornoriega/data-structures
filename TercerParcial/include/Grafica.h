#ifndef GRAFICA_H
#define GRAFICA_H
#include <lista_nodos.h>
#include <listaRutaCorta.h>

class Grafica
{
    lista_nodos A;
    listaRutaCorta L;

    public:
        Grafica();//A.nuevo
        ~Grafica();//A.borrar
        void agregar_arco(int, int,float);
        void pintar();
        void calcular_ruta_corta(int a, int b);


    protected:

    private:
};

#endif // GRAFICA_H
