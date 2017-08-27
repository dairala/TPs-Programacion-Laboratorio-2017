

#include "Calculos.h"


int calculos(float* resultado, float num1, float num2, char operacion)
{
    int retorno = -1;
    float fact=1.00;
    float aux;
    switch(operacion)
    {
        case SUMA:
            *resultado=num1+num2;
            retorno = 0;
            break;
        case RESTA:
            *resultado=num1-num2;
            retorno = 0;
            break;
        case MULTIPLICACION:
            *resultado=num1*num2;
            retorno = 0;
            break;
        case DIVISION:
            if(num2 != 0)
                {
                   *resultado = num1/num2;
                   retorno = 0;
                }
            break;
        case FACTORIAL:
            for(aux=num1;aux>1;aux--)
            {
                *resultado=fact*aux;
                retorno=0;
            }
            break;
        default:
            retorno=-1;
    }
    return retorno=0;
}
