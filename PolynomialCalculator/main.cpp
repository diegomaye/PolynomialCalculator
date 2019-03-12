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
    printf("///////////////////////////////////////////////////////////////////////////\n");
    printf("Bienvenido a PolynomialCalculator, con este sistema podras realizar crear\n");
    printf("sumar, multiplicar y evaluar polinomios, asi como determinar si un numero\n");
    printf("es raiz, en cualquier momento podras ver los polinomios en memoria, ademas\n");
    printf("el sistema te permite almacenar los polinomios para utilizarlos en futuras\n");
    printf("calculos. \n");
    printf("///////////////////////////////////////////////////////////////////////////\n");

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
        } else if(strreq(commando, COMMANDO[SALIR])){
            salir(polinomios);
        } else {
            print(mostrarError(COMANDO_INGRESADO_NO_EXISTE));
        }
    } while (!strreq(commando, COMMANDO[SALIR]));
}
