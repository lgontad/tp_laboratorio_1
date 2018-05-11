
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    long int dni;
    int estado;

}ePersonas;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersonas listadoPersonas[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersonas lista[],int, long int);

/** Funcion de Carga de Personas
 *
 * \param estructura personas
 * \param cantidad maxima de personas
 *
 */

void cargarPersona(ePersonas[], int);

/** Muestra el listado de Personas cargadas
 *
 * \param Estructura con listado de personas
 * \param cantidad de personas
 */

void mostrarListadoPersonas (ePersonas[], int );

/** Ordena las personas por nombre
 *
 * \param listado de personas
 * \param cantidad de personas
 * \return
 *
 */

void ordenarPersonas (ePersonas[], int );

void mostrarGrafico (ePersonas[], int );


