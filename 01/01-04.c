/*Modifica el programa del ejercicio 1 para que, además de "¡Hola, Mundo!",
imprima tu nombre en una nueva línea.*/


#include <stdio.h>
int main()
{   char nomb[10] = "Pepe.";
    printf("¡Hola, Mundo! \n");
    printf("%s", nomb);
    return 0;
}
