/*Ejercicio 4: Buscar un número en un array
Crea un programa que solicite al usuario 10 números, los almacene
en un array y luego le pida al usuario ingresar otro número. El
programa debe indicar si ese número está en el array o no.*/

#include <stdio.h>

int main() {
    int numeros[10];
    int i, numeroBuscar, encontrado = 0;

    // Solicitar al usuario 10 números
    printf("Ingresa 10 números:\n");
    for (i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Solicitar el número a buscar
    printf("Ingresa un número para buscar en el array: ");
    scanf("%d", &numeroBuscar);

    // Buscar el número en el array
    for (i = 0; i < 10; i++) {
        if (numeros[i] == numeroBuscar) {
            encontrado = 1;
            break;
        }
    }

    // Mostrar resultado
    if (encontrado)
        printf("El número %d está en el array.\n", numeroBuscar);
    else
        printf("El número %d no está en el array.\n", numeroBuscar);

    return 0;
}
