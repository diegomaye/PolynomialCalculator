//
//  Parser.cpp
//  PolynomialCalculator
//
//  Created by Diego, Rodrigo & Pablo.
//

#include "Parser.h"

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

/* METODO ORIGINAL HECHO X DIEGO:
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
*/

void sumarPolinomios(ABBPolinomios &polinomios, ListaStrings comando) {
    int elementos = contarElementos(comando) - 1;//Se saca el comando
    if (elementos != 3)
        print(mostrarError(CANTIDAD_PARAMETROS));
    else {
        String nombrePolinomio;
        strcrear(nombrePolinomio);
        darStringEnPosicion(comando, 1, nombrePolinomio);
        if (!esAlfanumerico(nombrePolinomio))
            print(mostrarError(STRING_ALFANUMERICO));
        else {
            if (existePolinomioEnABB(polinomios, nombrePolinomio))
                print(mostrarError(POLINOMIO_EXISTENTE));
            else {
                String nombrePolinomioASumar;
                strcrear(nombrePolinomioASumar);
                darStringEnPosicion(comando, 2, nombrePolinomioASumar);
                if (!existePolinomioEnABB(polinomios, nombrePolinomioASumar))
                    print(mostrarError(POLINOMIO_NO_EXISTENTE));
                else {
                    String nombrePolinomioASumar2;
                    strcrear(nombrePolinomioASumar2);
                    darStringEnPosicion(comando, 3, nombrePolinomioASumar2);
                    if (!existePolinomioEnABB(polinomios, nombrePolinomioASumar2))
                        print(mostrarError(POLINOMIO_NO_EXISTENTE));
                    else {
                        Polinomio polinomio1 = buscarPolinomio(polinomios, nombrePolinomioASumar);
                        Polinomio polinomio2 = buscarPolinomio(polinomios, nombrePolinomioASumar2);
                        Polinomio resultado;
                        if (polinomioNulo(polinomio1)) {
                            ListaTerminos terminos = NULL;
                            darTerminosPolinomio(polinomio2, terminos); // no deberia ser una función que devuelva ListaTerminos?
                            cargarPolinomio(resultado, nombrePolinomio, terminos);
                            insertarPolinomio(polinomios, resultado);
                            mostrarPolinomio(resultado);
                        } else {
                            cargarNombrePolinomio(resultado, nombrePolinomio);
                            sumarPolinomios(polinomio1, polinomio2, resultado);
                            insertarPolinomio(polinomios, resultado);
                            mostrarPolinomio(resultado);
                        }
                    }
                }
            }
        }
    }
}

/* METODO ORIGINAL HECHO X DIEGO:
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
*/

