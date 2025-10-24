/*Ejercicio 2: Vida Útil de las Variables Estáticas
Objetivo: Entender cómo las variables estáticas conservan su valor entre llamadas a la misma función.

1. Modifica el código anterior agregando una variable static llamada contadorEstatico dentro de la función incrementar().
2. Aumenta su valor en 1 cada vez que se llama a la función.
3. Imprime el valor de contadorEstatico dentro de la función.

Preguntas:
¿Por qué la variable estática conserva su valor entre llamadas a la función?
¿Qué diferencia hay entre la vida útil de una variable local y una variable estática?*/


#include <stdio.h>

// declaracion de variable global
int contadorGlobal;

// Función que incrementa las variables
void incrementar(int *contadorEstaticoPtr) { //se usa un puntero para acceder a la variable desde main()
    
    int contadorLocal; // declaracion de variable local
    static int contadorEstatico = 0; // declaracion de variable estatica

    //incremento de las variables
    contadorLocal++;
    contadorGlobal++;
    contadorEstatico++;

    // Asigna el valor actual de contadorEstatico al puntero
    *contadorEstaticoPtr = contadorEstatico;
}

int main() {
    int contadorLocal;
    int contadorEstatico;

    for (int i = 0; i < 3; i++) {
        incrementar(&contadorEstatico); // Pasamos la dirección de contadorEstatico	
        printf("Después de la llamada %d:\n", i + 1);
        printf("contadorLocal = %d\n", contadorLocal);
        printf("contadorGlobal = %d\n", contadorGlobal);
        printf("contadorEstatico = %d\n\n", contadorEstatico);

    }

    return 0;
}