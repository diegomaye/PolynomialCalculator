//
//  Error.\n"},h
//  PolynomialCalculator
//
//  Created by Diego, Rodrigo & Pablo.\n"},
//  Copyright © 2019 Code4Business.\n"}, All rights reserved.\n"},
//

#ifndef Error_h
#define Error_h

#include <stdio.h>
#include "String.h"

typedef enum {
    FORMATO_POLINOMIO_INCORRECTO,
    STRING_ALFANUMERICO,
    STRING_ALFANUMERICO1,
    STRING_ALFANUMERICO2,
    STRING_ALFANUMERICO3,
    CANTIDAD_PARAMETROS,
    NOMBRE_INCORRECTO,
    POLINOMIO_EXISTENTE,
    COEFICIENTE_CERO,
    FALTA_NOMBRE,
    POLINOMIO_NO_EXISTENTE,
    POLINOMIO_NO_EXISTENTE1,
    POLINOMIO_NO_EXISTENTE2,
    COEFICIENTE_NUMERICOS,
    CANTIDAD_PARAMETROS_MULTILICACION,
    POLINOMIOS_EXISTENTE_MULTIPLICACION,
    VALOR_PARA_EVALUAR,
    RESULTADO_EVALUAR_ERROR,
    RESULTADO_EVALUAR_CORRECTO,
    POLINOMIO_NO_EXISTENTE_EN_MEMORIA,
    FORMATO_ARCHIVO_INCORRECTO,
    NOMBRE_EXTENSION_INCORRECTO,
    EXISTE_ARCHIVO,
    NO_EXISTE_ARCHIVO,
    COMANDO_INGRESADO_NO_EXISTE
} Error;

typedef struct { Error value; char * descripcion; } Mensaje;

const Mensaje listaErrores[] = {
    {FORMATO_POLINOMIO_INCORRECTO, "El formato del nombre del polinomio no es correcto.\n"},
    {STRING_ALFANUMERICO, "El nombre del Polinomio debe ser alfanumérico"},
    {STRING_ALFANUMERICO1, "El nombre del Polinomio del primer parametro debe ser alfanumérico"},
    {CANTIDAD_PARAMETROS, "Cantidad de parámetros incorrecta.\n"},
    {NOMBRE_INCORRECTO, "El formato del nombre del polinomio no es correcto.\n"},
    {POLINOMIO_EXISTENTE, "El polinomio ha ser creado ya existe.\n"},
    {COEFICIENTE_CERO, "El primer coeficiente no puede ser cero.\n"},
    {FALTA_NOMBRE, "Cantidad de parámetros incorrecta.\n"},
    {POLINOMIO_NO_EXISTENTE, "Polinomio ingresado no existe en el ABB.\n"},
    {POLINOMIO_NO_EXISTENTE1, "El nombre del Polinomio del segundo parametro debe ser alfanumérico.\n"},
    {POLINOMIO_NO_EXISTENTE2, "El nombre del Polinomio del tercer parametro debe ser alfanumérico.\n"},
    {COEFICIENTE_NUMERICOS, "Los coeficientes del polinomio tiene que ser números.\n"},
    {CANTIDAD_PARAMETROS_MULTILICACION, "La multiplicación debe tener 3 parámetros.\n"},
    {POLINOMIOS_EXISTENTE_MULTIPLICACION, "Los polinomios a multiplicar deben de existir en el ABB de Polinomios.\n"},
    {VALOR_PARA_EVALUAR, "El valor a evaluar debe ser numérico.\n"},
    {RESULTADO_EVALUAR_ERROR, "No es raiz.\n"},
    {RESULTADO_EVALUAR_CORRECTO, "Si es raiz.\n"},
    {POLINOMIO_NO_EXISTENTE_EN_MEMORIA, "No existe ningún polinomio en memoria.\n"},
    {FORMATO_ARCHIVO_INCORRECTO, "El formato del nombre del archivo no es correcto.\n"},
    {NOMBRE_EXTENSION_INCORRECTO, "El nombre o la extensión no es correcto.\n"},
    {EXISTE_ARCHIVO, "Desea sobreescribir el archivo?"},
    {NO_EXISTE_ARCHIVO, "No existe un archivo en el disco con el nombre ingresado.\n"},
    {COMANDO_INGRESADO_NO_EXISTE, "El comando ingresado es incorrecto.\n"}
    
};

char* mostrarError(Error error);

#endif /* Error_h */
