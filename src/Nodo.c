#include <stdlib.h>
#include "Nodo.h"

Nodo* crearNodo(char *data, Nodo *prev, Nodo *sig){

    Nodo* nuevoNodo = (Nodo*)malloc( sizeof( struct Nodo ) );

    nuevoNodo->dato = data;

    nuevoNodo->prev = prev;
    nuevoNodo->sig = sig;

    return nuevoNodo;
}