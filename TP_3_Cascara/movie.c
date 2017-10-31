#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "movie.h"
#include "validar.h"

#define  LONG_PELICULA 100

int cantidadPelisTotal=100;
void cargarDatos(EMovie* movie)
{
    getString("Ingrese el Titulo de la pelicula:",movie->titulo);
    getString("Ingrese el Genero:",movie->genero);
    movie->duracion=getInt("Ingrese duracion de la pelicula:");
    getString("Ingrese una descripcion:",movie->descripcion);
    movie->puntaje=getInt("Ingrese un puntaje para la pelicula:");
    getString("Ingrese el link de la imagen:",movie->linkImagen);
}



/** \brief Guarda una struct al final de un archivo binario bin.dat
 * \param struct S_Person* p puntero a struct a ser escrita
 * \return 0: error, 1:OK
 */
int guardarPelicula(EMovie* movie)
{
    int cantidadMovie=0;
    FILE* FileBin;
    FileBin=fopen("movie.txt","ab+"); // append binario, lo crea si no existe
    if(FileBin==NULL)
    {
        printf("Error al abrir el archivo");
        exit (1);
    }
    fwrite(movie,sizeof(EMovie),1,FileBin); // escribo una struct al final
    cantidadMovie+=fread(movie, sizeof(EMovie),1, FileBin);
    //fclose(FileBin);

    if (cantidadMovie < 1)
    {
        printf("\nError al escribir el archivo");
    }
        fclose(FileBin);
        return cantidadMovie;
}


void modificarBorrar( FILE *FileBin, EMovie movie )
{
	int opc=0, ok, ch;

	do{
		limpiar( );

		dibujo();
		printf( "\n %-30s", "Titulo");
		printf( "\n %-30s", movie.titulo);
		dibujo();

		printf( "\n\n ========== Modificar/borrar pelicula ==========\n"
					"\n 1 - Modificar"
					"\n 2 - Borrar"
					"\n 3 - Continuar"
					"\n\n ingrese opcion.....:" );

			ok = scanf( "%d", &opc ) == 1 && opc > 0 && opc <= 3;
			while ((ch = getchar()) != EOF && ch != '\n');
		}while( !ok );


		switch ( opc ){
			case 1: ;
				break;
			case 2: ;
				break;
			case 3: break;
		}
}


void limpiar( void )
{
	system("cls||clear");
}

void dibujo( void )
{
	int con = 0;
	printf( "\n" );
	while( con <= 75 )
    {
		printf( "-" ); con++;
	}
}

void rewind(FILE *FileBin)
{
    rewind(FileBin);
}

