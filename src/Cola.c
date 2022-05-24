#include "../include/Cola.h"
#include <stdio.h>

/*

@author: Ruiz Sánchez Yael Nacxit
@date:   19/may/2022
@brief:  Implementación de funciones para cola

*/

/*

@brief: Crea una cola y le asigna un espacio en memoria
@return: Retorna una nueva cola vacía

*/
Cola* crearCola(){
    Cola* c = (Cola*)malloc( sizeof( struct Cola ) );
    c->primero = c->ultimo = NULL;
    c->len = 0;
    return c;
}

/*
 *
 * @brief: Encola un nodo de acuerdo a las reglas de una cola y aumentando su longitud
 * @param *nodo: Nodo a encolar
 * @param *c: Cola donde se encolara el nodo
 *
*/

void encolar_nodo(Nodo *nodo, Cola *c){
    if( c == NULL ) return;

    // printf("Dato a encolar: %s\n", nodo->dato);
    
    c->len++;

    if( c->primero == NULL ){

        c->primero = c->ultimo = nodo;

        return;
    }

    c->ultimo->sig = nodo;
    nodo->prev = c->ultimo;
    c->ultimo = nodo;    

    return;

}

/*
 * @brief: Desencola una cola retornando la información de lo que desencola y disminuye su longitud
 * @param *c: Cola a desencolar
 * @return data: Cadena que contenia el nodo desencolado
*/
char *desencolar(Cola *c){
    if( c->primero == NULL ) return "Cola vacia";

    Nodo* eliminado = c->primero;
    char *data = eliminado->dato;

    // printf("Desencolando %s...\n", eliminado->dato);
    
    c->len--;

    if( eliminado->sig ){

        eliminado->sig->prev = NULL;
        c->primero = eliminado->sig;

    }
    else{

        c->primero = c->ultimo = NULL;
        c->len = 0;

    }

    free( eliminado );

    return data;
}

/*
 * @brief: Comprueba si la cola está vacía según su longitud
 * @param *c: Cola a evaluar
 * @return: Verdadero o falso
*/
bool cola_vacia(Cola *c){
    return c->len == 0;
}

/*
 * @brief: Funciones para imprimir colas
 * @param *c: Cola a mostrar
*/

void mostrar(Cola *c){
    if( c->primero == NULL ) return;

    printf("Primero: %s\nUltimo: %s\nLongitud: %d\n", c->primero->dato, c->ultimo->dato, c->len);

    Nodo* actual = c->primero;

    printf("[");
    while ( actual ){
        printf(" %s ", actual->dato);
        actual = actual->sig;
    }
    printf("]");

    printf("\n------------------\n\n");

}


void mostrar_postfija(Cola *c){
    if( c->primero == NULL ) return;

    printf("\nNotación Postfija:\n");

    Nodo *actual = c->primero;

    printf("[");
    while (actual) {
        printf(" %s ", actual->dato);
        actual = actual->sig;
    }
    printf("]");
    printf("\n--------------------\n\n");
}


void mostrar_infija(Cola *c){
    if( c->primero == NULL ) return;

    printf("\nNotación Infija:\n");

    Nodo *actual = c->primero;

    printf("[");
    while (actual) {
        printf(" %s ", actual->dato);
        actual = actual->sig;
    }
    printf("]");
    printf("\n--------------------\n\n");
}
