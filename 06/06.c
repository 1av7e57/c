/*Ejercicio 6: Multiplicación de dos matrices
Escribe un programa que solicite al usuario dos matrices de tamaño
2x2 y calcule su producto.*/

#include <stdio.h>

int main() {
    int A[2][2], B[2][2], C[2][2], i, j, k;

    // Solicitar matriz A
    printf("Ingrese los elementos de la matriz A (2x2):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Solicitar matriz B
    printf("\nIngrese los elementos de la matriz B (2x2):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Calcular el producto de las matrices
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Mostrar el resultado
    printf("\nEl producto de las matrices A y B es:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
