/*Ejercicio 3: Comparar Cadenas
Escribe un programa que pida al usuario ingresar dos cadenas y luego
determine si son iguales o diferentes. Realiza esto con C-strings y con
std::string.

Requisitos:
Usar C-strings para la primera parte.
Usar std::string para la segunda parte.*/

//Version alternativa usando solo C-strings para adaptala al lenguaje C

#include <stdio.h>
#include <string.h>

int main() {
    // Declaramos dos cadenas (arreglos de caracteres)
    char str1[100];
    char str2[100];

    // Pedimos al usuario que ingrese la primera cadena
    printf("Ingresa la primera cadena: ");
    fgets(str1, sizeof(str1), stdin);

    // Pedimos al usuario que ingrese la segunda cadena
    printf("Ingresa la segunda cadena: ");
    fgets(str2, sizeof(str2), stdin);

    // Comparamos las cadenas
    if (strcmp(str1, str2) == 0) {
        printf("Las cadenas son iguales.\n");
    } else {
        printf("Las cadenas son diferentes.\n");
    }

    return 0;
}