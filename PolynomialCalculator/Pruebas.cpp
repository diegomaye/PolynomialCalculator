#include "Pruebas.h"

void pruebaString ()
{
    Boolean alfanumerico,numerico,contPuntos,exte;
    String s;
    int convertir;


    /*printf("PRUEBA DE SI UN STRING ES ALFANUMERICO:\n");
    strcrear(s);
    scan(s);
    alfanumerico=esAlfanumerico(s);
    if(alfanumerico==TRUE)
        printf("\nTRUE:El string ingresado es alfanumerico:");
    else
        printf("\nFALSE:El string ingresado NO es alfanumerico");
        strdestruir(s);

    printf("\n\nPRUEBA DE SI UN STRING ES NUMERICO:\n");
    strcrear(s);
    scan(s);
    numerico=esNumerico(s);
    if(numerico==TRUE)
        printf("\nTRUE:El string ingresado es numerico");
    else
        printf("\nFALSE:El string ingresado NO es numerico");
        strdestruir(s);

    printf("\n\nPRUEBA DE PASAR UN STRING A ENTERO:\n");
    strcrear(s);
    scan(s);
    convertir=convertirANumero(s);
    printf("\nEl String pasado a entero es: %d",convertir);
    strdestruir(s);*/

   /* printf("\nPRUEBA DE CONTAR PUNTOS EN UN STRING:\n");
    strcrear(s);
    scan(s);
    contPuntos=cantidadPuntosEnString(s);
    if(contPuntos==TRUE)
        printf("\nTRUE:  HAY UN SOLO PUNTO EN EL STRING");
    else
        printf("\nFALSE:  HAY MAS PUNTOS EN EL STRING ");*/


    printf("\nPRUEBA DE EXTENSION DE ARCHIVO:\n");
    strcrear(s);
    scan(s);
    exte=validarExtension(s);
    if(exte==TRUE)
        printf("\nNOMBRE DE ARCHIVO Y EXTENSION CORRECTOS");
    else
        printf("\nNOMBRE DE ARCHIVO O EXTENSION INCORRECTOS");






}
