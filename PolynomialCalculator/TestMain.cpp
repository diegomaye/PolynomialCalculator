#include "TestError.h"
#include "TestTermino.h"
#include "TestListaString.h"
#include "TestTerminos.h"
#include "TestPolinomio.h"

ListaTerminos terminosL1 = NULL;
ListaTerminos terminosL2 = NULL;
ListaTerminos terminosL3 = NULL;
Polinomio polinomio1;
Polinomio polinomio1Copia;
Polinomio polinomio2;
Polinomio polinomio3;

int main(){
    //PRUEBAS DE TODOS LOS MENSAJES DE ERROR:
    probarTodosMensajesDeError();
    printEnter();
    //PRUEBAS DE TERMINO:
    printf("///////////////// TESTS DE Termino.h /////////////////\n");
    printEnter();
    printf("Prueba Mostrar Terminos 'probarMostrarTermino' \n");
    probarMostrarTermino();
    printEnter();
    printf("Prueba de dar y cargar de Coeficiente/Exponente \n");
    probarDarCoeficienteTermino();
    probarDarExponenteTermino();
    probarCargarCoeficienteTerminoNegativo();
    probarCargarCoeficienteTerminoNegativo();
    printEnter();
    printf("PRUEBAS PARA LA SUMA//////////////////////// \n");
    printf("Prueba probarSumarTerminosPositivos(): \n");
    probarSumarTerminosPositivos();
    printf("Prueba probarSumarTerminosNegativoPositivo(): \n");
    probarSumarTerminosNegativoPositivo();
    printf("Prueba probarSumarTerminoConNulo(): \n");
    probarSumarTerminoConNulo();
    printEnter();
    printf("PRUEBAS PARA LA MULTIPLICACION////////////// \n");
    printf("Prueba probarMultiplicarTerminosPositivos(): \n");
    probarMultiplicarTerminosPositivos();
    printf("Prueba probarMultiplicarTerminosPositivoNegativo(): \n");
    probarMultiplicarTerminosPositivoNegativo();
    printf("Prueba probarMultiplicarTerminoConNulo(): \n");
    probarMultiplicarTerminoConNulo();
    printEnter();
    printf("PRUEBAS PARA LA EVALUACION///////////////// \n");
    printf("Prueba probarEvaluarTerminoPositivo(): \n");
    probarEvaluarTerminoPositivo();
    printf("Prueba probarEvaluarTerminoNegativo(): \n");
    probarEvaluarTerminoNegativo();
    printf("Prueba probarEvaluarTerminoNulo(): \n");
    probarEvaluarTerminoNulo();
    printf("PRUEBAS PARA LA LISTA DE STRING////////////// \n");

    /*
    printf("\nPRUEBA LISTA VACIA: ");
    probarListaVacia();
    printf("\nPRUEBA INSERTAR ELEMENTOS EN LA LISTA");
    probarInsertarListaString();
    printf("\nPRUEBA CONTAR LA CANTIDAD DE ELEMENTOS DE LA LISTA");
    probarContarElementosListaString();
    printf("\nPRUEBA DAR LISTA SEPARADA POR ESPACIOS");
    probarDarListaSeparadaPorEspacios();
    printf("\nPRUEBA DAR STRING EN UNA POSICION");
    probarStringEnPosicionLista();
    */
    printf("\nPREUEBA BORRAR DATOS DE LA LISTA");
    probarBorrarListaString();
    //PRUEBAS DE ARCHIVO:
//    printf("///////////////// TESTS DE Archivo.h /////////////////\n");
//    printEnter();
//    printf("Prueba Existe Archivo 'probarExisteArchivo' \n");
//    probarExisteArchivo();
//    printEnter();
//    printf("Prueba Crear Archivo 'probarCrearArchivo' \n");
//    probarCrearArchivo();
//    printEnter();
    //PRUEBAS DE TERMINOS:
    printf("///////////////// TESTS DE Terminos.h ////////////////\n");
    printEnter();
    //MOCKEANDO LISTA DE TERMINOS
    printf("Inicia el mockeo de terminos \n");
    mockTerminosPruebaInsert(terminosL1, terminosL2, terminosL3);
    printEnter();
    printf("Prueba probarInsertarTerminoAlFinal(...) \n");
    probarInsertarTerminoAlFinal(terminosL1);
    printEnter();
    printEnter();
    printf("Prueba probarInsertarTerminoEnElMedio(...) \n");
    probarInsertarTerminoEnElMedio(terminosL2);
    printEnter();
    printEnter();
    printf("Prueba probarInsertarTerminoAlPrincipio(...) \n");
    probarInsertarTerminoAlPrincipio(terminosL3);
    printEnter();
    printEnter();
    printf("Prueba probarInsertarTerminoEnListaVacia(...) \n");
    probarInsertarTerminoEnListaVacia();
    printEnter();
    printEnter();
    printf("Pruebar suma y producto de terminos \n");
    printEnter();
    probarSumarTerminos(terminosL1, terminosL2);
    probarMultiplicarTerminos(terminosL2, terminosL3);
    
    printf("///////////////// TESTS DE Polinomio.h ////////////////\n");
    mockPolinomiosPruebaCargar(polinomio1, polinomio2, polinomio3, terminosL1, terminosL2, terminosL3);
    polinomio1Copia = polinomio1;
    printf("Pruebas de la suma: \n");
    printEnter();
    probarSumaPolinomiosIgualLargo(polinomio1, polinomio1Copia);
    printEnter();
    probarSumaPolinomiosDiferenteLargo(polinomio2, polinomio3);
    printEnter();
    probarSumaPolinomioNulo(polinomio3);
    printEnter();
    printf("Pruebas del producto: \n");
    printEnter();
    probarMultiplicarPolinomiosIgualLargo(polinomio1, polinomio1Copia);
    printEnter();
    probarMultiplicarPolinomiosDiferenteLargo(polinomio2, polinomio3);
    printEnter();
    probarMultiplicarPolinomioNulo(polinomio3);
    printEnter();
    probarEvaluarPolinomio(polinomio1);
    printEnter();
    probarEsRaizPolinomio(polinomio1);
    printEnter();
    probarDarNombrePolinomio(polinomio1);
    printEnter();
    probarDarTerminosPolinomio(polinomio1);
    printEnter();
    probarPolinomioConMasTerminos(polinomio1, polinomio2);
    printEnter();
    probarPolinomiosIgualNombre(polinomio1, polinomio2);
    printEnter();
    probarPolinomioMenorNombre(polinomio1, polinomio2);
    printEnter();
    probarPolinomioNulo();
    printEnter();
    probarBorradoDePolinomio(polinomio1);
    printEnter();
}