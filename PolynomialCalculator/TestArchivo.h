#ifndef TESTARCHIVO_H_INCLUDED
#define TESTARCHIVO_H_INCLUDED

#include <stdio.h>
#include "Archivo.h"
#include "String.h"

const char * mockNombreArchivo = "pruebaArchivo.txt";
const char * mockNombreArchivoExiste = "pruebaArchivoExiste.txt";

void probarExisteArchivo();
void probarCrearArchivo();

#endif // TESTARCHIVO_H_INCLUDED
