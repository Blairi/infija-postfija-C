// https://docs.google.com/document/d/14msJ7g8jASsBlfn3TLur918ZqKfavk9p-cgDtChMr0o/edit
// https://www.youtube.com/watch?v=5zhXm3J9xdE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cola.h"
#include "Nodo.h"

#include "Pila.h"
#include "NodoPila.h"

int main(){

	system("clear");

	Pila *pila = crearPila();
	NodoPila *nodo1 = crearNodoPila("fondo");
	NodoPila *nodo2 = crearNodoPila("medio");
	NodoPila *nodo3 = crearNodoPila("cima");

	apilar_nodo(nodo1, pila);
	apilar_nodo(nodo2, pila);
	apilar_nodo(nodo3, pila);

	mostrarPila(pila);

	desapilar(pila);

	mostrarPila(pila);
	

	return (0);
}

/*
typedef char cadenaCaracteres[12];
    cadenaCaracteres caracteres[100];

	Cola *cola = crearCola();

	int len;
	printf("¿Cúantos caracteres tiene tu operación? ");
	scanf("%d", &len);
	
	for (int i = 0; i < len; i++){

		printf("Ingresa el caracter %d: ", i + 1);
		scanf("%s", caracteres[i]);
		
		Nodo *nodo = crearNodo(caracteres[i], NULL, NULL);
		
		encolar_nodo(nodo, cola);
	}

	mostrar(cola);

	desencolar(cola);

	mostrar(cola);
*/