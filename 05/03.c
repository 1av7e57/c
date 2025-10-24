/*Ejercicio 3: Alcance en Bucles y Condicionales
Objetivo: Explorar cómo cambia el alcance de una variable cuando es declarada dentro de bucles o bloques condicionales.

1. Dentro del main(), crea un bucle for que se ejecute 5 veces.
2. Declara una variable int i dentro del bucle y otra variable int j fuera del bucle.
3. Muestra el valor de i y j dentro del bucle y fuera del bucle.

Preguntas:
¿Por qué no puedes acceder a i fuera del bucle?
¿Qué pasa con la variable j? ¿Por qué es accesible dentro y fuera del bucle?*/

#include <stdio.h>

int main() {
    int j = 10; // Variable declarada fuera del bucle

    for (int i = 0; i < 5; i++) { // Variable declarada dentro del bucle
        printf("Dentro del bucle: i = %d, j = %d\n", i, j);
    }

    printf("Fuera del bucle: j = %d\n", j);
    // printf("Fuera del bucle: i = %d\n", i); // Esto generaría un error

    return 0;
}