/*Declaración e Inicialización
Crea una estructura llamada Estudiante que contenga los campos
nombre (cadena de caracteres), edad (entero) y promedio (flotante).
Declara una variable de tipo Estudiante e inicialízala con datos de tu
elección.*/

#include <stdio.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    // Declaración e inicialización de una variable de tipo Estudiante
    struct Estudiante estudiante1 = {"Juan Pérez", 20, 8.5};

    // Impresión de los datos del estudiante
    printf("Nombre: %s\n", estudiante1.nombre);
    printf("Edad: %d\n", estudiante1.edad);
    printf("Promedio: %.2f\n", estudiante1.promedio);

    return 0;
}