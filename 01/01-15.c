/*Escribe un programa que defina una función convertirCelsiusAFahrenheit(), la
cual reciba una temperatura en grados Celsius y devuelva la temperatura
equivalente en Fahrenheit. Usa la fórmula: F=(C*9/5) + 32 . Desde main(),
solicita una temperatura en Celsius al usuario y muestra el resultado en
Fahrenheit.*/

#include <math.h>
#include <stdio.h>

int convertirCelsiusAFahrenheit(int c)
{
    return (c*9/5) + 32;
}


int main()
{
    int c;
    printf("ingrese una temperatura en grados celsius \n");
    scanf("%d", &c);

    printf("su equivalente en grados fahrenheit es: %d\n", convertirCelsiusAFahrenheit(c));


    return 0;
}
