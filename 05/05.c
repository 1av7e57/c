/*Ejercicio 5: Funciones Recursivas y Variables Estáticas
Objetivo: Analizar el comportamiento de una variable estática dentro de una función recursiva.

1. Escribe una función recursiva contarLlamadas que cuente cuántas veces ha sido llamada.
2. Utiliza una variable static dentro de la función para almacenar la cantidad de llamadas.
3. Llama a la función varias veces desde main().

Preguntas:
¿Cómo afecta la variable estática al comportamiento de la función recursiva?
¿Por qué el valor de la variable estática no se reinicia en cada llamada recursiva?*/

#include <stdio.h>

// Función recursiva que cuenta cuántas veces ha sido llamada
void contarLlamadas() {
    static int llamadas = 0; // Variable estática
    llamadas++;
    printf("Llamada numero: %d \n", llamadas);

    // Condición para detener la recursión
    if (llamadas < 5) {
        contarLlamadas(); // Llamada recursiva
    }
}

int main() {
    contarLlamadas(); // Primera llamada
    return 0;
}
