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
 * Da de Baja un usuario en diferentes posiciones del array Lista
 * @param Pide DNI de persona
 * @param Recorre array buscando un espacio ocupado
 * @param Cambia el valor del estado del array lista para indicar a vacio
 * @return
 */
int baja (personas lista[], int recorre);

/**
 * Muestra una lista ordenada de personas
 * @param Recorre el array lista buscando los nombres
 * @param Acomoda alfabeticamente los datos
 * @return Muestra los nombres de manera ordenada
 */
void listado(personas lista[],int recorre);

/**
 * Muestra una Grafico ordenada de personas
 * @param Recorre el array lista buscando los nombres
 * @param Acomoda alfabeticamente los datos
 * @return Muestra los nombres de manera ordenada
 */
void grafico(personas lista[],int recorre);

#endif // FUNCIONES_H_INCLUDED
