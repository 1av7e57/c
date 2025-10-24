/*Ejercicio 1: Promedio de elementos

Escribe un programa que solicite al usuario 10 números, 
los almacene en un array y luego calcule el promedio de esos números.*/

#include <stdio.h>

int main() {
    int numeros[10]; // Declaración de arreglo de 10 enteros
    int i; // Variable de control para el bucle
    float suma = 0.0; // Variable para almacenar la suma de los números
    float promedio; // Variable para almacenar el promedio

    // Solicita al usuario que ingrese 10 números
    for (i = 0; i < 10; i++) {
        printf("Ingresa el numero %d: ", i + 1);
        scanf("%d", &numeros[i]); // Almacena el número en el arreglo
        suma += numeros[i];       // Suma el número a la variable 'suma'
    }

    // Calcula el promedio
    promedio = suma / 10;

    // Muestra el resultado
    printf("El promedio de los numeros es: %.2f\n", promedio);

    return 0;
}