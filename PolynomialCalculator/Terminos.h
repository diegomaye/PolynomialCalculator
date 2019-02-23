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

void insertarTermino(ListaTerminos &lstTerminos, Termino termino);
/*Ingresa un término a la lista de términos - se inserta ordenado por grado, de mayor a menor - es un procedimiento recursivo*/

//LISTADOS Y CONSULTAS
void listarTerminos(ListaTerminos lstTerminos);
/*Listar todos los términos realizadas, ordenados de exponente mayor a menor*/
int contarTerminos(ListaTerminos lstTerminos);
//Devuelve la cantidad de términos de la lista dada
void borrarTerminos(ListaTerminos &terminos, int exponente);
//Dado un grado, borra los términos en ese grado
/*PRECONDICION: La lista de terminos no puede estar vacía */
Termino primerTermino(ListaTerminos terminos);
//Devuelve el primer término de la lista
/*PRECONDICION: La lista de terminos no puede estar vacía */

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
Boolean listaVacia(ListaTerminos terminos);
/*Devuelve true si la lista de términos es vacía*/
void borrarNodosListaTerminos(ListaTerminos &terminos);
/*Borra todos los nodos de la Lista de términos*/

void normalizarTerminos(ListaTerminos &listaTerminos);
/*Normaliza la lista de términos eliminando términos con coeficiente cero - es un procedimiento recursivo*/
/*PRECONDICION: La lista de términos debe tener más de un término */


#endif /* Terminos_h */
