//
//  main.cpp
//  PolynomialCalculator
//
//  Created by Diego, Rodrigo & Pablo.
//

#include "Parser.h"

int main() {

    String commando;
    ABBPolinomios polinomios;
    crearArbolPolinomios(polinomios);
    Boolean salirSistema = FALSE;
    printf("///////////////////////////////////////////////////////////\n");
    printf("      ____        __                            _       __\n");
    printf("     / __ \\____  / __  ______  ____  ____ ___  (_____ _/ /\n");
    printf("    / /_/ / __ \\/ / / / / __ \\/ __ \\/ __ `__ \\/ / __ `/ /\n");
    printf("   / ____/ /_/ / / /_/ / / / / /_/ / / / / / / / /_/ / /\n");
    printf("  /_/    \\____/_/\\__, /_/ /_/\\____/_/ /_/ /_/_/\\__,_/_/\n");
    printf("     ______     /____/        __      __\n");
    printf("    / ________ _/ _______  __/ ____ _/ /_____  _____\n");
    printf("   / /   / __ `/ / ___/ / / / / __ `/ __/ __ \\/ ___/\n");
    printf("  / /___/ /_/ / / /__/ /_/ / / /_/ / /_/ /_/ / /\n");
    printf("  \\____/\\__,_/_/\\___/\\__,_/_/\\__,_/\\__/\\____/_/\n");
    printf("\n");
    printf("    Bienvenido a Polynomial Calculator, a continuacion se listan\n");
    printf("los comando que pueden ser utilizandos, ingrese 'ayuda' para mas \n");
    printf("informacion.\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////\n");

    do{
        printf("Ingresa el comando:\n");
        strcrear(commando);
        scan(commando);
        ListaStrings commandos;
        crearListaString(commandos);
        darListaSeparadaPorEspacios(commando, commandos);
        darStringEnPosicion(commandos, 0, commando);

        if(strreq(commando, COMMANDO[CREAR])){
            crearPolinomio(polinomios, commandos);
        } else if(strreq(commando, COMMANDO[SUMAR])){
            sumarPolinomios(polinomios, commandos);
        } else if(strreq(commando, COMMANDO[MULTIPLICAR])){
            multiplicarPolinomios(polinomios, commandos);
        } else if(strreq(commando, COMMANDO[EVALUAR])){
            evalarPolinomio(polinomios, commandos);
        } else if(strreq(commando, COMMANDO[ESRAIZ])){
            esraizPolinomio(polinomios, commandos);
        } else if(strreq(commando, COMMANDO[MOSTRAR])){
            mostrarPolinomio(polinomios, commandos);
        } else if(strreq(commando, COMMANDO[GUARDAR])){
            guardarPolinomio(polinomios, commandos);
        } else if(strreq(commando, COMMANDO[RECUPERAR])){
            recuperarPolinomio(polinomios, commandos);
        } else if(strreq(commando, COMMANDO[AYUDA])){
            ayuda(polinomios, commandos);
        } else if(strreq(commando, COMMANDO[SALIR])){
            salirSistema = salir(polinomios, commandos);
        } else {
            print(mostrarError(COMANDO_INGRESADO_NO_EXISTE));
        }
    } while (!salirSistema);
}
