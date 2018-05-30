
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "Funciones.h"

#define M 5

int main()
{
	eMovie movies[M];
	char seguir='s';
	char guardar= 's';
	int i;

		for( i=0; i<M; i++)
		movies[i].idPelicula=0;

	if(cargarDesdeArchivo(movies))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}

	system("pause");


	system("cls");
	do
	{
		switch(menu())
		{
			case '1':
				system("cls");
				alta(movies);
				break;
			case '2':
				system("cls");
				listar(movies);
				break;
			case '3':
				system("cls");
				baja(movies);
				break;
			case '4':
				system("cls");
				modificar(movies);
				break;
			/*case '5':
				system("cls");
				crearHTML(movies);
				break;*/
			case '6':

				printf("\nGuardar cambios S/N ?: ");
				guardar = tolower(getche());

				if(guardar == 's')
				{
					if(guardarEnArchivo(movies))
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
				}

				seguir='n';
				break;

		}
	}while(seguir=='s');
	printf("\n");
	system("pause");
}
