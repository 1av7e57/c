/*Ejercicio 2: Intercambio de valores con punteros
Escribe una función void intercambiar(int *a, int
*b) que intercambie los valores de dos variables
usando punteros. En main, declara dos variables
enteras, llámala usando sus direcciones y verifica
que los valores se hayan intercambiado correctamente.*/

#include <stdio.h>

// Declara la función para intercambiar los valores usando punteros
void intercambiar(int *a, int *b);

// Define la función para intercambiar los valores usando punteros
void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10;
    int b = 20;

    printf("Antes del intercambio: a = %d, b = %d\n", a, b);

    // Llama a la función con las direcciones de a y b
    intercambiar(&a, &b);

    printf("Después del intercambio: a = %d, b = %d\n", a, b);

    return 0;
}