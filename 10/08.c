/*Ejercicio 8: Filtrar Números en un Archivo
Escribe un programa que lea números desde un
archivo y solo imprima aquellos que sean
mayores a un número especificado por el
usuario.
Instrucciones:
-El archivo debe contener una lista de
números enteros.
-El programa debe pedir un número al
usuario y luego imprimir solo los números
del archivo que sean mayores a ese número.*/

// Inclusión de librerías
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Declaración de variables
    FILE *archivo;
    int numero_usuario, numero;

    // Pedir al usuario un número
    printf("Ingresa un número: ");
    scanf("%d", &numero_usuario);

    // Abrir el archivo en modo lectura
    archivo = fopen("numeros.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1; // Finaliza y comunica si hay error
    }

    // Leer números del archivo e imprimir los mayores al ingresado
    while (fscanf(archivo, "%d", &numero) != EOF) {
        if (numero > numero_usuario) {
            printf("%d\n", numero);
        }
    }

    // Cerrar el archivo
    fclose(archivo);
    return 0;
}