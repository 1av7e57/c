/*Crea un programa que lea una calificación numérica del usuario y asigne una
letra de calificación según el siguiente criterio:
90-100: A
80-89:  B
70-79:  C
60-69:  D
Menor a 60: F
Utiliza if, else if y else para implementar la lógica. ¿Hay una manera de
hacerlo más efectivo?*/

//formas de hacer el programa mas efectivo:

#include <stdio.h>

int main() {
    int cal;

    /*1-incluyendo un bucle do-while nos aseguramos que
    el programa vuelva a pedir la calificiacion si se
    ingresa un numero por fuera de el rango de 0 a 100*/

    do {
        //2-incluyendo esta linea especificamos al usuario el rango requerido
        printf("ingrese su calificacion en numeros del 0 al 100 \n");
        
        scanf("%d", &cal);
        
        /* 3-usamos el el operador lógico "o" ( || ) para especificar un rango
        y verificamos si la calificación ingresada por el usuario está fuera
        del rango permitido (0 a 100).*/
        if (cal < 0 || cal > 100) {
            printf("Calificación incorrecta. Intentelo nuevamente.\n");
            printf("\n");
        }

    } while (cal < 0 || cal > 100);

    /*4-especificando solo el rango de numeros mayores o iguales a
    el valor mas bajo evitamos especificar el valor mas alto*/

    if (cal >= 90) {
        printf("su calificacion es: A ");
    } else if (cal >= 80) {
        printf("su calificacion es: B ");
    } else if (cal >= 70) {
        printf("su calificacion es: C ");
    } else if (cal >= 60) {
        printf("su calificacion es: D ");
    } else {
        printf("su calificacion es: F ");
    }

    return 0;
}
