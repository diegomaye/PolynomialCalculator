//
//  Parser.cpp
//  PolynomialCalculator
//
//  Created by Diego, Rodrigo & Pablo.
//

#include "Parser.h"

void invocarComando(Comando com, ListaStrings &lista, ABBPolinomios &polinomios) {
    switch (com) {
    case CREAR:
        crearPolinomio(polinomios, lista);
        break;
    case SUMAR:
        sumarPolinomios(polinomios, lista);
        break;
    case MULTIPLICAR:
        multiplicarPolinomios(polinomios, lista);
        break;
    case EVALUAR:
        evalarPolinomio(polinomios, lista);
        break;
    case ESRAIZ:
        esraizPolinomio(polinomios, lista);
        break;
    case MOSTRAR:
        mostrarPolinomio(polinomios, lista);
        break;
    case GUARDAR:
        guardarPolinomio(polinomios, lista);
        break;
    case RECUPERAR:
        recuperarPolinomio(polinomios, lista);
        break;
    case SALIR:
        salir(polinomios);
        break;
    }
}

void crearPolinomio(ABBPolinomios &polinomios, ListaStrings commando) {

}

void sumarPolinomios(ABBPolinomios &polinomios, ListaStrings commando) {
}

void multiplicarPolinomios(ABBPolinomios &polinomios, ListaStrings commando) {
}

void evalarPolinomio(ABBPolinomios &polinomios, ListaStrings commando) {
}

void esraizPolinomio(ABBPolinomios &polinomios, ListaStrings commando) {
}

void mostrarPolinomio(ABBPolinomios &polinomios, ListaStrings commando) {
}

void guardarPolinomio(ABBPolinomios &polinomios, ListaStrings commando) {
}

void recuperarPolinomio(ABBPolinomios &polinomios, ListaStrings commando) {
}

void salir(ABBPolinomios &polinomios) {

}
