#ifndef __NODO_H_
#define __NODO_H_

#include <stdio.h>
/*

@author Nava Torres Gabriela
@date 17/may/2022
@brief Estructura de Nodo para Cola

*/
typedef struct Nodo
{
    char* dato;
    struct Nodo *sig;
    struct Nodo *prev;
} Nodo;

Nodo* crearNodo(char *data, Nodo *prev, Nodo *sig);

#endif
