//
//  main.cpp
//  PolynomialCalculator
//
//  Created by diegomaye on 2/15/19.
//  Copyright © 2019 Code4Business. All rights reserved.
//

#include "Archivo.h"
#include "Error.h"
#include "Parser.h"
#include "ListaStrings.h"

const char* ARCHIVO_EXPEDIENTES = "expedientes.dat";
const char* ARCHIVO_REVISIONES = "revisiones.dat";

int main() {
    int opcion = NINGUNA;

    ABBExpedientes expedientes;
    ListaRevisiones revisiones;

    crear(expedientes);
    cargarRevisiones(revisiones);

    if(existeArchivo(ARCHIVO_EXPEDIENTES))
        levantarExpedientes(expedientes, ARCHIVO_EXPEDIENTES);
    if(existeArchivo(ARCHIVO_REVISIONES))
        levantarRevisiones(revisiones, ARCHIVO_REVISIONES);

    while(opcion != OPCION_SALIDA){
        switch (opcion) {
            case REGISTRAR_EXPEDIENTE:
                printLinea();
                printf("Ingrese la informacion para registrar un nuevo expediente\n");
                printLinea();
                cargarExpedienteValidandoCodigo(expedientes);
                opcion = NINGUNA;
                printf("EXPEDIENTE CARGADO CORRECTAMENTE\n");
                printLinea();
                break;
            case REGISTRAR_REVISION:
                printLinea();
                printf("Ingrese la informacion para registrar una nueva revision\n");
                printLinea();
                cargarRevisionValidandoCodigo(revisiones, expedientes);
                opcion = NINGUNA;
                printf("REVISION INGRESADA CORRECTAMENTE\n");
                printLinea();
                break;
            case BORRAR_EXPEDIENTE:
                printLinea();
                printf("Borrado de expediente\n");
                printLinea();
                eliminarExpedientePorCodigo(expedientes, revisiones);
                opcion = NINGUNA;
                printf("EXPEDIENTE BORRADO CORRECTAMENTE\n");
                printLinea();
                break;
            case MENU_LISTADOS:
                submenu(opcion, expedientes, revisiones);
                break;
            default:
                imprimirMenu(opcion);
                break;
        }
    }

    bajarRevisiones(revisiones, ARCHIVO_REVISIONES);
    bajarExpedientes(expedientes, ARCHIVO_EXPEDIENTES);

}
