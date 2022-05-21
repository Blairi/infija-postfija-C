#include "../include/Cola.h"

Cola* crearCola(){
    Cola* c = (Cola*)malloc( sizeof( struct Cola ) );
    c->primero = c->ultimo = NULL;
    c->len = 0;
    return c;
}


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


bool cola_vacia(Cola *c){
    return c->len == 0;
}

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
