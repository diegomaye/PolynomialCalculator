//
//  TestTerminos.hpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/24/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#ifndef TestTerminos_h
#define TestTerminos_h

#include <stdio.h>
#include "Termino.h"
#include "String.h"
#include "Terminos.h"

void probarMostarTerminosL1(ListaTerminos terminos);
void probarMostarTerminosL2(ListaTerminos terminos);
void probarMostarTerminosL3(ListaTerminos terminos);
/*Prueba mostrar termino con los polinomios mokeados.*/

void probarInsertarTerminoAlFinal(ListaTerminos &terminos);
void probarInsertarTerminoEnElMedio(ListaTerminos &terminos);
void probarInsertarTerminoAlPrincipio(ListaTerminos &terminos);
void probarInsertarTerminoEnListaVacia(ListaTerminos &terminos);
/*Prueba insertar terminos con exponente excedido, con exponente menor, etc.*/

void probarInsBack(ListaTerminos &terminos);
void probarInsBackNulo(ListaTerminos &terminos);
void probarInsBackEnVacio(ListaTerminos &terminos);
/*Pruebas sobre el insBack, insertar al final de la lista.*/

void probarExisteGradoUno(ListaTerminos terminos);
void probarExisteGradoTres(ListaTerminos terminos);
void probarExisteGradoTreinta(ListaTerminos terminos);
/*Evalua el la existencia de grados en el polinomio con la funcion existeGrado(...).*/

void probarContarTerminos(ListaTerminos terminos);
void probarContarTerminoEnListaVacia(ListaTerminos terminos);
/*Probar la cuenta de terminos en la lista de termios*/

void probarBorrarTerminoAlPrincipio(ListaTerminos &terminos);
void probarBorrarTerminoAlFinal(ListaTerminos &terminos);
/*Prueba borrar un termino con borrarTermino(...)*/

void probarPrimerTermino(ListaTerminos terminos);
/*Prueba mostar primer termino de polinomio con primerTermino(...)*/

void sumarTerminos(ListaTerminos terminos1, ListaTerminos terminos2, ListaTerminos &terminosResultadoSuma);
/*Dados dos términos devuelve en “terminosResultadoSuma” el resultado de la suma*/
void multiplicarTerminos(ListaTerminos terminos1, ListaTerminos terminos2, ListaTerminos &terminosResultadoMultiplicacion);
/*Dados dos términos devuelve en “terminosResultadoMutiplicacion” el resultado de la multiplicación*/

int evaluarTerminos(ListaTerminos terminos, int evaluar);
/*Dada la lista de términos ingresada se reemplaza los términos por el término pasado por parámetro.*/
Boolean esRaizTerminos(ListaTerminos terminos, int raiz);
/*Dado un entero, devuelve true si es raiz*/

Termino ultimaTerminoAgregado(ListaTerminos terminos);
/*Devuelve el último término ingresado*/
/*PRECONDICION: La lista tiene al menos un elemento.*/
Boolean listaVacia(ListaTerminos terminos);
/*Devuelve true si la lista de términos es vacía*/
void borrarNodosListaTerminos(ListaTerminos &terminos);
/*Borra todos los nodos de la Lista de términos*/

void normalizarTerminos(ListaTerminos &terminos);
/*Normaliza la lista de términos eliminando términos con coeficiente cero - es un procedimiento recursivo*/
/*PRECONDICION: La lista de términos debe tener más de un término */

#endif /* TestTerminos_hpp */
