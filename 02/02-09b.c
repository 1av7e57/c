/*Desarrolla un programa que imprima un patrón de asteriscos en forma de
triángulo utilizando bucles for anidados.*/

/*alternativa para imprimir un triangulo en forma de piramide
incluyendo un bucle para espacios en blanco*/

#include <stdio.h>

int main() {
    int i, espacios, asteriscos, filas = 5;

    for (i = 1; i <= filas; i++) {
        // Espacios en blanco
        for (espacios = 1; espacios <= filas - i; espacios++) {
            printf(" ");
        }
        // Asteriscos
        for (asteriscos = 1; asteriscos <= 2 * i - 1; asteriscos++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
