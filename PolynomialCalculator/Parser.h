//
//  Parser.h
//  PolynomialCalculator
//
//  Created by Diego, Rodrigo & Pablo.
//

#ifndef Parser_h
#define Parser_h

#include <stdio.h>
#include "Error.h"
#include "Archivo.h"
#include "Polinomios.h"
#include "ListaStrings.h"

typedef enum {
    CREAR,
    SUMAR,
    MULTIPLICAR,
    EVALUAR,
    ESRAIZ,
    MOSTRAR,
    GUARDAR,
    RECUPERAR,
    AYUDA,
    SALIR
} Comando;


static const String COMMANDO[] = {
    "crear\0",
    "sumar\0",
    "multiplicar\0",
    "evaluar\0",
    "esRaiz\0",
    "mostrar\0",
    "guardar\0",
    "recuperar\0",
    "ayuda\0",
    "salir\0"
};

void crearPolinomio(ABBPolinomios &polinomios, ListaStrings commando);
/*dado un comando, crea un polinomio en el ABB*/

void sumarPolinomios(ABBPolinomios &polinomios, ListaStrings commando);
/*dado un comando y dos polinomios, los suma*/

void multiplicarPolinomios(ABBPolinomios &polinomios, ListaStrings commando);
/*dado un comando y dos polinomios, los multiplica*/

void evalarPolinomio(ABBPolinomios polinomios, ListaStrings commando);
/*dado un comando y un polinomio, lo evalua*/

void esraizPolinomio(ABBPolinomios polinomios, ListaStrings commando);
/*dado un comando y un polinomio, determina si es raiz*/

void mostrarPolinomio(ABBPolinomios &polinomios, ListaStrings commando);
/*dado un comando, lista todos los polinomios en pantalla*/

void guardarPolinomio(ABBPolinomios &polinomios, ListaStrings commando);
/*dado un comando, guarda un polinomio en un archivo*/
void recuperarPolinomio(ABBPolinomios &polinomios, ListaStrings commando);
/*dado un comando, recupera un archivo*/
void ayuda(ABBPolinomios &polinomios, ListaStrings comando);
/*muestra todos los comandos del sistema*/
Boolean salir(ABBPolinomios &polinomios, ListaStrings comando);
/*dado un comando, se sale del prpgrama*/
/*Funciones de soporte para validaciones*/
void validarEvaluarEsRaiz(ABBPolinomios polinomios, ListaStrings comando, String &nombrePolinomio, int &resultado, Boolean &valida);
#endif /* Parser_h */
