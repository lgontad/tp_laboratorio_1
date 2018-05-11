#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int buscarLugarLibre(ePersonas listadoPersonas[], int tam)
{
    int indice = -1;
    for(int i=0;i<tam;i++){
        if(listadoPersonas[i].estado==0){
            indice=i;
            break;
        }
    }
    return indice;
}

void cargarPersona(ePersonas listadoPersonas[], int valor)
{
    fflush(stdin);
    printf("\nIngrese el Nombre: ");
    gets(listadoPersonas[valor].nombre);
    printf("Ingrese Edad: ");
    scanf("%d",&listadoPersonas[valor].edad);
    fflush(stdin);
    printf("Ingrese el Numero de Documento: ");
    scanf("%ld",&listadoPersonas[valor].dni);

    listadoPersonas[valor].estado = 1;
}

void mostrarListadoPersonas (ePersonas listadoPersonas[], int cantidad)
{
    int i;
    int flag= 0;

    for(i=0;i<cantidad;i++)
    {
        if(listadoPersonas[i].estado==1)
        {
            printf("\n%s  -  %ld  -  %d \n",listadoPersonas[i].nombre,listadoPersonas[i].dni,listadoPersonas[i].edad);
            flag = 1;
        }
    }
        if(flag == 0)
        {
            printf("\nNo hay registros cargados para mostrar\n");
        }
}

int buscarPorDni(ePersonas listadoPersonas[],int cantidad, long int dniIngresado)
{
int posicion= -1;

    for(int i=0;i<cantidad;i++){
        if(listadoPersonas[i].dni==dniIngresado){
            posicion = i;
        }
    }
return posicion;
}

void ordenarPersonas(ePersonas listadoPersonas[], int cantidad )
{
    ePersonas auxiliarPersonas[cantidad];

    for(int i=0; i<cantidad-1; i++)
    {

        for(int j=i+1; j<cantidad; j++)
        {
             if(listadoPersonas[i].estado == 1)
             {

                 if((strcmp(listadoPersonas[i].nombre,listadoPersonas[j].nombre))> 0)
                    {
                         auxiliarPersonas[i]= listadoPersonas[i];
                         listadoPersonas[i]=listadoPersonas[j];
                         listadoPersonas[j]=auxiliarPersonas[i];

                    }
             }
        }
    }
}


void mostrarGrafico(ePersonas listadoPersonas[],int tam)
{
    int m18=0;
    int hasta35=0;
    int mayor35=0;
    int i;
    int max=0;
    int flag=0;
    system("cls");
    for(i=0; i<tam; i++)
    {
      if(listadoPersonas[i].estado==1)
        {
         if(listadoPersonas[i].edad<=18)
            {
               m18++;
            }
            else
            {
              if(listadoPersonas[i].edad>35)
                {
                    mayor35++;
                }
                else
                {
                    hasta35++;
                }
            }
        }
    }
    if(m18 >= hasta35 && m18 >= mayor35)
    {
        max = m18;
    }
    else
    {
        if(mayor35 >= m18 && mayor35 >= hasta35)
        {
            max = mayor35;
        }
        else
        {
            max = hasta35;
        }
    }
    // dibujo ejes e imprimo asteriscos segun edad
    for(i=max; i>0; i--)
    {
        printf("%02d|",i);

        if(i<= m18)
        {
            printf("*");
        }
        if(i<= hasta35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayor35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n\n", m18, hasta35, mayor35);
    printf("Grafico para una estad¡stica de: \n%d personas con edad menor o igual a 18 años,\n%d personas con edades entre 18 y 35 años, \n%d personas con edades mayores a 35 años", m18, hasta35,mayor35);
}
