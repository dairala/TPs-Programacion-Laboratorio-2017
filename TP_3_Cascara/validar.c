#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "validar.h"

#define MAX_INPUT 1000

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}
/**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}


/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo n�meros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{

    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar� el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }

}

int getNumerosChar (char array[],char mensaje[])
{
    fflush( stdin );
    int retorno=0;
    getString(mensaje,array);
    if(esNumeroChar(array))
    {
        retorno= 1;
    }
    return retorno;
}

int esNumeroChar (char num[])
{
    int i=0;
    while(num[i]!='\0')
    {
        if(num[i] < '0' || num[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}


void myFgets(char* buffer, int limite ,FILE* archivo)
{
    int i=0;
    fgets(buffer, limite ,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}
int val_getNombre(char* destino, char* msj,char* msjError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT)
    {
        printf(msj);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarNombre(buffer) == -1)
            {
                printf(msjError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int val_validarNombre(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z'))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

int val_getFloat(char* destino, char* msj,char* msjError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT)
    {
        printf(msj);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarFloat(buffer) == -1)
            {
                printf(msjError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int val_validarFloat(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] == '-')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

int val_getDireccion(char* destino, char* msj,char* msjError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT)
    {
        printf(msj);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarDireccion(buffer) == -1)
            {
                printf(msjError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int val_validarDireccion(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z'))
        {
            if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i]!=32)
            {
                retorno = -1;
                break;
            }
        }
     i++;
    }
    return retorno;
}

int val_getLink(char* destino, char* msj,char* msjError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT)
    {
        printf(msj);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarLink(buffer) == -1)
            {
                printf(msjError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int val_validarLink(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {

        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z'))
        {
            if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i]!=32)
            {
                if(*buffer+i=='w')
                {
                    retorno = -1;
                    break;
                }
            }
        }
     i++;
    }
    return retorno;
}
void getText(char* mensaje,char* cadenaCaracteres,int cantidadCaracteres)
{
    if(cantidadCaracteres==21)
    {
        fflush(stdin);
        printf("%s",mensaje);
        scanf("%21[^\n]",cadenaCaracteres);
    }
    else if(cantidadCaracteres==51)
    {
        fflush(stdin);
        printf("%s",mensaje);
        scanf("%51[^\n]",cadenaCaracteres);
    }
    else if(cantidadCaracteres==101)
    {
        fflush(stdin);
        printf("%s",mensaje);
        scanf("%101[^\n]",cadenaCaracteres);
    }
    else if(cantidadCaracteres==201)
    {
        fflush(stdin);
        printf("%s",mensaje);
        scanf("%101[^\n]",cadenaCaracteres);
    }

}
