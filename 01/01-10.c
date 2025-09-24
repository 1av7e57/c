/*Escribe un programa que use variables de tipo char para almacenar el género
de una persona ('M' para masculino, 'F' para femenino). El programa debe
imprimir un mensaje personalizado basado en el valor ingresado.*/

#include <math.h>
#include <stdio.h>

int main()
{
    char gen;

    printf("dime tu genero \n");
    printf("(ingresa M para masculino \n");
    printf("o F para femenino) \n");
    scanf("%c", &gen);

    if (gen=='M')
    {
        printf("eres hombre \n");
    }else if (gen=='F')
    {
        printf("eres mujer \n");
    }else{
        printf("caracter incorrecto \n");
    }

    return 0;
}