#include "TestString.h"

void probarEsAlfanumerico() {
    printf("PRUEBA DE SI UN STRING ES ALFANUMERICO:\n");
    printf("El string ");
    print(mockAlfanumerico);
    if (esAlfanumerico(mockAlfanumerico)) {
        printf(" es alfanumerico.");
    } else {
        printf(" no es alfanumerico.");
    }
    printEnter();
    printf("El string ");
    print(mockNoAlfanumerico);
    if (esAlfanumerico(mockNoAlfanumerico)) {
        printf(" es alfanumerico.");
    } else {
        printf(" no es alfanumerico.");
    }
    printEnter();
}
void probarEsNumerico() {
    printf("\nPRUEBA DE SI UN STRING ES NUMERICO:\n");
    printf("El string ");
    print(mockNumerico);
    if (esNumerico(mockNumerico)) {
        printf(" es numerico.");
    } else {
        printf(" no es numerico.");
    }
    printEnter();
    printf("El string ");
    print(mockNoNumerico);
    if (esNumerico(mockNoNumerico)) {
        printf(" es numerico.");
    } else {
        printf(" no es numerico.");
    }
    printEnter();
}
void probarConvertirANumero() {
    printf("\nPRUEBA DE PASAR UN STRING A ENTERO:\n");
    int val = convertirANumero(mockConvertirANumero);
    printf("El string ");
    print(mockConvertirANumero);
    if (val != 0) {
        printf(" pasado a entero es: %d",val);
    } else {
        printf(" no es un entero.");
    }
    int val2 = convertirANumero(mockNoConvertirANumero);
    printf("El string ");
    print(mockNoConvertirANumero);
    if (val2 != 0) {
        printf(" pasado a entero es: %d",val2);
    } else {
        printf(" no es un entero.");
    }
    printEnter();
}
/*void probarCantidadPuntosEnString() {
    printf("\nPRUEBA DE CONTAR PUNTOS EN UN STRING:\n");
    printf("El string ");
    print(mockCantidadPuntosEnString);
    if ((cantidadDePuntosEnString(mockCantidadPuntosEnString))) {
        printf(" tiene un solo punto.");
    } else {
        printf(" tiene más de un punto.");
    }
    printEnter();
    printf("El string ");
    print(mockCantidadPuntosEnStringMayor);
    if ((cantidadDePuntosEnString(mockCantidadPuntosEnStringMayor))) {
        printf(" tiene un solo punto.");
    } else {
        printf(" tiene más de un punto.");
    }
    printEnter();
}*/
void probarValidarExtension() {
    printf("\nPRUEBA DE EXTENSION DE ARCHIVO:\n");
    printf("El string ");
    print(mockValidarExtension);
    if ((validarExtension(mockValidarExtension))) {
        printf(" tiene un nombre y extension validos.");
    } else {
        printf(" tiene un nombre o extension invalidos.");
    }
    printEnter();
    printf("El string ");
    print(mockNoValidarExtension);
    if ((validarExtension(mockNoValidarExtension))) {
        printf(" tiene un nombre y extension validos.");
    } else {
        printf(" tiene un nombre o extension invalidos.");
    }
    printEnter();
}
