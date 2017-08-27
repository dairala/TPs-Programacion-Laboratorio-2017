#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "PideNumero.h"
#include "Calculos.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float a;
    float b;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    int facto=1;
    int p;
    int q;

    while(seguir=='s')
    {

        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la Suma (A+B)\n");
        printf("4- Calcular la Resta (A-B)\n");
        printf("5- Calcular la Division (A/B)\n");
        printf("6- Calcular la Multiplicacion (A*B)\n");
        printf("7- Calcular el Factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("1- Ingrese primer numero (A=x)\n");
                if(pedirNumero("Ingrese un numero",&a,100,0)==-1)
                {
                  printf("Error, fuera de rango");
                }
                printf("El numero x es: %.2f\n",a);
                break;
            case 2:
                fflush(stdin);
                printf("2- Ingrese segundo numero (B=y)\n");
                if(pedirNumero("Ingrese un numero",&b,100,0)==-1)
                {
                  printf("Error, fuera de rango");
                }
                printf("El numero y es: %.2f\n",b);
                break;
            case 3:
                fflush(stdin);
                printf("3- Calcular la suma (A+B)\n");
                if(pedirNumero("Ingrese primer numero (A)",&a,100,0)==-1)
                {
                  printf("Error, fuera de rango");
                }
                if(pedirNumero("Ingrese segundo numero (B)",&b,100,0)==-1)
                {
                  printf("Error, fuera de rango");
                }
                calculos(&suma,a,b,SUMA);
                printf("La suma de A + B es: %.2f\n",suma);
                break;
            case 4:
                fflush(stdin);
                printf("4- Calcular la resta (A-B)\n");
                if(pedirNumero("Ingrese primer numero (A)",&a,100,0)==-1)
                {
                  printf("Error, fuera de rango");
                }
                if(pedirNumero("Ingrese segundo numero (B)",&b,100,0)==-1)
                {
                  printf("Error, fuera de rango");
                }
                calculos(&resta,a,b,RESTA);
                printf("La resta de A - B es: %.2f\n",resta);
                break;
            case 5:
                fflush(stdin);
                printf("5- Calcular la Division (A/B)\n");
                if(pedirNumero("Ingrese primer numero (A)",&a,100,0)==-1)
                {
                  printf("Error, fuera de rango");
                }
                if(pedirNumero("Ingrese segundo numero (B)",&b,100,0)==-1)
                {
                  printf("Error, fuera de rango");
                }
                calculos(&division,a,b,DIVISION);
                printf("La division de A y B es: %.2f\n",division);
                break;
            case 6:
                fflush(stdin);
                printf("6- Calcular la multiplicacion (A*B)\n");
                if(pedirNumero("Ingrese primer numero (A)",&a,100,0)==-1)
                {
                  printf("Error, fuera de rango");
                }
                if(pedirNumero("Ingrese segundo numero (B)",&b,100,0)==-1)
                {
                  printf("Error, fuera de rango");
                }
                calculos(&multiplicacion,a,b,MULTIPLICACION);
                printf("La multiplicacion de A y B es: %.2f\n",multiplicacion);
                break;
            case 7:
                printf("7- Calcular el factorial (A!)\n");
                printf("Ingrese un numero para calcular su factorial\n");
                scanf("%d",&p);
                for(q=p;q>1;q--)
                {
                    facto=facto*q;
                }
                printf("El Factorial de %d=%d\n",p,facto);
                break;
            case 8:
                fflush(stdin);
                printf("8- Calcular todas las operacione\n");
                if(pedirNumero("Ingrese primer numero (A)",&a,100,0)==-1)
                {
                  printf("Error, fuera de rango");
                }
                if(pedirNumero("Ingrese segundo numero (B)",&b,100,0)==-1)
                {
                  printf("Error, fuera de rango");
                }
                printf("Ingrese un numero para calcular su factorial\n");
                scanf("%d",&p);
                for(q=p;q>1;q--)
                {
                    facto=facto*q;
                }
                calculos(&suma,a,b,SUMA);
                calculos(&resta,a,b,RESTA);
                calculos(&division,a,b,DIVISION);
                calculos(&multiplicacion,a,b,MULTIPLICACION);

                printf("El factorial de:%d=%d\n", p, facto);
                printf("El resultado de la suma entre A y B es: %.2f\n",suma);
                printf("El resultado de la resta entre A y B es: %.2f\n",resta);
                printf("El resultado de la division entre A y B es: %.2f\n",division);
                printf("El resultado de la multiplicacion entre A y B es: %.2f\n",multiplicacion);
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                return 0;
        }
        return 0;
}
return 0;
}
