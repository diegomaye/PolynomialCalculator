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

void sumarPolinomios(ABBPolinomios &polinomios, ListaStrings comando) {
    int elementos = contarElementos(comando) - 1;//Se saca el comando
    if (elementos != 3)
        print(mostrarError(CANTIDAD_PARAMETROS_SUMA));
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
                String nombrePolinomioASumar2;
                strcrear(nombrePolinomioASumar2);
                darStringEnPosicion(comando, 3, nombrePolinomioASumar2);
                if (!existePolinomioEnABB(polinomios, nombrePolinomioASumar)&&!existePolinomioEnABB(polinomios, nombrePolinomioASumar2))
                    print(mostrarError(POLINOMIO_NO_EXISTENTE_SUMA));
                else if (!existePolinomioEnABB(polinomios, nombrePolinomioASumar))
                    print(mostrarError(POLINOMIO_NO_EXISTENTE_SUMA1));
                else if(!existePolinomioEnABB(polinomios, nombrePolinomioASumar2))
                    print(mostrarError(POLINOMIO_NO_EXISTENTE_SUMA2));
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
                if (!existePolinomioEnABB(polinomios, nombrePolinomio1)&&!existePolinomioEnABB(polinomios, nombrePolinomio2))
                    print(mostrarError(POLINOMIO_NO_EXISTENTE_PRODUCTO));
                else if (!existePolinomioEnABB(polinomios, nombrePolinomio1))
                    print(mostrarError(POLINOMIO_NO_EXISTENTE_PRODUCTO1));
                else if(!existePolinomioEnABB(polinomios, nombrePolinomio2))
                    print(mostrarError(POLINOMIO_NO_EXISTENTE_PRODUCTO2));
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

void ayuda(ABBPolinomios &polinomios, ListaStrings comando) {
    int elementos = contarElementos(comando);//Se saca el comando
    if (elementos != 1)
        print(mostrarError(CANTIDAD_PARAMETROS));
    else {
        printf("'crear': Comando para la creacion de polinomios.\n");
        printf("crear [NOMBRE_NUEVO_POLINOMIO] COEFICIENTE_1 COEFICIENTE_2 .. COEFICIENTE_N\n");
        printf("Ejemplo: crear poly1 3 +2 -2 0 1 (da como resultado 3x^4 +2x^3 -2x^2 + 1)\n");
        printf("\n");
        printf("'sumar': Comando para la suma de polinomios.\n");
        printf("sumar [POLINOMIO_RESULTADO] POLINOMIO_1 POLINOMIO_2\n");
        printf("Ejemplo: sumar poly3 poly1 poly2 (inserta en poly3 el resultado de la suma)\n");
        printf("\n");
        printf("'multiplicar': COmando para multiplicar polinomios.\n");
        printf("multiplicar [POLINOMIO_RESULTADO] POLINOMIO_1 POLINOMIO_2\n");
        printf("Ejemplo: multiplicar poly3 poly1 poly2 (inserta en poly3 el resultado de la multiplicacion)\n");
        printf("\n");
        printf("'evaluar': Comando para la evaluacion de polinomios.\n");
        printf("sumar [POLINOMIO_A_EVALUAR] [VALOR]\n");
        printf("Ejemplo: evaluar poly1 1 (remplaza todas variables de poly1 por '1')\n");
        printf("\n");
        printf("'esRaiz': Comando para evaluar si un numero es raiz o no de un polinomio.\n");
        printf("esRaiz [POLINOMIO_A_EVALUAR] [VALOR]\n");
        printf("Ejemplo: evaluar poly1 1 (devuelve si 1 es raiz o no de poly1)\n");
        printf("\n");
        printf("'guardar': Comando para guardar un polinomio en un archivo de texto.\n");
        printf("guardar [POLINOMIO_A_GUARDAR] [NOMBRE_ARCHIVO]\n");
        printf("Ejemplo: guardar poly1 poly1.txt (almacena en poly1.txt, poly1)\n");
        printf("\n");
        printf("'recuperar': Comando para recurar polinomios en archivos de texto.\n");
        printf("recupera [NOMBRE_A_DAR_AL_POLINOMIO] [NOMBRE_ARCHIVO]\n");
        printf("Ejemplo: recupera poly1 poly1.txt (inserta en poly1 el contenido del archivo)\n");
        printf("\n");
        printf("'mostar': Muestra todos los polinomios en la memoria.\n");
        printf("'ayuda': Muestra todos los comandos y sus posibles valores.\n");
        printf("'salir': Permite salir del sistema, borrando el contenido de memoria.\n");
        printf("\n");
    }
}

void calcular(ABBPolinomios &polinomios, ListaStrings comando){
    String nombrePolinomio;
    strcrear(nombrePolinomio);
    darStringEnPosicion(comando, 1, nombrePolinomio);
    int elementos = contarElementos(comando);//Se saca el comando
    if (elementos != 2)
        print(mostrarError(CANTIDAD_PARAMETROS));
    else if(!existePolinomioEnABB(polinomios, nombrePolinomio))
            print(mostrarError(POLINOMIO_NO_EXISTENTE));
    else{
        Polinomio polinomio = buscarPolinomio(polinomios, nombrePolinomio);
        int grado = darGradoPolinomio(polinomio);
        if(grado > 2){
            printf("El polinomio es de un grado mayor a 2.\n");
        } else {
            switch (grado) {
                case 0:
                    printf("El polinomio no tiene variables.\n");
                    break;
//                case 1:
//                    int
//                    break;
//                case <#constant#>:
//                    <#statements#>
//                    break;
                default:
                    break;
            }
        }
    }
    
}

Boolean salir(ABBPolinomios &polinomios, ListaStrings comando) {
    int elementos = contarElementos(comando);//Se saca el comando
    if (elementos != 1){
        print(mostrarError(CANTIDAD_PARAMETROS));
        return FALSE;
    }
    else{
        eliminarABB(polinomios);
        printf("Hasta la vista, BYBE!\n");
        return TRUE;
    }
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

