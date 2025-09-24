/*Crea un programa que sume todos los números del 1 al N usando un
bucle while. Imprime la suma al final.*/

#include <stdio.h>

int main() {
    int n, i = 1, suma = 0;

    printf("Ingresa un numero entero positivo: ");
    scanf("%d", &n);

    while (i <= n) {
        suma += i;
        i++;
    }

    printf("La suma de los numeros del 1 al %d es: %d\n", n, suma);
    return 0;
}