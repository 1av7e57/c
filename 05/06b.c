/*Ejercicio 6: Desafío Final: Variables Globales, Locales y Estáticas en Acción
Objetivo: Combinar todos los conceptos aprendidos.

1. Declara una variable global resultado que almacene el resultado de una operación.
2. Dentro de una función calcular(), declara una variable local resultado que se actualice con una suma. Usa también una variable estática contador para llevar la cuenta de cuántas veces se ha llamado a calcular().
3. Muestra el valor de resultado (tanto local como global) y el valor de contador cada vez que se llama a la función.

//Version adaptada al lenguaje C

#include <stdio.h>

int resultado = 100; // Variable global

void calcular() {
    int resultadoLocal = 10; // Variable local (El nombre fue modificado para que no oculte la variable global)
    static int contador = 0; // Variable estática
    contador++;
    resultadoLocal += 5;
    resultado += 5; // Modifica la variable global (en C no esta disponible el operador ::)
    printf("Resultado local: %d\n", resultadoLocal);
    printf("Resultado global: %d\n", resultado);
    printf("Contador de llamadas: %d\n\n", contador);
}

int main() {
    calcular();
    calcular();
    calcular();
    return 0;
}