int func_obtenerEspacioLibrePelicula(EMovie* movie, int longitud)
{
    int retorno = -1;
    int i;
    if(movie != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(movie[i].estado == LUGAR_LIBRE)
            {
                //movie[i].id = movie[i+1]
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

//int func_cargarPelicula (EMovie* movie,int*  cantidadPelis , int index)
//{
//    int retorno = -1;
//    char bTitulo[51];
//    char bGenero[51];
//    char bDescripcion[51];
//    char bPuntaje[51];
//    char bDuracion[51];
//    char bLink[51];
//    char buffer[51];
//
//    if(movie != NULL && index >= 0)
//    {
//        if(val_getFloat(buffer,"","",3,51)==0)
//        {
//            if(val_getNombre(bTitulo,"\n Ingrese Titulo de la pelicula\n","\nError: Ingrese un titulo valido\n",3,15)==0)
//            {
//                if(val_getNombre(bGenero,"\n Ingrese el Genero \n","\nError: Ingrese un Genero valido\n",3,10)==0)
//                {
//                    if(val_getNombre(bDescripcion,"\n Ingrese una Descripcion de la Pelicula\n","\nError ingrese una descripcion valido:\n",3,51)==0)
//                    {
//                        if(val_getFloat(bDuracion,"\n Ingrese Duracion de la pelicula\n","\nError ingrese una Duracion valido:\n",3,10)==0)
//                        {
//                            if(val_getFloat(bPuntaje,"\n Ingrese Puntaje (1-9)\n","\nError ingrese un puntaje valido:\n",3,10)==0)
//                            {
//                                if(val_getLink(bLink,"\n Ingrese Link de la imagen\n","\nError ingrese un Link valido:\n",3,30)==0)
//                                {
//
//                                    strncpy(movie[index].titulo,bTitulo,15);
//                                    strncpy(movie[index].genero,bGenero,10);
//                                    strncpy(movie[index].descripcion,bDescripcion,10);
//                                    movie[index].duracion = atoi(bDuracion);
//                                    movie[index].puntaje = atoi(bPuntaje);
//                                    strncpy(movie[index].linkImagen,bLink,51);
//                                    movie[index].estado = LUGAR_OCUPADO;
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    if(guardarPelicula(movie)!=0)
//    {
//        printf("Carga exitosa!!!");
//        *cantidadPelis=guardarPelicula(movie);
//        retorno=0;
//    }
//
//    limpiar();
//    return retorno;
//}

int func_initPelicula (EMovie* movie, int longitud)
{
    int retorno = -1;
    int i;
    if(movie != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            movie[i].estado = LUGAR_LIBRE;
        }

    }
    return retorno;
}

void func_printPelicula (EMovie* movie)
{
    EMovie auxiliar;
    int cantidadLeida;
    FILE *pfileBin;

    pfileBin = fopen("movie.txt","rb");

    //rewind(pfileBin);
        while(!feof(pfileBin))
    {
        cantidadLeida = fread(&auxiliar ,sizeof (EMovie), 1 , pfileBin );
        if( cantidadLeida == 1)
            printf("Titulo: %s - Genero: %s", auxiliar.titulo, auxiliar.genero) ;
    }
    fclose(pfileBin);

}

void func_eliminarPelicula(EMovie* movie, int longitud)
{
    FILE *pfileBin;
    int i;
    int elegir;
    pfileBin=fopen ( "movie.txt", "rb+" );
    char buffer[50]="Este es elarchivo";

        printf("\nElija la pelicula que desea borrar:\n");
        fprintf(pfileBin, buffer);
        for(i=0; i<LONG_PELICULA; i++)
        {
            if(movie[i].estado == LUGAR_OCUPADO)
            {
                //fprintf(pfileBin, buffer);
                printf("\n%d- Pelicula: %s\n",i+1,movie[i].titulo);
            }

        }
        scanf("%d",&elegir);
    for(i= elegir-1; i<longitud-1; i++)
    {
        movie[i]= movie[i+1];
    }
    longitud--;
    limpiar();
    printf("Se borro exitosamente la pelicula");
    guardarPelicula(movie);
}

int func_modificaPelicula (EMovie* movie, int longitud)
{
    int retorno = -1;
    char bTitulo[51];
    char bGenero[51];
    char bDescripcion[51];
    char bPuntaje[51];
    char bDuracion[51];
    char bLink[51];
    char seguir='s';
    int opcion;
    int elegir;
    int i;
    int cant;
    FILE *pfileBin;

    if ((pfileBin=fopen("movie.txt","rb"))==NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    for(i=0; i<longitud; i++)
        {
            if(movie[i].estado == LUGAR_OCUPADO)
            {
                //printf("\n%d- Pelicula: %s\n",i+1,movie[i].titulo);
            }

        }
    while(!feof(pfileBin))
    {
        cant=fread(movie,sizeof(EMovie),1,pfileBin);
        if(cant!=1)
        {
            if(feof(pfileBin))
                break;
            else if(movie[i].estado == LUGAR_OCUPADO)
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
            printf("\n%d- Pelicula\t%s - Genero\t%s",i+1,movie->titulo,movie->genero);
    }
            fclose(pfileBin);
            getch();


        printf("\nElija la pelicula que desea modificar:\n");

        scanf("%d",&elegir);
    printf("Usted esta por modificar el Titulo:%s\n\n",movie[elegir-1].titulo);
    printf("Desea seguir? s o n\n\n");
    scanf("%s",&seguir);
    if(movie != NULL && elegir >= 0)
    {
        while(seguir=='s' || seguir=='S')
        {
            printf("\n1- Modificar Titulo\n");
            printf("2- Modificar Genero\n");
            printf("3- Modificar Descripcion\n");
            printf("4- Modificar Duracion\n");
            printf("5- Modificar Puntaje\n");
            printf("6- Modificar Link de la imagen\n");
            printf("7- Salir\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                if(val_getNombre(bTitulo,"\n Ingrese Titulo de la pelicula\n","\nError: Ingrese un titulo valido\n",3,15)==0)
                {
                    strncpy(movie[elegir-1].titulo,bTitulo,15);
                }
                printf("Modificacion exitosa!!");
                break;
            case 2:
                if(val_getNombre(bGenero,"\n Ingrese el Genero \n","\nError: Ingrese un Genero valido\n",3,10)==0)
                {
                    strncpy(movie[elegir-1].genero,bGenero,10);
                }
                printf("Modificacion exitosa!!");
                break;
            case 3:
                if(val_getDireccion(bDescripcion,"\n Ingrese una Descripcion de la Pelicula\n","\nError ingrese una descripcion valido:\n",3,51)==0)
                {
                    strncpy(movie[elegir-1].descripcion,bDescripcion,10);
                }
                printf("Modificacion exitosa!!");
                break;
            case 4:
                if(val_getFloat(bDuracion,"\n Ingrese Duracion de la pelicula\n","\nError ingrese una Duracion valido:\n",3,1)==0)
                {
                    movie[elegir-1].duracion = atoi(bDuracion);
                }
                limpiar();
                printf("Modificacion exitosa!!");
                break;
            case 5:
                if(val_getFloat(bPuntaje,"\n Ingrese Puntaje (1-9)\n","\nError ingrese un puntaje valido:\n",3,1)==0)
                {
                    movie[elegir-1].puntaje = atoi(bPuntaje);
                }
                limpiar();
                printf("Modificacion exitosa!!");
                break;
            case 6:
                if(val_getLink(bLink,"\n Ingrese Link de la imagen\n","\nError ingrese un Link valido:\n",3,30)==0)
                {
                    strncpy(movie[elegir-1].linkImagen,bLink,51);
                }
                limpiar();
                printf("Modificacion exitosa!!");
                break;
            case 7:
                seguir='n';
                break;
            default:
                limpiar();
                printf("Error. Opcion incorrecta.");

            }
        }
    }
    fclose(pfileBin);
    getch();
    return retorno;
}

void func_agregaNombrArchivo (EMovie *movie)
{
    FILE *pfileBin;
    char nombre[20];
    printf("\nIngrese el nombre y ruta del archivo que desea abrir: ");
    gets(nombre);
    if((pfileBin=fopen( nombre ,"rb"))==NULL)
    {
        if((pfileBin=fopen( nombre ,"wb"))==NULL)
        {
            printf("\nEl archivo %s no puede ser abierto",nombre);
            exit (1);
        }
            fclose(pfileBin);
    }
}

int fseek ( FILE *archivo , long desplazamiento , int origen)
{

}

void continuar(void)
{
    printf("Presione cualquier tecla para continuar.");
    getch();
}

long ftell (FILE * archivo )
{

    FILE *pfileBin;
    long int cant;
    long int  retorno=0;

    if ((pfileBin=fopen("movie.txt","rb"))==NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
        fseek (pfileBin , 0L , SEEK_END ); //Se envía la posición al final del archivo
        cant=ftell (pfileBin);
        printf("\nEl archivo tiene %ld bytes",cant);
        fclose(pfileBin);
        getch();
        retorno=cant;
        return retorno;
}

void func_modificarDatosPelicula(EMovie* movie, int* cantidadPelis,int* longitud)
{
    if(*cantidadPelis==0)
    {
        printf("No se encuentran peliculas en la base de datos.");
        getch();
        return;
    }
    int i;
    int indice;
    char opcion;
    int intentos=3;
    do
    {

        printf("\nElija la pelicula que desea modificar:\n");
        for(i=0; i<*cantidadPelis; i++)
        {
            printf("\n%d- Pelicula: %s\n",i+1,movie[i+1].titulo);
        }
        indice=getInt("Opcion: ")-1;
        if(indice<(*(cantidadPelis)))
        {
            limpiar();
            printf("\nEsta a punto de modificar %s.\nPresione la tecla S para continuar:",(*(movie+indice)).titulo);
            opcion=getChar(" ");
        }
        else
        {
            printf("Opcion incorrecta, le quedan %d intentos. Desea reintentar? S/N  ",intentos-1);
            opcion=getChar(" ");
            intentos--;
            continue;
        }

        if(opcion=='s'|| opcion == 'S')
        {
            limpiar();
            opcion=getChar("Ingrese la opcion a modificar: \n\n1-Titulo. \n2-Genero. \n3-Duracion. \n4-Descripcion \n5-Puntaje \n6-Link de imagen\n");
            switch(opcion)
            {
            case '1':
                if(cargar_titulo(movie,indice))
                    printf("\nModificacion exitosa!");
                break;
            case '2':
                if(cargar_genero(movie,indice))
                    printf("\nModificacion exitosa!");
                break;
            case '3':
                if(cargar_duracion(movie,indice,"\nIngrese la duracion de la pelicula (minutos):\n","\nValor incorrecto."))
                    printf("\nModificacion exitosa!");
                break;
            case '4':
                if(cargar_descripcion(movie,indice))
                    printf("\nModificacion exitosa!");
                break;
            case '5':
                cargar_puntaje(movie,indice);
                break;
            case '6':
                if(cargar_link(movie,indice))
                    printf("\nModificacion exitosa!");
                break;
            default :
                printf("Error. Opcion incorrecta.");
                break;
            }
            for(i=0; i<=indice; i++)
                editFileMovie(movie,0);
                func_creaArchivo(movie,cantidadPelis);
                guardarPelicula(movie);
                //guardarPelicula(movie);
            // return retorno;
        }
    }
    while(intentos>0 && (opcion =='s'&& opcion =='S'));
}

void editFileMovie(EMovie* movie,int indice)
{
    FILE* pFileBin=NULL;
    pFileBin=fopen("movie.txt","r+b");
    if(pFileBin==NULL)
        printf("Error al intentar abrir el archivo.");
    else
    {
        pFileBin=fopen("movie.txt","ab");
        if(pFileBin==NULL)
        {
            printf("\nError, no se pudo acceder a la base de datos.");
            getch();
        }
        else
        {
            fseek(pFileBin,sizeof(EMovie)*indice,SEEK_SET);
            fwrite(((movie+indice)),sizeof(EMovie),1,pFileBin);
            fclose(pFileBin);
        }
    }
}

int cargar_descripcion(EMovie* movie, int index)
{
    char auxDescripcion[100];
    int cantidadCaracteres;
    int retorno=0;
    char seguir='n';

    do
    {
        getText("\nIngrese la descripcion(40 caracteres maximo):\n",auxDescripcion,41);
        if((cantidadCaracteres=strlen(auxDescripcion))<41)
        {
            strcpy(movie[index+1].descripcion,auxDescripcion);
            retorno=1;
        }
        else
        {
            seguir=getChar("Ingreso una descripcion mayor a 40  caracteres.\nDesea reintentar? s/n:\n");
        }
    }
    while(seguir=='s' && retorno ==0);
    return retorno;

}
int cargar_genero(EMovie* movie,int index)
{
    char auxGenero[52];
    int cantidadCaracteres;
    int retorno=0;
    char seguir='n';
    do
    {
        getText("\nIngrese el genero(maximo de 20 caracteres):\n",auxGenero,51);
        if((cantidadCaracteres=strlen(auxGenero))<51)
        {
            strcpy(movie[index+1].genero,auxGenero);
            retorno=1;
        }
        else
        {
            seguir=getChar("\nDesea reintentar? s/n:\n");
        }

    }
    while(retorno!=1 && (seguir!= 's' || seguir!= 'S'));

    return retorno;
}


/**
* \brief Solicita un array de caracteres numericos al usuario,lo valida y lo devuelve
* \param array de datos
* \param array auxiliar
* \param Es el mensaje a ser mostrado
* \param Es el mensaje de error a ser mostrado
* \return 1 si el texto contiene solo numeros
*/
int cargar_duracion (EMovie* movie,int index, char mensaje[],char mensajeError[])
{
    char seguir='s';
    int retorno=0;
    char auxDuracion[20];
    do
    {

        retorno=getNumerosChar(auxDuracion,mensaje);
        if(retorno==0 || (atoi(auxDuracion)<40) || (atoi(auxDuracion)>4000 ))
        {
            printf(mensajeError);
            retorno=0;
            seguir=getChar("Desea reintentar? s/n");
        }
        else
        {
            retorno = 1;
            movie[index+1].duracion=atoi(auxDuracion);
        }
    }
    while(retorno!=1 && seguir == 's');


    return retorno;
}

int cargar_link(EMovie* movie,int index)
{
    char auxLink[102];
    int cantidadCaracteres;
    int retorno=0;
    char seguir='n';
    do
    {
        getText("\nIngrese el link:\n",auxLink,101);
        if((cantidadCaracteres=strlen(auxLink))<101)
        {

            strcpy(movie[index+1].linkImagen,auxLink);
            retorno=1;
        }
        else
        {
            seguir=getChar("\nDesea reintentar? s/n:\n");
        }

    }
    while(retorno!=1 && (seguir!= 's' || seguir!= 'S'));

    return retorno;
}


int cargar_puntaje (EMovie* movie,int index)
{
    char seguir='s';
    int retorno=0;
    char auxPuntaje[20];
    do
    {

        retorno=getNumerosChar(auxPuntaje,"\nIngrese el puntaje de la pelicula(1-9):\n");
        if(retorno==0 || (atoi(auxPuntaje)<0) || (atoi(auxPuntaje)>9 ))
        {
            printf("Valor incorrecto.");
            retorno=0;
            seguir=getChar("Desea reintentar? s/n");
        }
        else
        {
            retorno = 1;
            movie[index+1].puntaje=atoi(auxPuntaje);
        }
    }
    while(retorno!=1 && seguir == 's');


    return retorno;
}


int cargar_titulo(EMovie* movie,int index)
{
    char auxTitulo[22];
    int cantidadCaracteres;
    int retorno=0;
    char seguir='n';
    do
    {
        getText("\nIngrese el titulo(20 caracteres 20):\n",auxTitulo,21);
        if((cantidadCaracteres=strlen(auxTitulo))<21)
        {
            strcpy(movie[index+1].titulo,auxTitulo);
            retorno=1;
        }
        else
        {
            seguir=getChar("\nDesea reintentar? s/n:\n");
        }

    }
    while(retorno!=1 && (seguir!= 's' || seguir!= 'S'));

    return retorno;
}

int func_agregaPelicula(EMovie* movie,int* cantidadPelis, int* longitud)
{
    int retorno;
    retorno=cargar_titulo(movie,*cantidadPelis);
    if(retorno)
        retorno=cargar_duracion(movie,*cantidadPelis,"\nIngrese duracion de la pelicula en minutos:\n","\nValor incorrecto.");
    if(retorno)
        retorno=cargar_genero(movie,*cantidadPelis);
    if(retorno)
        retorno=cargar_link(movie,*cantidadPelis);
    if(retorno)
        retorno=cargar_puntaje(movie,*cantidadPelis);
    if(retorno)
        retorno=cargar_descripcion(movie,*cantidadPelis);
        *cantidadPelis=guardarPelicula(movie);
    return retorno;
}

void func_cargarPelicula(EMovie* movie,int* cantidadPelis, int* longitud)
{
    if(func_agregaPelicula(movie,cantidadPelis,longitud))
    {
        guardarPelicula(movie);
        printf("\nCarga Exitosa!!\n\n");
        (*cantidadPelis)++;
        continuar();
    }
}

void func_borrarPelicula(EMovie* movie, int* cantidadPelis,int* longitud)
{
    if(*cantidadPelis==0)
    {
        printf("No se encuentran peliculas");
        getch();
        return;
    }

    char opcion;
    int i;
    int intentos=3;
    int indice;

    do
    {
        printf("\nElija la pelicula que desea borrar:\n");
        for(i=0; i<*cantidadPelis; i++)
        {
            printf("\n%d- Pelicula: %s\n",i+1,movie[i+1].titulo);
        }
        indice=getInt("Opcion: ");
        if(indice<(*(cantidadPelis)) && indice>0)
        {
            limpiar();
            printf("\nEsta a punto de borrar %s.\nPresione la tecla S para continuar:",movie[indice+1].titulo);
            opcion=getChar(" ");

        }
        else
        {
            printf("Opcion incorrecta, le quedan %d intentos. Desea reintentar? S/N  ",intentos-1);
            opcion=getChar(" ");
            intentos--;
            limpiar();
            continue;
        }

        //crearPisarArchivoBinario(movie,cantidadPelis);
        //
        editFileMovie(movie,0);
        cantidadPelis--;
        func_comprimimeMovies(movie,cantidadPelis,indice, longitud);
        func_creaArchivo(movie,cantidadPelis);
        //guardarPelicula(movie);
        opcion='n';
    }
    while(intentos>0 && (opcion=='s'|| opcion== 'S'));

    continuar();

    // return retorno;
}

void func_creaArchivo(EMovie* movie, int* cantidadPelis)
{
    int i;
    FILE* pFileBin=NULL;
    pFileBin=fopen("movie.txt","wb");
    for(i=0; i<*cantidadPelis; i++)
    {
        fwrite(movie+i,sizeof(EMovie),1,pFileBin);
    }
    fclose(pFileBin);
    pFileBin=fopen("movie.txt","wb");
    for(i=0; i<*cantidadPelis; i++)
    {
        fwrite(movie+i,sizeof(EMovie),1,pFileBin);
    }
    fclose(pFileBin);
}

void func_comprimimeMovies(EMovie* movie,int* cantidadPelis, int indiceMovieborrada,int* longitud)
{
    //int i=0;
    EMovie auxLista[*longitud];

    auxLista[*longitud]=(movie[indiceMovieborrada]);
    movie[indiceMovieborrada]=(movie[*cantidadPelis-1]);
    movie[*cantidadPelis-1]=auxLista[*longitud];
    (*cantidadPelis)--;

    //i=((*longitud)-1);
    while((longitud-cantidadPelis)>10)
    {
        //free(*(movie+i));
        (*longitud)--;
    }
}
