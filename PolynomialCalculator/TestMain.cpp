#include "TestError.h"
#include "TestTermino.h"

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
}
