//
//  ListaStrings.h
//  PolynomialCalculator
//
//  Created by diegomaye on 2/15/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#ifndef ListaStrings_h
#define ListaStrings_h

#include <stdio.h>
#include "String.h"

typedef struct nodo_string {
                            String parametro;
                            nodo_string * sig;
                            } NodoString;

typedef NodoString * ListaStrings;


void crearListaString(ListaStrings &s);
/*Crea una Lista de String vacia*/
Boolean listaStringVacia(ListaStrings s);
/*Devuelve TRUE si la lista de String es vacia*/
void insertarElementoListaString(ListaStrings &s,String c);
/*Inserta un nuevo String al final de la lista*/
void darListaSeparadaPorEspacios(String c, ListaStrings &s);
/*devuelve la lista de strings a partir de un string con los comandos ingresados por pantalla*/
int contarElementos(ListaStrings lista);
/*dada una lista de Strings, devuelve la cantidad de strings que tiene*/
void darStringEnPosicion(ListaStrings lista, int posicion, String &s);
/*dado un string y una posición  devuelve el string en esa posición de la lista*/
void borrarNodosListaStrings(ListaStrings &lista);
/*Borra todos los nodos de la Lista de String*/
void strcopVariable(String &nuevoString,String strEntrada,int largo,int i);




#endif /* ListaStrings_h */
