//
//  TestTermino.cpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/22/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#include "TestTermino.h"



void probarMostrarTermino(){
    printf("mockTermino: ");
    mostrarTermino(mockTermino);
    printEnter();
    printf("mockTerminoNegativo: ");
    mostrarTermino(mockTerminoNegativo);
    printEnter();
    printf("mockTerminoNulo: ");
    mostrarTermino(mockTerminoNulo);
    printEnter();
}

void probarDarCoeficienteTermino(){
    printf("Para:");
    mostrarTermino(mockTermino);
    printEnter();
    int coeficiente = darCoeficienteTermino(mockTermino);
    printf("El valor del coeficiente es: %d\n", coeficiente);
}

void probarDarExponenteTermino(){
    printf("Para:");
    mostrarTermino(mockTermino);
    printEnter();
    int expoente = darExponenteTermino(mockTermino);
    printf("El valor del exponente es: %d\n", expoente);
}

void probarCargarCoeficienteTerminoNegativo(){
    Termino termino;
    printf("Coeficiente/Exponente %d/%d: ", -5, 1);
    cargarExponenteTermino(termino, 1);
    cargarCoeficienteTermino(termino, -5);
    mostrarTermino(termino);
    printEnter();
    
}

void probarCargarExponenteTerminoNegativo(){
    Termino termino;
    printf("Coeficiente/Exponente %d/%d: ", 1, -1);
    cargarCoeficienteTermino(termino, 1);
    cargarExponenteTermino(termino, -1);
    mostrarTermino(termino);
    printEnter();
}

/*OPERACIONES DE TERMINO*/
//Pruebas de Suma
void probarSumarTerminosPositivos(){
    Termino termino;
    printf("Primer termino: ");
    mostrarTermino(mockTermino);
    printEnter();
    printf("Segundo termino: ");
    mostrarTermino(mockTermino);
    printEnter();
    sumarTerminos(mockTermino, mockTermino, termino);
    printf("Termino resultado:");
    mostrarTermino(termino);
    printEnter();
}

void probarSumarTerminosNegativoPositivo(){
    Termino termino;
    printf("Primer termino: ");
    mostrarTermino(mockTerminoNegativo);
    printEnter();
    printf("Segundo termino: ");
    mostrarTermino(mockTerminoPosParaNeg);
    printEnter();
    sumarTerminos(mockTerminoNegativo, mockTerminoPosParaNeg, termino);
    printf("Termino resultado:");
    mostrarTermino(termino);
    printEnter();
}

void probarSumarTerminoConNulo(){
    Termino termino;
    printf("Primer termino: ");
    mostrarTermino(mockTerminoNulo);
    printEnter();
    printf("Segundo termino: ");
    mostrarTermino(mockTerminoExp0);
    printEnter();
    sumarTerminos(mockTerminoNulo, mockTerminoExp0, termino);
    printf("Termino resultado:");
    mostrarTermino(termino);
    printEnter();
}

void probarMultiplicarTerminosPositivos(){
    Termino termino;
    printf("Primer termino: ");
    mostrarTermino(mockTermino);
    printEnter();
    printf("Segundo termino: ");
    mostrarTermino(mockTermino);
    printEnter();
    multiplicarTerminos(mockTermino, mockTermino, termino);
    printf("Termino resultado:");
    mostrarTermino(termino);
    printEnter();
}

void probarMultiplicarTerminosPositivoNegativo(){
    Termino termino;
    printf("Primer termino: ");
    mostrarTermino(mockTerminoNegativo);
    printEnter();
    printf("Segundo termino: ");
    mostrarTermino(mockTermino);
    printEnter();
    multiplicarTerminos(mockTerminoNegativo, mockTermino, termino);
    printf("Termino resultado:");
    mostrarTermino(termino);
    printEnter();
}

void probarMultiplicarTerminoConNulo(){
    Termino termino;
    printf("Primer termino: ");
    mostrarTermino(mockTerminoNulo);
    printEnter();
    printf("Segundo termino: ");
    mostrarTermino(mockTermino);
    printEnter();
    multiplicarTerminos(mockTerminoNulo, mockTermino, termino);
    printf("Termino resultado:");
    mostrarTermino(termino);
    printEnter();
}

void probarEvaluarTerminoPositivo(){
    printf("Termino a evaluar con +'%d': ", evaluarPositivo);
    mostrarTermino(mockTermino);
    printEnter();
    printf("El resultado de la evaluacion es: %d", evaluarTermino(mockTermino, evaluarPositivo));
    printEnter();
}

void probarEvaluarTerminoNegativo(){
    printf("Termino a evaluar con '%d': ", evaluarNegativo);
    mostrarTermino(mockTermino);
    printEnter();
    printf("El resultado de la evaluacion es: %d", evaluarTermino(mockTermino, evaluarNegativo));
    printEnter();
}

void probarEvaluarTerminoNulo(){
    printf("Termino a evaluar con '%d': ", evaluarNulo);
    mostrarTermino(mockTermino);
    printEnter();
    printf("El resultado de la evaluacion es: %d", evaluarTermino(mockTermino, evaluarNulo));
    printEnter();
}
