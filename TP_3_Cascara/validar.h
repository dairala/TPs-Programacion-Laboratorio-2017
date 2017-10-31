#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED



#endif // VALIDAR_H_INCLUDED

void myFgets(char* buffer, int limite ,FILE* archivo);
/**
 * Toma el dato y valida sacando el LF que windows pones antes de \0
 * @param lista el array se pasa como parametro.
 * @return no devuelve nada.
 */
int val_getNombre(char* destino, char* msj,char* msjError,int intentos,int limite);
/**
 * valida nombre la toma del nombre que este bien y imprime un mensaje de error si esta mal ingresado
 * @param Toma el buffer y lo vuelve a validar
 * @return no devuelve 0 si esta todo bien.
 */
int val_validarNombre(char* buffer);
/**
 * valida nombre
 * @param Toma el dato y lo guardo en un buffer.
 * @return no devuelve 0 si esta todo bien.
 */
int val_getFloat(char* destino, char* msj,char* msjError,int intentos,int limite);
/**
 * valida float la toma del float que este bien y imprime un mensaje de error si esta mal ingresado
 * @param Toma el buffer y lo vuelve a validar
 * @return no devuelve 0 si esta todo bien.
 */
int val_validarFloat(char* buffer);
/**
 * valida el float
 * @param Toma el dato y lo guardo en un buffer.
 * @return no devuelve 0 si esta todo bien.
 */

int getInt();
float getFloat();
char getChar();

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);

void cleanStdin(void);
int getNumerosChar (char array[],char mensaje[]);
int esNumeroChar (char num[]);

void myFgets(char* buffer, int limite ,FILE* archivo);
int val_getNombre(char* destino, char* msj,char* msjError,int intentos,int limite);
int val_validarNombre(char* buffer);
int val_getFloat(char* destino, char* msj,char* msjError,int intentos,int limite);
int val_validarFloat(char* buffer);
int val_getDireccion(char* destino, char* msj,char* msjError,int intentos,int limite);
int val_validarDireccion(char* buffer);
int val_getLink(char* destino, char* msj,char* msjError,int intentos,int limite);
int val_validarLink(char* buffer);
void getText(char* mensaje,char* cadenaCaracteres,int cantidadCaracteres);

