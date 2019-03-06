#include "TestPolinomios.h"

void mockPolinomioPruebaInsert(Polinomio &polinomio, String nombre) {
    ListaTerminos mockListaTerminos;
    insertarTermino(mockListaTerminos, mockTermino1);
    insertarTermino(mockListaTerminos, mockTermino2);
    insertarTermino(mockListaTerminos, mockTermino3);
    cargarPolinomio(polinomio, nombre, mockListaTerminos);
}

void pruebaCrearABBPolinomios(ABBPolinomios &abb) {
    crearABBPolinomios(abb);
    if (abb == NULL)
        printf("El ABB de polinomios fue creado exitosamente.\n");
    else
        printf("El ABB de polinomios no fue creado exitosamente.\n");
}

void pruebaInsertarPolinomio(ABBPolinomios &abb) {
    Polinomio mockPolinomio;
    mockPolinomioPruebaInsert(mockPolinomio, mockNombre);
    printf("Polinomio antes de insertar en ABB de polinomios vacio:\n");
    mostrarPolinomio(mockPolinomio);
    printEnter();
    insertarPolinomio(abb, mockPolinomio); //prueba con ABBPolinomios vacio
    printf("ABB de polinomios luego de insertar un polinomio:\n");
    desplegarABB(abb);
    printEnter();
    Polinomio mockOtroPolinomio;
    mockPolinomioPruebaInsert(mockOtroPolinomio, mockOtroNombre);
    insertarPolinomio(abb, mockOtroPolinomio); //prueba con ABBPolinomios no vacio
    printf("ABB de polinomios luego de insertar otro polinomio:\n");
    desplegarABB(abb);
    printEnter();
}

void pruebaExisteAlMenosUnPolinomioEnABB(ABBPolinomios abb) {
    ABBPolinomios mockPolinomios;
    crearABBPolinomios(mockPolinomios);
    printf("Existe al menos un Polinomio en ABB de polinomios vacio:\n");
    if (existeAlMenosUnPolinomioEnABB(mockPolinomios))
        printf("Existe Polinomio en ABB de polinomios.\n");
    else
        printf("No existe Polinomio en ABB de polinomios.\n");
    printf("Existe al menos un Polinomio en ABB de polinomios dado:\n");
    desplegarABB(abb);
    printEnter();
    if (existeAlMenosUnPolinomioEnABB(abb))
        printf("Existe Polinomio en ABB de polinomios.\n");
    else
        printf("No existe Polinomio en ABB de polinomios.\n");

}

void pruebaExistePolinomioEnABB(ABBPolinomios abb) {
    printf("ABB de polinomios:\n");
    desplegarABB(abb);
    printEnter();
    printf("El Polinomio ");
    print(mockNombre);
    if (existePolinomioEnABB(abb, mockNombre)) {
        printf(" existe en el ABB de polinomios.\n");
    } else {
        printf(" no existe en el ABB de polinomios.\n");
    }
    printf("El Polinomio ");
    print(mockNombreNegativo);
    if (existePolinomioEnABB(abb, mockNombreNegativo)) {
        printf(" existe en el ABB de polinomios.\n");
    } else {
        printf(" no existe en el ABB de polinomios.\n");
    }
}

void pruebaDarRaiz(ABBPolinomios abb) {
    printf("Dado el siguiente ABB de polinomios:\n");
    desplegarABB(abb);
    printEnter();
    printf("La raiz es:\n");
    Polinomio pol = darRaiz(abb);
    mostrarPolinomio(pol);
    printEnter();
}

void pruebaDarIzquierdo(ABBPolinomios abb) {
    printf("Dado el siguiente ABB de polinomios:\n");
    desplegarABB(abb);
    printEnter();
    printf("El hijo izquierdo del arbol es:\n");
    ABBPolinomios arbol = darIzquierdo(abb);
    if (arbol == NULL)
        printf("El ABB de polinomios no tiene hijo izquierdo.\n");
    else
        desplegarABB(arbol);
    printEnter();
}

void pruebaDarDerecho(ABBPolinomios abb) {
    printf("Dado el siguiente ABB de polinomios:\n");
    desplegarABB(abb);
    printEnter();
    printf("El hijo derecho del arbol es:\n");
    ABBPolinomios arbol = darDerecho(abb);
    if (arbol == NULL)
        printf("El ABB de polinomios no tiene hijo derecho.\n");
    else
        desplegarABB(arbol);
    printEnter();
}

void pruebaBuscarPolinomio(ABBPolinomios abb) {
    printf("Dado el siguiente ABB de polinomios:\n");
    desplegarABB(abb);
    printEnter();
    printf("El siguiente polinomio:\n");
    Polinomio mockPolinomio;
    mockPolinomioPruebaInsert(mockPolinomio, mockNombre);
    mostrarPolinomio(mockPolinomio);
    printEnter();
    Polinomio pruebaPolinomio;
    pruebaPolinomio = buscarPolinomio(abb, mockNombre);
    if (polinomiosIgualNombre(mockPolinomio, pruebaPolinomio))
        printf("Pertenece al ABB de polinomios.\n");
    else
        printf("No pertenece al ABB de polinomios.\n");
    printf("Y el siguiente polinomio:\n");
    Polinomio mockOtroPolinomio;
    mockPolinomioPruebaInsert(mockOtroPolinomio, mockNombreNegativo);
    mostrarPolinomio(mockOtroPolinomio);
    printEnter();
    Polinomio pruebaOtroPolinomio;
    pruebaOtroPolinomio = buscarPolinomio(abb, mockNombreNegativo);
    if (polinomiosIgualNombre(mockOtroPolinomio, pruebaOtroPolinomio))
        printf("Pertenece al ABB de polinomios.\n");
    else
        printf("No pertenece al ABB de polinomios.\n");
}

void pruebaEliminarABB(ABBPolinomios &abb) {
    printf("Dado el siguiente ABB de polinomios:\n");
    desplegarABB(abb);
    printEnter();
    eliminarABB(abb);
    if (existeAlMenosUnPolinomioEnABB(abb))
        printf("El ABB de polinomios no fue correctamente eliminado.\n");
    else
        printf("El ABB de polinomios fue correctamente eliminado.\n");
}
