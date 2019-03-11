#ifndef TESTPOLINOMIOS_H_INCLUDED
#define TESTPOLINOMIOS_H_INCLUDED

#include <stdio.h>
#include "Polinomios.h"

const Termino mockTermino1 = {3,2};//+3x^2
const Termino mockTermino2 = {2,1};//+2x^1
const Termino mockTermino3 = {2,0};//+1x^0
const Termino mockTermino4 = {4,3};//+4x^3
const Termino mockTermino5 = {5,1};//+5x^1
const String mockNombre = "polinomio";
const String mockOtroNombre = "otroPolinomio";
const String mockNombreNegativo = "pruebaPolinomio";

void mockPolinomiosPruebaInsert(Polinomio &polinomio, String nombre, Polinomio &polinomio2, String nombre2);
//Mock para polinomios.

void pruebaCrearABBPolinomios(ABBPolinomios &abb);
void pruebaInsertarPolinomio(ABBPolinomios &abb);
void pruebaExisteAlMenosUnPolinomioEnABB(ABBPolinomios abb);
void pruebaExistePolinomioEnABB(ABBPolinomios abb);
void pruebaDarRaiz(ABBPolinomios abb);
void pruebaDarIzquierdo(ABBPolinomios abb);
void pruebaDarDerecho(ABBPolinomios abb);
void pruebaBuscarPolinomio(ABBPolinomios abb);
void pruebaEliminarABB(ABBPolinomios &abb);

#endif // TESTPOLINOMIOS_H_INCLUDED
