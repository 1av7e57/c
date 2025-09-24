/*escribe un programa que calcule el area de un circulo.
usa una variable de tipo float para almacenar el radio y otra para el area.
el valor de pi puede ser 3.1416.*/

#include <math.h>
#include <stdio.h>

int main()
{
    float rad;
    float pi = 3.1416;

    printf("dime el radio de el circulo: \n");
    scanf("%f", &rad);   
    
    float pot = pow(rad, 2);
    float are = pi*pot;

    printf("el area del circulo es: %.2f \n", are);

    return 0;
}
