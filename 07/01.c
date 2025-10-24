/*Ejercicio 1: Longitud de una Cadena
Escribe un programa que pida al usuario ingresar una cadena de texto. Luego,
el programa debe mostrar la longitud de esa cadena utilizando un C-string y
un std::string.

Requisitos:
Usar un C-string para la primera parte del ejercicio.
Usar std::string para la segunda parte.*/

//Versión alternativa adaptada al lenguaje C

#include <stdio.h>
#include <string.h>

int main() {

    // Parte 1: Usar C-string
    char texto[100];
    printf("Ingrese un texto: ");
    fgets(texto, 100, stdin);

    // Contar longitud manualmente (sin usar strlen)
    int longitudCstring = 0;
    while (texto[longitudCstring] != '\0') {
        longitudCstring++;
    }

    // Eliminar el salto de línea si existe
    if (longitudCstring > 0 && texto[longitudCstring - 1] == '\n') {
        longitudCstring--;
    }

    printf("La longitud del C-string es: %d\n", longitudCstring);

    // Parte 2: (no podemos utilizar std::string en C)
    char cadena[100];
    printf("Ingrese otra cadena: ");
    fgets(cadena, 100, stdin);

    // Usar strlen para obtener la longitud
    int longitudCadena = strlen(cadena);

    // Eliminar el salto de línea si existe
    if (longitudCadena > 0 && cadena[longitudCadena - 1] == '\n') {
        longitudCadena--;
    }

    printf("La longitud de la cadena es: %d\n", longitudCadena);

    return 0;
}