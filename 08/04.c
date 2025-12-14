/*Función para Modificar Datos
Crea una función llamada cambiarPromedio que reciba un puntero a
un Estudiante y un nuevo promedio como parámetros. Esta función
debe modificar el promedio del estudiante con el nuevo valor
proporcionado.*/

#include <stdio.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

//Declaración de la función para cambiar el promedio de un estudiante
void cambiarPromedio(struct Estudiante *estudiante1, float nuevoPromedio);

// Definición de la función para cambiar el promedio de un estudiante
void cambiarPromedio(struct Estudiante *estudiante1, float nuevoPromedio) {
    estudiante1->promedio = nuevoPromedio;
    }

int main() {
    // Declaración e inicialización de una variable de tipo Estudiante
    struct Estudiante estudiante1 = {"Juan Pérez", 20, 8.5};

    // Impresión de los datos del estudiante
    printf("Nombre: %s\n", estudiante1.nombre);
    printf("Edad: %d\n", estudiante1.edad);
    printf("Promedio Original: %.2f\n", estudiante1.promedio);
    printf("\n");

    // Llamada a la función para cambiar el promedio
    cambiarPromedio(&estudiante1, 9.0);

    // Impresión de los datos del estudiante con promedio cambiado
    printf("Nombre: %s\n", estudiante1.nombre);
    printf("Edad: %d\n", estudiante1.edad);
    printf("Nuevo Promedio: %.2f\n", estudiante1.promedio);
    printf("\n");

    return 0;
}