//
//  Termino.h
//  PolynomialCalculator
//
//  Created by Diego, Rodrigo & Pablo.
//

#ifndef Termino_h
#define Termino_h

#include <stdio.h>
#include <cmath>
#include "String.h"

typedef struct{
    int coeficiente;
    int exponente;
} Termino;

void mostrarTermino(Termino termino);
//Muestra los datos del Término por pantalla
int darCoeficienteTermino(Termino termino);
//Devuelve el coeficiente del término
int darExponenteTermino(Termino termino);
//Devuelve el exponente del término
void cargarCoeficienteTermino(Termino &termino, int coeficiente);
//Carga el coeficiente en el término
void cargarExponenteTermino(Termino &termino, int exponente);
//Carga el exponente en el término
Boolean terminoMayorGrado(Termino termino1, Termino termino2);
//Devueve true si termino1 es mayor que termino2

/*OPERACIONES DE TERMINO*/
void sumarTerminos(Termino termino1, Termino termino2, Termino &termino1Resultado);
/*Dados dos términos devuelve en “termino1Resultado” la suma de ambos términos */
/*PRECONDICION: ambos terminos del mismo exponente*/
void multiplicarTerminos(Termino termino1, Termino termino2, Termino &termino1Resultado);
/*Dados dos términos devuelve en “termino1Resultado” la multiplicación de ambos*/
int evaluarTermino(Termino termino, int valor);
/*Devuelve el resultado de evaluar el valor dado elevado al exponente del término y luego multiplicado por el coeficiente del término*/
void bajarTermino(Termino termino, FILE * f);
//Almacena el término en el archivo f
void levantarTermino(Termino &termino, FILE * f);
//Recupera el término almacenado en el archivo f


#endif /* Termino_h */
