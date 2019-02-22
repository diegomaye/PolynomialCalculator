//
//  Termino.cpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/15/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#include "Termino.h"

void mostrarTermino(Termino termino){
    /* controlar cosas con varios if:
     ejemplo: si el coeficiente es 1, no se muestra
     si es -1, se muestra - pero no el 1
     si es mayor que cero, mostrar expresamente el +
     si el grado es 0, solo se muestra el coeficiente
     etc */
    
    printf("%dx^%d", termino.coeficiente, termino.exponente);
}

int darCoeficienteTermino(Termino termino){
    return termino.coeficiente;
}

int darExponenteTermino(Termino termino){
    return termino.exponente;
}

void cargarCoeficienteTermino(Termino &termino, int coeficiente){
    termino.coeficiente = coeficiente;
}

void cargarExponenteTermino(Termino &termino, int exponente){
    termino.exponente = exponente;
}

/*OPERACIONES DE TERMINO*/
void sumarTerminos(Termino termino1, Termino termino2, Termino &termino1Resultado){
    if (termino1.exponente == termino2.exponente){
        termino1Resultado.coeficiente = termino1.coeficiente + termino2.coeficiente;
        termino1Resultado.exponente = termino1.exponente;
    }
}

void multiplicarTerminos(Termino termino1, Termino termino2, Termino &termino1Resultado){
    int coeficiente = termino1.coeficiente * termino2.coeficiente;
    int exponente = termino1.exponente + termino2.exponente;
    termino1Resultado.coeficiente = coeficiente;
    termino1Resultado.exponente = exponente;
}

int evaluarTermino(Termino termino, int valor){
    // ojo con esta cuenta
    return termino.coeficiente * pow(valor, termino.exponente);
}
void bajarTermino(Termino termino, FILE * f){
    fwrite (&termino.coeficiente, sizeof(int), 1, f);
    fwrite (&termino.exponente, sizeof(int), 1, f);
}
void levantarTermino(Termino &termino, FILE * f){
    fread (&termino.coeficiente, sizeof(int), 1, f);
    fread (&termino.exponente, sizeof(int), 1, f);
}
