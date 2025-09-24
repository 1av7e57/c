/*Modifica el programa del ejercicio anterior para incluir otras dos funciones:
resta() y multiplicacion(), que calculen la resta y la multiplicación de dos
números.*/

#include <math.h>
#include <stdio.h>

int suma ()
{
    int a,b;
    printf("suma: \n");
    printf("ingresa el primer numero: \n");  
    scanf("%d", &a);
    printf("ingresa el segundo numero: \n"); 
    scanf("%d", &b);
    return a+b;
}

int rest ()
{
    int a,b;
    printf("resta: \n");
    printf("ingresa el primer numero: \n");  
    scanf("%d", &a);
    printf("ingresa el segundo numero: \n"); 
    scanf("%d", &b);
    return a-b;
}

int mult ()
{
    int a,b;
    printf("resta: \n");
    printf("ingresa el primer numero: \n");  
    scanf("%d", &a);
    printf("ingresa el segundo numero: \n"); 
    scanf("%d", &b);
    return a*b;
}

int main()
{   
    
    printf("el resultado de la suma es: %d\n", suma());
    printf("\n");
    printf("el resultado de la resta es: %d\n", rest());
    printf("\n");
    printf("el resultado de la multiplicacion es: %d\n", mult());
    printf("\n");

    return 0;
}