/*Crea un programa que invierta los dígitos de un número entero. Usa
un bucle while para extraer los dígitos y reconstruir el número
invertido.*/

#include <stdio.h>

int main() {
    int n, invertido = 0, digito;

    printf("Ingresa un numero entero: ");
    scanf("%d", &n);

    while (n != 0) {
        digito = n % 10;
        invertido = invertido * 10 + digito;
        n = n / 10;
    }

    printf("El numero invertido es: %d\n", invertido);

    return 0;
}