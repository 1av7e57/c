/*Ejercicio 2: Invertir un array

Dado un array de 5 enteros, escribe un programa que lo invierta. Es
decir que el primer elemento pase a ser el último y viceversa.*/
#include <stdio.h>

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int i, temp;

    printf("Array original: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    // Invertir el array
    for (i = 0; i < 2; i++) {
        temp = array[i];
        array[i] = array[4 - i];
        array[4 - i] = temp;
    }

    printf("\nArray invertido: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}