#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED
#include "funciones.h"

/** \brief Obtiene el numero ingresado como valor para asignacion
 *
 * \param toma el valor ingresado y lo muestra junto con el valor ya asignado
 * \return Retorna el numero obtenido
 *
 */

int ingreseNumero(char letra)
{
    int numero1=0;
    printf("\nIngrese el valor de %c: ",letra);
    scanf("%d",&numero1);
    printf("El numero %c ahora vale: %d\n",letra,numero1);
    system("pause");
    system("cls");
    return numero1;

}

/**\brief Suma los dos numeros.
 *
 * \param numero a.
 * \param numero b.
 * \return Retorna el resultado de la suma de los numeros a y b.
 *
 */

int suma(int numero1,int numero2)
{
    int resultado;
    resultado=numero1+numero2;
    printf("La suma de los numeros es: %d\n",resultado);

return resultado;
}

/**\brief Resta los dos numeros.
 *
 * \param numero a.
 * \param numero b.
 * \return Retorna el resultado de la resta de los numeros a y b.
 *
 */

int resta(int numero1,int numero2)
{
    int resultado;
    resultado=numero1-numero2;
    printf("La resta de los numeros es: %d\n",resultado);

return resultado;
}

/**\brief Divide los dos numeros.
 *
 * \param numero a.
 * \param numero b.
 * \return Retorna el resultado de la division de los numeros a y b.
 *
 */

float division(float numero1,float numero2)
{

    float resultado;

    while(numero2==0)
    {
        printf("Error, no se puede dividir por cero\n");
        scanf("Ingrese numero b:%f",&numero2);
        break;
    }
    if(numero2>1)
    {
        resultado=numero1/numero2;
        printf("La division de los numeros a y b es: %f\n",resultado);
    }
    if (numero2==1)
    {
        printf("La division de los numeros a y b es: %f\n",numero1);
    }

return resultado;

}

/**\brief Multiplica los dos numeros.
 *
 * \param numero a.
 * \param numero b.
 * \return Retorna el resultado de la division de los numeros a y b.
 *
 */

int multiplicacion(int numero1,int numero2)
{

    int resultado;
    resultado=numero1*numero2;
    printf("La multiplicacion de los numeros es: %d\n",resultado);

return resultado;
}

/**\brief Factoriza el numero a.
 *
 * \param numero a.
 * \return Retorna el resultado del numero a factorizado.
 *
 */

float factorial(float numero1)
{

    int i;
    int acum=1;

    for(i=numero1;i>0;i--)

        {
            acum=acum*i;

        }

return acum;
}

#endif // FUNCIONES_H_INCLUDED
