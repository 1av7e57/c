/*Escribe un programa que solicite al usuario ingresar un número entero y
determine si es par o impar utilizando una estructura condicional if-else.*/

#include<math.h>
#include<stdio.h>

int main()
{
    int n;
    printf("ingrese un numero: \n");
    scanf("%d", &n);
    if (n%2==0)
    {
        printf("el numero es par \n");
    }else{
        printf("el numero es impar");
    }        

    return 0;
}
