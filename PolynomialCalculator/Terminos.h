//
//  Terminos.h
//  PolynomialCalculator
//
//  Created by diegomaye on 2/15/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#ifndef Terminos_h
#define Terminos_h

#include <stdio.h>
#include "String.h"
#include "Termino.h"

typedef struct nodo_termino {
    Termino termino;
    nodo_termino * sig;
} NodoTermino;

typedef NodoTermino * ListaTerminos;

void mostrarTerminos(ListaTerminos terminos);
/*Muestra todos los termions del polinomio por consola, ordenados en forma descendente por exponente.*/
void insertarTermino(ListaTerminos &terminos, Termino termino);
/*Ingresa un término a la lista de términos - se inserta ordenado por grado, de mayor a menor - es un procedimiento recursivo*/
/*PRECONDICION: El termino a ser ingresado tiene un grado que no existe en la lista de terminos*/
void insBack(ListaTerminos &terminos, Termino termino);
/*inserta un termino al final de la lista*/
Boolean existeGrado(ListaTerminos &terminos, Termino termino);
/*devuelve true si ese grado ya existe en la lista*/
int contarTerminos(ListaTerminos terminos);
//Devuelve la cantidad de términos de la lista dada
Boolean mayorCantidadDeTerminos(ListaTerminos terminos1, ListaTerminos terminos2);
//Devuelve true si terminos1 tiene mayor cantidad de terminos que terminos2
void borrarTermino(ListaTerminos &terminos, int exponente);
//Dado un grado, borra los términos en ese grado
/*PRECONDICION: La lista de terminos no puede estar vacía */
Termino primerTermino(ListaTerminos terminos);
//Devuelve el primer término de la lista
/*PRECONDICION: La lista de terminos no puede estar vacía */
Boolean mayorGrado(ListaTerminos terminos1, ListaTerminos terminos2);
//Dados dos listados de terminos determina terminos1 es de mayor grado que terminos2.

void sumarTerminos(ListaTerminos terminos1, ListaTerminos terminos2, ListaTerminos &terminosResultadoSuma);
/*Dadas dos listas de terminos devuelve en terminosResultadoSuma el resultado de sumar mabas listas*/
/*PRECONDICION: terminos1 tiene mayor cantidad de terminos que terminos2*/
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

void bajarTerminos(ListaTerminos terminos, const char* nomArch);
void levantarTerminos(ListaTerminos &terminos, const char* nomArch);

#endif /* Terminos_h */
