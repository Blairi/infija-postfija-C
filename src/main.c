// https://docs.google.com/document/d/14msJ7g8jASsBlfn3TLur918ZqKfavk9p-cgDtChMr0o/edit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/Cola.h"
#include "../include/Nodo.h"

#include "../include/Pila.h"
#include "../include/NodoPila.h"

void postfija();
int presedencia(char *caracter);
bool esOperador(char *caracter);

int main(){//O=n^2

	system("clear");

	postfija();//O=n^2

	return (0);
}

/*
 * @authors: Montiel Aviles Axel Fernando
 *           Lopez Lopez Axel Dion
 * @date: 21/may/2022
 * @brief: Función para convertir expresión infija o postfija
*/
void postfija(){//O=n^2
	typedef char cadenaCaracteres[12];
	cadenaCaracteres caracteres[100];

	// Creamos una cola para insertar cada elemento de la operación
	Cola *cola = crearCola();

	int len;
	printf("¿Cuántos elementos tiene tu operación? ");
	scanf("%d", &len); 
	
	// Iteramos segun la cantidad de elementos 
	for (int i = 0; i < len; i++){//O=n

		printf("Ingresa el elemento %d: ", i + 1);
		scanf("%s", caracteres[i]);

		// Creamos un nodo con la información que ingresa el usuario y lo encolamos a la cola
		Nodo *nodo = crearNodo(caracteres[i], NULL, NULL);
		encolar_nodo(nodo, cola);
	}

	mostrar_infija(cola);//O=n
	
	/*
	 * Creamos una nueva cola donde guardaremos cada elemento de la nueva expresión postfija
	 * y una pila para ir guardando los operadores
	*/
	Cola *cola_postfija = crearCola();
	Pila *pila = crearPila();

	// Hacemos uso de apuntadores para poder comparar en cada interación
	char *parentesis_izq = "(";
	char *parentesis_der = ")";

	char *operador;

	/*
	 * En esta parte iteramos según la cantidad de elementos que existan
	*/
	for (int i = 0; i < len; i++){//O=n*n
		
		// La función desencolar nos retorna la información del primer elemento y a su vez lo elimina de la cola
		char *actual = desencolar(cola);

		if( esOperador( actual ) ){
			
			/* Aqui comprobamos que la pila no este vacia, que el operador que esta en la cima
			 * de la pila no sea "(" y además comprobamos la presedencia del operador.
			 * Si todas estas condiciones las cumple, creamos un nodo para agregarlo a la cola
			 * y eliminamos la cima de la pila hasta que dejen de ser verdaderas.
			*/ 
			while( !esvacia(pila) && //O=n
					   strcmp(operador = pila->cima->dato, parentesis_izq) != 0 &&
						 presedencia(actual) <= presedencia(operador)){ //
				
				Nodo *nodoCola = crearNodo(operador, NULL, NULL);
				encolar_nodo(nodoCola, cola_postfija);
				desapilar(pila);

			}

			// Si las condiciones del while no se cumplieron apilamos el nuevo operador
			NodoPila *nodoPila = crearNodoPila(actual);
			apilar_nodo(nodoPila, pila);

		}
		
		// Si no es operador, comprobamos si es un "(" para apilarlo
		else if( strcmp(actual, parentesis_izq) == 0 ){
			NodoPila *nodoPila = crearNodoPila(actual);
			apilar_nodo(nodoPila, pila);
		}
		
		// Si no es "(", comprobamos si es un ")" para desapilar todos los operadores
		else if( strcmp(actual, parentesis_der) == 0 ){
			
			// Aqui iteramos desapilando cada elemento y encolandolo a la cola postfija
			// hasta encontrar el "(" que le corresponde
			while( strcmp(operador = pila->cima->dato, parentesis_izq) != 0 ){//O=n
				Nodo *nodoCola = crearNodo(operador, NULL, NULL);
				encolar_nodo(nodoCola, cola_postfija);
				desapilar(pila);
			}

		}

		// Si no se cumplio ninguna condición anterior significa que el elemento
		// es un número, así que lo encolamos
		else{
			Nodo *nodoCola = crearNodo(actual, NULL, NULL);
			encolar_nodo(nodoCola, cola_postfija);
		}

	}
	
	// Al acabar la iteración, desapilamos todos los operadores que falten
	// para agregarlos a la cola postfija
	while (!esvacia(pila)) {//O=n
		
		// Aqui ignoramos el "(" ya que no es parte de la notación
		if( strcmp(pila->cima->dato, parentesis_izq) != 0 ){
			Nodo *nodoCola = crearNodo(pila->cima->dato, NULL, NULL);
			encolar_nodo(nodoCola, cola_postfija);
		}

		desapilar(pila);
	}

	// Finalmente mostramos el resultado
	mostrar_postfija(cola_postfija);//O=n
	mostrarPila(pila);//O=n
	
}

/*
 * @author: Montiel Aviles Axel Fernando
 * @date: 21/may/2022
 * @brief: Comprobamos si el caracter es un operador
 * @param *caracter: Cadena a evaluar
 * @return: Falso o Verdadero
*/

bool esOperador(char *caracter){//O=1
	return presedencia(caracter) != 0;
}

/*
 * @author: Montiel Aviles Axel Fernando
 * @date: 21/may/2022
 * @brief: Evaluamos la presedencia de un operador según las reglas de la notación postfija
 * @param *caracter: Operador a evaluar
 * @return int: Retorna un entero de 0 a 3 según su prioridad
*/

int presedencia(char *caracter){//O=1

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
