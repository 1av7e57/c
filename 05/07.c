/*Ejercicio 7: Contador de Llamadas en Diferentes Funciones

Enunciado:
Crea dos funciones llamadas funcionA y funcionB. Cada una de estas funciones debe llevar un contador que indique cuántas veces ha sido llamada dicha función. Sin embargo, las funciones no deben compartir sus contadores. Al final, desde el main(), llama a cada función varias veces y muestra cuántas veces ha sido invocada cada una.

Piensa en qué tipo de variable utilizarías para contar las llamadas.
Reflexiona sobre cómo y dónde debes declarar las variables para que se mantenga la cuenta entre las llamadas, pero que no se compartan entre las funciones.

Puntos a considerar:
¿Qué variables tienen que ser locales? ¿Cuál tiene que ser estática?
¿Cómo mantendrás la separación de los contadores entre las dos funciones?*/

#include <stdio.h>

// Declaración de las funciones
void funcionA();
void funcionB();

// Variables estáticas para contar las llamadas
static int contadorA = 0;
static int contadorB = 0;

// Definición de la función A
void funcionA() {
    contadorA++; //incremento de la variable contadorA
    printf("funcionA ha sido llamada %d veces.\n", contadorA);
}

// Definición de la función B
void funcionB() {
    contadorB++; //incremento de la variable contadorB
    printf("funcionB ha sido llamada %d veces.\n", contadorB);
}

int main() {
    // Llamadas a las funciones
    funcionA();
    funcionB();
    funcionA();
    funcionB();
    funcionA();
    funcionB();

    return 0;
}