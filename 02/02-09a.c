/*Desarrolla un programa que imprima un patrón de asteriscos en forma de
triángulo utilizando bucles for anidados.*/

#include <stdio.h>

int main() {
    int i, asteriscos, filas = 5;

    for (i = 1; i <= filas; i++) {
        for (asteriscos = 1; asteriscos <= i; asteriscos++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}