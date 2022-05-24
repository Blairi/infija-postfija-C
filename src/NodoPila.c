#include <stdlib.h>
#include "../include/NodoPila.h"

/*

@author:      Nava Torres Gabriela
@date:        17/amy/2022
@brief:       Se encarga de crear un nodo para agregarlo una Pila
@param *data: Cadena a asignar para el nodo
@return nuevoNodo: Retorna un nuevo nodo con la información 

*/
NodoPila *crearNodoPila(char *data){ //O=1

    NodoPila *nuevoNodo = (NodoPila*)malloc( sizeof( struct NodoPila ) );

    nuevoNodo->dato = data;

    nuevoNodo->sig = NULL;

    return nuevoNodo;
}
