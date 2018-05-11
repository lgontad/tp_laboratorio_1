#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 20

int main()
{
    ePersonas listadoPersonas[TAM];


    char seguir='s';
    int opcion=0;
    int indiceLugarLibre;
    int documentoExiste;
    long int dniIngresado;

    while(opcion != 5)
    {
        printf("\nINGRESE LA OPCION DE MENU DESEADA: ");
        opcion = getInt("\n\n\n1 - ALTA PERSONA \n2 - BORRAR PERSONA \n3 - LISTAR ORDENADO \n4 - GRAFICO DE EDADES\n5 - SALIR\n\n\n");
        printf("\n");

        switch(opcion)
        {
            case 1:
                indiceLugarLibre = buscarLugarLibre(listadoPersonas, TAM);
                if(indiceLugarLibre == -1)
                {
                    printf("\n\nNo quedan Lugares Libres!\n");
                    break;
                }
                else
                {
                    cargarPersona(listadoPersonas, indiceLugarLibre);
                }
                break;

            case 2:

                printf("Ingresar el DNI de la Persona: \n");
                fflush(stdin);
                scanf("%ld", &dniIngresado);

                documentoExiste = buscarPorDni(listadoPersonas, TAM, dniIngresado);

                if (documentoExiste == -1)
                {
                   printf("DNI no Existe en la Base de Datos");
                }
               else
                {
                   printf("La persona de dio de baja correctamente");
                   listadoPersonas[documentoExiste].estado = 0;
                }
                break;

            case 3:
                ordenarPersonas(listadoPersonas, TAM);
                mostrarListadoPersonas(listadoPersonas, TAM);

                break;
            case 4:
                mostrarGrafico(listadoPersonas, TAM);
                break;

            case 5:
                seguir = 'n';
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
