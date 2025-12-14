/*Ejercicio 7: Registros de Personas (Nombre y
Edad)
Crea un programa que guarde nombres y edades
de varias personas en un archivo y luego lea
esos registros e imprima la lista en el
formato: Nombre - Edad.
Instrucciones:
-El archivo debe guardar la información de
las personas en formato nombre edad.
-El programa debe leer y mostrar todos los
registros del archivo.*/

// Inclusión de librerías
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de constantes
#define MAX_LARGO_NOMBRE 100
#define MAX_ENTRADAS 100

int main() {

    // Declaración de variables
    FILE *archivo;
    char nombreArchivo[] = "registros.txt";
    char nombre[MAX_LARGO_NOMBRE];
    int edad;
    int contador = 0;

    // Crear o abrir el archivo para escritura
    archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return 1; // Finaliza y comunica si hay error (1)
    }

    // Solicitar información al usuario
    printf("Ingresa nombres y edades (escribe 'fin' para terminar):\n");
    while (contador < MAX_ENTRADAS) {
        printf("Nombre: ");
        scanf("%s", nombre);
        if (strcmp(nombre, "fin") == 0) break; // Finaliza e imprime registro si el usuario ingresa "fin"


        printf("Edad: ");
        scanf("%d", &edad);

        fprintf(archivo, "%s %d\n", nombre, edad);
        contador++;
    }    
    // Cerrar archivo
    fclose(archivo);

    // Abrir archivo en modo lectura
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 2; // Finaliza y comunica si hay error (2)
    }

    // Mostrar registros
    printf("\nLista de registros:\n");
    while (fscanf(archivo, "%s %d", nombre, &edad) != EOF) {
        printf("%s %d\n", nombre, edad);
    }
    // Cerrar archivo
    fclose(archivo);
    return 0;
}