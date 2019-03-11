//
//  Terminos.cpp
//  PolynomialCalculator
//
//  Created by Diego, Rodrigo & Pablo.
//

#include "Terminos.h"

void crearListaTerminos(ListaTerminos &terminos){
    terminos = NULL;
}

void mostrarTerminos(ListaTerminos terminos){
    while(terminos != NULL){
        mostrarTermino(terminos -> termino);
        printf(" ");
        terminos = terminos -> sig;
    }
}

void insertarTermino(ListaTerminos &terminos, Termino termino){
    if(terminos == NULL){
        terminos = new NodoTermino;
        terminos -> termino = termino;
        terminos -> sig = NULL;
    } else if (darExponenteTermino(terminos -> termino) < darExponenteTermino(termino)) { /// recordar usar funciones selectoras sobre el termino
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
    else if (darExponenteTermino(terminos -> termino) == darExponenteTermino(termino))
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

Boolean mayorCantidadDeTerminos(ListaTerminos terminos1, ListaTerminos terminos2){
    int val1 = contarTerminos(terminos1);
    int val2 = contarTerminos(terminos2);
    if (val1 > val2)
        return TRUE;
    else
        return FALSE;
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

Boolean mayorGrado(ListaTerminos terminos1, ListaTerminos terminos2){
    Termino termino1 = primerTermino(terminos1);
    Termino termino2 = primerTermino(terminos2);
    return terminoMayorGrado(termino1, termino2);
}


void sumarTerminos(ListaTerminos terminos1, ListaTerminos terminos2, ListaTerminos &resultado){
    if (terminos1 != NULL) {
        Termino termino1 = primerTermino(terminos1);
        if(terminos2 == NULL){
            resultado = terminos1;
        } else {
            Termino termino2 = primerTermino(terminos2);
            if(darExponenteTermino(termino1) > darExponenteTermino(termino2)){ /// selectoras
                resultado = new NodoTermino;
                resultado -> termino = termino1;
                resultado -> sig = NULL;
                sumarTerminos(terminos1 -> sig, terminos2, resultado -> sig);
            } else if(darExponenteTermino(termino1) == darExponenteTermino(termino2)){
                resultado = new NodoTermino;
                sumarTerminos(termino1, termino2, resultado -> termino);
                resultado -> sig = NULL;
                sumarTerminos(terminos1 -> sig, terminos2 -> sig, resultado -> sig);
            } else if(darExponenteTermino(termino1) < darExponenteTermino(termino2)){
                resultado = new NodoTermino;
                resultado -> termino = termino2;
                resultado -> sig = NULL;
                sumarTerminos(terminos1, terminos2 -> sig, resultado -> sig);
            }
        }
    }
}

void multiplicarTerminosXTermino(ListaTerminos terminos, Termino termino, ListaTerminos &resultado){
    if (terminos == NULL) {
        resultado = NULL;
    }
    else{
        resultado = new NodoTermino;
        multiplicarTerminos(primerTermino(terminos), termino, resultado -> termino);
        multiplicarTerminosXTermino(terminos -> sig, termino, resultado -> sig);
    }
}

void multiplicarTerminos(ListaTerminos terminos1, ListaTerminos terminos2, ListaTerminos &resultado){
    if (terminos1 == NULL) {
        resultado = NULL;
    } else if (terminos2 == NULL) {
                resultado = NULL;
        } else if (contarTerminos(terminos1) == 1){
                Termino termino = primerTermino(terminos1);
                multiplicarTerminosXTermino(terminos2, termino, resultado);
            } else {
                Termino termino = primerTermino(terminos1);
                ListaTerminos terminosMultiplicadosXTermino;
                ListaTerminos terminosRetorno;
                multiplicarTerminosXTermino(terminos2, termino, terminosMultiplicadosXTermino);
                multiplicarTerminos(terminos1 -> sig, terminos2, terminosRetorno);
                if(mayorCantidadDeTerminos(terminosMultiplicadosXTermino, terminosRetorno)){
                    sumarTerminos(terminosMultiplicadosXTermino, terminosRetorno, resultado);
                }
                else {
                    sumarTerminos(terminosRetorno, terminosMultiplicadosXTermino, resultado);
                }

        }
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

void bajarTerminos(ListaTerminos terminos, FILE * f){
    while (terminos != NULL) {
        bajarTermino(terminos -> termino, f);
        terminos = terminos -> sig;
    }
    fclose (f);
}

void levantarTerminos(ListaTerminos &terminos, FILE * f){
    Termino termino;
    levantarTermino(termino, f);
    while (!feof(f)) {
        insertarTermino(terminos, termino);
        levantarTermino(termino, f);
    }
    fclose (f);
}
