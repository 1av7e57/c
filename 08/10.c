/*Uso de Punteros y Estructuras
Crea una función llamada modificarEdad que reciba un puntero a un
Estudiante y un nuevo valor de edad. Esta función debe cambiar la
edad del estudiante. En el main, crea un estudiante, modifica su edad
usando esta función, y muestra el resultado.*/

#include <stdio.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[256];
    int edad;
    float promedio;
};

// Declaración de la función para modificar la edad del estudiante
void modificarEdad(struct Estudiante *estudiante1, int nuevaEdad);

// Definición de la función para modificar la edad del estudiante
void modificarEdad(struct Estudiante *estudiante1, int nuevaEdad) {
    estudiante1->edad = nuevaEdad;
}

int main() {
    // Declaración e inicialización de una variable de tipo Estudiante
    struct Estudiante estudiante1 = {"Juan Pérez", 20, 8.5};

    // Imprimir los datos originales del estudiante
    printf("Datos originales del estudiante:\n");
    printf("Nombre: %s\n", estudiante1.nombre);
    printf("Edad: %d\n", estudiante1.edad);
    printf("Promedio: %.1f\n", estudiante1.promedio);

    // Pedir al usuario una nueva edad
    int nuevaEdad;
    printf("\nIngrese una nueva edad para el estudiante: ");
    scanf("%d", &nuevaEdad);

    // Llamar a la función modificarEdad
    modificarEdad(&estudiante1, nuevaEdad);

    // Mostrar los datos actualizados
    printf("\nDatos actualizados del estudiante:\n");
    printf("Nombre: %s\n", estudiante1.nombre);
    printf("Edad: %d\n", estudiante1.edad);
    printf("Promedio: %.1f\n", estudiante1.promedio);

    return 0;
}

