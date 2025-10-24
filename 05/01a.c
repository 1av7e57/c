/*Ejercicio 1: Variables Locales y Globales
Objetivo: Practicar el uso de variables globales y locales, entendiendo el alcance de cada una.

1.Declara una variable global llamada contadorGlobal y una variable local llamada contadorLocal dentro de una función llamada incrementar.
2. Dentro de la función incrementar, aumenta en 1 el valor de ambas variables cada vez que se llama a la función.
3. En el main(), llama a la función incrementar() tres veces y muestra el valor de ambas variables después de cada llamada.*/

#include <stdio.h>

// Declaracion de la variable global
int contadorGlobal;

// Función que incrementa las variables
void incrementar() {
  int contadorLocal; // Declaracion de la variable local

  //Incremento de las variables
  contadorLocal++;
  contadorGlobal++;
}

int main() {
    // Llamamos tres veces a la funcion incrementar()
    incrementar();
    incrementar();
    incrementar();

    // Mostrar valores finales de las variables
    printf("contadorGlobal = %d\n", contadorGlobal);
    // contadorLocal no es accesible directamente en main()

    return 0;
}