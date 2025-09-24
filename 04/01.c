/*Escribir una función que imprima un saludo personalizado.
La función debe recibir el nombre de la persona como parámetro y luego imprimir “Hola, [nombre]”.*/

#include <stdio.h>

// Declaración de la función
void saludar(char nombre[]);

// Definición de la función
void saludar(char nombre[]) {
    printf("Hola, %s\n", nombre);
}

int main() {
    char nombre[20];

    printf("Ingresa tu nombre: ");
    scanf("%s", nombre);
    
    // Llamada a la función
    saludar(nombre);

    return 0;
}