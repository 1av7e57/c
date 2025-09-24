/*Escribir una función que reciba dos números y devuelva su media aritmética.
Recibe dos números de tipo float y devuelve el resultado.
Nota: La media aritmética es la suma de todos los números divididos la cantidad de números sumados.*/

/*version alternativa que suma todos los numeros ingresados por el usuario
y los divide por la cantidad de numeros ingresados sin especificar previamente una cantidad de números*/

#include <stdio.h>

// Declaración de la función
float calcularMedia(float suma, int cantidad);

// Definición de la función
float calcularMedia(float suma, int cantidad) {
    return suma / cantidad;
}

int main() {
    float numero, suma = 0.0;
    int cantidad = 0;

    printf("Ingrese números separados por la tecla ENTER (ingrese 0 para finalizar):\n");

    while (1) {
        scanf("%f", &numero);
        if (numero == 0) {
            break;
        }
        suma += numero;
        cantidad++;
    }

    if (cantidad == 0) {
        printf("No se ingresaron números.\n");
    } else {
        float media = calcularMedia(suma, cantidad);
        printf("La media aritmética es: %.2f\n", media);
    }

    return 0;
}