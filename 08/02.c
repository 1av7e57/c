/*Impresión de Datos
Utiliza la estructura Estudiante creada en el ejercicio anterior y
escribe una función llamada imprimirEstudiante que reciba un
Estudiante como parámetro y muestre sus datos en la consola.*/

#include <stdio.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

// Función para imprimir los datos de un estudiante1
void imprimirEstudiante(struct Estudiante estudiante1) {
    printf("Nombre: %s\n", estudiante1.nombre);
    printf("Edad: %d\n", estudiante1.edad);
    printf("Promedio: %.2f\n", estudiante1.promedio);
}

int main() {
    // Declaración e inicialización de una variable de tipo Estudiante
    struct Estudiante estudiante1 = {"Juan Pérez", 20, 8.5};

    // Llamada a la función imprimirEstudiante
    imprimirEstudiante(estudiante1);

    return 0;
}