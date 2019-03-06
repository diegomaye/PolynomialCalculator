//
//  Error.cpp
//  PolynomialCalculator
//
//  Created by Diego, Rodrigo & Pablo.
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
