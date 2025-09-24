/*Investiga y usa las funciones de la biblioteca <math.h> para calcular la raíz
cuadrada de un número ingresado por el usuario. Imprime el resultado en
pantalla.*/

#include <stdio.h>
#include <math.h>
int main()
{
    float num;
    float raiz;

    printf("ingrese un numero: ");
    scanf("%f," ,&num);

    raiz = sqrt(num);

    printf("la raiz de %.2f = %.2f", num, raiz);
    
    return 0;
}