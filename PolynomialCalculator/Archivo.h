#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include "String.h"

Boolean existeArchivo(const char * nomArchivo);
/*devuelve true si existe un archivo identificado con nomArchivo*/
FILE * crearArchivo(const char * nomArchivo);
/*devuelve el archivo creado con el nombre nomArchivo*/
/*PRECONDICION: nomArchivo debe tener extensión .txt*/


#endif // ARCHIVOS_H_INCLUDED
