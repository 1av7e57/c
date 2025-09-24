/*Pida al usuario ingresar un número que debe estar entre 1 y 8, y en
caso de estar dentro de este rango, imprimir la escalera de mario con
“#” simbolizando cada escalon, de la altura ingresada por el usuario.*/

#include <stdio.h>

int main() {
    int altura;

    printf("Ingresa un número entre 1 y 8: ");
    scanf("%d", &altura);

    if (altura >= 1 && altura <= 8) {
        for (int i = 1; i <= altura; i++) {
            for (int j = 1; j <= i; j++) {
                printf("#");
            }
            printf("\n");
        }
    } else {
        printf("El número ingresado no está en el rango permitido.\n");
    }

    return 0;
}