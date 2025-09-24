/*Escribir una función que calcule el cuadrado de un número entero.
La función debe recibir un número entero como parámetro y devolver su cuadrado.*/

#include <math.h>  
#include <stdio.h>

// Declaración de la función
double cuadrado(int numero);

// Definición de la función
double cuadrado(int numero) {
    return pow(numero, 2);  // Calcula el cuadrado del número
}

int main() {
    int numero;
    double resultado;
    
    // Solicitar al usuario que ingrese un número
    printf("Ingresa un número entero: \n");
    scanf("%d", &numero);
    
    // Llamada a la función
    resultado = cuadrado(numero);
    
    // Mostrar el resultado
    printf("El cuadrado de %d es %.2f \n", numero, resultado);
    
    return 0;
}
