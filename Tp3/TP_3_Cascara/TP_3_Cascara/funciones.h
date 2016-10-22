#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[150];
    int puntaje;
    char linkImagen[200];
    int isEmpty;

}EMovie;

#endif

/**
 *  \brief Inicializa el el estado del array de peliculas en 0
 *  @param movies: estructura donde se guardara el registro
 *  @param lenght: Tamaño del maximo del array
 */
int initializerList(EMovie* movies, int length);

/**
 *  \brief Agrega una pelicula al array de peliculas
 *  @param movies: estructura donde se guardara el registro
 *  @param lenght: Tamaño del array de estructura
 */
void addMovie(EMovie* movies,int lenght);

/**
 *  \brief Borra una pelicula al array de peliculas
 *  @param movies: estructura donde se borrara el registro
 *  @param lenght: Tamaño del array de estructura
 *  @return retorna un flag de valor 1 si borro la pelicula
 */
void deleteMovie(EMovie* movies,int lenght);

/**
 *  \brief Modifica una pelicula
 *  @param movies: estructura de peliculas de la cual se modificara una
 *  @param lenght: Tamaño del array de estructura
 */
void modifyMovie(EMovie* movie,int lenght);

/** \brief Crea un archivo html
 *  @param movies: estructura de peliculas
 *  @param lenght: Tamaño del array de estructura
 */
void createHTML(EMovie *movies,int lenght);

/**
 * Obtiene el primer indice libre del array.
 * @param movies se pasa como parametro.
 * @param lenght: Tamaño del array de estructura
 * @return el primer indice disponible
 */
int getFreeSpace(EMovie* movie, int lenght);

/**
 * @param Muestra los datos de una pelicula
 * @param movies: estructura de peliculas
 */
void showMovie(EMovie* movie);

/**
 * @param Imprime una opcion para realizar una seleccion
 */
int printMenu(char *menu);

/**
 * @param Verifica un numero y valida el rango del mismo
 * @param minimo: rango minimo del numero
 * @param maximo: rango maximo del numero
 */
int getInt(int minimo, int maximo);

