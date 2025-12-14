/*Ejercicio 10: Reemplazo de Números en un
Archivo
Escribe un programa que lea un archivo con
números, reemplace todos los números mayores
a un valor dado por el usuario por el valor
de 0, y luego escriba el resultado en un nuevo
archivo.
Instrucciones:
-El archivo debe contener una lista de
números enteros.
-El programa debe pedir un valor al usuario
y reemplazar todos los números mayores a
ese valor por 0.
-El resultado debe guardarse en un archivo
nuevo llamado resultado.txt.*/

// Inclusión de librerías
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaración de variables
    FILE *archivoEntrada, *archivoSalida;
    int numero, valorLimite;

    // Pedir al usuario el valor límite
    printf("Ingresa el valor limite: ");
    scanf("%d", &valorLimite);

    // Abrir el archivo de entrada en modo lectura
    archivoEntrada = fopen("numeros.txt", "r");
    if (archivoEntrada == NULL) {
        printf("No se pudo abrir el archivo de entrada.\n");  // Imprime mensaje en caso de error
        return 1; // Cierra con error (1)
    }

    // Crear o sobrescribir el archivo de salida
    archivoSalida = fopen("resultado.txt", "w");
    if (archivoSalida == NULL) {
        printf("No se pudo crear el archivo de salida.\n");  // Imprime mensaje en caso de error
        fclose(archivoEntrada);
        return 2; // Cierra con error (2)
    }

    // Procesar cada número del archivo
    while (fscanf(archivoEntrada, "%d", &numero) != EOF) {
        if (numero > valorLimite) {
            fprintf(archivoSalida, "0\n");
        } else {
            fprintf(archivoSalida, "%d\n", numero);
        }
    }

    // Cerrar archivos
    fclose(archivoEntrada);
    fclose(archivoSalida);

    //Mensaje final al usuario
    printf("Proceso completado. Los resultados se guardaron en 'resultado.txt'.\n");
    return 0;
}