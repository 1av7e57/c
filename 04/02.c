/*Escribir una función que devuelva el mayor de dos números enteros.
Debe recibir dos enteros y devolver el mayor de ellos.*/

#include <stdio.h>

// Declaración de la función
int mayor(int a, int b);

// Definición de la función
int mayor(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    int num1, num2, resultado;

    // Solicitar al usuario que ingrese los valores
    printf("Ingrese el primer numero: \n");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: \n");
    scanf("%d", &num2);

    // Llamada a la función
    resultado = mayor(num1, num2);

    printf("El mayor de %d y %d es: %d \n", num1, num2, resultado);
    return 0;
}



