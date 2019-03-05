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
#include "Polinomio.h"

void mockPolinomiosPruebaCargar(Polinomio &polinomio1, Polinomio &polinomio2, Polinomio &polinomio3, ListaTerminos &terminosL1, ListaTerminos &terminosL2, ListaTerminos &terminosL3);

void probarSumaPolinomiosIgualLargo(Polinomio &polinomio1, Polinomio &polinomio2);
void probarSumaPolinomiosDiferenteLargo(Polinomio &polinomio1, Polinomio &polinomio2);
void probarSumaPolinomioNulo(Polinomio polinomio1);
/*Pruebas de la multiplicación.*/
void probarMultiplicarPolinomiosIgualLargo(Polinomio &polinomio1, Polinomio &polinomio2);
void probarMultiplicarPolinomiosDiferenteLargo(Polinomio &polinomio1, Polinomio &polinomio2);
void probarMultiplicarPolinomioNulo(Polinomio polinomio1);
/*Pruebas del producto.*/
void probarEvaluarPolinomio(Polinomio polinomio);
/*Prueba que dado un polinomio devuelve el resultado numerico de sustituir el entero evaluar en el polinomio.
 Para el caso del polinomio nulo devuelve 0*/
void probarEsRaizPolinomio(Polinomio polinomio);
/*Prueba el caso en el que erRaizPolinomio(...) devuelve TRUE si el valor ingresado en raiz devuelve 0 al ejecutar evaluarPolinomio, con el mismo polinomio y evaluar = resultado*/
void probarDarNombrePolinomio(Polinomio polinomio);
/*Prueba que dado un polinomio devuelve el nombre del mismo cargado en la variable nombre*/
void probarDarTerminosPolinomio(Polinomio polinomio);
/*Prueba dado un polinomio devuelve todos los termions de este polinomio.*/
void probarPolinomioConMasTerminos(Polinomio polinomio1, Polinomio polinomio2);
/*Prueba que terminosL1 tenga mas terminos que terminosL2*/
void probarPolinomiosIgualNombre(Polinomio polinomio1, Polinomio polinomio2);
/*Prueba que los dos polinomios ingresados tengan el mismo nombre*/
void probarPolinomioMenorNombre(Polinomio polinomio1, Polinomio polinomio2);
/*Prueba que un polinomio tenga un nombre alfanumericamente menor a otro*/
void probarPolinomioNulo();
//Evalua al polinomio vacio
void probarBorradoDePolinomio(Polinomio polinomio);
/*Borra un polinomio de memoria*/

#endif /* TestPolinomio_h */
