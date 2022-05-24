#ifndef __NODO_PILA_H_
#define __NODO_PILA_H_

/*

@author Nava Torres Gabriela
@date 17/may/2022
@brief Estructura de Nodo para Pila

*/

#include <stdio.h>

typedef struct NodoPila
{
    char *dato;
    struct NodoPila *sig;
} NodoPila;

NodoPila* crearNodoPila( char *data );

#endif
