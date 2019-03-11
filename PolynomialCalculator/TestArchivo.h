#ifndef TestArchivo_h
#define TestArchivo_h

#include <stdio.h>
#include "Archivo.h"

const char * const mockNombreArchivo = "pruebaArchivo.txt";
const char * const mockNombreArchivoExiste = "pruebaArchivoExiste.txt";

void probarExisteArchivo();
void probarCrearArchivo();

#endif
