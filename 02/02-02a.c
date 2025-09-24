/*Crea un programa que lea una calificación numérica del usuario y asigne una
letra de calificación según el siguiente criterio:
90-100: A
80-89:  B
70-79:  C
60-69:  D
Menor a 60: F
Utiliza if, else if y else para implementar la lógica. ¿Hay una manera de
hacerlo más efectivo?*/

#include<stdio.h>

int main()
{
    int cal;
    printf("ingrese su calificacion \n");
    scanf("%d", &cal);
    if (cal>=90 & cal<=100)
    {
        printf("su calificacion es: A");
    }else if (cal>=80 & cal<=89)
    {
        printf("su calificacion es: B");

    }else if (cal>=70 & cal<=79)
    {
        printf("su calificacion es: C");

    }else if (cal>=60 & cal<=69)
    {
        printf("su calificacion es: D");

    }else if (cal<60)
    {
        printf("su calificacion es: F");

    }else
    {
        printf("calificacion incorrecta");
    }         

    return 0;
}
