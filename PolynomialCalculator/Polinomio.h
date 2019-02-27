//
//  Polinomio.h
//  PolynomialCalculator
//
//  Created by diegomaye on 2/15/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#ifndef Polinomio_h
#define Polinomio_h

#include <stdio.h>
#include "String.h"
#include "Terminos.h"

typedef struct{
    String nombre;
    ListaTerminos terminos;
} Polinomio;

void cargarPolinomio(Polinomio &polinomio, String nombre, ListaTerminos listTerm);
/*Carga los datos del Polinomio*/
void mostrarPolinomio(Polinomio polinomio);
/*Muestra los datos del Polinomio por pantalla*/
void sumarPolinomios(Polinomio polinomio1, Polinomio polinomio2, Polinomio &resultado);
/*Dados dos polinomios devuelve en “resultado” el polinomio resultante de la suma*/
void multiplicarPolinomios(Polinomio polinomio1, Polinomio polinomio2, Polinomio &resultado);
//Dados dos polinomios devuelve en “resultado” el polinomio resultante de la multiplicación.
int evaluarPolinomio(Polinomio polinomio, int evaluar);
/*Dado un polinomio devuelve el resultado numerico de sustituir el entero evaluar en el polinomio.
 Para el caso del polinomio nulo devuelve 0*/
Boolean esRaizPolinomio(Polinomio polinomio, int raiz);
/*Devuelve TRUE si el valor ingresado en raiz devuelve 0 al ejecutar evaluarPolinomio, con el mismo polinomio y evaluar = resultado*/
void darNombrePolinomio(Polinomio polinomio, String &nombre);
/*Dado un polinomio devuelve el nombre del mismo cargado en la variable nombre*/
void darTerminosPolinomio(Polinomio polinomio, ListaTerminos &terminos);
/*Dado un polinomio devuelve todos los termions de este polinomio.*/
Boolean polinomioConMasTerminos(Polinomio pol1, Polinomio pol2);
/*determina si pol1 tiene más cantidad de términos que pol2*/
Boolean polinomiosIgualNombre(Polinomio pol1, Polinomio pol2);
/*determina si pol1 es igual a pol2 en cuyo caso retorna true*/
Boolean polinomioMenorNombre(Polinomio pol1, Polinomio pol2);
/*devuelve si un polinomio tiene un nombre alfabeticamente menor a otro*/
Boolean polinomioNulo(Polinomio pol);
//Devuelve true si el polinomio es el polinomio vacio
void borrarPolinomio(Polinomio &polinomio);
/*dado un nombre de polinomio lo borra de la memoria*/

void bajarPolinomio(Polinomio polinomio, FILE * f);
/*dado un polinomio se escribe este en un archivo*/
void levantarPolinomio(Polinomio &polinomio, FILE * f);
/*dado el nombre de un polinomio se levanta el archivo correspondiente a ese nombre y se carga en polinomio*/
Boolean existePolinomioEnArchivo(Polinomio polinomio);
/*dado un polinomio verifica si el polinomio si existe un archivo con ese nombre de polinomio*/


#endif /* Polinomio_h */
