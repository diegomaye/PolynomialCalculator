//
//  Terminos.cpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/15/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#include "Terminos.h"

void mostrarTerminos(ListaTerminos terminos){
    while(terminos != NULL){
        mostrarTermino(terminos -> termino);
        terminos = terminos -> sig;
    }
}

void insertarTermino(ListaTerminos &terminos, Termino termino){
    if(terminos == NULL){
        terminos = new NodoTermino;
        terminos -> termino = termino;
        terminos -> sig = NULL;
    } else if (terminos -> termino.exponente < termino.exponente) {
        ListaTerminos nuevoNodo = new NodoTermino;
        nuevoNodo -> termino = termino;
        nuevoNodo -> sig = terminos;
        terminos = nuevoNodo;
    } else {
        insertarTermino(terminos -> sig, termino);
    }
}

void insBack(ListaTerminos &terminos, Termino termino){
    if(terminos == NULL){
        terminos = new NodoTermino;
        terminos -> termino = termino;
        terminos -> sig = NULL;
    } else {
        insBack(terminos -> sig, termino);
    }
}

Boolean existeGrado(ListaTerminos &terminos, Termino termino){
    if(terminos == NULL)
        return FALSE;
    else if (terminos -> termino.exponente == termino.exponente)
        return TRUE;
    else
        return existeGrado(terminos, termino);
}

int contarTerminos(ListaTerminos terminos){
    int count = 0;
    while(terminos != NULL){
        count ++;
        terminos = terminos -> sig;
    }
    return count;
}

void borrarTermino(ListaTerminos &terminos, int exponente){
    if (terminos != NULL)
    {
        if (exponente ==  darExponenteTermino(terminos -> termino))
        {
            ListaTerminos aux = terminos;
            terminos = terminos -> sig;
            delete aux;
        }
        else
            borrarTermino(terminos -> sig, exponente);
    }
}

Termino primerTermino(ListaTerminos terminos){
    return terminos -> termino;
}

void sumarTerminos(ListaTerminos terminos1, ListaTerminos terminos2, ListaTerminos &terminosResultadoSuma){
    
}

void multiplicarTerminos(ListaTerminos terminos1, ListaTerminos terminos2, ListaTerminos &terminosResultadoMultiplicacion){
    
}

int evaluarTerminos(ListaTerminos terminos, int evaluar){
    if(terminos == NULL)
        return 0;
    else
        return evaluarTermino(terminos -> termino, evaluar) + evaluarTerminos(terminos -> sig, evaluar);
}

Boolean esRaizTerminos(ListaTerminos terminos, int raiz){
    if(evaluarTerminos(terminos, raiz)==0)
        return TRUE;
    else
        return FALSE;
}

Termino ultimaTerminoAgregado(ListaTerminos terminos){
    if(terminos -> sig == NULL)
        return terminos -> termino;
    else
        return ultimaTerminoAgregado(terminos -> sig);
}

Boolean listaVacia(ListaTerminos terminos){
    if(terminos == NULL)
        return TRUE;
    else
        return FALSE;
}

void borrarNodosListaTerminos(ListaTerminos &terminos){
    if (terminos != NULL) {
        ListaTerminos aux = terminos;
        terminos = terminos -> sig;
        delete aux;
        borrarNodosListaTerminos(terminos);
    }
}

void normalizarTerminos(ListaTerminos &terminos){
    if (terminos != NULL)
    {
        if (darCoeficienteTermino(terminos -> termino) == 0)
        {
            ListaTerminos aux = terminos;
            terminos = terminos -> sig;
            delete aux;
            normalizarTerminos(terminos);
        }
        else
            normalizarTerminos(terminos -> sig);
    }
}
