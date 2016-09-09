#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{

    int opcion=0;
    int numero1=0;
    int numero2=0;

do{

        printf("1- Ingresar 1er operando (A=%d)\n", numero1);
        printf("2- Ingresar 2do operando (B=%d)\n", numero2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n\n");

        printf("Ingrese la opcion deseada: ");
        scanf("%d",&opcion);


switch(opcion)
        {
            case 1:
                numero1=ingreseNumero('a');
                break;
            case 2:
                numero2=ingreseNumero('b');
                break;
            case 3:
                suma(numero1,numero2);
                system("pause");
                system("cls");
                break;
            case 4:
                resta(numero1,numero2);
                system("pause");
                system("cls");
                break;
            case 5:
                division(numero1,numero2);
                system("pause");
                system("cls");
                break;
            case 6:
                multiplicacion(numero1,numero2);
                system("pause");
                system("cls");
                break;
            case 7:
                printf("El factorial del numero A es: %.2f\n",factorial(numero1));
                system("pause");
                system("cls");
                break;
            case 8:
                suma(numero1,numero2);
                resta(numero1,numero2);
                division(numero1,numero2);
                multiplicacion(numero1,numero2);
                printf("El factorial del numero A es: %.2f\n",factorial(numero1));
                system("pause");
                system("cls");
                break;
            case 9:
                printf("Presione una tecla para salir!\n\n\n");
                return 0;
                break;
        }

}while(opcion<9);

printf("Error, opcion incorrecta, por favor ingrese una opcion valida\n");
system("pause");
system("cls");


return main();

}
