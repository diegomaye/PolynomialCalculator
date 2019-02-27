//
//  Polinomio.cpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/15/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#include "Polinomio.h"

void cargarPolinomio(Polinomio &polinomio, String nombre, ListaTerminos listTerm){
    polinomio.nombre = nombre;
    polinomio.terminos = listTerm;
}

void mostrarPolinomio(Polinomio polinomio){
    print(polinomio.nombre);
    printf("=");
    mostrarTerminos(polinomio.terminos);
}

void sumarPolinomios(Polinomio polinomio1, Polinomio polinomio2, Polinomio &resultado){
    if(mayorCantidadDeTerminos(polinomio1.terminos, polinomio2.terminos)){
        sumarTerminos(polinomio1.terminos, polinomio2.terminos, resultado.terminos);
    }
    else {
        sumarTerminos(polinomio2.terminos, polinomio1.terminos, resultado.terminos);
    }
}

void multiplicarPolinomios(Polinomio polinomio1, Polinomio polinomio2, Polinomio &resultado){
    multiplicarTerminos(polinomio1.terminos, polinomio2.terminos, resultado.terminos);
}

int evaluarPolinomio(Polinomio polinomio, int evaluar){
    return evaluarTerminos(polinomio.terminos, evaluar);
}

Boolean esRaizPolinomio(Polinomio polinomio, int raiz){
    return esRaizTerminos(polinomio.terminos, raiz);
}

void darNombrePolinomio(Polinomio polinomio, String &nombre){
    nombre = polinomio.nombre;
}

void darTerminosPolinomio(Polinomio polinomio, ListaTerminos &terminos){
    terminos = polinomio.terminos;
}

Boolean polinomioConMasTerminos(Polinomio pol1, Polinomio pol2){
    return mayorCantidadDeTerminos(pol1.terminos, pol2.terminos);
}

Boolean polinomiosIgualNombre(Polinomio pol1, Polinomio pol2){
    return strreq(pol1.nombre, pol2.nombre);
}
Boolean polinomioMenorNombre(Polinomio pol1, Polinomio pol2){
    return strmen(pol1.nombre, pol2.nombre);
}
Boolean polinomioNulo(Polinomio pol){
    if (pol.terminos == NULL)
        return TRUE;
    else
        return FALSE;
}

void borrarPolinomio(Polinomio &polinomio){
    borrarNodosListaTerminos(polinomio.terminos);
}

void bajarPolinomio(Polinomio polinomio, FILE * f){
    //????????????
}

void levantarPolinomio(Polinomio &polinomio, FILE * f){
    //????????????
}

Boolean existePolinomioEnArchivo(Polinomio polinomio){
    return TRUE;
    //????????????
}

