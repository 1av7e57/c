/*Estructura Anidada
Define una estructura Curso que contenga los campos codigo (cadena
de caracteres) y nombre (cadena de caracteres). Luego, crea una
estructura Estudiante que incluya un campo de tipo Curso y un campo
anioInscripcion (entero). Inicializa una variable Estudiante y muestra
sus datos.*/

#include <stdio.h>

// Definición de la estructura Curso
struct Curso {
    char codigo[256];
    char nombre[256];
};

// Definición de la estructura Estudiante
struct Estudiante {
    struct Curso curso1;
    int anioInscripcion;
};

int main() {
    // Inicialización de una variable de tipo Estudiante
    struct Estudiante estudiante1 = {"CS101", "Introducción a la Programación", 2025} ;

    // Mostrar los datos en consola
    printf("Código del curso: %s\n", estudiante1.curso1.codigo);
    printf("Nombre del curso: %s\n", estudiante1.curso1.nombre);
    printf("Año de inscripción: %d\n", estudiante1.anioInscripcion);

    return 0;
}