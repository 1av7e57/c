/*Escribir una función que invierta los caracteres de una cadena de texto.
Recibe una cadena y debe modificarla para que los caracteres aparezcan en orden inverso.*/

#include <stdio.h>
#include <string.h>

// Declaración de la función
void invertirCadena(char *cadena);

// Definición de la función
void invertirCadena(char *cadena) {
    int longitud = strlen(cadena);
    int i, j;
    char temp;

    for (i = 0, j = longitud - 1; i < j; i++, j--) {
        temp = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = temp;
    }
}

int main() {
    // Declaración de variables
    char cadena[100];

    // Cuerpo del programa
    printf("Ingresa una cadena de texto: \n");
    fgets(cadena, sizeof(cadena), stdin);

    // Llamada a la función
    invertirCadena(cadena);

    printf("Cadena invertida: %s \n", cadena);

    return 0;
}