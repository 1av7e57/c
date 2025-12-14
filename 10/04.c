/*Ejercicio 4: Manejo de Errores en Archivos
Modifica el programa anterior para que maneje
errores al abrir el archivo (por ejemplo, si
el archivo no existe).
Instrucciones:
Si el archivo no se puede abrir, muestra
un mensaje de error apropiado y termina el
programa.*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo;
    double nota, suma = 0.0;
    int contador = 0;

    // Abrir el archivo en modo lectura
    archivo = fopen("notas.txt", "r");
    // Si el archivo no existe o no se puede abrir, se imprime un mensaje de error y termina el programa
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Leer cada línea del archivo
    while (fscanf(archivo, "%lf", &nota) != EOF) {
        suma += nota;
        contador++;
    }

    // Cerrar el archivo
    fclose(archivo);

    // Si no hay notas en el archivo, se imprime un mensaje de error
    if (contador == 0) {
        printf("No hay notas en el archivo.\n");
    } else {
        // Calcular y mostrar el promedio
        double promedio = suma / contador;
        printf("El promedio de las notas es: %.2f\n", promedio);
    }

    return 0;
}