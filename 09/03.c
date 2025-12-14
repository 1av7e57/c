/*Ejercicio 3: Uso de punteros y arrays
Declara un array de enteros con los valores {1, 2,
3, 4, 5}. Usa un puntero para recorrer el array e
imprimir cada valor. Al final, usa el puntero para
modificar los valores del array multiplicándolos
por 2 y muestra el array actualizado.*/

#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;  // Puntero apuntando al primer elemento del array
    int size = sizeof(arr) / sizeof(arr[0]);  // Calcular el tamaño del array

    // Imprimir los valores originales
    printf("Valores originales:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    // Modificar los valores multiplicándolos por 2
    for (int i = 0; i < size; i++) {
        *(p + i) *= 2;
    }

    // Imprimir los valores actualizados
    printf("Valores actualizados:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    return 0;
}