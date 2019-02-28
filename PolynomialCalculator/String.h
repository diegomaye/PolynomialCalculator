//
//  String.h
//  Obligatorio2-P2
//
//  Created by diegomaye on 11/23/18.
//  Copyright © 2018 Diego Maye. All rights reserved.
//

#ifndef String_h
#define String_h

#include <stdio.h>
#include <stdlib.h>
#include "Boolean.h"

const int MAX = 80;
const char VACIO = '\0';
const char ENTER = '\n';

typedef char * String;

void strcrear(String &s);
/*crea un string vacio solo con \0*/
void strdestruir(String &s);
/*libera la memoria dinamica usada por el string*/
int strlar(String s);
/*calcula el largo del string*/
void print(String s);
/*despliega el string*/
void printIn(String s, int espacio);
/*despliega un string con espacion al final*/
void printSpaces(int espacio);
/*imprime espacios*/
void printEnter();
/*imprime saltos de linea*/
void scan(String &s);
/*carga el string por teclado*/
Boolean strmen(String s1, String s2);
/*determina si s1 es alfabeticamente menor que s2*/
Boolean strreq(String s1, String s2);
/*determina si los strings son iguales*/
void strcop(String &s1, String s2);
/*copia el segmento en el primero*/
void strcon(String &s1, String s2);
/*concatena el segundo al final del primero*/
void strswp(String &s1, String &s2);
/*intercambia ambos string*/
Boolean esAlfanumerico(String s);
/*devuelve true si el string es alfanumérico*/
Boolean esNumerico(String s);
/*devuelve true si el string es numérico*/
int convertirANumero(String s);
/*devuelve int con el valor del string*/
Boolean validarExtension(String nombreArchivo);
/*devuelve true si el nombre y la extensión son correctos*/
Boolean cantidadPuntosEnString(String s);



//Almacenamiento
void toString(String s, FILE * f);
/*dado un string y un archivo, almacena el string en un archivo*/
void fromString(String &s, FILE * f);
/*dado un archivo y un string pasado por valor, carga en el string el contenido del archivo*/

#endif /* String_h */

