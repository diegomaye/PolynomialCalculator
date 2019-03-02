//
//  TestPolinomio.cpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/28/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#include "TestPolinomio.h"

void mockPolinomiosPruebaCargar(Polinomio &polinomio1, Polinomio &polinomio2, Polinomio &polinomio3, ListaTerminos &terminosL1, ListaTerminos &terminosL2, ListaTerminos &terminosL3){
    String nombrePol1 = "polinomio1";
    cargarPolinomio(polinomio1, nombrePol1, terminosL1);
    
    String nombrePol2 = "polinomio2";
    cargarPolinomio(polinomio2, nombrePol2, terminosL2);
    
    String nombrePol3 = "polinomio3";
    cargarPolinomio(polinomio3, nombrePol3, terminosL3);
}

void probarSumaPolinomiosIgualLargo(Polinomio &polinomio1, Polinomio &polinomio2) {
    Polinomio resultado;
    cargarPolinomio(resultado, "resultado", NULL);
    printf("Prueba probarSumaPolinomiosIgualLargo se suman: \n");
    mostrarPolinomio(polinomio1);
    printEnter();
    printf("+ \n");
    mostrarPolinomio(polinomio2);
    printEnter();
    sumarPolinomios(polinomio1, polinomio2, resultado);
    printf("--------------------------------\n");
    mostrarPolinomio(resultado);
    printEnter();
}

void probarSumaPolinomiosDiferenteLargo(Polinomio &polinomio1, Polinomio &polinomio2) {
    Polinomio resultado;
    cargarPolinomio(resultado, "resultado", NULL);
    printf("Prueba probarSumaPolinomiosDiferenteLargo se suman: \n");
    mostrarPolinomio(polinomio1);
    printEnter();
    printf("+ \n");
    mostrarPolinomio(polinomio2);
    printEnter();
    sumarPolinomios(polinomio1, polinomio2, resultado);
    printf("--------------------------------\n");
    mostrarPolinomio(resultado);
    printEnter();
}

void probarSumaPolinomioNulo(Polinomio polinomio1) {
    Polinomio resultado;
    cargarPolinomio(resultado, "resultado", NULL);
    printf("Prueba probarSumaPolinomioNulo polinomio a probar sumar con nulo es: \n");
    mostrarPolinomio(polinomio1);
    printEnter();
    Polinomio polinomioNulo;
    cargarPolinomio(polinomioNulo, "polinomioNulo", NULL);
    sumarPolinomios(polinomio1, polinomioNulo, resultado);
    printf("--------------------------------\n");
    mostrarPolinomio(resultado);
    printEnter();
}

void probarMultiplicarPolinomiosIgualLargo(Polinomio &polinomio1, Polinomio &polinomio2) {
    Polinomio resultado;
    cargarPolinomio(resultado, "resultado", NULL);
    printf("Prueba probarMultiplicarPolinomiosIgualLargo se multiplican: \n");
    mostrarPolinomio(polinomio1);
    printEnter();
    printf("x \n");
    mostrarPolinomio(polinomio2);
    printEnter();
    multiplicarPolinomios(polinomio1, polinomio2, resultado);
    printf("--------------------------------\n");
    mostrarPolinomio(resultado);
    printEnter();
}

void probarMultiplicarPolinomiosDiferenteLargo(Polinomio &polinomio1, Polinomio &polinomio2) {
    Polinomio resultado;
    cargarPolinomio(resultado, "resultado", NULL);
    printf("Prueba probarMultiplicarPolinomiosDiferenteLargo se multiplican: \n");
    mostrarPolinomio(polinomio1);
    printEnter();
    printf("x \n");
    mostrarPolinomio(polinomio2);
    printEnter();
    multiplicarPolinomios(polinomio1, polinomio2, resultado);
    printf("--------------------------------\n");
    mostrarPolinomio(resultado);
    printEnter();
}

void probarMultiplicarPolinomioNulo(Polinomio polinomio1) {
    Polinomio resultado;
    cargarPolinomio(resultado, "resultado", NULL);
    printf("Prueba probarMultiplicarPolinomioNulo polinomio a probar multiplicar por nulo es: \n");
    mostrarPolinomio(polinomio1);
    printEnter();
    Polinomio polinomioNulo;
    cargarPolinomio(polinomioNulo, "polinomioNulo", NULL);
    multiplicarPolinomios(polinomio1, polinomioNulo, resultado);
    printf("--------------------------------\n");
    mostrarPolinomio(resultado);
    printEnter();
}

