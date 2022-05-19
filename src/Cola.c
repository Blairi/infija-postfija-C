#include "Cola.h"

Cola* crearCola(){
    Cola* c = (Cola*)malloc( sizeof( struct Cola ) );
    c->primero = c->ultimo = NULL;

    return c;
}


void encolar_nodo(Nodo *nodo, Cola *c){
    if( c == NULL ) return;

    // printf("Dato a encolar: %s\n", nodo->dato);

    if( c->primero == NULL ){

        c->primero = c->ultimo = nodo;

        return;
    }

    nodo->prev = NULL;
    nodo->sig = c->primero;

    c->primero->prev = nodo;

    c->primero = nodo;

    return;

}


void encolar(char *data, Cola* c){
    
    if( c == NULL ) return;

    if( c->primero == NULL ){

        Nodo *nuevo_nodo = crearNodo( data, NULL, NULL );
        c->primero = c->ultimo = nuevo_nodo;

        return;
    }

    Nodo *nuevo_nodo = crearNodo( data, NULL, c->primero );
    c->primero->prev = nuevo_nodo;
    c->primero = nuevo_nodo;

    return;
}


char *desencolar(Cola *c){
    if( c->primero == NULL ) return "Cola vacia";

    Nodo* eliminado = c->ultimo;
    char *data = eliminado->dato;

    if( eliminado->prev ){
        eliminado->prev->sig = eliminado->sig;
    }
    else{
        c->primero = eliminado->sig;
    }

    if( eliminado->sig ){
        eliminado->sig->prev = eliminado->prev;
    }
    else{
        c->ultimo = eliminado->prev;
    }

    free( eliminado );

    return data;
}


void mostrar(Cola *c){
    if( c->primero == NULL ) return;

    printf("Primero: %s\nUltimo: %s\n", c->primero->dato, c->ultimo->dato);

    Nodo* actual = c->primero;

    printf("[");
    while ( actual ){
        printf(" %s ", actual->dato);
        actual = actual->sig;
    }
    printf("]");

    printf("\n------------------\n\n");

}