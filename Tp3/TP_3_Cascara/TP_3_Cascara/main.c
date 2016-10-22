#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"
#include "funciones.c"
#define MAX 50

int main()
{

    EMovie movies[MAX];
    initializerList(movies,MAX);
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        opcion=printMenu("1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar pelicula\n4- Crear pagina web\n5- Salir\n\n");

        fflush(stdin);

        switch(opcion)
        {
        case 1:
            addMovie(movies, MAX);
            break;
        case 2:
            deleteMovie(movies,MAX);
            break;
        case 3:
            modifyMovie(movies,MAX);
            break;
        case 4:
            createHTML(movies, MAX);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Opcion no valida, favor reingrese opcion.\n");
            fflush(stdin);
            system("PAUSE");
            system("cls");
        }
    }

    return 0;
}
