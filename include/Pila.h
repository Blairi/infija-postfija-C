#ifndef __PILA_H_
#define __PILA_H_

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "NodoPila.h"

typedef struct Pila
{
    struct NodoPila *cima, *fondo;
    int len;
} Pila;

Pila* crearPila();
void apilar_nodo(NodoPila *nodo, Pila *p);
char *desapilar(Pila *p);
void mostrarPila(Pila *p);
bool esvacia(Pila *p);

#endif
