#ifndef PILA_H
#define PILA_H
#define VACIO 999999

struct caja{
    int valor;
    caja *siguiente;
    caja *anterior;
};

enum donde{VACIA,PRINCIPIO,ENMEDIO,FINAL};
enum encontrado{SI,NO};

class pila
{
    caja *principio;
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
