/*Escribe un programa que imprima todos los números primos entre 1
y N usando un bucle for y otro bucle anidado para verificar si un
número es primo.*/

#include <stdio.h>

int main() {
    int n, i, j, esPrimo;

    printf("Ingrese un numero entero positivo: \n");
    scanf("%d", &n);

    printf("Numeros primos entre 1 y %d son: \n", n);

    for (i = 2; i <= n; i++) {
        esPrimo = 1;

        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                esPrimo = 0;
                break;
            }
        }

        if (esPrimo) {
            printf("%d ", i);
        }
    }

    return 0;
}