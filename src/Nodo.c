#include <stdlib.h>
#include "../include/Nodo.h"

/*

@author:      Nava Torres Gabriela
@date:        17/amy/2022
@brief:       Se encarga de crear un nodo para agregarlo a una Cola
@param *data: Cadena a asignar para el nodo
@param *prev: Apuntador hacia un nodo previo
@param  *sig: Apuntador hacia un nodo siguiente 
@return nuevoNodo: Retorna un nuevo nodo con la información y referencias establecidas

*/

Nodo* crearNodo(char *data, Nodo *prev, Nodo *sig){

    Nodo* nuevoNodo = (Nodo*)malloc( sizeof( struct Nodo ) );

    nuevoNodo->dato = data;

    nuevoNodo->prev = prev;
    nuevoNodo->sig = sig;

    return nuevoNodo;
}
