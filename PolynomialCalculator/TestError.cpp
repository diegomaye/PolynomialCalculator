//
//  TestError.cpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/22/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#include "TestError.h"

void probarTodosMensajesDeError(){
    print(mostrarError(FORMATO_POLINOMIO_INCORRECTO));
    print(mostrarError(FORMATO_POLINOMIO_INCORRECTO));
    print(mostrarError(STRING_ALFANUMERICO));
    print(mostrarError(CANTIDAD_PARAMETROS));
    print(mostrarError(NOMBRE_INCORRECTO));
    print(mostrarError(POLINOMIO_EXISTENTE));
    print(mostrarError(COEFICIENTE_CERO));
    print(mostrarError(FALTA_NOMBRE));
    print(mostrarError(POLINOMIO_NO_EXISTENTE));
    print(mostrarError(COEFICIENTE_NUMERICOS));
    print(mostrarError(CANTIDAD_PARAMETROS_MULTILICACION));
    print(mostrarError(POLINOMIOS_EXISTENTE_MULTIPLICACION));
    print(mostrarError(VALOR_PARA_EVALUAR));
    print(mostrarError(RESULTADO_EVALUAR_ERROR));
    print(mostrarError(RESULTADO_EVALUAR_CORRECTO));
    print(mostrarError(POLINOMIO_NO_EXISTENTE_EN_MEMORIA));
    print(mostrarError(FORMATO_ARCHIVO_INCORRECTO));
    print(mostrarError(NOMBRE_EXTENSION_INCORRECTO));
    print(mostrarError(EXISTE_ARCHIVO));
    print(mostrarError(NO_EXISTE_ARCHIVO));
}
