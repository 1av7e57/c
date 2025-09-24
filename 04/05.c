/*Escribir una función que determine si un número es par o impar.
Recibe un número entero como parámetro y devuelve 1 si es par, y 0 si es impar.*/

// Declaración de librerias
#include <stdio.h>

// Declaración de la función
int esPar(int numero);

// Definición de la función
int esPar(int numero) {
    if (numero % 2 == 0) {
        return 1; // El número es par
    } else {
        return 0; // El número es impar
    }
}

int main() {
    // Declaración de variables
    int numero;

    // Cuerpo del programa
    printf("Ingrese un número entero: ");
    scanf("%d", &numero);

    // Llamada a la función
    if (esPar(numero)) {
        printf("El número es par.\n");
    } else {
        printf("El número es impar.\n");
    }

    return 0;
}
