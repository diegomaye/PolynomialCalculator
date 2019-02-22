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
#include "Termino.h"

typedef struct nodo_termino {
    Termino termino;
    nodo_termino * sig;
} NodoTermino;

typedef NodoTermino * ListaTerminos;

#endif /* Terminos_h */
