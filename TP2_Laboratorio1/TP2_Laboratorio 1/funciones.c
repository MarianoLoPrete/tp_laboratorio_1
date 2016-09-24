#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAX 20


int validarnumeros(char numeros[]); /// Valida que los caracteres ingresados sean solo numeros

int validarcaracteres(char cadena[]); /// Valida que los caracteres ingresados sean solo letras

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
        int i=0;
        printf("Ingrese el nombre de la persona:");
        fflush(stdin);
        gets(lista[recorre].nombre);
            while(validarcaracteres(lista[recorre].nombre)==0)
            {
                printf("\nError! Nombre valido solo con letras \n\n\nFavor de reingresar el nombre: ");
                fflush(stdin);
                gets(lista[recorre].nombre);
                printf("Nombre Cargado.\n");
            }
        printf("Ingrese edad:");
        fflush(stdin);
        scanf("%d",&lista[recorre].edad);
            while(lista[recorre].edad <1 || lista[recorre].edad >125)
            {
                printf("\nError! Favor de ingresad edad correcta: ");
                fflush(stdin);
                scanf("%d",&lista[recorre].edad);
                printf("Edad Cargada.\n");
            }
        printf("Ingrese DNI:");
        fflush(stdin);
        scanf("%d",&lista[recorre].dni);
            for(i=0;i<recorre;i++)
            {
                if(lista[i].dni==lista[recorre].dni)
                {
                printf("Error! DNI Ya existe \n\n\nFavor de reingresar otro DNI: ");
                fflush(stdin);
                scanf("%d",&lista[recorre].dni);
                }
                else
                {
                    printf("DNI Cargado.\n");
                }
                break;
            }

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



void grafico(personas lista[])
{
//int auxMenor,int auxEntre, int auxMayor

    int i;
    int auxiliar2=0;
    int auxiliar1;
    int auxMenor=0;
    int auxEntre=0;
    int auxMayor=0;

     for(i=0;i<MAX;i++)
      {
        if(lista[i].estado==1)
        {


                if(lista[i].edad<=18)
                        {
                            auxMenor++;
                        }
                else if(lista[i].edad>=19 && lista[i].edad<=35)
                        {
                            auxEntre++;
                        }
                else if(lista[i].edad>=36)
                        {
                            auxMayor++;
                        }
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

    for(i=auxiliar1;i>0;i--)
    {
        if(i<3)
        {
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= auxMenor)
        {
            printf("*");
        }
        if(i<= auxEntre)
        {
            auxiliar2=1;
            printf("\t\t*");
        }
        if(i<= auxMayor)
        {
            if(auxiliar2==0)
                printf("\t\t\t*");
            if(auxiliar2==1)
                printf("\t\t*");

        }

        printf("\n");
    }

// printf("\n   %d\t%d\t%d", auxMenor, auxEntre, auxMayor);



}

int validarcaracteres(char cadena[])
{
   int i=0;

   while(cadena[i]!='\0')
        {
            if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
            return 0;
            i++;
        }

   return 1;
}

int validarnumeros(char cadena[])
{
   int i=0;
   while(cadena[i] != '\0')
   {
       if(cadena[i] < '0' || cadena[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

