/*Ejercicio 6: Remover Espacios en Blanco
Escribe un programa que elimine todos los espacios en blanco de una cadena.

Pista: Usar un bucle para recorrer la cadena y construir una nueva
cadena sin espacios.*/

//Versión alternativa adaptada al lenguaje C

#include <stdio.h>
#include <string.h>

int main() {
    char input[100];  // Almacena la cadena ingresada por el usuario
    char result[100]; // Almacena la cadena sin espacios en blanco

    printf("Ingresa una cadena: ");
    fgets(input, sizeof(input), stdin);  // Lee la entrada del usuario

    int j = 0; // Índice para la cadena resultante
    for (int i = 0; i < strlen(input); ++i) {
        if (input[i] != ' ') {
            result[j++] = input[i]; // Agrega el carácter si no es un espacio
        }
    }
    result[j] = '\0'; // Cierra la cadena resultante con el carácter nulo

    printf("Cadena sin espacios en blanco: %s\n", result);
    return 0;
}