#ifndef PILA_H
#define PILA_H
#define VACIO 999999


class pila
{
    int cuantos;
    public:
        pila();
        ~pila();
        void agregar(int a);
        int sacar(void);
        void pintar(void);
        int ObtenerCuantos(void);

};

#endif // PILA_H
