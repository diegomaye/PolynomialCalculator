//
//  Error."},h
//  PolynomialCalculator
//
//  Created by diegomaye on 2/15/19."},
//  Copyright © 2019 Code4Business."}, All rights reserved."},
//

#ifndef Error_h
#define Error_h

#include <stdio.h>
#include "String.h"

typedef enum {
    FORMATO_POLINOMIO_INCORRECTO,
    STRING_ALFANUMERICO,
    CANTIDAD_PARAMETROS,
    NOMBRE_INCORRECTO,
    POLINOMIO_EXISTENTE,
    COEFICIENTE_CERO,
    FALTA_NOMBRE,
    POLINOMIO_NO_EXISTENTE,
    COEFICIENTE_NUMERICOS,
    CANTIDAD_PARAMETROS_MULTILICACION,
    POLINOMIOS_EXISTENTE_MULTIPLICACION,
    VALOR_PARA_EVALUAR,
    RESULTADO_EVALUAR_ERROR,
    RESULTADO_EVALUAR_CORRECTO,
    POLINOMIO_NO_EXISTENTE_EN_MEMORIA,
    FORMATO_ARCHIVO_INCORRECTO,
    NOMBRE_EXTENSION_INCORRECTO,
    EXISTE_ARCHIVO,NO_EXISTE_ARCHIVO
} Error;

typedef struct { Error value; char * descripcion; } Mensaje;

const Mensaje listaErrores[] = {
    {FORMATO_POLINOMIO_INCORRECTO, "El formato del nombre del polinomio no es correcto."},
    {STRING_ALFANUMERICO, "El nombre del Polinomio debe ser alfanumérico"},
    {CANTIDAD_PARAMETROS, "Cantidad de parámetros incorrecta."},
    {NOMBRE_INCORRECTO, "El formato del nombre del polinomio no es correcto."},
    {POLINOMIO_EXISTENTE, "El polinomio ya existe."},
    {COEFICIENTE_CERO, "El primer coeficiente no puede ser cero."},
    {FALTA_NOMBRE, " Cantidad de parámetros incorrecta."},
    {POLINOMIO_NO_EXISTENTE, "Polinomio ingresado no existe en el ABB."},
    {COEFICIENTE_NUMERICOS, " Los coeficientes del polinomio tiene que ser números."},
    {CANTIDAD_PARAMETROS_MULTILICACION, "La multiplicación debe tener 3 parámetros."},
    {POLINOMIOS_EXISTENTE_MULTIPLICACION, "Los polinomios a multiplicar deben de existir en el ABB de Polinomios."},
    {VALOR_PARA_EVALUAR, "El valor a evaluar debe ser numérico."},
    {RESULTADO_EVALUAR_ERROR, "No es raiz."},
    {RESULTADO_EVALUAR_CORRECTO, "Si es raiz."},
    {POLINOMIO_NO_EXISTENTE_EN_MEMORIA, "No existe ningún polinomio en memoria."},
    {FORMATO_ARCHIVO_INCORRECTO, "El formato del nombre del archivo no es correcto."},
    {NOMBRE_EXTENSION_INCORRECTO, "El nombre o la extensión no es correcto."},
    {EXISTE_ARCHIVO, "Desea sobreescribir el archivo?"},
    {NO_EXISTE_ARCHIVO, "No existe un archivo en el disco con el nombre ingresado."}
};

char* mostrarError(Error error);

#endif /* Error_h */
