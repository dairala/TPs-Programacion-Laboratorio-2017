#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    unsigned char estado;
}EMovie;
#endif // MOVIE_H_INCLUDED

#define LUGAR_LIBRE 0
#define LUGAR_OCUPADO 1

void cargarDatos(EMovie* movie);
int guardarPelicula(EMovie* movie);
void modificarBorrar( FILE *FileBin, EMovie movie );
void limpiar( void );
void dibujo( void );
void rewind(FILE *FileBin);
void continuar(void);

int func_obtenerEspacioLibrePelicula(EMovie* movie, int longitud);
//int func_cargarPelicula (EMovie* movie,int*  cantidadPelis , int index);
int func_initPelicula (EMovie* movie, int longitud);
void func_printPelicula (EMovie* movie);
void func_eliminarPelicula(EMovie* movie, int longitud);
int func_modificaPelicula (EMovie* movie, int longitud);

long ftell (FILE * archivo );

void func_modificarDatosPelicula(EMovie* movie, int* cantidadPelis,int* longitud);

void editFileMovie(EMovie* movie,int indice);

int cargar_descripcion(EMovie* movie, int index);
int cargar_genero(EMovie* movie,int index);
int cargar_duracion (EMovie* movie,int index, char mensaje[],char mensajeError[]);
int cargar_link(EMovie* movie,int index);
int cargar_puntaje (EMovie* movie,int index);
int cargar_titulo(EMovie* movie,int index);

int func_agregaPelicula(EMovie* movie,int* cantidadPelis, int* longitud);
void func_cargarPelicula(EMovie* movie,int* cantidadPelis, int* longitud);
void func_borrarPelicula(EMovie* movie, int* cantidadPelis,int* longitud);
void func_creaArchivo(EMovie* movie, int* cantidadPelis);
void func_comprimimeMovies(EMovie* movie,int* cantidadPelis, int indiceMovieborrada,int* longitud);
