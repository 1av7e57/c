/*Implementa un programa que calcule el factorial de un número N
usando un bucle for. El factorial de N (denotado como N!) es el
producto de todos los números enteros positivos menores o iguales a
N.*/

#include <stdio.h>

int main() {
    int n, i;
    //unsigned: Indica que la variable no puede almacenar números negativos
    //long long: Es un tipo de dato que permite almacenar números muy grandes.
    unsigned long long factorial = 1;

    printf("Ingresa un numero entero positivo: ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {

        /*multiplica el valor actual de factorial por i, 
        luego asigna el resultado de nuevo a factorial*/
        factorial *= i;
    }

    printf("El factorial de %d es %llu\n", n, factorial);
    
    return 0;
}