/*Ejercicio 2: Invertir una Cadena
Escribe un programa que pida al usuario ingresar una cadena y luego imprima
la cadena en orden inverso.

Requisitos:
Usar un std::string para almacenar la cadena.
Imprimir la cadena en orden inverso utilizando un bucle for.*/

//Version alternativa adaptada al lenguaje C

#include <stdio.h>
#include <string.h>

int main() {
    // Declaramos un C-string para almacenar la cadena
    char cadena[100];  
    printf("Ingrese una cadena: ");
    // Leemos la cadena del usuario
    fgets(cadena, sizeof(cadena), stdin);  
    printf("Cadena invertida: ");
    
    // Bucle for para obtener la cadena en orden inverso
    for (int i = strlen(cadena) - 1; i >= 0; i--) {
        //imprimimos la cadena al reves
        printf("%c", cadena[i]);
    }
    printf("\n");
    return 0;
}