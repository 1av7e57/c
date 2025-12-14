/*Ejercicio 1: Escribir y Leer Datos Simples
Escribe un programa que lea dos números desde
la entrada estándar (teclado) y los guarde en
un archivo de texto. Luego, lea los números
del archivo y los imprima en la pantalla.
Instrucciones:
-Pide al usuario que ingrese dos números
enteros.
-Guarda esos números en un archivo
llamado numeros.txt.
-Luego, lee los números desde el archivo y
muéstralos en la pantalla.*/

#include <stdio.h>

int main() {

    //Declara variables enteras para almacenar números
    int num1, num2;
    //Declara un puntero a un archivo
    FILE *archivo;

    // Pedir al usuario que ingrese dos números enteros
    printf("Ingresa el primer número: ");
    scanf("%d", &num1);
    printf("Ingresa el segundo número: ");
    scanf("%d", &num2);

    // Guardar los números en un archivo llamado "numeros.txt"
    archivo = fopen("numeros.txt", "w"); // Abre el archivo en modo escritura (crea si no existe o sobreescribe)
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return 1;
    }
    fprintf(archivo, "%d\n%d", num1, num2);
    fclose(archivo);

    // Leer los números desde el archivo y mostrarlos en la pantalla
    archivo = fopen("numeros.txt", "r"); //Abre el archivo en modo lectura
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }
    fscanf(archivo, "%d", &num1);
    fscanf(archivo, "%d", &num2);
    fclose(archivo);

    printf("Los números leídos del archivo son: %d y %d\n", num1, num2);

    return 0;
}