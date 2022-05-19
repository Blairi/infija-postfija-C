// https://docs.google.com/document/d/14msJ7g8jASsBlfn3TLur918ZqKfavk9p-cgDtChMr0o/edit
// https://www.youtube.com/watch?v=5zhXm3J9xdE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Cola.h"
#include "Nodo.h"

#include "Pila.h"
#include "NodoPila.h"

void probarColaDL();
void probarPila();

int main(){

	system("cls");

	probarColaDL();
	

	return (0);
}

void probarPila(){
	Pila *pila = crearPila();
	NodoPila *nodo1 = crearNodoPila("fondo");
	// NodoPila *nodo2 = crearNodoPila("medio");
	// NodoPila *nodo3 = crearNodoPila("cima");

	apilar_nodo(nodo1, pila);
	// apilar_nodo(nodo2, pila);
	// apilar_nodo(nodo3, pila);

	mostrarPila(pila);

	desapilar(pila);

	mostrarPila(pila);
}

void probarColaDL(){
	// typedef char cadenaCaracteres[12];
    // cadenaCaracteres caracteres[100];

	Cola *cola = crearCola();

	// int len;
	// printf("¿Cuantos elementos tiene tu operacion? ");
	// scanf("%d", &len);
	
	// for (int i = 0; i < len; i++){

	// 	printf("Ingresa el elemento %d: ", i + 1);
	// 	scanf("%s", caracteres[i]);
		
	// 	Nodo *nodo = crearNodo(caracteres[i], NULL, NULL);
		
	// 	encolar_nodo(nodo, cola);
	// }

	Nodo *n1 = crearNodo("(", NULL, NULL);
	Nodo *n2 = crearNodo("6", NULL, NULL);
	Nodo *n3 = crearNodo("+", NULL, NULL);
	Nodo *n4 = crearNodo("2", NULL, NULL);
	Nodo *n5 = crearNodo(")", NULL, NULL);
	Nodo *n6 = crearNodo("*", NULL, NULL);
	Nodo *n7 = crearNodo("3", NULL, NULL);
	Nodo *n8 = crearNodo("/", NULL, NULL);
	Nodo *n9 = crearNodo("2", NULL, NULL);
	Nodo *n10 = crearNodo("^", NULL, NULL);
	Nodo *n11 = crearNodo("2", NULL, NULL);
	Nodo *n12 = crearNodo("-", NULL, NULL);
	Nodo *n13 = crearNodo("4", NULL, NULL);
	encolar_nodo(n1, cola);
	encolar_nodo(n2, cola);
	encolar_nodo(n3, cola);
	encolar_nodo(n4, cola);
	encolar_nodo(n5, cola);
	encolar_nodo(n6, cola);
	encolar_nodo(n7, cola);
	encolar_nodo(n8, cola);
	encolar_nodo(n9, cola);
	encolar_nodo(n10, cola);
	encolar_nodo(n11, cola);
	encolar_nodo(n12, cola);
	encolar_nodo(n13, cola);
	// mostrar(cola);

	Cola *cola_postfija = crearCola();
	Pila *pila = crearPila();

	char *parentesis_izq = "(";
	char *parentesis_der = ")";
	char *mas = "+";
	char *menos = "-";
	char *division = "/";
	char *potencia = "^";
	char *multiplicacion = "*";

	char *actual = desencolar(cola);

	for (int i = 0; i < 13; i++){
		if( strcmp( actual, parentesis_izq ) != 0 &&
			strcmp( actual, parentesis_der ) != 0 &&
			strcmp( actual, mas ) 			 != 0 &&
			strcmp( actual, menos )  		 != 0 &&
			strcmp( actual, division )       != 0 &&
			strcmp( actual, potencia )       != 0 &&
			strcmp( actual, multiplicacion ) != 0   )
		{
			Nodo *nodo = crearNodo( actual, NULL, NULL );
			encolar_nodo(nodo, cola_postfija);
		}

		if( strcmp( actual, parentesis_izq ) == 0){
			NodoPila *nodo = crearNodoPila( actual );
			apilar_nodo(nodo, pila);
		}

		if( strcmp( actual, parentesis_der ) == 0){
			Nodo *nodo = crearNodo( pila->cima->dato , NULL, NULL );
			encolar_nodo(nodo, cola_postfija);
			while( desapilar(pila) );
		}

		if( strcmp( actual, mas ) == 0){
			NodoPila *nodo = crearNodoPila( actual );
			apilar_nodo(nodo, pila);
		}

		if( strcmp( actual, multiplicacion ) == 0){
			NodoPila *nodo = crearNodoPila( actual );
			apilar_nodo(nodo, pila);
		}

		if( strcmp( actual, potencia ) == 0){
			NodoPila *nodo = crearNodoPila( actual );
			apilar_nodo(nodo, pila);
		}

		if( strcmp( actual, division ) == 0 && strcmp( pila->cima->dato, multiplicacion ) == 0 ){
			Nodo *nodo = crearNodo( multiplicacion , NULL, NULL );
			encolar_nodo(nodo, cola_postfija);

			while( desapilar(pila) );

			NodoPila *nodoPila = crearNodoPila( division );
			apilar_nodo(nodoPila, pila);

		}

		if( strcmp( actual, menos ) == 0 && 
		  ( strcmp( pila->cima->dato, potencia ) == 0 ||
		    strcmp( pila->cima->dato, division ) == 0 )
		){
			bool interruptor = true; // TODO: Terminar de desapilar
			while( interruptor ){
				char *dato = desapilar(pila);
				Nodo *nodo = crearNodo( dato, NULL, NULL );
				printf("%s\n", dato);
				interruptor = false;

				// encolar_nodo(nodo, cola_postfija);
			}
		}


		actual = desencolar(cola);
	}
	
	mostrar(cola_postfija);
	mostrarPila(pila);
	
}