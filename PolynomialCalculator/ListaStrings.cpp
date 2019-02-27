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
    nuevoElemento->info=c;
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
                while(c[j]!= ' ')
                {
                    strlar(c);

                }
                largo=strlar(c);
                nuevoString=new char[largo+1];
                strcop(nuevoString,c);
                crearListaString(s);
                insertarElementoListaString(s,c); /// cuidado aca, esta copiando el string completo y no solo el pedacito que interesa
                /// sugerencia: ademas de i, usar otro indice j (mirar dibujo de la hojita)
            }

    }



int contarElementos(ListaStrings lista)
{
    if (lista == NULL)
        return 0;
    else
        return 1 + contarElementos(lista->sig);
}

void darStringEnPosicion(ListaStrings lista, int &posicion, String &s)
{


}

void borrarNodosListaStrings(ListaStrings &lista,String &s)
{
    ListaStrings aux= lista;
    while(lista != NULL)
    {
        /// tambien hay que borrar aux-> info
        s=aux->info;
        lista=aux->sig;
        delete aux;
    }
}
