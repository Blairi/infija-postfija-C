#include "../include/Pila.h"
#include "../include/NodoPila.h"

/*

@author: Marín Montaño Josué 
@date:   19/may/2022
@brief:  Implementación de funciones para Pila

*/

/*

@brief: Crea una cola y le asigna un espacio en memoria
@return: Retorna una nueva pila vacía

*/
Pila *crearPila(){ //O=1
    Pila *p = (Pila*)malloc( sizeof( struct Pila ) );

    p->cima = p->fondo = NULL;

    return p;
}

/*
 * @brief: Apila un nodo siguiendo las reglas de la estructura Pila
 * @param *nodo: Nodo a apilar
 * @param *p: Pila para apilar el nodo
*/

void apilar_nodo(NodoPila *nodo, Pila *p){ //O=1

    if( p == NULL ) return;

    p->len ++;

    if( p->fondo == NULL ){

        p->fondo = p->cima = nodo;
        p->fondo->sig = NULL;

        return;
    }

    nodo->sig = p->cima;
    p->cima = nodo;

}

/*
 * @brief: Desapila por arriba retornando la información del nodo desapilado
 * @param *p: Pila a desapilar
 * @return data: Cadena del nodo desapilado
*/

char *desapilar(Pila *p){ //O=1
    if( p->fondo == NULL ) return NULL;

    NodoPila *eliminado = p->cima;
    char *data = eliminado->dato;

    // printf("Desapilando... %s\n", data);

    if( eliminado->sig ){
        p->cima = eliminado->sig;
        p->len--;
    }
    else{
        p->cima = p->fondo = NULL;
        p->len = 0;
    }

    free( eliminado );

    return data;

}

/*
 * @brief: Evalua la pila comprobando por su longitud
 * @param *p: Pila a evaluar
 * @return: Verdadero o falso
*/

bool esvacia(Pila *p){ //O=1
    return p->len == 0;
}

/*
 * @brief: Funcion para mostrar el estado de la pila
 * @param *p: Pila a mostar
*/

void mostrarPila(Pila *p){ O=n
    if( p->fondo == NULL ) return;

    printf("Cima: %s\nFondo: %s\nLongitud: %d\n", p->cima->dato, p->fondo->dato, p->len);

    NodoPila *actual = p->cima;

    while( actual ){ //O=n
        printf("| %s |\n", actual->dato);
        actual = actual->sig;
    }
    printf("_____");
    printf("\n----------------------\n");

}
