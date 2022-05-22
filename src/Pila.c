#include "../include/Pila.h"

#include "../include/NodoPila.h"

Pila *crearPila(){
    Pila *p = (Pila*)malloc( sizeof( struct Pila ) );

    p->cima = p->fondo = NULL;

    return p;
}


void apilar_nodo(NodoPila *nodo, Pila *p){

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


char *desapilar(Pila *p){
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


bool esvacia(Pila *p){
    return p->len == 0;
}


void mostrarPila(Pila *p){
    if( p->fondo == NULL ) return;

    printf("Cima: %s\nFondo: %s\nLongitud: %d\n", p->cima->dato, p->fondo->dato, p->len);

    NodoPila *actual = p->cima;

    while( actual ){
        printf("| %s |\n", actual->dato);
        actual = actual->sig;
    }
    printf("_____");
    printf("\n----------------------\n");

}
