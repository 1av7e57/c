/*Escribe un programa que solicite un número N e imprima la tabla de
multiplicar del 1 al 10 usando un bucle for.*/

#include <stdio.h>

int main() {
    int n, i;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    for(i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", n, i, n * i);
    }
    return 0;
}