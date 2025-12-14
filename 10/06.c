/*Ejercicio 6: Agrupar y Calcular Totales por
Grupo
Modifica el programa anterior para calcular
el total de todos los números en cada grupo y
mostrar el total general al final.
Instrucciones:
-Muestra el total de cada grupo y el total
general de todos los números.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_GRUPOS 100  // Máximo número de grupos diferentes que se pueden manejar

// Definición de una estructura para almacenar los datos de cada grupo
typedef struct {
    int grupo;       // Número del grupo
    double total;    // Suma total de los números en el grupo
    int contador;    // Cantidad de números en el grupo
} datosGrupos;

int main() {
    // Abrir el archivo en modo lectura
    FILE *archivo = fopen("datos.txt", "r");
    if (!archivo) {   // Verificar si se pudo abrir el archivo (si no, imprime el mensaje apropiado)
        printf("No se pudo abrir el archivo.\n");
        return 1;  // Salir con error (1)
    }

    // Inicializar el array para almacenar los datos de los grupos
    datosGrupos arrayGrupos[MAX_GRUPOS] = {0};
    int contadorGrupos = 0;  // Contador de grupos procesados

    int numero;          // Variable para almacenar un número leído
    int grupo;           // Variable para almacenar el grupo correspondiente

    // Leer cada línea del archivo
    while (fscanf(archivo, "%d %d", &numero, &grupo) == 2) { // Verifica que se hayan leído correctamente dos valores (numero y grupo) antes de entrar al bucle

        int indice = -1;  // Índice del grupo en el array (inicializado a -1 para indicar que no se encuentra)

        // Buscar si el grupo ya existe en el array
        for (int i = 0; i < contadorGrupos; i++) {
            if (arrayGrupos[i].grupo == grupo) {
                indice = i;  // Si se encuentra, guardar el índice
                break;
            }
        }

        // Estructura de control "if" para decidir si el grupo ya existe
        if (indice == -1) { // Verifica si el grupo no existe en el array.
            // Si no existe, verificar si hay espacio disponible en el array
            if (contadorGrupos >= MAX_GRUPOS) {
                printf("Se alcanzó el número máximo de grupos.\n");
                fclose(archivo);  // Cerrar el archivo
                return 2;      // Salir con error (2)
            }

            // Si hay espacio y el grupo no existe (indice == -1): inicializar un nuevo grupo
            arrayGrupos[contadorGrupos].grupo = grupo;
            arrayGrupos[contadorGrupos].total = numero;
            arrayGrupos[contadorGrupos].contador = 1;
            contadorGrupos++;  // Incrementar el contador de grupos
        } else {
            // Estructura de control "else" para el caso en que el grupo ya existe
            // Si el grupo ya existe: actualizar el total y el contador
            arrayGrupos[indice].total += numero;
            arrayGrupos[indice].contador++;
        }
    }

    // Cerrar el archivo
    fclose(archivo);

    // Variable para almacenar el total general
    double totalGeneral = 0.0;

    // Estructura de control "for" para mostrar los resultados por cada grupo
    for (int i = 0; i < contadorGrupos; i++) {
        double promedio = arrayGrupos[i].total / arrayGrupos[i].contador;
        printf("Grupo %d: Total = %.2f, Promedio = %.2f\n", arrayGrupos[i].grupo, arrayGrupos[i].total, promedio);
        totalGeneral += arrayGrupos[i].total;
    }

    // Mostrar el total general
    printf("Total general de todos los números: %.2f\n", totalGeneral);

    return 0;  // Salir sin errores
}