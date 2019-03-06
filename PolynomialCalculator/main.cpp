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
    do{
        strcrear(commando);
        scan(commando);
        ListaStrings commandos;
        crearListaString(commandos);
        darListaSeparadaPorEspacios(commando, commandos);
        darStringEnPosicion(commandos, 0, commando);
        if(strreq(commando, CREAR)){
            crearPolinomio(polinomios, commandos);
        } else if(strreq(commando, SUMAR)){
            sumarPolinomios(polinomios, commandos);
        } else if(strreq(commando, MULTIPLICAR)){
            multiplicarPolinomios(polinomios, commandos);
        } else if(strreq(commando, EVALUAR)){
            evalarPolinomio(polinomios, commandos);
        } else if(strreq(commando, ESRAIZ)){
            esraizPolinomio(polinomios, commandos);
        } else if(strreq(commando, MOSTRAR)){
            mostrarPolinomio(polinomios, commandos);
        } else if(strreq(commando, GUARDAR)){
            guardarPolinomio(polinomios, commandos);
        } else if(strreq(commando, RECUPERAR)){
            recuperarPolinomio(polinomios, commandos);
        } else {
            printf("Comando erroneo");//TODO: Revisar documentacion y poner comando correcto.
        }
    } while (strreq(commando, SALIR));
}
