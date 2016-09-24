#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAX 3

typedef struct
{
    int dni;
    int edad;
    int estado;
    char nombre[25];

}personas;

void iniciar(personas lista[],int recorre)

{
    int i;
    for(i=0;i<recorre;i++)
    {
        lista[i].estado=-1;
    }

}

int obtener(personas lista[],int recorre)

{
    int i;
    int aux=-1;
    for(i=0;i<recorre;i++)
    {
        if(lista[i].estado==-1)
        {
            aux=i;
            break;
        }

    }
    return aux;
}


void alta(personas lista[],int recorre)

{

        printf("Ingrese el nombre de la persona:");
        fflush(stdin);
        gets(lista[recorre].nombre);
        printf("Ingrese edad:");
        fflush(stdin);
        scanf("%d",&lista[recorre].edad);
        printf("Ingrese DNI:");
        fflush(stdin);
        scanf("%d",&lista[recorre].dni);

}

int baja (personas lista[],int recorre)
{
    int dniBaja;
    int i;
    int aux=-1;
    printf("Ingrese el DNI: ");
    scanf("%d",&dniBaja);

    for(i=0;i<=recorre;i++)
    {
        if(lista[i].dni==dniBaja)
            {
                aux=i;
                break;
            }
    }

    return aux;
}


void listado(personas lista[],int recorre)


{
        int j;
        int i;
        personas auxiliar;

      for(i=0;i<recorre-1;i++)
        {
            for(j=i+1;j<recorre;j++)
            {
               if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                {
                    auxiliar=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxiliar;
                }

            }

        }

        for(i=0;i<recorre;i++)
        {
            if(lista[i].estado==1)
            {
                printf("DNI--- NOMBRE --- EDAD\n");
                printf("%d ---- %s ---- %d\n",lista[i].dni,lista[i].nombre,lista[i].edad);
            }
        }


}



void grafico(personas lista[],int recorre)
{

    int auxMenor;
    int auxEntre;
    int auxMayor;
    int i;
    int auxiliar2=0;
    int auxiliar1;

    for(i=0;i<recorre;i++)
    {
        if(lista[recorre].edad<=18)
        {
            auxMenor++;
        }
        else if(lista[recorre].edad>=19 && lista[recorre].edad<=35)
        {
            auxEntre++;
        }
        else if(lista[recorre].edad>=36)
        {
            auxMayor++;
        }
    }

    if(auxMenor >= auxEntre && auxMenor >= auxMayor)
    {
        auxiliar1 = auxMenor;
    }

    else
    {
        if(auxEntre >= auxMenor && auxEntre >= auxMayor)
        {
            auxiliar1 = auxEntre;
        }
        else
        {
        auxiliar1 = auxMayor;
        }
    }

    for(i=auxiliar1; i>0; i--)
    {
        if(i<3)
        {
            printf("%02d|",i);
        }
        if(i<= auxMenor)
        {
            printf("*");
        }
        if(i<= auxEntre)
        {
            auxiliar2=1;
            printf("\t*");
        }
        if(i<= auxMayor)
        {
            if(auxiliar2==0)
                printf("\t\t*");
            if(auxiliar2==1)
                printf("\t*");

        }

        printf("\n");
    }

    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");



}





