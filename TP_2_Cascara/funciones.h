#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[50];
    int edad;
    unsigned char estado;
    int dni;

}ePersona;
#endif // FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define LUGAR_LIBRE 0
#define LUGAR_OCUPADO 1
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int func_obtenerEspacioLibre(ePersona* persona, int longitud);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int func_buscarPorDni(ePersona* persona, int dni, int longitud);
int func_cargarPersona (ePersona* persona, int index);
int func_initPersona (ePersona* persona, int longitud);
int func_printPersona (ePersona* persona, int longitud);
void func_eliminarPersona(ePersona* persona, int longitud, int index);
void func_imprimeGrafico(ePersona* persona, int longitud, int index);
//FUNCIONES_H_INCLUDED
