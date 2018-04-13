#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

// el factorial deberia ser con numero entero, validar que ingrese un entero, verificar lo que estoy pasandole,
// si es entero hacer el factorial sino error

int main()
{
    char seguir='s';
    char confirmarSalida; // lo utilizo para confirmar que quiere salir del sistema
    int primerOperandoIngresado=0; // este flag lo utizo para validar si se ingreso el PrimerOperando o no
    int segundoOperandoIngresado=0; // al igual que el flag anteriror lo utilizo para validar el SegundoOperando
    int opcion=0;
    float primerOperando;
    float segundoOperando;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    long long factor;
    float auxiliarFactorial; // lo utilizo para saber si el numero ingresado es decimal o no


    while(seguir=='s')
    {
        printf("*************************************\n");
        printf("***Bienvenido a la calculadora UTN***\n");
        printf("*************************************\n\n");


        if (primerOperandoIngresado== 0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");

        }
        else
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n",primerOperando);
        }
        if (segundoOperandoIngresado == 0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n",segundoOperando);
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n");

        printf("Por favor, ingrese el numero de la opcion deseada:\n\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese el 1er operando: ");
            scanf("%f", &primerOperando);
            primerOperandoIngresado = 1;
            break;
        case 2:
            printf("Ingrese el 2do operando: ");
            scanf("%f", &segundoOperando);
            segundoOperandoIngresado = 1;
            break;
        case 3:
            if (validarParametros(primerOperandoIngresado,segundoOperandoIngresado))
            {
                suma = sumar(primerOperando, segundoOperando);
                printf("La suma de A+B es: %.2f\n",suma);
            }
            system("pause");
            break;
        case 4:
            if (validarParametros(primerOperandoIngresado,segundoOperandoIngresado))
            {
                resta = restar(primerOperando, segundoOperando);
                printf("La resta de A-B es: %.2f\n",resta);
            }
            system("pause");
            break;
        case 5:
            if (validarParametros(primerOperandoIngresado,segundoOperandoIngresado))
            {
                if (validarDivisionCero (segundoOperando))
                {
                    division = dividir(primerOperando, segundoOperando);
                    printf("La division de A/B: %.2f\n", division);
                }
            }
            system("pause");
            break;
        case 6:
            if (validarParametros(primerOperandoIngresado,segundoOperandoIngresado))
            {
                multiplicacion = multiplicar (primerOperando,segundoOperando);
                printf("La multiplicacion de A*B es: %.2f\n", multiplicacion);
            }
            system("pause");
            break;
        case 7:

            auxiliarFactorial = primerOperando - (int)primerOperando; // determino si el numero ingresado es decimal

            if (primerOperandoIngresado== 0)
            {
                printf("Debe ingresar el operador A para esta funcion\n");
            }
            else if (primerOperando < 0 || auxiliarFactorial != 0) // determino si el numero ingresado en positivo o decimal para mostrar error al usuario
            {
                printf("Error: Imposible Factorear un numero decimal o Negativo\n");
            }
            else
            {
                factor = factorial (primerOperando);
                printf("El factorial de A! es: %lld\n",factor);
            }
            system("pause");
            break;
        case 8:
            if (validarParametros(primerOperandoIngresado,segundoOperandoIngresado))
            {
                suma = sumar(primerOperando,segundoOperando);
                resta = restar(primerOperando,segundoOperando);
                division = dividir(primerOperando,segundoOperando);
                multiplicacion = multiplicar(primerOperando,segundoOperando);
                factor = factorial(primerOperando);
                printf("El resultado de las operaciones es: \n Suma: %.2f \n Resta: %.2f \n Division: %.2f \n Multiplicacion: %.2f \n Factorial: %lld \n", suma,resta,division,multiplicacion,factor);
            }
            system("pause");
            break;
        case 9:
            printf("Realmente desea salir? [s/n]\n");
            confirmarSalida = tolower(getche()); // fuerzo mayusculas a minisculas para confirmar salida
            if(confirmarSalida == 's')
            {
                seguir = 'n';
            }
            printf("\n\n");
            break;
        default: // lo utilizo para validar que ingrese un numero entre 1 y 9 en las opciones
            printf("Error: Seleccione una opcion entre 1 y 9\n");
            system("pause");
            break;

        }

        system("cls");
    }

    return 0;

}
