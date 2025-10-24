/*Ejercicio 7: Palíndromo
Escribe un programa que determine si una cadena es un palíndromo (se lee
igual de adelante hacia atrás y viceversa).

Pista: Usa el método .substr() y .length() para comparar partes de
la cadena.*/

//Versión alternativa para el lenguaje C

#include <stdio.h>
#include <string.h>

// Declaramos la función para eliminar espacios en blanco y el carácter de nueva línea al final de la cadena
void limpiarEspacios(char *cadena);

// Declaramos la función para verificar si una cadena es un palíndromo
int esPalindromo(char *cadena);

// Definimos la función para eliminar todos los espacios en blanco de la cadena
void limpiarEspacios(char *cadena) {
    int i = 0;
    int j = 0;
    while (cadena[i]) {
        if (cadena[i] != ' ' && cadena[i] != '\n' && cadena[i] != '\t') {
            cadena[j++] = cadena[i];
        }
        i++;
    }
    cadena[j] = '\0';
}

// Definimos la función para verificar si la cadena es un palíndromo
int esPalindromo(char *cadena) {
    int longitud = strlen(cadena);
    for (int i = 0; i < longitud / 2; i++) {
        if (cadena[i] != cadena[longitud - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char entrada[100];
    printf("Ingresa una cadena: ");
    fgets(entrada, sizeof(entrada), stdin);

    // Llamada a la función que elimina todos los espacios en blanco
    limpiarEspacios(entrada);

    // Llamada a la función que verifica si la cadena es un palindromo
    if (esPalindromo(entrada)) {
        printf("La cadena es un palíndromo.\n");
    } else {
        printf("La cadena no es un palíndromo.\n");
    }

    return 0;
}