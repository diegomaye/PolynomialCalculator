#include "TestArchivo.h"

void probarExisteArchivo(){
    if (existeArchivo(mockNombreArchivoExiste)) {
        printf("pruebaArchivoExiste.txt ya existe");
    } else {
        printf("pruebaArchivoExiste.txt no existe");
    }
    printEnter();
}

void probarCrearArchivo(){
    if (existeArchivo(mockNombreArchivo)) {
        crearArchivo(mockNombreArchivo);
        printf("Se sobreescribe pruebaArchivo.txt");
    } else {
        crearArchivo(mockNombreArchivo);
        printf("Se crea pruebaArchivo.txt");
    }
    printEnter();
}
