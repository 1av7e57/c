/*Contar Estudiantes
Define un arreglo de estructuras Estudiante con espacio para 5
estudiantes. Pide al usuario que ingrese los datos de cada estudiante y
luego imprime cuántos estudiantes tienen un promedio superior a 7.0.*/

#include <stdio.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[256];
    int edad;
    float promedio;
};

// Declaración de la función para imprimir la cantidad de estudiantes con promedio > 7.0
void contarEstudiantesConPromedioSuperior(struct Estudiante estudiantes[], int tamano);

// Definición de la función para imprimir la cantidad de estudiantes con promedio > 7.0
void contarEstudiantesConPromedioSuperior(struct Estudiante estudiantes[], int tamano) {
    int contador = 0;
    for (int i = 0; i < tamano; i++) {
        if (estudiantes[i].promedio > 7.0) {
            contador++;
        }
    }
    printf("Cantidad de estudiantes con promedio superior a 7.0: %d\n", contador);
}

int main() {
    // Definición del arreglo de estructuras
    struct Estudiante estudiantes[5];

    // Pedir al usuario que ingrese los datos de cada estudiante
    for (int i = 0; i < 5; i++) {
        printf("Ingrese los datos del estudiante %d:\n", i + 1);
        printf("Nombre: ");
        scanf("%s", estudiantes[i].nombre);
        printf("Edad: ");
        scanf("%d", &estudiantes[i].edad);
        printf("Promedio: ");
        scanf("%f", &estudiantes[i].promedio);
        printf("\n");
    }

    // Llamar a la función para contar estudiantes con promedio superior a 7.0
    contarEstudiantesConPromedioSuperior(estudiantes, 5);

    return 0;
}