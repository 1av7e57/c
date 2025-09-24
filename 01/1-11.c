/*Escribe un programa que defina y use una función llamada suma(). La función
debe tomar dos números enteros como parámetros y devolver la suma de estos
números.*/

#include <math.h>
#include <stdio.h>

int suma ()
{
    int a,b;
    printf("ingresa el primer numero: \n");  
    scanf("%d", &a);
    printf("ingresa el segundo numero: \n"); 
    scanf("%d", &b);
    return a+b;
}

int main()
{   
    
    printf("el resultado de la suma es: %d", suma());
    return 0;
}