void multiplicarPolinomios(ABBPolinomios &polinomios, ListaStrings comando) {
    int elementos = contarElementos(comando) - 1;//Se saca el comando
    if (elementos != 3)
        print(mostrarError(CANTIDAD_PARAMETROS_MULTILICACION));
    else {
        String nombreResultado;
        strcrear(nombreResultado);
        darStringEnPosicion(comando, 1, nombreResultado);
        if (!esAlfanumerico(nombreResultado))
            print(mostrarError(STRING_ALFANUMERICO));
        else {
            if (existePolinomioEnABB(polinomios, nombreResultado))
                print(mostrarError(POLINOMIO_EXISTENTE));
            else {
                String nombrePolinomio1;
                strcrear(nombrePolinomio1);
                darStringEnPosicion(comando, 2, nombrePolinomio1);
                String nombrePolinomio2;
                strcrear(nombrePolinomio2);
                darStringEnPosicion(comando, 3, nombrePolinomio2);
                if (!existePolinomioEnABB(polinomios, nombrePolinomio1) || !existePolinomioEnABB(polinomios, nombrePolinomio2))
                    print(mostrarError(POLINOMIOS_EXISTENTE_MULTIPLICACION));
                else {
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
/*
void evalarPolinomio(ABBPolinomios polinomios, ListaStrings comando) {
    String nombrePolinomio;
    strcrear(nombrePolinomio);
    darStringEnPosicion(comando, 1, nombrePolinomio);
    int elementos = contarElementos(comando) - 1;//Se saca el comando
    if (elementos != 2)
        print(mostrarError(CANTIDAD_PARAMETROS));
    else {
        if(!existePolinomioEnABB(polinomios, nombrePolinomio))//TODO: verificar previamente que el nombre es alfanumerico? no es necesario, no?
            print(mostrarError(POLINOMIO_NO_EXISTENTE));
        else{
            Polinomio polinomio = buscarPolinomio(polinomios, nombrePolinomio);
            String strEvaluar;
            strcrear(strEvaluar);
            darStringEnPosicion(comando, 2, strEvaluar);
            Boolean esNumero = esNumerico(strEvaluar);
            if(!esNumero){
                print(mostrarError(VALOR_PARA_EVALUAR));
            } else {
                int evaluar = convertirANumero(strEvaluar);
                int resultado = evaluarPolinomio(polinomio, evaluar);
                printf("El resultado de evaluar ");
                print(nombrePolinomio);
                printf(" es %d\n", resultado);
            }
        }
    }
}
*/

void evalarPolinomio(ABBPolinomios polinomios, ListaStrings comando) {
    String nombrePolinomio;
    int resultado;
    Boolean valida = FALSE;
    validarEvaluarEsRaiz(polinomios, comando, nombrePolinomio, resultado, valida);
    if(valida){
        printf("El resultado de evaluar ");
        print(nombrePolinomio);
        printf(" es %d\n", resultado);
    }
}

void esraizPolinomio(ABBPolinomios polinomios, ListaStrings comando) {
    String nombrePolinomio;
    int resultado;
    Boolean valida = FALSE;
    validarEvaluarEsRaiz(polinomios, comando, nombrePolinomio, resultado, valida);
    if(valida){
        if(resultado == 0){
            printf("El valor ingresado es raiz del polinomio ");
            print(nombrePolinomio);
            printEnter();
        }
        else{
            printf("El valor ingresado no es raiz del polinomio ");
            print(nombrePolinomio);
            printEnter();
        }
    }
}

void mostrarPolinomio(ABBPolinomios &polinomios, ListaStrings comando) {
    int elementos = contarElementos(comando);//Se saca el comando
    if (elementos != 1)
        print(mostrarError(CANTIDAD_PARAMETROS));
    else if (!existeAlMenosUnPolinomioEnABB(polinomios))
            print(mostrarError(POLINOMIO_NO_EXISTENTE_EN_MEMORIA));
        else
            desplegarABB(polinomios);
}

void guardarPolinomio(ABBPolinomios &polinomios, ListaStrings comando) {
    String nombrePolinomio;
    strcrear(nombrePolinomio);
    darStringEnPosicion(comando, 1, nombrePolinomio);
    int elementos = contarElementos(comando) - 1;//Se saca el comando
    if (elementos != 2)
        print(mostrarError(CANTIDAD_PARAMETROS));
    else {
        if(!existePolinomioEnABB(polinomios, nombrePolinomio))
            print(mostrarError(POLINOMIO_NO_EXISTENTE));
        else{
            String nombreArchivo;
            strcrear(nombreArchivo);
            darStringEnPosicion(comando, 2, nombreArchivo);
            Boolean existe = validarExtension(nombreArchivo);
            if(!existe){
                print(mostrarError(FORMATO_ARCHIVO_INCORRECTO));
            } else {
                if (existeArchivo(nombreArchivo)) {
                    print(mostrarError(EXISTE_ARCHIVO));
                    String escritura;
                    strcrear(escritura);
                    scan(escritura);
                    ListaStrings respuesta;
                    crearListaString(respuesta);
                    darListaSeparadaPorEspacios(escritura, respuesta);
                    int elementosRespuesta = contarElementos(respuesta);
                    if (elementosRespuesta != 1)
                        print(mostrarError(RESPUESTA_INCORRECTA));
                    else {
                        darStringEnPosicion(respuesta, 0, escritura);
						if (strreq(escritura, SI_MA) || strreq(escritura, SI_MI)) {
                            Polinomio polinomio = buscarPolinomio(polinomios, nombrePolinomio);
                            bajarTerminosPolinomio(polinomio, nombreArchivo);
                            printf("Polinomio almacenado correctamente en ");
                            print(nombreArchivo);
                            printEnter();
                        } else if (strreq(escritura, NO_MA) || strreq(escritura, NO_MI))
                                    print(mostrarError(COMANDO_ABORTADO));
                                else
									print(mostrarError(RESPUESTA_INCORRECTA));
                    }
                } else {
                    Polinomio polinomio = buscarPolinomio(polinomios, nombrePolinomio);
                    bajarTerminosPolinomio(polinomio, nombreArchivo);
                    printf("Polinomio almacenado correctamente en ");
                    print(nombreArchivo);
                    printEnter();
                }

            }
        }
    }
}

void recuperarPolinomio(ABBPolinomios &polinomios, ListaStrings comando) {
    String nombrePolinomio;
    strcrear(nombrePolinomio);
    darStringEnPosicion(comando, 1, nombrePolinomio);
    int elementos = contarElementos(comando) - 1;//Se saca el comando
    if (elementos != 2)
        print(mostrarError(CANTIDAD_PARAMETROS));
    else {
        if(!esAlfanumerico(nombrePolinomio))
            print(mostrarError(STRING_ALFANUMERICO));
        else{
            if(existePolinomioEnABB(polinomios, nombrePolinomio))
                print(mostrarError(POLINOMIO_EXISTENTE));
            else{
                String nombreArchivo;
                strcrear(nombreArchivo);
                darStringEnPosicion(comando, 2, nombreArchivo);
                if (!validarExtension(nombreArchivo))
                    print(mostrarError(NOMBRE_EXTENSION_INCORRECTO));
                else {
                    Boolean existe = existeArchivo(nombreArchivo);
                    if(!existe){
                        print(mostrarError(NO_EXISTE_ARCHIVO));
                    } else {
                        Polinomio polinomio;
                        cargarPolinomio(polinomio, nombrePolinomio, NULL);
                        levantarTerminosPolinomio(polinomio, nombreArchivo);
                        insertarPolinomio(polinomios, polinomio);
                        mostrarPolinomio(polinomio);
                    }
                }
            }
        }
    }
}

void salir(ABBPolinomios &polinomios) {
    eliminarABB(polinomios);
    printf("Hasta la vista!");
}

void validarEvaluarEsRaiz(ABBPolinomios polinomios, ListaStrings comando, String &nombrePolinomio, int &resultado, Boolean &valida){//TODO: Esta bien devolver un booleano o tendria que ser un parametro por referencia?
    strcrear(nombrePolinomio);
    darStringEnPosicion(comando, 1, nombrePolinomio);
    int elementos = contarElementos(comando) - 1;//Se saca el comando
    if (elementos != 2)
        print(mostrarError(CANTIDAD_PARAMETROS));
    else {
        if(!existePolinomioEnABB(polinomios, nombrePolinomio))
            print(mostrarError(POLINOMIO_NO_EXISTENTE));
        else{
            Polinomio polinomio = buscarPolinomio(polinomios, nombrePolinomio);
            String strEvaluar;
            strcrear(strEvaluar);
            darStringEnPosicion(comando, 2, strEvaluar);
            Boolean esNumero = esNumerico(strEvaluar);
            if(!esNumero){
                print(mostrarError(VALOR_PARA_EVALUAR));
            } else {
                int evaluar = convertirANumero(strEvaluar);
                resultado = evaluarPolinomio(polinomio, evaluar);
                valida = TRUE;
            }
        }
    }
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

