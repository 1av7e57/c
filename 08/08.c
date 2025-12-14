/*Mostrar Todos los Estudiantes
Escribe una función llamada mostrarTodosEstudiantes que reciba un
arreglo de Estudiante y su tamaño, y que muestre los datos de todos
los estudiantes en la consola.*/

#include <stdio.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[256];
    int edad;
    float promedio;
};

// Declaración de la función mostrarTodosEstudiantes
void mostrarTodosEstudiantes(struct Estudiante estudiantes[], int tamaño);

// Definición de la función mostrarTodosEstudiantes
void mostrarTodosEstudiantes(struct Estudiante estudiantes[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("Nombre: %s\n", estudiantes[i].nombre);
        printf("Edad: %d\n", estudiantes[i].edad);
        printf("Promedio: %.2f\n", estudiantes[i].promedio);
        printf("-----------------------------\n");
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

    // Llamada a la función mostrarTodosEstudiantes
    mostrarTodosEstudiantes(estudiantes, 5);

    return 0;
}