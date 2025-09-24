/*Escribe un programa que incluya comentarios de una línea y de varias líneas.
Asegúrate de que el programa funcione correctamente.*/

#include <stdio.h> //incluimos la libreria estandar de entrada/salida
#include <math.h> // incluimos la libreria de matematica

int main() //funcion principal
{
    float num; //declaramos la variable para el numero
    float raiz; //declaramos la variable para la raiz

    printf("ingrese un numero: "); /*usamos la funcion de salida printf 
                                    para imprimir texto en pantalla
                                    solicitando el numero al usuario*/

    scanf("%f," ,&num); /*usamos la funcion de salida scanf 
                           para guardar el numeor ingresado en
                           su respectiva variable*/

    raiz = sqrt(num); /*realizamos la operacion con la
                        funcion de raiz cuadrada sqrt
                        y asignamos el resultado como valor
                        a su variable correspondiente */

    printf("la raiz de %.2f = %.2f", num, raiz); /*imprimimos el valor de ambas variables
                                                    usando printf e indicamos su correspondencia*/
    
    return 0; /*si todo sale bien el programa deberia 
                retornar el valor 0 al finalizar indicando 
                una ejecucion exitosa*/

}