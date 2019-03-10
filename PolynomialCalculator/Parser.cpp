//
//  Parser.cpp
//  PolynomialCalculator
//
//  Created by Diego, Rodrigo & Pablo.
//

#include "Parser.h"

void invocarComando(Comando com, ListaStrings &lista, ABBPolinomios &polinomios) {
    switch (com) {
    case CREAR:
        crearPolinomio(polinomios, lista);
        break;
    case SUMAR:
        sumarPolinomios(polinomios, lista);
        break;
    case MULTIPLICAR:
        multiplicarPolinomios(polinomios, lista);
        break;
    case EVALUAR:
        evalarPolinomio(polinomios, lista);
        break;
    case ESRAIZ:
        esraizPolinomio(polinomios, lista);
        break;
    case MOSTRAR:
        mostrarPolinomio(polinomios, lista);
        break;
    case GUARDAR:
        guardarPolinomio(polinomios, lista);
        break;
    case RECUPERAR:
        recuperarPolinomio(polinomios, lista);
        break;
    case SALIR:
        salir(polinomios);
        break;
    }
}

void crearPolinomio(ABBPolinomios &polinomios, ListaStrings comando) {
    String nombrePolinomio;
    strcrear(nombrePolinomio);
    darStringEnPosicion(comando, 1, nombrePolinomio);
    if(!esAlfanumerico(nombrePolinomio))
        print(mostrarError(STRING_ALFANUMERICO));
    else {
        int elementos = contarElementos(comando)-2;//Se saca el nombre y el comando
        if (elementos < 1)
            print(mostrarError(CANTIDAD_PARAMETROS));
        else {
            int i = 0;
            Boolean esNumero = TRUE;
            String strCoeficiente;
            strcrear(strCoeficiente);
            while (i < elementos && esNumero) {
                darStringEnPosicion(comando, i + 2, strCoeficiente);
                esNumero = esNumerico(strCoeficiente);
                i++;
            }
            if (!esNumero)
                print(mostrarError(COEFICIENTE_NUMERICOS));
            else {
                String strCoeficiente;
                strcrear(strCoeficiente);
                darStringEnPosicion(comando, 2, strCoeficiente);
                int coeficiente = convertirANumero(strCoeficiente);
                if (coeficiente == 0 && elementos > 3)
                    print(mostrarError(COEFICIENTE_CERO));
                else {
                    if (existePolinomioEnABB(polinomios, nombrePolinomio))
                        print(mostrarError(POLINOMIO_EXISTENTE));
                    else {
                        Polinomio resultado;
                        int exponente = elementos - 1;
                        ListaTerminos lstTerminos;
                        crearListaTerminos(lstTerminos);
                        int j = 0;
                        while (j < elementos) {
                            Termino termino;
                            cargarCoeficienteTermino(termino, coeficiente);
                            cargarExponenteTermino(termino, exponente);
                            insertarTermino(lstTerminos, termino);
                            darStringEnPosicion(comando, j + 3, strCoeficiente);
                            coeficiente = convertirANumero(strCoeficiente);
                            j++;
                            exponente--;
                        }
                        normalizarTerminos(lstTerminos);
                        cargarPolinomio(resultado, nombrePolinomio, lstTerminos);
                        insertarPolinomio(polinomios, resultado);
                        mostrarPolinomio(resultado);
                    }
                }
            }
        }
    }
}

void sumarPolinomios(ABBPolinomios &polinomios, ListaStrings comando) {
    int elementos = contarElementos(comando) - 1;//Se saca el comando
    if (elementos != 3)
        print(mostrarError(CANTIDAD_PARAMETROS));
    else {
        String nombrePolinomio1, nombrePolinomio2, nombreResultado;
        Boolean nombresValidos = sonNombreValidos(comando, nombrePolinomio1, nombrePolinomio2, nombreResultado);
        if(nombresValidos){
            if(existen(polinomios, nombrePolinomio1, nombrePolinomio2)){
                if(existePolinomioEnABB(polinomios, nombreResultado)){
                    print(mostrarError(POLINOMIO_EXISTENTE));
                } else {
                    Polinomio polinomio1 = buscarPolinomio(polinomios, nombrePolinomio1);
                    Polinomio polinomio2 = buscarPolinomio(polinomios, nombrePolinomio2);
                    Polinomio resultado;
                    cargarNombrePolinomio(resultado, nombreResultado);
                    sumarPolinomios(polinomio1, polinomio2, resultado);
                    insertarPolinomio(polinomios, resultado);
                    mostrarPolinomio(resultado);
                }
            }
        }
    }
}

