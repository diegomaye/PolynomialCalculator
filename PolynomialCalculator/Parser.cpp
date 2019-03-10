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
    if(esAlfanumerico(nombrePolinomio)){
        Polinomio polinomio;
        int elementos = contarElementos(comando)-2;//Se saca el nombre y el comando
        ListaTerminos lstTerminos;
        crearListaTerminos(lstTerminos);
        Boolean salir = FALSE;
        int i = 0;
        while(i < elementos && !salir){
            String strCoeficiente;
            strcrear(strCoeficiente);
            darStringEnPosicion(comando, i + 2, strCoeficiente);
            Boolean esNumero = esNumerico(strCoeficiente);
            if(esNumero){
                int coeficiente = convertirANumero(strCoeficiente);
                if(coeficiente != 0){
                    Termino termino;
                    cargarCoeficienteTermino(termino, coeficiente);
                    cargarExponenteTermino(termino, i);
                    insertarTermino(lstTerminos, termino);
                }
            } else {
                print(mostrarError(COEFICIENTE_NUMERICOS));
                salir = TRUE;
            }
            i++;
        }
        if(!salir){
            cargarPolinomio(polinomio, nombrePolinomio, lstTerminos);
            insertarPolinomio(polinomios, polinomio);
            mostrarPolinomio(polinomio);
        }
    }
}

void sumarPolinomios(ABBPolinomios &polinomios, ListaStrings comando) {
    String nombrePolinomio1, nombrePolinomio2, nombreResultado;
    darStringEnPosicion(comando, 1, nombrePolinomio1);
    darStringEnPosicion(comando, 2, nombrePolinomio2);
    darStringEnPosicion(comando, 3, nombreResultado);
    Polinomio polinomio1 = buscarPolinomio(polinomios, nombrePolinomio1);
    Polinomio polinomio2 = buscarPolinomio(polinomios, nombrePolinomio2);
    Polinomio resultado;
    cargarNombrePolinomio(resultado, nombreResultado);
    sumarPolinomios(polinomio1, polinomio2, resultado);
    insertarPolinomio(polinomios, resultado);
    mostrarPolinomio(resultado);
}

void multiplicarPolinomios(ABBPolinomios &polinomios, ListaStrings comando) {
    String nombrePolinomio1, nombrePolinomio2, nombreResultado;
    darStringEnPosicion(comando, 1, nombrePolinomio1);
    darStringEnPosicion(comando, 2, nombrePolinomio2);
    darStringEnPosicion(comando, 3, nombreResultado);
    Polinomio polinomio1 = buscarPolinomio(polinomios, nombrePolinomio1);
    Polinomio polinomio2 = buscarPolinomio(polinomios, nombrePolinomio2);
    Polinomio resultado;
    cargarNombrePolinomio(resultado, nombreResultado);
    multiplicarPolinomios(polinomio1, polinomio2, resultado);
    insertarPolinomio(polinomios, resultado);
    mostrarPolinomio(resultado);
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
    //bajarPolinomio(polinomio, crearArchivo(nombreArchivo));//TODO: TODO BIEN? Respuesta: lo cambiamos por bajarTerminosPolinomio
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
    //FILE * file = fopen(nombreArchivo, "wd");//TODO: mm no iriia aca...
    //levantarPolinomio(polinomio, file); idem antes
    levantarTerminosPolinomio(polinomio, nombreArchivo);
    mostrarPolinomio(polinomio);
}

void salir(ABBPolinomios &polinomios) {
    eliminarABB(polinomios);
}
