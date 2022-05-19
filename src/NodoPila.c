#include <stdlib.h>
#include "NodoPila.h"

NodoPila *crearNodoPila(char *data){

    NodoPila *nuevoNodo = (NodoPila*)malloc( sizeof( struct NodoPila ) );

    nuevoNodo->dato = data;

    nuevoNodo->sig = NULL;

    return nuevoNodo;
}