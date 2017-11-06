#ifndef LISTA_ORD_H
#define LISTA_ORD_H
#define VACIO 99999999999

struct caja{
    int valor;
    int repeticiones;
    caja *siguiente;
    caja *anterior;
};

enum donde{VACIA,PRINCIPIO,ENMEDIO,FINAL};
enum encontrado{SI,NO};


class lista_ord_rep
{
    caja *principio, *anterior,*anteriorAux;
    int cuantos;
    donde donde;
    encontrado encontrado;

    public:
        lista_ord_rep();
        ~lista_ord_rep();
        void buscar(int a);
        int agregar(int a);
        int borrar(int a);
        void pintar();

};

#endif // LISTA_ORD_H
