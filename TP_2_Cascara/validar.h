
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
