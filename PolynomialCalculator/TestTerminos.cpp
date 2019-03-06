//
//  TestTerminos.cpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/24/19.
//

#include "TestTerminos.h"

void mockTerminosPruebaInsert(ListaTerminos &terminosL1, ListaTerminos &terminosL2, ListaTerminos &terminosL3){
    
    insertarTermino(terminosL1, (Termino){2,3});
    insertarTermino(terminosL1, (Termino){-5,2});
    insertarTermino(terminosL1, (Termino){1,1});
    
    insertarTermino(terminosL2, (Termino){20,8});
    insertarTermino(terminosL2, (Termino){4,0});
    
    insertarTermino(terminosL3, (Termino){-4,5});
    insertarTermino(terminosL3, (Termino){-4,4});
    insertarTermino(terminosL3, (Termino){4,3});
    insertarTermino(terminosL3, (Termino){4,2});
    insertarTermino(terminosL3, (Termino){2,1});
    insertarTermino(terminosL3, (Termino){2,0});
}

void probarInsertarTerminoAlFinal(ListaTerminos &terminos){
    printf("Terminos antes de insertar termino al final:\n");
    mostrarTerminos(terminos);
    printEnter();
    printf("Terminos despues de insertar termino -7 al final:\n");
    insertarTermino(terminos, (Termino){-7,0});
    mostrarTerminos(terminos);
}

void probarInsertarTerminoEnElMedio(ListaTerminos &terminos){
    printf("Terminos antes de insertar termino en el medio:\n");
    mostrarTerminos(terminos);
    printEnter();
    printf("Terminos despues de insertar termino -10x^3 en el medio:\n");
    insertarTermino(terminos, (Termino){-10,3});
    mostrarTerminos(terminos);
}
void probarInsertarTerminoAlPrincipio(ListaTerminos &terminos){
    printf("Terminos antes de insertar termino al principio:\n");
    mostrarTerminos(terminos);
    printEnter();
    printf("Terminos despues de insertar termino x^6 al principio:\n");
    insertarTermino(terminos, (Termino){1,6});
    mostrarTerminos(terminos);
}

void probarInsertarTerminoEnListaVacia(){
    printf("Se crea lista nula y se inserta un elemento\n");
    ListaTerminos listaNula = NULL;
    printf("Terminos despues de insertar termino 6 en lista vacia:\n");
    insertarTermino(listaNula, (Termino){6,0});
    mostrarTerminos(listaNula);
}

void probarInsBack(ListaTerminos &terminos){
    mostrarTerminos(terminos);
}

void probarExisteGradoUno(ListaTerminos terminos){
    mostrarTerminos(terminos);
}
void probarExisteGradoTres(ListaTerminos terminos){
    mostrarTerminos(terminos);
}
void probarExisteGradoTreinta(ListaTerminos terminos){
    mostrarTerminos(terminos);
}

void probarContarTerminos(ListaTerminos terminos){
    mostrarTerminos(terminos);
}
void probarContarTerminoEnListaVacia(ListaTerminos terminos){
    mostrarTerminos(terminos);
}

void probarBorrarTerminoAlPrincipio(ListaTerminos &terminos){
    mostrarTerminos(terminos);
}
void probarBorrarTerminoAlFinal(ListaTerminos &terminos){
    mostrarTerminos(terminos);
}

void probarPrimerTermino(ListaTerminos terminos){
    mostrarTerminos(terminos);
}

void probarSumarTerminos(ListaTerminos terminosL1, ListaTerminos terminosL2){
    printf("PRUEBA DE LA SUMA\n");
    mostrarTerminos(terminosL1);
    printEnter();
    printf("+ \n");
    mostrarTerminos(terminosL2);
    printEnter();
    printf("------------------------------ \n");
    ListaTerminos nuevaLista = NULL;
    sumarTerminos(terminosL1, terminosL2, nuevaLista);
    mostrarTerminos(nuevaLista);
    printEnter();
    printEnter();
}

void probarMultiplicarTerminos(ListaTerminos terminosL1, ListaTerminos terminosL2){
    printf("PRUEBA DEL PRODUCTO\n");
    printf("Se van a multiplicar los terminos: \n");
    mostrarTerminos(terminosL1);
    printEnter();
    printf("x \n");
    mostrarTerminos(terminosL2);
    printEnter();
    printf("------------------------------ \n");
    ListaTerminos producto = NULL;
    multiplicarTerminos(terminosL1, terminosL2, producto);
    mostrarTerminos(producto);
    printEnter();
    printEnter();
}
