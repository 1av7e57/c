/*Crea un programa que imprima los números del 1 al 20, pero omita los múltiplos
de 3 utilizando la sentencia continue.*/

#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 20; i++) {
        if (i % 3 == 0) {
            continue;
        }
        printf("%d\n", i);
    }

    return 0;
}