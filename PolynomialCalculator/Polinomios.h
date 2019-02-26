//
//  Polinomios.h
//  PolynomialCalculator
//
//  Created by diegomaye on 2/15/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#ifndef Polinomios_h
#define Polinomios_h

#include <stdio.h>
#include "Polinomio.h"

typedef struct nodo_polinomio {
    			Polinomio pol;
    			nodo_polinomio * hizq;
    			nodo_polinomio * hder;
                } Nodo;

typedef Nodo * ABBPolinomios;

void insertarPolinomio (ABBPolinomios &arbolPolinomios, Polinomio polinomio);
//inserta un polinomio en el árbol binario de búsqueda de polinomios
Boolean existeAlMenosUnPolinomioEnABB(ABBPolinomios arbolPolinomios);
//devuelve si existe al menos un polinomio en memoria
Boolean existePolinomioEnABB(ABBPolinomios arbolPolinomios, String nombre);
//devuelve si existe un polinomio con ese nombre
void desplegarABB(ABBPolinomios arbolPolinomios);
//desplega el arbol binario de búsqueda de polinomios por pantalla
Polinomio darRaiz(ABBPolinomios arbolPolinomios);
//PRECONDICION:arbolPolinomios no es vacío - Devuelve la raíz del árbol
ABBPolinomios darIzquierdo(ABBPolinomios arbolPolinomios);
//PRECONDICION:arbolPolinomios no es vacío - Devuelve el hijo izquierdo del árbol
ABBPolinomios darDerecho(ABBPolinomios arbolPolinomios);
//PRECONDICION:arbolPolinomios no es vacío - Devuelve el hijo derecho del árbol
void eliminarABB(ABBPolinomios &arbolPolinomios);
//elimina el arbol binario de búsqueda de polinomios en memoria
Polinomio buscarPolinomio(ABBPolinomios arbol, String nombre);
//devuelve si existe un polinomio con ese nombre
/*PRECONDICION:el polinomio con ese nombre debe existir en arbol*/


#endif /* Polinomios_h */
