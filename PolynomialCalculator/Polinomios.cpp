//
//  Polinomios.cpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/15/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#include "Polinomios.h"

void insertarPolinomio(ABBPolinomios &arbolPolinomios, Polinomio polinomio) {
    if (!existeAlMenosUnPolinomioEnABB(arbolPolinomios)) {
        arbolPolinomios = new Nodo;
        arbolPolinomios -> pol = polinomio;
        arbolPolinomios -> hizq = NULL;
        arbolPolinomios -> hder = NULL;

    } else {
        String nombre; //falta el crear string
        darNombrePolinomio(arbolPolinomios->pol, nombre);
        String nombreIngreso;
        darNombrePolinomio(polinomio, nombreIngreso);
        if (strmen(nombreIngreso, nombre)){
            insertarPolinomio(arbolPolinomios -> hizq, polinomio);
        }
        else insertarPolinomio(arbolPolinomios -> hder, polinomio);
    }
}
Boolean existeAlMenosUnPolinomioEnABB(ABBPolinomios arbolPolinomios) {
    Boolean existe = TRUE;
    if (arbolPolinomios == NULL) {
        existe = FALSE;
    }
    return existe;
}
Boolean existePolinomioEnABB(ABBPolinomios arbolPolinomios, String nombre) {
    if (!existeAlMenosUnPolinomioEnABB(arbolPolinomios)) {
        return FALSE;
    } else {
        String nombrePol; //crear el string
        darNombrePolinomio(arbolPolinomios->pol, nombrePol);
        if (strreq(nombrePol, nombre)) {
            return TRUE;
        } else {
            if (strmen(nombre, nombrePol)) {
                return existePolinomioEnABB(darIzquierdo(arbolPolinomios), nombre);
            } else {
                return existePolinomioEnABB(darDerecho(arbolPolinomios), nombre);
            }
        }
    }
}
void desplegarABB(ABBPolinomios arbolPolinomios) {
    if (arbolPolinomios != NULL) {
        desplegarABB(arbolPolinomios->hizq);
        mostrarPolinomio(arbolPolinomios->pol);
        desplegarABB(arbolPolinomios->hder);
    }
}
Polinomio darRaiz(ABBPolinomios arbolPolinomios) {
    return arbolPolinomios ->pol;
}
ABBPolinomios darIzquierdo(ABBPolinomios arbolPolinomios) {
    return arbolPolinomios ->hizq;
}
ABBPolinomios darDerecho(ABBPolinomios arbolPolinomios) {
    return arbolPolinomios ->hder;
}
void eliminarABB(ABBPolinomios &arbolPolinomios) {
    if (arbolPolinomios != NULL) {
        eliminarABB(arbolPolinomios ->hizq);
        eliminarABB(arbolPolinomios ->hder);
        borrarPolinomio(arbolPolinomios->pol);
        delete arbolPolinomios;
        arbolPolinomios = NULL;
    }
}
Polinomio buscarPolinomio(ABBPolinomios arbol, String nombre) {
    String nombrePol; //llamar al crear string
    darNombrePolinomio(arbol ->pol, nombrePol);
    if (strreq(nombre, nombrePol)) {
        return darRaiz(arbol);
    } else {
        if (strmen(nombre, nombrePol)) {
            return buscarPolinomio(darIzquierdo(arbol), nombre);
        } else {
            return buscarPolinomio(darDerecho(arbol), nombre);
        }
    }
}
