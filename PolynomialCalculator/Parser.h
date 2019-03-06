//
//  Parser.h
//  PolynomialCalculator
//
//  Created by Diego, Rodrigo & Pablo.
//

#ifndef Parser_h
#define Parser_h

#include <stdio.h>
#include "Error.h"
#include "Archivo.h"
#include "Polinomios.h"
#include "ListaStrings.h"

const String CREAR = "crear";
const String SUMAR = "sumar";
const String MULTIPLICAR = "multiplicar";
const String EVALUAR = "evalur";
const String ESRAIZ = "esraiz";
const String MOSTRAR = "mostrar";
const String GUARDAR = "guardar";
const String RECUPERAR = "recuperar";
const String SALIR = "salir";

void crearPolinomio(ABBPolinomios &polinomios, ListaStrings commando);

void sumarPolinomios(ABBPolinomios &polinomios, ListaStrings commando);

void multiplicarPolinomios(ABBPolinomios &polinomios, ListaStrings commando);

void evalarPolinomio(ABBPolinomios &polinomios, ListaStrings commando);

void esraizPolinomio(ABBPolinomios &polinomios, ListaStrings commando);

void mostrarPolinomio(ABBPolinomios &polinomios, ListaStrings commando);

void guardarPolinomio(ABBPolinomios &polinomios, ListaStrings commando);

void recuperarPolinomio(ABBPolinomios &polinomios, ListaStrings commando);

#endif /* Parser_h */
