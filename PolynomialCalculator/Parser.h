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

typedef enum {
    CREAR,
    SUMAR,
    MULTIPLICAR,
    EVALUAR,
    ESRAIZ,
    MOSTRAR,
    GUARDAR,
    RECUPERAR,
    SALIR
} Comando;


static const String COMMANDO[] = {
    "crear\0",
    "sumar\0",
    "multiplicar\0",
    "evaluar\0",
    "esRaiz\0",
    "mostrar\0",
    "guardar\0",
    "recuperar\0",
    "salir\0"
};

void invocarComando(Comando com, ListaStrings &lista, ABBPolinomios &polinomios);

void crearPolinomio(ABBPolinomios &polinomios, ListaStrings commando);

void sumarPolinomios(ABBPolinomios &polinomios, ListaStrings commando);

void multiplicarPolinomios(ABBPolinomios &polinomios, ListaStrings commando);

void evalarPolinomio(ABBPolinomios &polinomios, ListaStrings commando);

void esraizPolinomio(ABBPolinomios &polinomios, ListaStrings commando);

void mostrarPolinomio(ABBPolinomios &polinomios, ListaStrings commando);

void guardarPolinomio(ABBPolinomios &polinomios, ListaStrings commando);

void recuperarPolinomio(ABBPolinomios &polinomios, ListaStrings commando);

void salir(ABBPolinomios &polinomios);

#endif /* Parser_h */
