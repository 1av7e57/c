/*Ejercicio 5: Búsqueda de Palabra en Texto
Escribe un programa que pida al usuario ingresar un texto largo y luego
ingrese una palabra. El programa debe decir si la palabra existe en el texto y
en qué posición aparece la primera vez.

Requisitos:
Usar std::string y el método .find().*/

//Version alternativa adaptada al lenguaje C

#include <stdio.h>
#include <string.h>

int main() {
    char texto[1000];
    char palabra[100];

    // Pedir al usuario que ingrese un texto largo
    printf("Ingresa un texto largo: ");
    fgets(texto, sizeof(texto), stdin);

    // Pedir al usuario que ingrese una palabra
    printf("Ingresa una palabra: ");
    fgets(palabra, sizeof(palabra), stdin);

    // Eliminar el salto de línea del final de las cadenas
    texto[strcspn(texto, "\n")] = '\0';
    palabra[strcspn(palabra, "\n")] = '\0';

    // Buscar la posición de la primera aparición de la palabra en el texto
    char* posicion = strstr(texto, palabra);

    // Verificar si la palabra fue encontrada
    if (posicion != NULL) {
        printf("La palabra \"%s\" fue encontrada en la posición: %zu\n", palabra, (size_t)(posicion - texto + 1));
    } else {
        printf("La palabra \"%s\" no fue encontrada en el texto.\n", palabra);
    }

    return 0;
}