#include <stdio.h>
#include "funciones.h"

/** \brief Realiza la suma de 2 numeros
 *
 * \param primer numero ingresado
 * \param segundo numero ingresado
 * \return resultado de la Suma
 *
 */


float sumar ( float numero1, float numero2 )
    {
      return numero1 + numero2;
    }

/** \brief Realiza la resta de 2 numeros
 *
 * \param primer numero ingresado
 * \param segundo numero ingresado
 * \return Resultado de la Resta
 *
 */

float restar (float numero1, float numero2 )
    {
    return numero1 - numero2;
    }


/** \brief Realiza la Division de 2 numeros
 *
 * \param primer numero ingresado
 * \param segundo numero ingresado
 * \return Resultado Division
 *
 */

float dividir (float numero1, float numero2)
    {
        if(validarDivisionCero(numero2))
           {
                float x = numero1;
                float y = numero2;
                float resultado = x/y;
                return resultado;
           }
    }

/** \brief Realiza la Multiplicacion de 2 numeros
 *
 * \param primer numero ingresado
 * \param segundo numero ingresado
 * \return Productor de los 2 numeros
 *
 */


float multiplicar ( float numero1, float numero2)
    {
    return numero1 * numero2;
    }

/** \brief Realiza el Factorial de un numero
 *
 * \param Numero ingresado
 * \return Resultado del Factorial del numero ingresado
 *
 */

long long factorial (int numero)
{
    int i;
    long long acumulador = 1;
    for (i=numero; i>1; i--) // Con el for lo que hago es ir disminuyendo hasta el entero 1 por el cual debo multiplicar el resultado
    {
    acumulador = acumulador * i; // con el acumulador, voy guardando el resultado de la multiplicación anterior y le aplico la nueva multiplicación en base al numero que representa i hasta llegar a 1
    }
    return acumulador; // guardo el resultado final para mostrarlo en main
}


/** \brief Valido entrada de parámetros A y B
 *
 * \param Flag que indica si se ingreso numero 1
 * \param Flag que indica si se ingreso numero 2
 * \return 1 indicando que ambos fueron ingresados
 *
 */

int validarParametros(int flagA, int flagB)
{
    if (flagA == 0 || flagB == 0)
    {
        printf("Debe ingresar ambos operadores para esta funcion\n");
    }
    else
    {
        return 1;
    }
}


/** \brief Validador de Segundo Operando en 0 para division
 *
 * \param Segundo numero ingresado
 * \return Numero si es distinto de 0
 *
 */

int validarDivisionCero (int numero2)
{
    if (numero2 == 0)
     {
        printf("Error: No se puede dividir por Cero\n");
     }
     else
     {
     return numero2;
     }
}
