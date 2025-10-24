/*Ejercicio 4: Alcance de Variables Globales y Locales con el Mismo Nombre
Objetivo: Comprender cómo C maneja variables globales y locales con el mismo nombre.

//Version modificada para mostras ambas variables en C

#include <stdio.h>

// Variable global
int dato = 10;

void mostrarDato() {
    // Variable local con nombre diferente
    int datoLocal = 5;

    // Accedemos a la variable global
    printf("Valor de la variable global: %d\n", dato);
    printf("Valor de la variable local: %d\n", datoLocal);
}

int main() {
    mostrarDato();
    return 0;
}
