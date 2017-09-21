#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validar.h"

int func_obtenerEspacioLibre(ePersona* persona, int longitud)
{
    int retorno = -1;
    int i;
    if(persona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(persona[i].estado == LUGAR_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

int func_cargarPersona (ePersona* persona, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bEdad[51];
    char bDni[51];
    char buffer[51];

    if(persona != NULL && index >= 0)
    {
        if(val_getFloat(buffer,"","",3,51)==0)
        {
             if(val_getFloat(bEdad,"\n Ingrese Edad\n","\nError: Ingrese Edad valida\n",3,51)==0)
             {
                if(val_getFloat(bDni,"\n Ingrese DNI\n","\nError: Ingrese DNI valido\n",3,51)==0)
                {
                    if(val_getNombre(bNombre,"\n Ingrese Nombre\n","\nError ingrese un nombre valido:\n",3,51)==0)
                    {
                        strncpy(persona[index].nombre,bNombre,51);
                        persona[index].edad = atoi(bEdad);
                        persona[index].dni = atoi(bDni);
                        persona[index].estado = LUGAR_OCUPADO;
                    }
                }
             }
        }

    }
    return retorno;
}

int func_initPersona (ePersona* persona, int longitud)
{
    int retorno = -1;
    int i;
    if(persona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            persona[i].estado = LUGAR_LIBRE;
        }

    }
    return retorno;
}

int func_printPersona (ePersona* persona, int longitud)
{
    int retorno = -1;
    int i;
    if(persona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(persona[i].estado == LUGAR_OCUPADO)
            {
                printf("\nID: %d - Nombre: %s - Edad: %d - DNI: %d\n",i,persona[i].nombre,persona[i].edad,persona[i].dni);
            }
        }

    }
    return retorno;
}

void func_eliminarPersona(ePersona* persona, int longitud, int index)
{
    int i;

    for(i= index; i<longitud-1; i++)
    {
        persona[i]= persona[i+1];
    }
    longitud--;
}

int func_buscarPorDni(ePersona* persona, int dni, int longitud)
{
    int retorno = -1;
    int i;
    if(persona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(persona[i].dni == dni)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

int func_imprimeGrafico(ePersona* persona,int index, int longitud)
{
    int i;
    int menor18=0;
    int de19a35=0;
    int mayor35=0;
    int flag=0;
    int mayor;

    for(i=0; i<longitud ; i++)
    {
    if(persona[index].edad<=18)
    {
        menor18 ++;
    }
    else
    {
        if(persona[index].edad>18 && persona[index].edad<36)
        {
            de19a35 ++;
        }
        else
        {
            mayor35 ++;
        }
    }
    }
    if(menor18 >= de19a35 && menor18 >= mayor35)
    {
        mayor = menor18;
    }
    else
    {
        if(de19a35 >= menor18 && de19a35 >= mayor35)

            mayor = de19a35;

        else

            mayor = mayor35;

    }
    for(i=mayor;i>0;i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
        {
            printf("%02d|",i);
        }
        if(i<menor18)
        {
            printf("*");
        }
        if(i<=de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<=mayor35)
        {
            if(flag==0)

                printf("\t\t*");



                if(flag==1)

                    printf("\t*");


        }
        printf("\n");
    }
    printf("--------------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n    %d\t%d\t%d\n",menor18, de19a35, mayor35);

   return 0;
}

int func_obtenerIndiceEdad(ePersona* persona, int longitud)
{
    int retorno = -1;
    int i;
    if(persona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(persona[i].estado == LUGAR_OCUPADO)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}
