/*Ejercicio 4: Función para modificar valores
Escribe una función void incrementar(int *p, int
incremento) que reciba un puntero a entero y un
valor de incremento. La función debe sumar el valor
del incremento al valor apuntado por el puntero. En
main, verifica que funciona pasando distintas
variables y valores de incremento.*/

#include <stdio.h>

// Se declara la función que incrementa el valor apuntado por el puntero
void incrementar(int *p, int incremento);

// Se define la función que incrementa el valor apuntado por el puntero
void incrementar(int *p, int incremento) {
    *p += incremento;
}

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    // Verificar la función con distintas variables
    incrementar(&a, 5);
    incrementar(&b, 10);
    incrementar(&c, 15);

    // Imprimir los resultados
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    return 0;
}