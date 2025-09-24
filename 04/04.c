/*Escribir una función que calcule el factorial de un número.
El programa debe recibir un número entero positivo y devolver su factorial. Debe incluir el manejo de casos base.*/

#include <stdio.h>

// Declaración de la función
int factorial(int numero);

// Definición de la función
int factorial(int numero) {
    int calculo = 1;

    // Validación explícita de caso base
    // Si el número es 0, el factorial es 1 por definición (0! = 1)
    if (numero == 0) {
        return 1;
    } else {
        // Si el número es mayor que 0, calculamos el factorial
        for (int i = 1; i <= numero; i++) {
            calculo *= i;
        }
    }

    return calculo;
}

int main() {
    int numero, resultado;

    // Solicitar al usuario que ingrese un número
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &numero);

    // Verificar si el número es positivo
    if (numero < 0) {
        printf("El número ingresado no es positivo.\n");
    } else {
        // Llamada a la función para calcular el factorial
        resultado = factorial(numero);
        printf("El factorial de %d es %d\n", numero, resultado);
    }

    return 0;
}