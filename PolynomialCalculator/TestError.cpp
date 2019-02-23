//
//  TestError.cpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/22/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#include "TestError.h"

void probarTodosMensajesDeError(){
    printf("///////////////// TESTS DE Error.v /////////////////");
    print(mostrarError(FORMATO_POLINOMIO_INCORRECTO));
    printEnter();
    print(mostrarError(FORMATO_POLINOMIO_INCORRECTO));
    printEnter();
    print(mostrarError(STRING_ALFANUMERICO));
    printEnter();
    print(mostrarError(CANTIDAD_PARAMETROS));
    printEnter();
    print(mostrarError(NOMBRE_INCORRECTO));
    printEnter();
    print(mostrarError(POLINOMIO_EXISTENTE));
    printEnter();
    print(mostrarError(COEFICIENTE_CERO));
    printEnter();
    print(mostrarError(FALTA_NOMBRE));
    printEnter();
    print(mostrarError(POLINOMIO_NO_EXISTENTE));
    printEnter();
    print(mostrarError(COEFICIENTE_NUMERICOS));
    printEnter();
    print(mostrarError(CANTIDAD_PARAMETROS_MULTILICACION));
    printEnter();
    print(mostrarError(POLINOMIOS_EXISTENTE_MULTIPLICACION));
    printEnter();
    print(mostrarError(VALOR_PARA_EVALUAR));
    printEnter();
    print(mostrarError(RESULTADO_EVALUAR_ERROR));
    printEnter();
    print(mostrarError(RESULTADO_EVALUAR_CORRECTO));
    printEnter();
    print(mostrarError(POLINOMIO_NO_EXISTENTE_EN_MEMORIA));
    printEnter();
    print(mostrarError(FORMATO_ARCHIVO_INCORRECTO));
    printEnter();
    print(mostrarError(NOMBRE_EXTENSION_INCORRECTO));
    printEnter();
    print(mostrarError(EXISTE_ARCHIVO));
    printEnter();
    print(mostrarError(NO_EXISTE_ARCHIVO));
    printEnter();
}
