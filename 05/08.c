/*Ejercicio 8: Juego de Adivinanza con un Contador Global

Enunciado:
Diseña un pequeño juego de adivinanza en el que el usuario debe adivinar un número del 1 al 10. El programa debe llevar la cuenta de cuántos intentos lleva el usuario antes de adivinar correctamente el número. Debes usar una variable global para contar los intentos y asegurarte de que el contador se mantenga hasta que el usuario adivine el número correcto.

Crea una función llamada adivinarNumero que genere el número aleatorio y solicite un número al usuario en cada intento.
Usa la variable global para contar los intentos e imprime el número de intentos al final.

Puntos a considerar:
¿Por qué se debe usar una variable global en este caso?
¿Cómo aseguras que el contador global se incremente con cada intento?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Variable global para contar los intentos
int intentos = 0;

// Función para generar el número aleatorio y manejar los intentos
void adivinarNumero() {
    int numeroAleatorio = rand() % 10 + 1;
    int numeroUsuario;

    printf("Adivina el número (1-10): \n");
    scanf("%d", &numeroUsuario);

    while (numeroUsuario != numeroAleatorio) {
        intentos++;
        printf("Intento incorrecto. Inténtalo de nuevo: \n");
        scanf("%d", &numeroUsuario);
    }

    intentos++; // Incrementar el contador para el intento correcto
    printf("¡Felicidades! Adivinaste el número en %d intentos.\n", intentos);
}

int main() {
    srand(time(0)); // Inicializar la semilla para números aleatorios
    adivinarNumero();
    return 0;
}