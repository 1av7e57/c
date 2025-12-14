/*Ejercicio 7: Punteros y funciones
Escribe una función void sumarArreglo(int *arr, int
tamano, int incremento) que reciba un puntero a un
array, su tamaño y un valor de incremento. La
función debe sumar el valor del incremento a cada 
elemento del array. En main, crea un array, llama
a la función y muestra el array modificado.*/

#include <stdio.h>

// Declara la función que suma un valor a cada elemento del arreglo
void sumarArreglo(int *arr, int tamano, int incremento);

// Define la función que suma un valor a cada elemento del arreglo
void sumarArreglo(int *arr, int tamano, int incremento) {
    for (int i = 0; i < tamano; i++) {
        arr[i] += incremento;
    }
}

int main() {

    int arr[5] = {1, 2, 3, 4, 5};
    int tamano = sizeof(arr) / sizeof(arr[0]);
    int incremento = 10;

    // Muestra el arreglo original
    printf("Arreglo original:\n");
    for (int i = 0; i < tamano; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Llama a la función
    sumarArreglo(arr, tamano, incremento);

    // Imprime el valor del incremento
    printf("Incremento: %d \n", incremento);
    // Muestra el arreglo modificado
    printf("Arreglo modificado:\n");
    for (int i = 0; i < tamano; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}