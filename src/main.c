// https://docs.google.com/document/d/14msJ7g8jASsBlfn3TLur918ZqKfavk9p-cgDtChMr0o/edit
// https://www.youtube.com/watch?v=5zhXm3J9xdE

#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/Cola.h"
#include "../include/Nodo.h"

#include "../include/Pila.h"
#include "../include/NodoPila.h"

void probarColaDL();
void probarPila();
int presedencia(char *caracter);
bool esOperador(char *caracter);

int main(){

	system("clear");

	probarColaDL();
	//probarPila();
	

	return (0);
}

void probarPila(){
	Pila *pila = crearPila();
	NodoPila *nodo1 = crearNodoPila("fondo");
	NodoPila *nodo2 = crearNodoPila("medio");
	NodoPila *nodo3 = crearNodoPila("cima");

	apilar_nodo(nodo1, pila);
	apilar_nodo(nodo2, pila);
	apilar_nodo(nodo3, pila);

	mostrarPila(pila);

	desapilar(pila);
	desapilar(pila);
	desapilar(pila);

	mostrarPila(pila);
	
	if( esvacia(pila) ){
		printf("es vacia\n");
	}

}

void probarColaDL(){
	typedef char cadenaCaracteres[12];
	cadenaCaracteres caracteres[100];

	Cola *cola = crearCola();

	int len;
	printf("¿Cuantos elementos tiene tu operacion? ");
	scanf("%d", &len); 
	
	for (int i = 0; i < len; i++){

		printf("Ingresa el elemento %d: ", i + 1);
		scanf("%s", caracteres[i]);
		
		Nodo *nodo = crearNodo(caracteres[i], NULL, NULL);
		
		encolar_nodo(nodo, cola);
	} 

	/* Nodo *n1 = crearNodo("(", NULL, NULL); */
	/* Nodo *n2 = crearNodo("6", NULL, NULL); */
	/* Nodo *n3 = crearNodo("+", NULL, NULL); */
	/* Nodo *n4 = crearNodo("2", NULL, NULL); */
	/* Nodo *n5 = crearNodo(")", NULL, NULL); */
	/* Nodo *n6 = crearNodo("*", NULL, NULL); */
	/* Nodo *n7 = crearNodo("3", NULL, NULL); */
	/* Nodo *n8 = crearNodo("/", NULL, NULL); */
	/* Nodo *n9 = crearNodo("2", NULL, NULL); */
	/* Nodo *n10 = crearNodo("^", NULL, NULL); */
	/* Nodo *n11 = crearNodo("2", NULL, NULL); */
	/* Nodo *n12 = crearNodo("-", NULL, NULL); */
	/* Nodo *n13 = crearNodo("4", NULL, NULL); */
	/* encolar_nodo(n1, cola); */
	/* encolar_nodo(n2, cola); */
	/* encolar_nodo(n3, cola); */
	/* encolar_nodo(n4, cola); */
	/* encolar_nodo(n5, cola); */
	/* encolar_nodo(n6, cola); */
	/* encolar_nodo(n7, cola); */
	/* encolar_nodo(n8, cola); */
	/* encolar_nodo(n9, cola); */
	/* encolar_nodo(n10, cola); */
	/* encolar_nodo(n11, cola); */
	/* encolar_nodo(n12, cola); */
	/* encolar_nodo(n13, cola); */
	mostrar_infija(cola);

	Cola *cola_postfija = crearCola();
	Pila *pila = crearPila();
	
	char *parentesis_izq = "(";
	char *parentesis_der = ")";

	char *operador;

	for (int i = 0; i < len; i++){

		char *actual = desencolar(cola);
		if( esOperador( actual ) ){
			
			while( !esvacia(pila) && 
					   strcmp(operador = pila->cima->dato, parentesis_izq) != 0 &&
						 presedencia(actual) <= presedencia(operador)){
				
				Nodo *nodoCola = crearNodo(operador, NULL, NULL);
				encolar_nodo(nodoCola, cola_postfija);
				desapilar(pila);

			}

			NodoPila *nodoPila = crearNodoPila(actual);
			apilar_nodo(nodoPila, pila);

		}

		else if( strcmp(actual, parentesis_izq) == 0 ){
			NodoPila *nodoPila = crearNodoPila(actual);
			apilar_nodo(nodoPila, pila);
		}
		
		else if( strcmp(actual, parentesis_der) == 0 ){
			
			while( strcmp(operador = pila->cima->dato, parentesis_izq) != 0 ){
				Nodo *nodoCola = crearNodo(operador, NULL, NULL);
				encolar_nodo(nodoCola, cola_postfija);
				desapilar(pila);
			}

		}

		else{
			Nodo *nodoCola = crearNodo(actual, NULL, NULL);
			encolar_nodo(nodoCola, cola_postfija);
		}

	}

	while (!esvacia(pila)) {
		
		if( strcmp(pila->cima->dato, parentesis_izq) != 0 ){
			Nodo *nodoCola = crearNodo(pila->cima->dato, NULL, NULL);
			encolar_nodo(nodoCola, cola_postfija);
		}

		desapilar(pila);
	}

	mostrar_postfija(cola_postfija);
	mostrarPila(pila);
	
}



bool esOperador(char *caracter){
	return presedencia(caracter) != 0;
}


int presedencia(char *caracter){

	char *potencia = "^";
	char *multiplicacion = "*";
	char *division =  "/";
	char *mas = "+";
	char *menos = "-";

	if( strcmp(caracter, mas) == 0 || strcmp(caracter, menos) == 0 ) return 1;
	else if( strcmp(caracter, multiplicacion) == 0 || strcmp(caracter, division) == 0 ) return 2;
	else if( strcmp(caracter, potencia) == 0 ) return 3;
	else return 0;

}
