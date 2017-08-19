#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

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
    int factorial=1;
    int p;
    int q;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("1- Ingresar 1er operando (A=x)\n");
                scanf("%f",&a);
                printf("El numero x es: %.2f\n",a);
                break;
            case 2:
                fflush(stdin);
                printf("2- Ingresar 2do operando (B=y)\n");
                scanf("%f",&b);
                printf("El numero y es: %.2f\n",b);
                break;
            case 3:
                fflush(stdin);
                printf("3- Calcular la suma (A+B)\n");
                printf("Ingresar 1er operando (A)\n");
                scanf("%f",&a);
                printf("El numero x es: %.2f\n",a);
                printf("Ingresar 2do operando (B)\n");
                scanf("%f",&b);
                printf("El numero y es: %.2f\n",b);
                suma=a+b;
                printf("La suma de A + B es: %.2f\n",suma);
                break;
            case 4:
                fflush(stdin);
                printf("4- Calcular la resta (A-B)\n");
                printf("Ingresar 1er operando (A)\n");
                scanf("%f",&a);
                printf("El numero x es: %.2f\n",a);
                printf("Ingresar 2do operando (B)\n");
                scanf("%f",&b);
                printf("El numero y es: %.2f\n",b);
                resta=a-b;
                printf("La resta de A y B es: %.2f\n",resta);
                break;
            case 5:
                fflush(stdin);
                printf("5- Calcular la division (A/B)\n");
                printf("Ingresar 1er operando (A)\n");
                scanf("%f",&a);
                printf("El numero x es: %.2f\n",a);
                printf("Ingresar 2do operando (B)\n");
                scanf("%f",&b);
                printf("El numero y es: %.2f\n",b);
                division=a/b;
                printf("La division de A y B es: %.2f\n",division);
                break;
            case 6:
                fflush(stdin);
                printf("6- Calcular la multiplicacion (A*B)\n");
                printf("Ingresar 1er operando (A)\n");
                scanf("%f",&a);
                printf("El numero x es: %.2f\n",a);
                printf("Ingresar 2do operando (B)\n");
                scanf("%f",&b);
                printf("El numero y es: %.2f\n",b);
                multiplicacion=a*b;
                printf("La multiplicacion de A y B es: %.2f\n",multiplicacion);
                break;
            case 7:
                fflush(stdin);
                printf("7- Calcular el factorial (A!)\n");
                printf("Ingresar numero para calcular su factorial (A)\n");
                scanf("%d",&p);
                for (q=p;q>1;q--){
                    factorial = factorial*q;
                }
                printf("El factorial de:%d=%d\n", p, factorial);
                break;
            case 8:
                fflush(stdin);
                printf("8- Calcular todas las operacione\n");
                printf("Ingresar 1er operando (A)\n");
                scanf("%f",&a);
                printf("El numero A es: %.2f\n",a);
                printf("Ingresar 2do operando (B)\n");
                scanf("%f",&b);
                printf("El numero B es: %.2f\n",b);
                printf("Ingresar numero para calcular su factorial (C)\n");
                scanf("%d",&p);
                suma=a+b;
                resta=a-b;
                division=a/b;
                multiplicacion=a*b;
                for (q=p;q>1;q--){
                        factorial = factorial*q;
                }
                printf("El factorial de:%d=%d\n", p, factorial);
                printf("El resultado de la suma entre A y B es: %.2f\n",suma);
                printf("El resultado de la resta entre A y B es: %.2f\n",resta);
                printf("El resultado de la division entre A y B es: %.2f\n",division);
                printf("El resultado de la multiplicacion entre A y B es: %.2f\n",multiplicacion);
                break;
            case 9:
                seguir = 'n';
                break;
        }
        return 0;
}
}
