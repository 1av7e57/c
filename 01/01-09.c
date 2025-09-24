/*Escribe un programa en el que el usuario ingrese dos números enteros. 
Usa variables para almacenar estos números y luego imprime la suma, resta,
multiplicación y división de esos números.*/

#include <math.h>
#include <stdio.h>

int main()
{
    int n1;
    int n2;
    printf("ingresa el primer numero entero \n");
    scanf("%d", &n1);
    printf("ingresa el segundo numero entero \n");
    scanf("%d", &n2);
    int sum = n1 + n2;
    int res = n1 - n2;
    int mul = n1 * n2;
    int div = n1 / n2;
    printf("la suma de ambos numeros es: %d\n", sum);
    printf("la resta de ambos numeros es: %d\n", res);
    printf("la multiplicacion de ambos numeros es: %d\n", mul);
    printf("la division de ambos numeros es: %d\n", div);
    
    return 0;

}