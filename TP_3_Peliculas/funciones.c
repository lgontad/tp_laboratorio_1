#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define M 5

char menu()
{       char c;
	system("cls");
	printf("MENU\n1. ALTA\n2. LISTAR\n3. BAJA\n4. MODIFICAR\n5. GENERAR PAGINA WEB\n6. SALIR\n");
	printf("Elija una opcion: ");
	c=getche();
	return c;
}

int buscarLibre(eMovie peliculas[])
{
	int index=-1;
	int i;
	for( i=0; i < M; i++)
	   if(peliculas[i].idPelicula==0){
		index=i;
		break;
	   }
	return index;
}

void alta(eMovie peliculas[])
{
	int index, i;
	int id;
	int dur;
	int encontro=0;
	int puntos;
	/*Buscamos cual es el primer indice libre dentro del array*/
	index=buscarLibre(peliculas);
	if(index!=-1)//si hay lugar:
	{

		printf("INGRESO DE DATOS:\n");
		printf("Ingrese ID: ");
		scanf("%d", &id);
		/*Buscamos si el legajo ya existe*/
		for(i=0; i<M; i++)
		{
			if(id==peliculas[i].idPelicula)
			{
				encontro=1;//encontro en true
				break;
			}
		}
		if(!encontro)//entra si encontro==0
		{
			peliculas[index].idPelicula=id;
			printf("Ingrese Titulo: ");
			fflush(stdin);
			gets(peliculas[index].titulo);
			printf("Ingrese Genero: ");
			fflush(stdin);
			gets(peliculas[index].genero);
			printf("Ingrese Duracion (minutos): ");
			scanf("%d", &dur);
			peliculas[index].duracion=dur;
			printf("Ingrese Descripcion: ");
			fflush(stdin);
			gets(peliculas[index].descripcion);
			printf("Ingrese Puntaje ( 0 a 10 ): ");
			scanf("%d", &puntos);
			peliculas[index].puntaje=puntos;
			printf("Ingrese Link de la Imagen: ");
			fflush(stdin);
            gets(peliculas[index].linkImagen);
			system("cls");
		}
		else
		{
			printf("��El ID ingresado ya Existe!!");
			getch();
		}
	}
	else
	{
		printf("No queda espacio");
		getch();
	}
}

void toString(eMovie* unaMovie)
{
	printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%d\t\t%s\n",unaMovie->idPelicula, unaMovie->titulo, unaMovie->genero, unaMovie->duracion, unaMovie->descripcion, unaMovie->puntaje, unaMovie->linkImagen);
}

