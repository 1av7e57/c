/*declara tres variables: un entero, un numero con decimales y un caracter.
asigna valores a estas variables e imprimelas en la consola*/

#include <math.h>
#include <stdio.h>

int main()
{
    int entero = 10;
    float decimal = 0.25;
    char caracter = 'a';

    printf(" numero entero: %d \n", entero);
    printf(" numero con decimales: %.2f \n", decimal);
    printf(" caracter: %c \n", caracter);

    return 0;
}