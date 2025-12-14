/*Estructura de Fecha de Nacimiento
Define una estructura Fecha con los campos dia, mes, y anio. Luego,
modifica la estructura Estudiante para incluir un campo de tipo Fecha
llamado fechaNacimiento. Pide al usuario que ingrese la fecha de
nacimiento y muestra todos los datos del estudiante incluyendo su
fecha de nacimiento.*/

#include <stdio.h>

// Definición de la estructura Fecha
struct Fecha {
    int dia;
    int mes;
    int anio;
};

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[256];
    int edad;
    float promedio;
    struct Fecha fechaNacimiento; // Campo de tipo Fecha
};

int main() {
    // Declaración e inicialización de una variable de tipo Estudiante
    struct Estudiante estudiante1 = {"Juan Pérez", 20, 8.5, {0, 0, 0}}; // Inicialización de fechaNacimiento con valores por defecto

    // Imprimir datos originales del estudiante
    printf("Datos originales del estudiante:\n");
    printf("Nombre: %s\n", estudiante1.nombre);
    printf("Edad: %d\n", estudiante1.edad);
    printf("Promedio: %.1f\n", estudiante1.promedio);

    // Pedir al usuario que ingrese la fecha de nacimiento
    printf("\nIngrese la fecha de nacimiento del estudiante:\n");
    printf("Día: ");
    scanf("%d", &estudiante1.fechaNacimiento.dia);
    printf("Mes: ");
    scanf("%d", &estudiante1.fechaNacimiento.mes);
    printf("Año: ");
    scanf("%d", &estudiante1.fechaNacimiento.anio);

    // Mostrar todos los datos del estudiante, incluyendo la fecha de nacimiento
    printf("\nDatos del estudiante actualizados:\n");
    printf("Nombre: %s\n", estudiante1.nombre);
    printf("Edad: %d\n", estudiante1.edad);
    printf("Promedio: %.1f\n", estudiante1.promedio);
    printf("Fecha de nacimiento: %02d/%02d/%04d\n", estudiante1.fechaNacimiento.dia, estudiante1.fechaNacimiento.mes, estudiante1.fechaNacimiento.anio);

    return 0;
}