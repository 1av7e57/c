/*Escribe un programa que busque un número específico dentro de un arreglo de
enteros. Si encuentra el número, debe imprimir su posición y salir del bucle
utilizando break. Si el número no se encuentra, debe informar al usuario.*/

#include <stdio.h>

int main() {
    int arreglo[] = {10, 20, 30, 40, 50};
    int tamano = sizeof(arreglo) / sizeof(arreglo [0]);
    int numeroBuscar;
    int i;

    printf("Ingresa el numero que deseas buscar: ");
    scanf("%d", &numeroBuscar);

    for (i = 0; i < tamano; i++) {
        if (arreglo[i] == numeroBuscar) {
            printf("El numero %d fue encontrado en la posicion %d.\n", numeroBuscar, i);
            break;
        }
    }

    if (i == tamano) {
        printf("El numero %d no fue encontrado en el arreglo.\n", numeroBuscar);
    }

    return 0;
}