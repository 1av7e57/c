/*Crea un programa con una variable global llamada contador. Luego, escribe
una función que incremente el valor de contador en 1 cada vez que se llame.
Llama a la función varias veces desde main() y muestra el valor de contador
después de cada llamada.*/

#include <math.h>
#include <stdio.h>

int contador=1;

int sum()
{
    return contador++;
}

int main()
{
    printf("el valor del contador es: %d\n", sum());
    printf("el valor del contador es: %d\n", sum());
    printf("el valor del contador es: %d\n", sum());
    printf("el valor del contador es: %d\n", sum());
    printf("el valor del contador es: %d\n", sum());
    printf("el valor del contador es: %d\n", sum());
    printf("el valor del contador es: %d\n", sum());
    printf("el valor del contador es: %d\n", sum());
    printf("el valor del contador es: %d\n", sum());
    printf("el valor del contador es: %d\n", sum());
    return 0;
}