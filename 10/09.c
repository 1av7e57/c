/*Ejercicio 9: Contar las Ocurrencias de un
Número
Escribe un programa que lea un archivo con una
lista de números y cuente cuántas veces
aparece un número específico que el usuario
ingrese.
Instrucciones:
-El archivo debe contener una lista de
números enteros.
-El programa debe pedir al usuario un
número y contar cuántas veces aparece en
el archivo.*/

// Inclusión de librerías
#include <stdio.h>

int main() {

    // Declaración de variables
    FILE *archivo;
    int numero_buscado, numero, contador = 0;

    // Abrir el archivo en modo lectura
    archivo = fopen("numeros.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");   // Imprime mensaje en caso de error
        return 1;  // Cierra con error
    }

    // Pedir al usuario el número a buscar
    printf("Ingresa el número que deseas contar: ");
    scanf("%d", &numero_buscado);

    // Leer el archivo línea por línea y contar coincidencias
    while (fscanf(archivo, "%d", &numero) != EOF) {
        if (numero == numero_buscado) {
            contador++;
        }
    }

    // Cerrar el archivo
    fclose(archivo);

    // Mostrar el resultado
    printf("El número %d aparece %d veces en el archivo.\n", numero_buscado, contador);

    return 0;
}