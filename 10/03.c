/*Ejercicio 3: Promedio de Números
Escribe un programa que calcule el promedio
de una lista de números almacenados en un
archivo.
Instrucciones:
-Crea un archivo llamado notas.txt que
contenga las notas de un estudiante (uno
por línea).
-Tu programa debe leer todas las notas
desde el archivo y calcular el promedio de
las mismas.
-Muestra el promedio en la pantalla.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo;
    double nota, suma = 0.0;
    int contador = 0;

    // Abrir el archivo en modo lectura
    archivo = fopen("notas.txt", "r");
    
    // Leer cada línea del archivo
    while (fscanf(archivo, "%lf", &nota) != EOF) {
        suma += nota;
        contador++;
    }

    // Cerrar el archivo
    fclose(archivo);

    // Calcular y mostrar el promedio    
    double promedio = suma / contador;
    printf("El promedio de las notas es: %.2f\n", promedio);

    return 0;
}