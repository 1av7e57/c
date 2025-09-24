/*Desarrolla un programa que imprima la tabla de multiplicar de un número
ingresado por el usuario utilizando un bucle do-while. El programa debe
preguntar al usuario si desea ver otra tabla después de cada ejecución.*/

#include <stdio.h>

int main() {
    int numero, i, respuesta;

    do {
        printf("Ingrese un numero para ver su tabla de multiplicar: ");
        scanf("%d", &numero);

        printf("Tabla de multiplicar del %d:\n", numero);
        i = 1;
        do {
            printf("%d x %d = %d\n", numero, i, numero * i);
            i++;
        } while (i <= 10);

        printf("¿Desea ver otra tabla? (1 para si, 0 para no): ");
        scanf("%d", &respuesta);
    } while (respuesta == 1);

    return 0;
}