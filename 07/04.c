/*Ejercicio 4: Contar Vocales
Escribe un programa que pida al usuario ingresar una cadena y luego cuente
cuántas vocales contiene.

Requisitos:
Usar std::string para almacenar la cadena.
Considerar las vocales tanto en minúsculas como en mayúsculas.*/

//Versión alternativa para el lenguaje C

#include <stdio.h>
#include <string.h> //En lugar de <string>
#include <ctype.h> // En lugar de <cctype>, para usar toupper()

int main() {
    char cadena[256]; // Tamaño fijo para la cadena
    int contadorVocales = 0;
    int i;

    printf("Ingresa una cadena: ");
    fgets(cadena, sizeof(cadena), stdin); // En lugar de std::getline()
                                          // Para leer la cadena

    for (i = 0; i < strlen(cadena); ++i) {
        char c = cadena[i];
        char upperChar = toupper(c); // En lugar de std::toupper() 
                                     //Para convertir a mayúsculas

        if (upperChar == 'A' || upperChar == 'E' || upperChar == 'I' ||
            upperChar == 'O' || upperChar == 'U') {
            contadorVocales++;
        }
    }

    printf("La cadena contiene %d vocales.\n", contadorVocales);
    return 0;
}