# PolynomialCalculator

Sistema de software que permite realizar operaciones basicas con polinomios de coeficientes enteros. La aplicación permite definir polinomios con coeficientes enteros y ejecutar un conjunto de funcionalidades sobre ellos, entre ellas operaciones que permitan chequear raíces enteras y evaluar un polinomio en un valor entero dado, así como otras operaciones adicionales.

## Como clonar y crear issues sobre el proyecto.

Para bajar el proyecto:
```
git clone https://github.com/diegomaye/PolynomialCalculator.git
```

Para implementar un issue o crear un branch:
```
git checkout -b [nombre_branch_para_issue]
```
La nomenclarura para "nombre_branch_para_issue" sera siempre ISSUE#X donde X es el numero de issue ej:
```
git checkout -b ISSUE#3
```
Para subir el branch primera vez:
```
git push -u origin [nombre_branch_para_issue]
```

## Esquema del proyecto
Digrama de modulos del sistema:

## Planteo del Problema

 Se desea desarrollar un sistema de software que permita a estudiantes de bachillerato trabajar con polinomios con coeficientes enteros. La aplicación permitirá definir polinomios con coeficientes enteros por parte del estudiante y ejecutar de un conjunto de funcionalidades sobre ellos, destacándose principalmente las operaciones que permiten chequear raíces enteras y evaluar un polinomio en un valor entero dado, así como otras operaciones adicionales.
 Si bien la cantidad de polinomios que se manejarán en memoria será finita, el sistema deberá permitir tener en memoria tantos polinomios como se desee. Además, no existirá cota para el grado de cada polinomio. Es decir, cada polinomio podrá ser de cualquier grado.
 Para interactuar con la aplicación, el usuario digitará una serie de comandos por teclado que le indicarán al programa las diferentes acciones a realizar. El programa deberá interpretar el comando ingresado por el usuario y luego realizar la acción correspondiente. Los comandos disponibles son los siguientes:

### Funciones Principale

* crear: crea un nuevo polinomio especificando todos sus coeficientes
* sumar: realiza la suma de dos polinomios, creando uno nuevo como resultado
* multiplicar: realiza la multiplicación de dos polinomios, creando uno nuevo como resultado evaluar: realiza la evaluación * * para un polinomio en un valor entero dado
* esraiz: muestra por pantalla si un número entero dado es raíz de un polinomio
* mostrar: muestra por pantalla todos los polinomios existentes en memoria
* guardar: guarda en archivo un polinomio existente en memoria
* recuperar: recupera a memoria un polinomio previamente guardado en archivo
* salir: abandona la aplicación

## Ejemplos de Ejecucion

### Ejempo 1
```console
foo@bar:~$ crear pepe 2 0 0 -1 –8
pepe = +2x4 –x -8
foo@bar:~$ crear lolo 1 0 1
lolo = +x2 +1
foo@bar:~$ sumar maria pepe lolo
maria = +2x4 +x2 –x -7 
foo@bar:~$ multiplicar megalolo lolo lolo 
megalolo = +x4 +2x2 +1
foo@bar:~$ evaluar lolo -3
10
foo@bar:~$ esraiz lolo -1
no es raiz
foo@bar:~$ mostrar
lolo = +x2 +1
 maria = +2x4 +x2 –x -7
 megalolo = +x4 +2x2 +1
 pepe = +2x4 –x -8
foo@bar:~$ guardar pepe pepe.txt
polinomio almacenado correctamente en pepe.txt 
foo@bar:~$ salir
hasta la próxima
```
### Ejemplo 2
```console
foo@bar:~$ recuperar pepe pepe.txt
pepe = +2x4 –x -8
foo@bar:~$ crear negapepe -2 0 0 1 8 negapepe = -2x4 +x +8
foo@bar:~$ sumar nulo pepe negapepe
nulo = 0
foo@bar:~$ crear raicesdist 1 0 -1 
raicesdist = +x2 -1
foo@bar:~$ esraiz raicesdist 1
es raiz
foo@bar:~$ esraiz raicesdist -1
es raiz
foo@bar:~$ recuperar doble raizdoble.txt 
doble = +x2 -2x +1
foo@bar:~$ esraiz doble 1
es raiz
foo@bar:~$ mostrar
doble = +x2 -2x +1
negapepe = -2x4 +x +8
nulo = 0
pepe = +2x4 –x -8
raicesdist = +x2 -1
foo@bar:~$ salir
hasta la próxima
```
## Una aproximacion de la solucion

Como se dijo anteriormente, no existe cota para la cantidad de polinomios que se pueden almacenar en memoria. Además, varias de operaciones requieren realizar búsquedas para saber si un nombre de polinomio existe o no. También se tiene un comando para listar todos los polinomios existentes en memoria, ordenados alfabéticamente de menor a mayor. Tomando en cuenta estas consideraciones, se deberá elegir una estructura de datos adecuada que permita almacenar a los polinomios en memoria.

Por otra parte, se deberá elegir otra estructura de datos adecuada para almacenar a un polinomio, teniendo en cuenta que se debe almacenar tanto su nombre como sus términos con coeficientes distintos de cero (excepto únicamente en el caso del polinomio nulo). Cada término tiene un coeficiente entero y un exponente natural. Un polinomio almacenará una cantidad no acotada de términos, los cuales deberán almacenarse ordenados de mayor a menor grado.

También serán eventualmente necesarias otras estructuras de datos auxiliares no evidentes a simple vista. Se debe analizar cuidadosamente cada comando a efectos de detectar cualquier otra estructura de datos que resulte útil y/o necesaria.

En relación a la lectura e interpretación de los comandos, todo comando será inicialmente leído desde teclado y cargado en un string. Luego se realizará un procesamiento (habitualmente se llama parsing a dicho procesamiento) de ese string para determinar de qué comando se trata, si es sintácticamente correcto, y posteriormente ejecutar las acciones que correspondan al comando en cuestión. Cuanto más sofisticado sea el parsing, más positivamente será valorado el trabajo. Se sugiere particionar el proceso de parsing en las siguientes etapas (definiendo oportunamente los procedimientos y funciones que sean necesarios en cada caso):

• Lectura del comando en un string.
• Validación del comando ingresado, devolviendo como resultado si es o no sintácticamente
 erróneo, el tipo de comando en cuestión y los parámetros que correspondan.
• Procesamiento del comando luego de haber sido validado, manipulando adecuadamente las
 estructuras de datos que sean pertinentes.

Además del parsing, también se deberá definir los procedimientos y funciones necesarios para el procesamiento de todos los comandos, así como los módulos necesarios, distribuyendo adecuadamente todos los subprogramas entre ellos, respetando los criterios usuales de modularización
