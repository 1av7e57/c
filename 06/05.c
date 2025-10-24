/*Ejercicio 5: Máximo y mínimo en un array
Escribe un programa que solicite al usuario 10 números, los almacene
en un array y luego determine el número mayor y menor del array.*/

#include <stdio.h>

int main() {
    int numeros[10];
    int i;
    int mayor, menor;

    // Solicitar al usuario que ingrese 10 números
    printf("Por favor, ingrese 10 números:\n");
    for (i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Inicializar mayor y menor con el primer elemento del array
    mayor = menor = *numeros;

    // Determinar el número mayor y menor
    for (i = 1; i < 10; i++) {
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    // Mostrar resultados
    printf("El número mayor es: %d\n", mayor);
    printf("El número menor es: %d\n", menor);

    return 0;
}
