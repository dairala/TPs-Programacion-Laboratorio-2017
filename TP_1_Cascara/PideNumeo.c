#include <stdio.h>
#include <stdlib.h>
#include "PideNumero.h"


     int pedirNumero(char msg[],float* x, float maximo, float minimo)
     {
         float aux;
         printf("%s\n",msg);
         scanf("%f",&aux);
         if(aux<maximo && aux>minimo)
         {
             *x=aux;
             return 0;
         }
         return -1;
     }
