#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char  titulo[20];
    char  genero[20];
    int   duracion;
    char  descripcion[50];
    int   puntaje;
    char  linkImagen[120];
    int   idPelicula;
    int   idEstado;
}eMovie;

/**
 *  Carga Menu al inicio de la aplicacion
 */

char menu(void);


/**
 *  Agrega una pelicula al archivo binario
 *  @param listado de peliculas a ser mostradas
 *
 */
void alta(eMovie*);

/**
 *  Realiza un listado de Peliculas
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void listar(eMovie*);



void modificar(eMovie*);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
void baja(eMovie*);


/**
 *  Busca si hay lugar para agregar una pelicula
 *  @param listado de peliculas
 *  @return id correspondiente a ID si hay lugar vacio
 */
int buscarLibre(eMovie*);

void toString(eMovie*);
int guardarEnArchivo(eMovie *);
int cargarDesdeArchivo(eMovie *);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void crearHTML(eMovie *);




#endif // FUNCIONES_H_INCLUDED