void probarEvaluarPolinomio(Polinomio polinomio) {
    printf("Prueba probarEvaluarPolinomio: ");

    int evaluar = 3;
    printf("Prueba de evaluacion con el valor %d del polinomio: \n", evaluar);
    mostrarPolinomio(polinomio);
    printEnter();
    int resultado = evaluarPolinomio(polinomio, evaluar);
    printf("El resultado de la evaluacion es: %d\n", resultado);
}

void probarEsRaizPolinomio(Polinomio polinomio) {
    printf("Prueba probarEsRaizPolinomio: ");

    int evaluar = 3;
    printf("Prueba si el valor %d es raiz del polinomio: \n", evaluar);
    mostrarPolinomio(polinomio);
    printEnter();
    Boolean esRaiz = esRaizPolinomio(polinomio, evaluar);
    if(esRaiz){
        printf("El valor %d es raiz\n", evaluar);
    } else {
        printf("El valor %d no es raiz\n", evaluar);
    }
}

void probarDarNombrePolinomio(Polinomio polinomio) {
    printf("Prueba probarDarNombrePolinomio: ");
    printf("El nombre del polinomio es: \n");
    String nombre;
    strcrear(nombre);
    darNombrePolinomio(polinomio, nombre);
    print(nombre);
}

void probarDarTerminosPolinomio(Polinomio polinomio) {
    printf("Prueba probarDarTerminosPolinomio: ");
    printf("Los terminos del polinomio ");
    String nombre;
    strcrear(nombre);
    darNombrePolinomio(polinomio, nombre);
    print(nombre);
    printf(" son: ");
    ListaTerminos terminos = NULL;
    darTerminosPolinomio(polinomio, terminos);
    mostrarTerminos(terminos);
}

void probarPolinomioConMasTerminos(Polinomio polinomio1, Polinomio polinomio2) {
    printf("Prueba probarPolinomioConMasTerminos el polinomio: \n");
    mostrarPolinomio(polinomio1);
    printEnter();
    printf("Tiene mas terminos que?: \n");
    mostrarPolinomio(polinomio2);
    printEnter();
    Boolean tieneMas = polinomioConMasTerminos(polinomio1, polinomio2);
    if(tieneMas) {
        printf("Si tiene mas.\n");
    } else {
        printf("No tiene mas.\n");
    }
    printEnter();
}

void probarPolinomiosIgualNombre(Polinomio polinomio1, Polinomio polinomio2) {
    printf("Prueba probarPolinomiosIgualNombre el polinomio: \n");
    mostrarPolinomio(polinomio1);
    printEnter();
    printf("Tiene el mismo nombre que?: \n");
    mostrarPolinomio(polinomio2);
    printEnter();
    Boolean tieneMas = polinomiosIgualNombre(polinomio1, polinomio2);
    if(tieneMas) {
        printf("Si tienen el mismo.\n");
    } else {
        printf("No tienen el mismo.\n");
    }
    printEnter();
}

void probarPolinomioMenorNombre(Polinomio polinomio1, Polinomio polinomio2) {
    printf("Prueba probarPolinomioMenorNombre el polinomio: \n");
    mostrarPolinomio(polinomio1);
    printEnter();
    printf("Un nombre menor que?: \n");
    mostrarPolinomio(polinomio2);
    printEnter();
    Boolean tieneMenor = polinomioMenorNombre(polinomio1, polinomio2);
    if(tieneMenor) {
        printf("Si tienen menor nombre.\n");
    } else {
        printf("No tienen menor nombre.\n");
    }
    printEnter();
}

void probarPolinomioNulo() {
    printf("Prueba probarPolinomioNulo el polinomio: \n");
    Polinomio polinomio;
    cargarPolinomio(polinomio, "polinomioNulo", NULL);
    mostrarPolinomio(polinomio);
    printEnter();
    printf("Es el polinomio nulo. \n");
    printEnter();
}

void probarBorradoDePolinomio(Polinomio polinomio) {
    printf("Prueba probarBorradoDePolinomio ");
    printf("El polinomio antes de ser eliminado: \n");
    mostrarPolinomio(polinomio);
    printEnter();
    borrarPolinomio(polinomio);
    printf("El polinomio despues de ser eliminado: \n");
    mostrarPolinomio(polinomio);
    printEnter();
}
