/*Usa bucles anidados para crear una matriz 5x5 donde cada elemento
sea la suma de sus índices de fila y columna.*/

#include <stdio.h>

int main() {
    int matriz [5][5]; // Declaración de la matriz 5x5

    // Bucles anidados para llenar la matriz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = i + j; // Asignación del valor correspondiente
        }
    }

    // Impresión de la matriz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]); // Impresión de cada elemento
        }
        printf("\n"); // Salto de línea al final de cada fila
    }

    return 0;
}