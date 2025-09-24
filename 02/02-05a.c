/*Crea un programa que solicite al usuario ingresar números enteros positivos. El
programa debe continuar pidiendo números hasta que el usuario ingrese 0. Al
finalizar, muestra la suma de todos los números ingresados utilizando un bucle while.*/

#include <stdio.h>

int main() {
    int numero, suma = 0;

    printf("Ingresa números enteros positivos (ingresa 0 para terminar):\n");

    while (1) {  // Bucle infinito hasta que el usuario ingrese 0
        scanf("%d", &numero);

        if (numero == 0) {
            break;  // Sale del bucle si el número es 0
        }

        if (numero < 0) {
            printf("Ingresa un número positivo.\n");
            continue;  // Salta al final del bucle para pedir otro número
        }

        suma += numero;  // Suma el número ingresado a la variable 'suma'
    }

    printf("La suma de todos los números ingresados es: %d\n", suma);

    return 0;
}