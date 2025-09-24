/*Desarrolla un programa que muestre un menú con las siguientes opciones:
1. Sumar dos números
2. Restar dos números
3. Multiplicar dos números
4. Dividir dos números
5. Salir
El usuario debe seleccionar una opción, y el programa debe solicitar los
números necesarios y mostrar el resultado utilizando la sentencia switch.*/

#include<stdio.h>

int main()
{
    int x, n1, n2;
    int sum, res, mul, div;
    inicio:
    printf("seleccione una tarea a realizar: \n");
    printf("1. Sumar dos números \n");
    printf("2. Restar dos números \n");
    printf("3. Multiplicar dos números \n");
    printf("4. Dividir dos números \n");
    printf("5. salir \n");
    printf("\n");
    scanf("%d", &x);
    printf("\n");
    switch (x)
    {
    case 1:
        printf("Suma de dos números: \n");        
        printf("ingrese el primer numero: \n");
        scanf("%d", &n1);
        printf("ingrese el segundo numero: \n");
        scanf("%d", &n2);
        sum=n1+n2;
        printf("el resultado de su suma es: %d\n", sum);
        break;
    
    case 2:
        printf("Resta de dos números: \n");
        printf("ingrese el primer numero: \n");
        scanf("%d", &n1);
        printf("ingrese el segundo numero: \n");
        scanf("%d", &n2);
        res=n1-n2;
        printf("el resultado de su resta es: %d\n", res);
        break;

    case 3:
        printf("multiplicacion de dos números: \n");
        printf("ingrese el primer numero: \n");
        scanf("%d", &n1);
        printf("ingrese el segundo numero: \n");
        scanf("%d", &n2);
        mul=n1*n2;
        printf("el resultado de su multiplicacion es: %d\n", mul);
        break;

    case 4:
        printf("division de dos números: \n");
        printf("ingrese el primer numero: \n");
        scanf("%d", &n1);
        printf("ingrese el segundo numero: \n");
        scanf("%d", &n2);
        div=n1/n2;
        printf("el resultado de su division es: %d\n", div);
        break;

    case 5: 
        printf("presione enter para salir \n");
        break;
    
    default: 
        printf("valor incorrecto \n");
        printf("intente nuevamente \n");
        printf("\n");
        goto inicio;

        break;
    }
   
    return 0;
}
