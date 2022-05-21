#ifndef __COLA_H_
#define __COLA_H_

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Nodo.h"

typedef struct Cola
{
    struct Nodo *primero, *ultimo;
    int len;
} Cola;

Cola* crearCola();
void encolar (char *data, Cola* c);
void encolar_nodo(Nodo *nodo, Cola *c);
char* desencolar(Cola *c);
void mostrar(Cola *c);
bool cola_vacia(Cola *c);

#endif
