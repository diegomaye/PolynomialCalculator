//
//  Polinomios.cpp
//  PolynomialCalculator
//
//  Created by Diego, Rodrigo & Pablo.
//  Copyright � 2019 Code4Business. All rights reserved.
//

#include "Polinomios.h"

void crearArbolPolinomios(ABBPolinomios &polinomios){
    polinomios=NULL;
}

void insertarPolinomio(ABBPolinomios &arbolPolinomios, Polinomio polinomio) {
    if (!existeAlMenosUnPolinomioEnABB(arbolPolinomios)) {
        arbolPolinomios = new Nodo;
        arbolPolinomios -> pol = polinomio;
        arbolPolinomios -> hizq = NULL;
        arbolPolinomios -> hder = NULL;

    } else {
        String nombre;
        strcrear(nombre);
        darNombrePolinomio(arbolPolinomios->pol, nombre);
        String nombreIngreso;
        strcrear(nombreIngreso);
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
        String nombrePol;
        strcrear(nombrePol);
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
    String nombrePol;
    strcrear(nombrePol);
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
