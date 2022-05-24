#ifndef __COLA_H_
#define __COLA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Nodo.h"

/*

@author: Ruiz Sánchez Yael Nacxit
@date:   19/may/2022
@brief:  Estructra de cola

*/

typedef struct Cola
{
    struct Nodo *primero, *ultimo;
    int len;
} Cola;

Cola* crearCola();
void encolar_nodo(Nodo *nodo, Cola *c);
char* desencolar(Cola *c);
void mostrar(Cola *c);
void mostrar_postfija(Cola *c);
void mostrar_infija(Cola *c);
bool cola_vacia(Cola *c);

#endif
