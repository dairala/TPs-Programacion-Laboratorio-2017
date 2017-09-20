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

//void func_imprimeGrafico(ePersona* persona, int longitud)
//{
//   //int persona[].edad;
//   int i;
//   //int j;
//   //int max;
//
//   //max = 0;
//
//        for (i=0; i<longitud ; i++)
//        {
//            if(persona[i].edad < 19 )
//                {
//                    printf("*");
//                }
//                else
//                {
//                    printf("  ");
//                }
//
//        }
//
//        for (i=0; i<longitud ; i++)
//        {
//            if(persona[i].edad > 18 && persona[i].edad < 36)
//                {
//                    printf("*");
//                }
//                else
//                {
//                    printf("  ");
//                }
//       putchar('\n');
//        }
//
//                for (i=0; i<longitud ; i++)
//        {
//            if(persona[i].edad > 35)
//                {
//                    printf("*");
//                }
//                else
//                {
//                    printf("  ");
//                }
//       putchar('\n');
//        }
//        for (i = max; i > 0; i--)
//        {
//           for (j = 0; j < 5; j++)
//           {
//                if(persona[i].edad < 19 )
//                {
//                    printf("*");
//                }
//                else
//                {
//                    printf("  ");
//                }
//
//           }
//        }
//      putchar('\n');
//        }

//        for (i = 0; i < 5; i++)
//        {
//           if(persona[i].edad > 18 && persona[i].edad <36)
//           {
//
//           if (persona[i].edad > max)
//           {
//               max = persona[i].edad;
//           }
//        }
//        for (i = max; i > 0; i--)
//        {
//           for (j = 0; j < 5; j++)
//           {
//                if (persona[j].edad >= i)
//                {
//                    printf(" *");
//                }
//                else
//                {
//                    printf("  ");
//                }
//
//           }
//        }
//      putchar('\n');
//        }
//
//        for (i = 0; i < 5; i++)
//        {
//            if(persona[i].edad >36)
//            {
//           if (persona[i].edad > max)
//           {
//               max = persona[i].edad;
//           }
//        }
//        for (i = max; i > 0; i--)
//        {
//           for (j = 0; j < 5; j++)
//           {
//                if (persona[j].edad >= i)
//                {
//                    printf(" *");
//                }
//                else
//                {
//                    printf("  ");
//                }
//
//           }
//        }
//      putchar('\n');
//        }

void func_imprimeGrafico(ePersona* persona, int longitud, int index)
{

   //int persona[].edad = {1, 3, 9, 7, 5};
   int i;
   int j;
   int max;

   max = 0;
   for (i = index; i < longitud; i++)
   {
      if (persona[i].edad > max)
      {
          max = persona[i].edad;
      }
   }
   for (i = max; i > 0; i--)
    {
      for (j = index; j < longitud; j++)
         {
             if(persona[j].edad <19)
             {
             if (persona[j].edad < i)
             {
                 printf(" *");
             }
             else
               {
                   printf("  ");
               }
             }
         }

      putchar('\n');
    }

}
