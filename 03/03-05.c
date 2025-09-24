/*Usa un bucle while para sumar los dígitos de un número entero. El
programa debe seguir dividiendo el número por 10 hasta que todos
los dígitos hayan sido sumados.*/

#include <stdio.h>

int main() {
    int n, suma = 0, digito;

    printf("Ingresa un numero entero: ");
    scanf("%d", &n);

    while (n > 0) {
        digito = n % 10;       // Obtiene el último dígito
        suma += digito;       // Suma el dígito a la variable 'suma'
        n = n / 10;           // Elimina el último dígito del número
    }

    printf("La suma de los dígitos es: %d\n", suma);
    return 0;
}