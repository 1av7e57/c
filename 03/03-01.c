/*Escribe un programa que use un bucle for para imprimir todos los
números del 1 al N donde N es ingresado por el usuario.*/

#include <stdio.h>

int main() {
    int n, i;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%d\n", i);
    }

    return 0;
}