#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#define MAX 20


int main()
{
    personas lista[MAX];
    char seguir='s';
    int opcion=0;
    int posicionDato;
    int dniBaja;


    iniciar(lista,MAX);



    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");

        printf("Eliga la opcion deseada: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
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
                system("cls");
                break;
            case 2:
                printf("Ingrese el DNI: ");
                scanf("%d",&dniBaja);
                posicionDato=buscarPorDni(lista,dniBaja,MAX);
                if(posicionDato==-1)
                {

                    printf("No existe el numero de DNI ingresado\n");

                    break;
                }
                else if(posicionDato!=-1)
                {
                    lista[posicionDato].estado=-1;

                    printf("Se han borrado el DNI ingresado.\n");
                }
                system("pause");
                system("cls");
                break;
            case 3:
                listado(lista,MAX);
                system("pause");
                system("cls");
                break;
            case 4:
                grafico(lista);
                system("pause");
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
        }

    }

    return 0;
}
