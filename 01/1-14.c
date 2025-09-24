/*Escribe un programa que defina una función llamada esPar() que reciba un
número entero como parámetro y devuelva 1 si es par o 0 si es impar. Luego,
desde main(), pide un número al usuario y usa esta función para decir si el
número es par o impar.*/

#include <math.h>
#include <stdio.h>


int esPar(int n)
{   
    if (n % 2 == 0) {
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    printf("ingrese un numero \n");
    scanf("%d", &n);
    if (esPar(n) == 1) {
        printf("Es par");
    }
    else {
        printf("Es impar");
    }
    return 0;
}