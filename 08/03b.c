/*Estructura Anidada
Define una estructura Curso que contenga los campos codigo (cadena
de caracteres) y nombre (cadena de caracteres). Luego, crea una
estructura Estudiante que incluya un campo de tipo Curso y un campo
anioInscripcion (entero). Inicializa una variable Estudiante y muestra
sus datos.*/

#include <stdio.h>
#include <string.h>

// Definición de la estructura Curso
typedef struct {
    char codigo[256];
    char nombre[256];
} Curso;

// Definición de la estructura Estudiante
typedef struct {
    Curso curso1;
    int anioInscripcion;
} Estudiante;

int main() {
    // Inicialización de una variable de tipo Estudiante
    Estudiante estudiante1;

    // Asignación de valores
    strcpy(estudiante1.curso1.codigo, "CS101");
    strcpy(estudiante1.curso1.nombre, "Introducción a la Programación");
    estudiante1.anioInscripcion = 2025;

    // Mostrar los datos en consola
    printf("Código del curso: %s\n", estudiante1.curso1.codigo);
    printf("Nombre del curso: %s\n", estudiante1.curso1.nombre);
    printf("Año de inscripción: %d\n", estudiante1.anioInscripcion);

    return 0;
}