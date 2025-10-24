/*Ejercicio 1: Variables Locales y Globales
Objetivo: Practicar el uso de variables globales y locales, entendiendo el alcance de cada una.

1.Declara una variable global llamada contadorGlobal y una variable local llamada contadorLocal dentro de una función llamada incrementar.
2. Dentro de la función incrementar, aumenta en 1 el valor de ambas variables cada vez que se llama a la función.
3. En el main(), llama a la función incrementar() tres veces y muestra el valor de ambas variables después de cada llamada.*/

Preguntas:
¿Qué diferencia notas entre el comportamiento de la variable global y la local?
¿Por qué la variable local no conserva su valor entre llamadas?*/

#include <stdio.h>

// Declaración de la variable global
int contadorGlobal;

// Función que incrementa las variables
    void incrementar() {        
    int contadorLocal; // Declaración de la variable local     
        
    //Incremento de las variables
    contadorLocal++;
    contadorGlobal++;

}

int main() {
    
    int contadorLocal;// Declaracion para que la variable local sea utilizable dentro de main()

    //Llamamos tres veces a la funcion incrementar()
    incrementar();
    incrementar();
    incrementar(); 

    //Imprimimos los valores finales de las variables
    printf("contadorLocal = %d\n", contadorLocal);
    printf("contadorGlobal = %d\n", contadorGlobal);

    return 0;
}