#ifndef GRAFICA_H
#define GRAFICA_H
#include <lista_nodos.h>

class Grafica
{
    lista_nodos A;

    public:
        Grafica();//A.nuevo
        ~Grafica();//A.borrar
        void agregar_arco(int, int,float);
        void pintar();


    protected:

    private:
};

#endif // GRAFICA_H
