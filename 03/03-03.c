/*Escribe un programa que use un bucle for para imprimir los
números pares del 1 al 20 y luego los números impares del 1 al 20.*/

#include <stdio.h>

int main() {

    printf("los numeros pares del 1 al 20 son: \n");
    // Imprimir números pares del 1 al 20
    for (int i = 2; i <= 20; i += 2) {
        printf("%d\n", i);
    }
    printf("\n");
    printf("los numeros impares del 1 al 20 son: \n");
    // Imprimir números impares del 1 al 20
    for (int i = 1; i <= 20; i += 2) {
        printf("%d\n", i);
    }

    return 0;
}