/*Ejercicio 5: Punteros a punteros
Declara un entero x con el valor 15, un puntero ptr
que apunte a x y un puntero a puntero pptr que
apunte a ptr. Imprime el valor de x usando pptr.*/

#include <stdio.h>

int main() {
    int x = 15;           // Declara un entero x con valor 15
    int *ptr = &x;        // Declara un puntero ptr que apunta a x
    int **pptr = &ptr;    // Declara un puntero a puntero pptr que apunta a ptr

    // Imprime el valor de x usando pptr
    printf("El valor de x es: %d\n", **pptr);

    return 0;
}
