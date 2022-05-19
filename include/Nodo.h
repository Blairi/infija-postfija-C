#ifndef __NODO_H_
#define __NODO_H_

#include <stdio.h>

typedef struct Nodo
{
    char* dato;
    struct Nodo *sig;
    struct Nodo *prev;
} Nodo;

Nodo* crearNodo(char *data, Nodo *prev, Nodo *sig);

#endif