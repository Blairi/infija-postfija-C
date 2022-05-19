#ifndef __PILA_H_
#define __PILA_H_

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "NodoPila.h"

typedef struct Pila
{
    struct NodoPila *cima, *fondo;
} Pila;

Pila* crearPila();
void apilar_nodo(NodoPila *nodo, Pila *p);
char *desapilar(Pila *p);
void mostrarPila(Pila *p);

#endif