#include <stdio.h>
#include <stdlib.h>
#include "movie.h"

#define  LONG_PELICULA 100

int main()
{

    EMovie movie[LONG_PELICULA];
    char seguir='s';
    int opcion=0;
    int cantidadPelis=0;
    int cantidadPelisTotal=100;
    func_obtenerEspacioLibrePelicula(movie,LONG_PELICULA);

    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                func_cargarPelicula(movie, &cantidadPelis, &cantidadPelisTotal);
                break;
            case 2:
                func_modificarDatosPelicula(movie,&cantidadPelis,&cantidadPelisTotal);
                break;
            case 3:
                func_borrarPelicula(movie, &cantidadPelis, &cantidadPelisTotal);
               break;
            case 4:
                func_printPelicula(movie);
                break;
            case 5:
                seguir = 'n';
                break;
        }
        limpiar();
    }

    return 0;
}


