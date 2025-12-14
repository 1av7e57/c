/*Ejercicio 2: Suma de Números en un Archivo
Escribe un programa que lea una lista de
números desde un archivo de texto y calcule
la suma de todos ellos.
Instrucciones:
-Crea un archivo llamado numeros.txt que
contenga una lista de números enteros (uno
por línea).
-Tu programa debe leer esos números y
calcular su suma total.
-Muestra la suma al final.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo;
    int numero;
    int suma = 0;

    // Abrir el archivo en modo lectura (el archivo debe crearse manualmente primero)
    archivo = fopen("numeros.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Leer cada número del archivo y sumar
    while (fscanf(archivo, "%d", &numero) != EOF) {
        suma += numero;
    }

    // Cerrar el archivo
    fclose(archivo);

    // Mostrar la suma total
    printf("La suma de los números es: %d\n", suma);

    return 0;
}