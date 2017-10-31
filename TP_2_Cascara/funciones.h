#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{
    char nombre[50];
    int edad;
    unsigned char estado;
    int dni;

}ePersona;
#endif // FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define LUGAR_LIBRE 0
#define LUGAR_OCUPADO 1

int func_obtenerEspacioLibre(ePersona* persona, int longitud);
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int func_buscarPorDni(ePersona* persona, int dni, int longitud);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int func_cargarPersona (ePersona* persona, int index);
/**
 * Carga los datos obtenidos en sus campos orrespondientes
 * @param lista el array se pasa como parametro.
 * @param se pasa indice de los lugaes libres para cargar y pone el flag en OCUPADO.
 * @return devuelve -1
 */
int func_initPersona (ePersona* persona, int longitud);
/**
 * Recorre todo el array inicializando el flag estado LUAR LIBRE
 * @param lista el array se pasa como parametro.
 * @param se pasa tamaño del array.
 * @return devuelve 1
 */
int func_printPersona (ePersona* persona, int longitud);
/**
 * Imprime lista ordenado por nombre delarray en donde el flag estado este OCUPADO
 * @param lista el array se pasa como parametro.
 * @param se pasa tamaño del array.
 * @return devuelve -1
 */
void func_eliminarPersona(ePersona* persona, int longitud, int index);
/**
 * Elimina persona por DNI
 * @param lista el array se pasa como parametro.
 * @param se pasa tamaño del array.
 * @param se pasa indice del DNI a eliminar.
 * @return no devuelve nada
 */
int func_imprimeGrafico(ePersona* persona,int index, int longitud);
/**
 * Imprime grafico por edades (menos a 18, de 19 a 35 y mayor a 35)
 * @param lista el array se pasa como parametro.
 * @param se pasa tamaño del array.
 * @param se pasa indice del indice del campo edad
 * @return devuelve un 0.
 */
int func_obtenerIndiceEdad(ePersona* persona, int longitud);
/**
 * Obtiene indice del campo edad
 * @param lista el array se pasa como parametro.
 * @param se pasa tamaño del array.
 * @return devuelve indeci de la edad.
 */
