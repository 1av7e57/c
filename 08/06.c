/*Búsqueda de Estudiante
Escribe una función llamada buscarEstudiantePorNombre que reciba
un arreglo de Estudiante, el tamaño del arreglo y un nombre como
parámetros. La función debe retornar el índice del estudiante si lo
encuentra, o -1 si no lo encuentra.*/

#include <stdio.h>
#include <string.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[256];
    int edad;
    float promedio;
};

// Declaración de la función para buscar un estudiante por nombre
int buscarEstudiantePorNombre(struct Estudiante estudiantes[], int tamano, const char *nombreBuscado);

// Definición de la función para buscar un estudiante por nombre
int buscarEstudiantePorNombre(struct Estudiante estudiantes[], int tamano, const char *nombreBuscado) {
    for (int i = 0; i < tamano; i++) {
        if (strcmp(estudiantes[i].nombre, nombreBuscado) == 0) {
            return i; // Retorna el índice si el nombre coincide
        }
    }
    return -1; // Retorna -1 si no se encuentra el nombre
}

int main() {
    // Declaración del arreglo de estudiantes
    struct Estudiante estudiantes[5];

    // Inicialización de los datos de los estudiantes
    estudiantes[0] = (struct Estudiante){"Ana", 20, 8.5};
    estudiantes[1] = (struct Estudiante){"Carlos", 22, 9.0};
    estudiantes[2] = (struct Estudiante){"Marta", 19, 7.8};
    estudiantes[3] = (struct Estudiante){"Luis", 21, 8.9};
    estudiantes[4] = (struct Estudiante){"Sofia", 2, 8.2};

    // Pedir al usuario que ingrese el nombre de un estudiante para buscar
    char nombreBuscado[256];
    printf("Ingrese el nombre del estudiante a buscar: ");
    scanf("%s", nombreBuscado);
    printf("\n");

    // Llamar a la función de búsqueda
    int indice = buscarEstudiantePorNombre(estudiantes, 5, nombreBuscado);

    // Mostrar el resultado
    if (indice != -1) {
        printf("Estudiante encontrado en índice: %d\n", indice+1); //Sumamos 1 al indice para contar del 1 al 5
        printf("Nombre: %s\n", estudiantes[indice].nombre);
        printf("Edad: %d\n", estudiantes[indice].edad);
        printf("Promedio: %.2f\n", estudiantes[indice].promedio);
    } else {
        printf("Estudiante no encontrado.\n");
    }

    return 0;
}