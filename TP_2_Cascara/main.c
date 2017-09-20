#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    ePersona persona[20];
    int index;
    func_initPersona(persona,20);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                func_cargarPersona(persona,func_obtenerEspacioLibre(persona,20));
                break;
            case 2:
                printf("\nIngrese DNI de la persona a eliminar:\n ");
                scanf("%d", &index);
                func_eliminarPersona(persona, 20, func_buscarPorDni(persona,index,20));
                break;
            case 3:
                func_printPersona(persona,20);
                break;
            case 4:
                func_imprimeGrafico (persona,20,func_obtenerEspacioLibre(persona));
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
