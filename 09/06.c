/*Ejercicio 6: Uso de new y delete
Escribe un programa que:
-Use new para crear un entero en el montón y lo
inicialice en 50.
-Imprima el valor y la dirección de este entero.
-Libere la memoria usando delete y verifique que
ya no se puede acceder a ese valor.*/

//Versión alternativa adaptada al lenguaje C

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Usar malloc para asignar memoria en el montón
    int *num = (int *)malloc(sizeof(int));
    
    if (num == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Inicializar el entero en 50
    *num = 50;

    // Imprimir el valor y la dirección
    printf("Valor: %d\n", *num);
    printf("Dirección: %p\n", (void *)num);

    // Liberar la memoria
    free(num);
    num = NULL;  // Establecer el puntero en NULL después de liberar

    if (num == NULL) {
        printf("La memoria ha sido liberada y el puntero es NULL ahora.\n");
    }

    return 0;
}

/*Notas:
En C, no existe la palabra clave new ni delete como en C++. 
En su lugar, se usan malloc y free para asignar y liberar memoria en el montón.
El programa imprime el valor y la dirección del entero asignado dinámicamente.
Después de liberar la memoria con free, el puntero num no se vuelve NULL, 
por lo que no se puede garantizar que el valor ya no sea accesible 
(aunque la memoria se haya liberado).
En este caso, se opta por establecer el puneto num en NULL 
manualmente después de liberar la memoria*/