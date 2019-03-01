//
//  TestPolinomio.hpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/28/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#ifndef TestPolinomio_h
#define TestPolinomio_h

#include <stdio.h>

void probarCargarPolinomio();
/*Prueba carga los datos del Polinomio*/
void probarMostrarPolinomio();
/*Prueba la muestra los datos del Polinomio por pantalla*/
void probarSumarPolinomios();
/*Prueba que dados dos polinomios devuelve en “resultado” el polinomio resultante de la suma*/
void probarMultiplicarPolinomios();
//Prueba que dados dos polinomios devuelve en “resultado” el polinomio resultante de la multiplicación.
void probarEvaluarPolinomio();
/*Prueba que dado un polinomio devuelve el resultado numerico de sustituir el entero evaluar en el polinomio.
 Para el caso del polinomio nulo devuelve 0*/
void probarEsRaizPolinomio();
/*Prueba el caso en el que erRaizPolinomio(...) devuelve TRUE si el valor ingresado en raiz devuelve 0 al ejecutar evaluarPolinomio, con el mismo polinomio y evaluar = resultado*/
void probarDarNombrePolinomio();
/*Prueba que dado un polinomio devuelve el nombre del mismo cargado en la variable nombre*/
void probarDarTerminosPolinomio();
/*Prueba dado un polinomio devuelve todos los termions de este polinomio.*/
void probarPolinomioConMasTerminos();
/*Prueba que terminosL1 tenga mas terminos que terminosL2*/
void probarPolinomiosIgualNombre();
/*Prueba que los dos polinomios ingresados tengan el mismo nombre*/
void probarPolinomioMenorNombre();
/*Prueba que un polinomio tenga un nombre alfanumericamente menor a otro*/
void probarPolinomioNulo();
//Evalua al polinomio acio
void probarborrardoDePolinomio();
/*Borra un polinomio de memoria*/

#endif /* TestPolinomio_h */
