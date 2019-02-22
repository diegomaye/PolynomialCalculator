//
//  Error.cpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/15/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#include "Error.h"

char * mostrarError(Error error){
    int i = 0;
    while(listaErrores[i].value != error){
        i++;
    }
    String mensaje;
    strcrear(mensaje);
    strcop (mensaje, listaErrores[i].descripcion);
    return mensaje;
}
