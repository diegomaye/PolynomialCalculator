#ifndef TESTSTRING_H_INCLUDED
#define TESTSTRING_H_INCLUDED

#include <stdio.h>
#include "String.h"

const String mockAlfanumerico = "alfa1234";
const String mockNoAlfanumerico = "alfa-1234";
char * mockNumerico = "1234";
char * mockNoNumerico = "abcd";
char * mockConvertirANumero = "1234";
char * mockNoConvertirANumero = "1234";
char * mockCantidadPuntosEnString = "alfa.beta";
char * mockCantidadPuntosEnStringMayor = "alfa.beta.gamma";
char * mockValidarExtension = "alfa.txt";
char * mockNoValidarExtension = "alfa.jpg";


void probarEsAlfanumerico();
void probarEsNumerico();
void probarConvertirANumero();
//void probarCantidadPuntosEnString();
void probarValidarExtension();

#endif // TESTSTRING_H_INCLUDED
