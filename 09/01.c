/*Ejercicio 1: Uso básico de punteros
Declara una variable int llamada a e inicialízala
con el valor 5. Declara un puntero p que apunte a
a y luego usa el puntero para:
Imprimir la dirección de a.
Imprimir el valor de a usando el puntero.
Cambiar el valor de a a 10 usando el puntero y
mostrar el nuevo valor.*/

#include <stdio.h>

int main() {
    int a = 5;       // Declara e inicializa la variable 'a' con el valor 5
    int *p = &a;     // Declara un puntero 'p' que apunta a 'a'

    // 1. Imprimir la dirección de 'a'
    printf("Dirección de 'a': %p\n", &a);

    // 2. Imprimir el valor de 'a' usando el puntero
    printf("Valor de 'a' usando el puntero: %d\n", *p);

    // 3. Cambiar el valor de 'a' a 10 usando el puntero
    *p = 10;
    printf("Nuevo valor de 'a': %d\n", *p);

    return 0;
}