void multiplicarPolinomios(ABBPolinomios &polinomios, ListaStrings comando) {
    int elementos = contarElementos(comando) - 1;//Se saca el comando
    if (elementos != 3)
        print(mostrarError(CANTIDAD_PARAMETROS));
    else {
        String nombrePolinomio1, nombrePolinomio2, nombreResultado;
        Boolean nombresValidos = sonNombreValidos(comando, nombrePolinomio1, nombrePolinomio2, nombreResultado);
        if(nombresValidos){
            if(existen(polinomios, nombrePolinomio1, nombrePolinomio2)){
                if(existePolinomioEnABB(polinomios, nombreResultado)){
                    print(mostrarError(POLINOMIO_EXISTENTE));
                } else {
                    Polinomio polinomio1 = buscarPolinomio(polinomios, nombrePolinomio1);
                    Polinomio polinomio2 = buscarPolinomio(polinomios, nombrePolinomio2);
                    Polinomio resultado;
                    cargarNombrePolinomio(resultado, nombreResultado);
                    multiplicarPolinomios(polinomio1, polinomio2, resultado);
                    insertarPolinomio(polinomios, resultado);
                    mostrarPolinomio(resultado);
                }
            }
        }
    }
}

void evalarPolinomio(ABBPolinomios &polinomios, ListaStrings comando) {
    String nombrePolinomio;
    String strEvaluar;
    darStringEnPosicion(comando, 1, nombrePolinomio);
    Polinomio polinomio = buscarPolinomio(polinomios, nombrePolinomio);
    strcrear(strEvaluar);
    Boolean esNumero = esNumerico(strEvaluar);
    if(esNumero){
        int evaluar = convertirANumero(strEvaluar);
        int resultado = evaluarPolinomio(polinomio, evaluar);
        printf("El resultado de evaluar ");
        print(nombrePolinomio);
        printf("es %d", resultado);
    } else {
        print(mostrarError(VALOR_PARA_EVALUAR));
    }
}

void esraizPolinomio(ABBPolinomios &polinomios, ListaStrings comando) {
    String nombrePolinomio;
    String strEvaluar;
    darStringEnPosicion(comando, 1, nombrePolinomio);
    Polinomio polinomio = buscarPolinomio(polinomios, nombrePolinomio);
    strcrear(strEvaluar);
    Boolean esNumero = esNumerico(strEvaluar);
    if(esNumero){
        int evaluar = convertirANumero(strEvaluar);
        esRaizPolinomio(polinomio, evaluar);
    } else {
        print(mostrarError(VALOR_PARA_EVALUAR));
    }
}

void mostrarPolinomio(ABBPolinomios &polinomios, ListaStrings comando) {
    desplegarABB(polinomios);
}

void guardarPolinomio(ABBPolinomios &polinomios, ListaStrings comando) {
    String nombrePolinomio;
    String nombreArchivo;
    darStringEnPosicion(comando, 1, nombrePolinomio);
    darStringEnPosicion(comando, 2, nombreArchivo);
    Polinomio polinomio = buscarPolinomio(polinomios, nombrePolinomio);
    bajarTerminosPolinomio(polinomio, nombreArchivo);
    printf("Polinomio almacenado correctamente en ");
    print(nombreArchivo);
    printEnter();
}

void recuperarPolinomio(ABBPolinomios &polinomios, ListaStrings comando) {
    String nombrePolinomio;
    String nombreArchivo;
    darStringEnPosicion(comando, 1, nombrePolinomio);
    darStringEnPosicion(comando, 2, nombreArchivo);
    Polinomio polinomio;
    cargarPolinomio(polinomio, nombreArchivo, NULL);
    levantarTerminosPolinomio(polinomio, nombreArchivo);
    mostrarPolinomio(polinomio);
}

void salir(ABBPolinomios &polinomios) {
    eliminarABB(polinomios);
}

Boolean sonNombreValidos(ListaStrings comando, String &nombrePolinomio1, String &nombrePolinomio2, String &nombreResultado){
    strcrear(nombrePolinomio1);
    Boolean nombreValidos = FALSE;
    darStringEnPosicion(comando, 2, nombrePolinomio1);
    if(!esAlfanumerico(nombrePolinomio1))
        print(mostrarError(STRING_ALFANUMERICO1));
    else {
        strcrear(nombrePolinomio2);
        darStringEnPosicion(comando, 3, nombrePolinomio2);
        if(!esAlfanumerico(nombrePolinomio2))
            print(mostrarError(STRING_ALFANUMERICO2));
        else {
            strcrear(nombreResultado);
            darStringEnPosicion(comando, 1, nombreResultado);
            if(!esAlfanumerico(nombreResultado))
                print(mostrarError(STRING_ALFANUMERICO3));
            else {
                nombreValidos = TRUE;
            }
        }
    }
    return nombreValidos;
}

Boolean existen(ABBPolinomios arbol, String nombrePolinomio1, String nombrePolinomio2){
    if(!existePolinomioEnABB(arbol, nombrePolinomio1))
        print(mostrarError(POLINOMIO_NO_EXISTENTE1));
    else {
        if(!existePolinomioEnABB(arbol, nombrePolinomio1))
            print(mostrarError(POLINOMIO_NO_EXISTENTE2));
        else {
            return TRUE;
        }
    }
    return FALSE;
}

