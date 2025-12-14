/*Ejercicio 8: Invertir un array usando punteros
Crea una función void invertir(int *arr, int
tamano) que reciba un puntero a un array de enteros
y su tamaño. La función debe invertir el array in
situ usando solo aritmética de punteros. Verifica
en main que funciona con un array de prueba.*/

#include <stdio.h>

//Declara la función invertir
void invertir(int *arr, int tamano);

//Define la función invertir
void invertir(int *arr, int tamano) {
    int *inicio = arr;
    int *fin = arr + tamano - 1;

    while (inicio < fin) {
        // Intercambia elementos
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;

        // Mueve los punteros
        inicio++;
        fin--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int tamano = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < tamano; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Llamada a la función invertir
    invertir(arr, tamano);

    printf("Array invertido:\n");
    for (int i = 0; i < tamano; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}