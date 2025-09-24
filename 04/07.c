/*Escribir una función que reciba un array y su tamaño, y devuelva el mayor elemento del array.
Debe iterar a través del array para encontrar el valor máximo.*/

// Declaración de librerias
#include <stdio.h>

// Declaración de la función
int encontrarMaximo(int array[], int tamano);

// Definición de la función
int encontrarMaximo(int array[], int tamano) {
    int max = *array;
    for (int i = 1; i < tamano; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int main() {
    // Declaración de variables
    int array[] = {5, 3, 9, 1, 7};
    int tamano = sizeof(array) / sizeof(*array);

    // Llamada a la función
    int maximo = encontrarMaximo(array, tamano);
    printf("El mayor elemento del array es: %d\n", maximo);

    return 0;
}