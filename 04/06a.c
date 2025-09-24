/*Escribir una función que reciba dos números y devuelva su media aritmética.
Recibe dos números de tipo float y devuelve el resultado.
Nota: La media aritmética es la suma de todos los números divididos la cantidad de números sumados.*/

// Declaración de librerias
#include <stdio.h>

// Declaración de la función
float calcularMedia(float num1, float num2);

// Definición de la función
float calcularMedia(float num1, float num2) {
    return (num1 + num2) / 2.0;
}

int main() {
    // Declaración de variables
    float numero1, numero2, media;

    // Cuerpo del programa
    printf("Ingrese el primer numero: ");
    scanf("%f", &numero1);

    printf("Ingrese el segundo numero: ");
    scanf("%f", &numero2);

    // Llamada a la función
    media = calcularMedia(numero1, numero2);

    printf("La media aritmética es: %.2f\n", media);

    return 0;
}