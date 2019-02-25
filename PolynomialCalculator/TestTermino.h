//
//  TestTermino.hpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/22/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#ifndef TestTermino_h
#define TestTermino_h

#include <stdio.h>
#include "Termino.h"
#include "String.h"

const Termino mockTermino = {3, 2};//+3x^2
const Termino mockTerminoNegativo = {-2, 4};//-2x^4
const Termino mockTerminoPosParaNeg = {2, 4};//-2x^4
const Termino mockTerminoNulo = {0, 0};//
const Termino mockTerminoExp0 = {4, 0};//+4x^0

const int evaluarPositivo = 4;
const int evaluarNegativo = -3;
const int evaluarNulo = 0;

void probarMostrarTermino();
//prueba mostart los datos de termino en pantalla
void probarDarCoeficienteTermino();
//prueba dar coeficiente
void probarDarExponenteTermino();
//prueba dar exponente
void probarCargarCoeficienteTerminoNegativo();
//prueba cargar coeficiente en un termino
void probarCargarExponenteTerminoNegativo();
//prueba cargar exponente en un termino

/*OPERACIONES DE TERMINO*/
//Pruebas de Suma
void probarSumarTerminosPositivos();
void probarSumarTerminosNegativoPositivo();
void probarSumarTerminoConNulo();
/*prueba sumar dos terminos*/
/*PRECONDICION: ambos terminos del mismo exponente*/

//Pruebas Producto
void probarMultiplicarTerminosPositivos();
void probarMultiplicarTerminosPositivoNegativo();
void probarMultiplicarTerminoConNulo();
/*prueba multiplicar dos terminos*/

//Pruebas Evaluavion Termino
void probarEvaluarTerminoPositivo();
void probarEvaluarTerminoNegativo();
void probarEvaluarTerminoNulo();
/*prueba evaluar un termino en base a un valor pasado por parametro*/

#endif /* TestTermino_hpp */
