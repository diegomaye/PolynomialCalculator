//
//  ListaStrings.cpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/15/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#include "ListaStrings.h"

void crearListaString(ListaStrings &s)
{
    s=NULL;
}

Boolean listaStringVacia(ListaStrings s)
{
    Boolean resu=FALSE;
    if(s == NULL)
    {
      resu=TRUE;
    }

    return resu;
}

void darString(ListaStrings ls,String &s)
{
    strcop(s,ls->parametro);
}


void insertarElementoListaString(ListaStrings &s,String c)
{
    ListaStrings nuevoElemento= new NodoString;
    nuevoElemento->parametro=c;
    nuevoElemento->sig=NULL;
    if(s==NULL)
    {
        s=nuevoElemento;
    }
    else
    {
         ListaStrings aux = s;
        while(aux->sig != NULL)
        {
            aux=aux->sig;
        }
        aux->sig=nuevoElemento;
    }

}

void darListaSeparadaPorEspacios(String c, ListaStrings &s)
{
    int i=0;
    int j=0;
    int largo=0;
    String nuevoString;
    strcrear(nuevoString);
    while(c[i] != '\0')
    {
        while(c[i] == ' ')
        {
            i++;
        }
                while(c[j]!= ' ') /// no solo el espacio, sino tmb \0
                {
                    strlar(c);
                    j++;
                }
                largo=strlar(c);
                nuevoString=new char[largo+1];
                strcop(nuevoString,c);
                crearListaString(s);
                insertarElementoListaString(s,c);
            }

    }



int contarElementos(ListaStrings lista)
{
    if (lista == NULL)
        return 0;
    else
        return 1 + contarElementos(lista->sig);
}

void darStringEnPosicion(ListaStrings lista, int posicion, String &s)
{
    /// re-pensarlo, ir restando posicion de a 1 en cada llamada recursiva
    /// cuando posicion llega a 1 => devuelvo el string de ese nodo
    /// por lo menos 2 pasos base van a haber
    posicion=0;
    if(lista != NULL)
    {
        if(strreq(lista->parametro,s)) /// esta comparacion no va
            darString(lista,s); /// mejor llamar a strcop
        else
        {
            posicion=posicion+1;
            darStringEnPosicion(lista,posicion,s);
        }
    }

}

void borrarNodosListaStrings(ListaStrings &lista)
{

    if(lista != NULL)
    {
        ListaStrings aux= lista;
        lista=aux->sig;
        strdestruir(aux->parametro);
        delete aux;
        borrarNodosListaStrings(lista);
    }
}
