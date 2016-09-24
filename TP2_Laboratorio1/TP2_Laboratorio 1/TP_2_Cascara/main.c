#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#define MAX 3


int main()
{
    personas lista[MAX];
    char seguir='s';
    int opcion=0;
    int posicionDato;
    iniciar(lista,MAX);



    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                posicionDato=obtener(lista,MAX);
                if(posicionDato!=-1)
                {
                    alta(lista,posicionDato);
                    lista[posicionDato].estado=1;
                    printf("\nSe dio de alta.\n");
                }
                else
                {
                    printf("\nNo se encontraron posiciones libres.");
                }
                system("pause");
                break;
            case 2:
                posicionDato=baja(lista,MAX);
                if(posicionDato!=-1)
                {
                    lista[posicionDato].estado=-1;
                    printf("\nSe dio de baja.\n");
                }
                else
                 {
                    printf("\nDNI no existe.");
                 }
                system("pause");
                break;
            case 3:
                listado(lista,MAX);
                break;
            case 4:
                grafico(lista,MAX);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
