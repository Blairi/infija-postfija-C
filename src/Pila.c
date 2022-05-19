#include "Pila.h"
#include "NodoPila.h"

Pila *crearPila(){
    Pila *p = (Pila*)malloc( sizeof( struct Pila ) );

    p->cima = p->fondo = NULL;

    return p;
}


void apilar_nodo(NodoPila *nodo, Pila *p){

    if( p == NULL ) return;

    if( p->fondo == NULL ){

        p->fondo = p->cima = nodo;
        p->fondo->sig = NULL;

        return;
    }

    nodo->sig = p->cima;
    p->cima = nodo;

}


char *desapilar(Pila *p){
    if( p->cima == NULL ) return "Pila vacia";
    
    NodoPila *eliminado = p->cima;
    char *data = eliminado->dato;

    printf("Desapilando... %s\n", data);

    p->cima = p->cima->sig;

    free( eliminado );

}


void mostrarPila(Pila *p){
    if( p->fondo == NULL ) return;

    printf("Cima: %s\nFondo: %s\n", p->cima->dato, p->fondo->dato);

    NodoPila *actual = p->cima;

    while( actual ){
        printf(" %s ", actual->dato);
        actual = actual->sig;
    }

    printf("\n----------------------\n");

}