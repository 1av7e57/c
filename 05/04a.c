/*Ejercicio 4: Alcance de Variables Globales y Locales con el Mismo Nombre
Objetivo: Comprender cómo C++ maneja variables globales y locales con el mismo nombre.

1. Declara una variable global llamada dato y una variable local con el mismo nombre dato dentro de la función mostrarDato().
2. Dentro de la función, usa ::dato para acceder a la variable global y muestra su valor, junto con el valor de la variable local.
3. En el main(), llama a la función y muestra los resultados.

Preguntas:
¿Cómo distingue C++ entre la variable local y la global con el mismo nombre?
¿Por qué es necesario usar el operador :: para acceder a la variable global dentro de la función?*/

#include <stdio.h>

// Variable global
int dato = 10;

void mostrarDato() {
    // Variable local con el mismo nombre
    int dato = 5;

    // Accedemos a la variable global usando el operador de resolución de ámbito (::)
    printf("Valor de la variable global: %d\n", ::dato); //este operador no esta disponible en C por lo que al compilar se genera un error
    printf("Valor de la variable local: %d\n", dato);
}

int main() {
    mostrarDato();
    return 0;
}
