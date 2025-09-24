/*Escribir una función que calcule el valor absoluto de un número.
La función debe recibir un número entero y devolver su valor absoluto.
Nota: El valor absoluto de un número es el valor sin signo negativo o positivo,
es decir el valor absoluto de X se representa como |X|, y de igual manera 
el valor absoluto de –X se representa como |X|.*/

// Declaración de librerias
#include <stdio.h>

// Declaración de la función
int valorAbsoluto(int numero);

// Definición de la función
int valorAbsoluto(int numero) {
    if (numero < 0) {
        return -numero;
    } else {
        return numero;
    }
}

int main() {
    // Declaración de variables
    int numero, resultado;

    // Cuerpo del programa
    printf("Ingrese un número entero: \n");
    scanf("%d", &numero);

    // Llamada a la función
    resultado = valorAbsoluto(numero);
    printf("El valor absoluto de %d es [%d] \n", numero, resultado);

    return 0;
}