#ifndef __NODO_PILA_H_
#define __NODO_PILA_H_

#include <stdio.h>

typedef struct NodoPila
{
    char *dato;
    struct NodoPila *sig;
} NodoPila;

NodoPila* crearNodoPila( char *data );

#endif