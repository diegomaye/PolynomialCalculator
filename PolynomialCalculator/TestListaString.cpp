#include "TestListaString.h"

void probarListaVacia()
{
    ListaStrings ls;
    //crearListaString(ls);
    printf("\nPrueba si una lista de string es vacia");

    if(listaStringVacia(ls))
        printf("\nTRUE:LA LISTA ES VACIA");
    else
        printf("\nFALSE:LA LISTA NO ES VACIA");

}

void probarInsertarListaString()
{
    ListaStrings ls;
    crearListaString(ls);
    String string1,string2,string3;
    strcrear(string1);
    strcrear(string2);
    strcrear(string3);
    string1="crear";
    string2="pepe";
    string3="13";
    insertarElementoListaString(ls,string1);
    insertarElementoListaString(ls,string2);
    insertarElementoListaString(ls,string3);
    printEnter();

    if(listaStringVacia(ls))
        printf("\nLa LISTA ESTA VACIA");
    else
    {
         while(ls!=NULL)
        {
            print(ls->parametro);
            printEnter();
            ls=ls->sig;

        }
    }
}
void probarDarListaSeparadaPorEspacios()
{
    ListaStrings lista;
    crearListaString(lista);
    String entrada;
    strcrear(entrada);
    entrada=" crear  pepe 13";
    darListaSeparadaPorEspacios(entrada,lista);
    printEnter();
    while(lista!= NULL)
    {

        String campo= lista->parametro;
        printf("COMANDO:\n");
        print(campo);
        printEnter();
        lista=lista->sig;
    }
}

void probarContarElementosListaString()
{
    int total;
    ListaStrings ls;
    crearListaString(ls);
    String string1,string2,string3;
    strcrear(string1);
    strcrear(string2);
    strcrear(string3);
    string1="crear";
    string2="pepe";
    string3="13";
    insertarElementoListaString(ls,string1);
    insertarElementoListaString(ls,string2);
    insertarElementoListaString(ls,string3);
    printEnter();
    total=contarElementos(ls);
    printf("\nLA CANTIDAD DE ELEMENTOS DE LA LISTA ES:%d",total);
}


void probarStringEnPosicionLista()
{
    int posicion=2;
    ListaStrings ls;
    crearListaString(ls);
    String string1;
    strcrear(string1);
    string1="crear pepe 13";
    darListaSeparadaPorEspacios(string1,ls);
    insertarElementoListaString(ls,string1);
    printEnter();
    darStringEnPosicion(ls,posicion,string1);
    print(string1);
}

void probarBorrarListaString()
{
    ListaStrings ls;
    crearListaString(ls);
    String string1;
    strcrear(string1);
    string1="crear pepe 10 30 ";
    darListaSeparadaPorEspacios(string1,ls);
    insertarElementoListaString(ls,string1);
    printEnter();
     while(ls!=NULL)
        {
            print(ls->parametro);
            printEnter();
            ls=ls->sig;
        }
    borrarNodosListaStrings(ls);

    if(listaStringVacia(ls))
    {
        printf("SE BORRARON LOS DATOS DE LA LISTA");
        while(ls!=NULL)
        {
            print(ls->parametro);
            printEnter();
            ls=ls->sig;
        }

    }
    else
    {
        printf("SE BORRARON LOS DATOS DE LA LISTA");
        while(ls!=NULL)
        {
            print(ls->parametro);
            printEnter();
            ls=ls->sig;
        }
    }
}
