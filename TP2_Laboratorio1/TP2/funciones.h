#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "funciones.c"
#include "funciones.h"



/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtener(personas lista[],int recorre);


/**
 * Inicializa todas las operaciones
 * @param lista estado le asigna el valor cero
 */

void iniciar(personas lista[],int recorre);

/**
 * Da de alta un usuario en diferentes posiciones del array Lista
 * @param Pide datos de persona
 * @param Asigna valores a posiciones de array
 */
void alta(personas lista[],int recorre);


/**
 * Muestra una lista ordenada de personas
 * @param Recorre el array lista buscando los nombres
 * @param Acomoda alfabeticamente los datos
 * @return Muestra los nombres de manera ordenada
 */
void listado(personas lista[],int recorre);

/**
 * Muestra una Grafico ordenada de personas
 * @param Recorre el array lista buscando los las edades
 * @param Acomoda los datos en columnas
 * @return Muestra las edades
 */
void grafico(personas lista[]);

/**
 * Muestra una Grafico ordenada de personas
 * @param Recorre el array lista buscando los nombres
 * @param Acomoda alfabeticamente los datos
 * @return Muestra los nombres de manera ordenada
 */

#endif // FUNCIONES_H_INCLUDED
