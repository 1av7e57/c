/*Investiga cómo funciona la función scanf() en C y usa este conocimiento para
modificar el programa del ejercicio 1. Ahora el programa debe pedirle al
usuario su nombre e imprimir "¡Hola, [nombre del usuario]!".*/


#include <stdio.h>
int main()
{   char nomb[20];
    printf("indique su nombre \n");
    scanf("%s", nomb);
    printf("¡Hola, %s", nomb);
    printf("!");
    return 0;
}