void listar(eMovie *peliculas)
{
	int i,j;
	eMovie auxMovie;

	for(i=0; i<M-1;i++)
	{
		for(j=i+1; j<M; j++)
		{
			if(strcmp(peliculas[i].titulo,peliculas[j].titulo)>0)
			{
				auxMovie=peliculas[i];
				peliculas[i]=peliculas[j];
				peliculas[j]=auxMovie;
			}
		}
	}

	printf("\ID\tTitulo\tGenero\tDuracion\t\tDescripcion\tPuntaje\tLinkImagen\n");
	for(i=0; i<M; i++)
	{
		if(peliculas[i].idPelicula!=0)
		   toString((peliculas + i));

	}
	getch();
}
void baja(eMovie* peliculas)
{
	int id, flag=0,i;
	char opcion;
	printf("Ingrese Id a dar de baja: ");
	scanf("%d", &id);
	for(i=0; i<M; i++)
	{
		if(id==peliculas[i].idPelicula)
		{
			printf("Datos a eliminar:\n");

			toString((peliculas + i));

			printf("\nID encontrado. �Seguro desea dar de baja?");
			opcion=getche();
			if(opcion=='s')
			{
				peliculas[i].idPelicula=0;
				printf("��Registro eliminado!!");
			}
			else
			{
				printf("El registro no fue eliminado!");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("ID inexistente");
		getch();
	}
}
void modificar(eMovie* peliculas)
{
	int id, puntos, flag=0,i;
	char opcion;
	system("cls");
	printf("Ingrese el Id de la Pelicula a modificar: ");
	scanf("%d",&id);
	for( i=0; i<M; i++)
	{
		if(id==peliculas[i].idPelicula)
		{
			printf("Datos encontrados:\n");

			toString((peliculas + i));

			printf("\nIngrese el nuevo Puntaje: ");
			scanf("%f", &puntos);
			printf("Esta seguro que desea modificar? ");
			opcion=getche();
			if(opcion=='s')
			{
				peliculas[i].puntaje=puntos;
				printf("Registro modificado");
			}
			else
			{
				printf("El registro no fue modificado");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("ID inexistente");
		getch();
	}
}
void mayorPuntaje(eMovie* peliculas)
{
	int i, flag=0;
	float maxPuntaje;
	for(i=0; i<M; i++)
	{
		if(peliculas[i].idPelicula!=0)
		  if(flag==0 || peliculas[i].puntaje>maxPuntaje)
		  {
			maxPuntaje=peliculas[i].puntaje;
			flag=1;
		  }
	}
	printf("El o las Peliculas con mayor puntaje (%d) son:\n", maxPuntaje);
	for(i=0; i<M; i++)
	{
		if(peliculas[i].idPelicula!=0)
		  if(peliculas[i].puntaje==maxPuntaje)
		  {

			toString((peliculas + i));
		  }
	}
	getch();
}

int guardarEnArchivo(eMovie * x)
{

	FILE *f;

		f=fopen("Peliculas.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(x,sizeof(eMovie),M,f);

	fclose(f);

	return 0;
}

int cargarDesdeArchivo(eMovie *x)
{
	int flag = 0;
	FILE *f;

	f=fopen("Peliculas.dat", "rb");
	if(f==NULL)
	{
		f= fopen("Peliculas.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	fread(x,sizeof(eMovie),M,f);
    }

	fclose(f);
	return 0;

}

/*void crearHTML(eMovie *x)
{
    int i;
    FILE *f;
    char encabezado[50]="Listado De Peliculas";
    char buffer[1080]= {}; //="<html><body><MARQUEE><h1>Hola a todos</h1></MARQUEE></body></html>";

    strcat(buffer,"<html><head><style>table, th, td {border: 1px solid"
            "black; border-collapse: collapse;}th, td { padding: 15px;}"
           "</style> </head><body><MARQUEE BGCOLOR=#7070ff><h1>");

    strcat(buffer,encabezado);

    strcat(buffer,"</h1></MARQUEE><br><br>");
    strcat(buffer,"<article class='col-md-4 article-intro'> "
       "<a href='#'> <img class='img-responsive img-rounded' src='x[i].Genero' alt=''> "
               "</a>"
               "<h3>"
                    "<a href='#'>Back to the future</a> "
               "</h3>"
                "<ul>"
                    "<li>G�nero:Aventura</li>"
                    "<li>Puntaje:86</li>"
                    "<li>Duraci�n:116</li>"
                    "</ul>"
                "<p>A young man is accidentally sent thirty years into the past in a time-traveling DeLorean invented by his friend, Dr. Emmett Brown, and must make sure his high-school-age parents unite in order to save his own existence.</p>"
                "</article>"
           "</body></html>");


     f=fopen("Lista de Peliculas.html", "w");

     if(f == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
         fprintf(f,"Listado de Peliculas\n\n\n");
         fprintf(f,"Titulo    Genero     Puntaje \n");

         for(i=0; i<M; i++)
         {
                  if(x[i].idPelicula != 0)
                  {
                  fprintf(f,"%d\t%s\t\%s\t\%d\t\%s\t\%d\t\%s\n",x[i].idPelicula, x[i].titulo, x[i].genero,x[i].duracion, x[i].descripcion,x[i].puntaje, x[i].linkImagen);
                  }
         }
      }

      fclose(f);

      printf("Listado creado con exito\n");
      system("pause");
}*/


   /* fprintf(archivo,buffer);

    fclose(archivo);
    return 0;*/
