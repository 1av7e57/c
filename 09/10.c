/*Ejercicio 10: Manejo dinámico de arrays
-Usa new para crear un array dinámico de n
enteros, donde n es un valor proporcionado por
el usuario.
-Llena el array con valores proporcionados por
el usuario.
-Calcula el promedio de los valores usando un
puntero para recorrer el array.
-Muestra el promedio y libera la memoria del
array con delete[].*/

//Versión alternativa, adaptada al lenguaje C

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Pedir al usuario el número de elementos
    printf("Ingrese el número de elementos: ");
    scanf("%d", &n);

    // Crear un array dinámico con 'malloc'
    int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    // Llenar el array con valores proporcionados por el usuario
    for (int i = 0; i < n; i++) {
        printf("Ingrese el valor %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Calcular el promedio usando un puntero para recorrer el array
    int* ptr = array;
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += *ptr;
        ptr++;
    }
    double promedio = (double)suma / n;

    // Mostrar el promedio
    printf("El promedio es: %.2f\n", promedio);

    // Liberar la memoria del array con 'free'
    free(array);

    // Asignar NULL manualmente al puntero
    array = NULL;

    return 0;
}