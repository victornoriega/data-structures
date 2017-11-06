#ifndef UTILERIAS_H
#define UTILERIAS_H

struct caja2;
struct caja1{
    int num_nodo;
    caja1 *siguiente;
    caja2 *direccion_nodo;
    float longitud;
};

enum encontrado{SI,NO};
enum donde{VACIO,PRINCIPIO,ENMEDIO,FINAL};

#endif // UTILERIAS_H
