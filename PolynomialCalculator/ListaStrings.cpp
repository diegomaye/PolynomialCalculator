//
//  ListaStrings.cpp
//  PolynomialCalculator
//
//  Created by Diego, Rodrigo & Pablo.
//

#include "ListaStrings.h"

void crearListaString(ListaStrings &listaString){
    listaString = NULL;
}

Boolean listaStringVacia(ListaStrings s){
    Boolean resu=FALSE;
    if(s == NULL){
      resu=TRUE;
    }

    return resu;
}


void insertarElementoListaString(ListaStrings &s,String c){
    ListaStrings nuevoElemento= new NodoString;
    nuevoElemento->parametro=c;
    nuevoElemento->sig=NULL;
    if(s==NULL){
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
void devolverStringConLargoEnPosicion(String &nuevoString, String strEntrada, int largo, int i){
    nuevoString = new char[largo + 1];
    int j, posInicial = i-largo, t = 0;
    for(j = posInicial; j<i ;j++){
        nuevoString[t]=strEntrada[j];
        t++;
    }
    nuevoString[t] = VACIO;
}

void darListaSeparadaPorEspacios(String strEntrada, ListaStrings &lstComando){
    int i=0, largo=0;
    String nuevoString;
    strcrear(nuevoString);
    crearListaString(lstComando);
    while(strEntrada[i] != VACIO)
    {
        while(strEntrada[i] == ' ')
        {
            i++;
        }
        while((strEntrada[i]!= ' ') && (strEntrada[i] != VACIO))
        {
            i++;
            largo++;
        }
        devolverStringConLargoEnPosicion(nuevoString, strEntrada, largo, i);
        insertarElementoListaString(lstComando, nuevoString);
        largo=0;
    }
}

int contarElementos(ListaStrings lista){
    if (lista == NULL)
        return 0;
    else
        return 1 + contarElementos(lista->sig);
}

void darStringEnPosicion(ListaStrings lista, int posicion, String &enPosicion){
    if(lista != NULL){
        if(posicion == 0)
            strcop(enPosicion, lista->parametro);
        else
            darStringEnPosicion(lista->sig,posicion-1, enPosicion);
    }
}

void borrarNodosListaStrings(ListaStrings &lista){
    if(lista != NULL){
        ListaStrings aux = lista;
        lista = aux->sig;
        strdestruir(aux->parametro);
        delete aux;
        borrarNodosListaStrings(lista);
    }
}



