/*Ordenar Estudiantes
Implementa una función llamada ordenarEstudiantesPorPromedio
que reciba un arreglo de Estudiante y su tamaño. La función debe
ordenar el arreglo de estudiantes de forma ascendente según su
promedio.*/

#include <stdio.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[256];
    int edad;
    float promedio;
};

// Declaración de la Función para ordenar estudiantes por promedio (ascendente)
void ordenarEstudiantesPorPromedio(struct Estudiante estudiantes[], int tamano); 

// Definición de la función para ordenar estudiantes por promedio (ascendente)
void ordenarEstudiantesPorPromedio(struct Estudiante estudiantes[], int tamano) {
    struct Estudiante temp;
    int i, j;

    for (i = 0; i < tamano - 1; i++) {
        for (j = 0; j < tamano - i - 1; j++) {
            if (estudiantes[j].promedio > estudiantes[j + 1].promedio) {
                // Intercambiar estudiantes[j] y estudiantes[j + 1]
                temp = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Declaración del arreglo de Estudiante
    struct Estudiante estudiantes[5];

    // Inicialización de los datos de los estudiantes
    estudiantes[0] = (struct Estudiante){"Ana", 20, 8.5};
    estudiantes[1] = (struct Estudiante){"Carlos", 22, 9.0};
    estudiantes[2] = (struct Estudiante){"Marta", 19, 7.8};
    estudiantes[3] = (struct Estudiante){"Luis", 21, 8.9};
    estudiantes[4] = (struct Estudiante){"Sofia", 2, 8.2};

    // Llamada a la función ordenarEstudiantesPorPromedio
    ordenarEstudiantesPorPromedio(estudiantes, 5);

    // Mostrar el resultado en consola
    printf("Estudiantes ordenados por promedio (ascendente):\n");
    for (int i = 0; i < 5; i++) {
        printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", estudiantes[i].nombre, estudiantes[i].edad, estudiantes[i].promedio);
    }

    return 0;
}