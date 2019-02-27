#include "Archivo.h"

Boolean existeArchivo(const char * nomArchivo) {
    Boolean existe = FALSE;
    FILE * f = fopen(nomArchivo, "rb");
    if (f != NULL) {
        existe = TRUE;
        fclose(f);
    }
    return existe;
}

FILE * crearArchivo(const char * nomArchivo) {
    FILE * f = fopen(nomArchivo, "wb");
    fclose(f);
    return f;
}


