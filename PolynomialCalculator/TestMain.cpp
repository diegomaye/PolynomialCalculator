#include "TestError.h"
#include "TestTermino.h"
#include "TestTerminos.h"

int main() {
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
    printEnter();
    //PRUEBAS DE TERMINOS:
    printf("///////////////// TESTS DE Terminos.h ////////////////\n");
    printEnter();
    //MOCKEANDO LISTA DE TERMINOS
    ListaTerminos terminosL1 = NULL;
    insertarTermino(terminosL1, (Termino){2,3});
    insertarTermino(terminosL1, (Termino){-5,2});
    insertarTermino(terminosL1, (Termino){1,1});
    insertarTermino(terminosL1, (Termino){-7,0});
    
    ListaTerminos terminosL2 = NULL;
    insertarTermino(terminosL2, (Termino){20,8});
    insertarTermino(terminosL2, (Termino){-10,3});
    insertarTermino(terminosL2, (Termino){4,0});
    
    ListaTerminos terminosL3 = NULL;
    insertarTermino(terminosL3, (Termino){1,6});
    insertarTermino(terminosL3, (Termino){-4,5});
    insertarTermino(terminosL3, (Termino){-4,4});
    insertarTermino(terminosL3, (Termino){4,3});
    insertarTermino(terminosL3, (Termino){4,2});
    insertarTermino(terminosL3, (Termino){2,1});
    insertarTermino(terminosL3, (Termino){2,0});
    
    printf("Prueba probarMostarTerminosLXX() para las listas terminosL1, terminosL2, terminosL3 \n");
    probarMostarTerminosL1(terminosL1);
    printEnter();
    probarMostarTerminosL2(terminosL2);
    printEnter();
    probarMostarTerminosL3(terminosL3);
    printEnter();
}
