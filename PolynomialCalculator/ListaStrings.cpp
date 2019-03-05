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
void strcopVariable(String &nuevoString,String strEntrada,int largo,int i)
{
    nuevoString= new char[largo+1];
    int posInicial=i-largo;
    int j;
    int t=0;
    for(j=posInicial;j<=i;j++)
    {
        nuevoString[t]=strEntrada[j];
        t++;
    }
    nuevoString[t]='\0';

}

void darListaSeparadaPorEspacios(String strEntrada, ListaStrings &lstComando)
{
    int i=0,largo=0;
    String nuevoString;
    strcrear(nuevoString);
    crearListaString(lstComando);
    while(strEntrada[i] != '\0')
    {
        while(strEntrada[i] == ' ')
        {
            i++;
        }
        while((strEntrada[i]!= ' ') && (strEntrada[i] != '\0'))
        {
            i++;
            largo++;
        }

        strcopVariable(nuevoString,strEntrada,largo,i);
        insertarElementoListaString(lstComando,nuevoString);
        largo=0;
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
    if(lista != NULL)
    {
        if(posicion == 1)
            strcop(s,lista->parametro);
        else
            darStringEnPosicion(lista->sig,posicion-1,s);
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



