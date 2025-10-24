/*Ejercicio 3: Matriz identidad

Escribe un programa que cree una matiz identidad de tamaño 3x3.
La matriz identidad es una matriz cuadrada con 1s en la diagonal
principal y 0s en las demás posiciones.*/

#include <stdio.h>

int main() {
    int size = 3;
    int matrix[3][3];

    // Inicializar la matriz identidad
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}