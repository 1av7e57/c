/*Ejercicio 9: Contador de caracteres con punteros
Escribe una función int contarCaracter(const char
*str, char c) que reciba un puntero a una cadena y
un carácter. La función debe contar cuántas veces
aparece c en la cadena. Prueba la función en main
con distintas cadenas y caracteres.*/

#include <stdio.h>

// Declara una función que cuenta cuántas veces aparece un caracter en la cadena 'str'
int contarCaracter(const char *str, char c);

// Define una función que cuenta cuántas veces aparece un caracter en la cadena 'str'
int contarCaracter(const char *str, char c) {
    int count = 0;
    while (*str != '\0') {
        if (*str == c) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    //Establece una cadena y un caracter de prueba, y llama a la función imprimiendo los resultados
    const char *cadena1 = "Hola, mundo!";
    char caracter1 = 'o';
    printf("La letra '%c' aparece %d veces en \"%s\"\n", caracter1, contarCaracter(cadena1, caracter1), cadena1);

    //Establece otra cadena y caracter de prueba, y llama a la función imprimiendo los resultados
    const char *cadena2 = "C es un lenguaje de programación";
    char caracter2 = 'e';
    printf("La letra '%c' aparece %d veces en \"%s\"\n", caracter2, contarCaracter(cadena2, caracter2), cadena2);

    return 0;
}