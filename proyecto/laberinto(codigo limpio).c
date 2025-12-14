#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#define FILAS 17
#define COLUMNAS 33
int x = 1, y = 1;
int movimientos = 0;
typedef struct {
    int x, y, dist;
} Nodo;
void configurarTerminal();
char obtenerTecla();
void mostrarMenuInicio();
int calcularMinimosMovimientos(char laberinto[FILAS][COLUMNAS], int inicioX, int inicioY, int *salidaX, int *salidaY);
int cargarLaberinto(char laberinto[FILAS][COLUMNAS], const char *nombreArchivo);
void mostrarLaberinto(char laberinto[FILAS][COLUMNAS], int x, int y);
int validarMovimiento(char input);
void moverJugador(char laberinto[FILAS][COLUMNAS], int *x, int *y, char input);
void configurarTerminal() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN] = 1;
    newt.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}
char obtenerTecla() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN] = 1;
    newt.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
void mostrarMenuInicio() {
    printf("\033[2J\033[H");
    printf("╔══════════════════════════════════════╗\n");
    printf("║            LABERINTO                 ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ 1. Jugar                             ║\n");
    printf("║ 2. Salir                             ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Ingresa tu opción (1/2): ");
}
int calcularMinimosMovimientos(char laberinto[FILAS][COLUMNAS], int inicioX, int inicioY, int *salidaX, int *salidaY) {
    Nodo cola[1000];
    int frente = 0, cola_tamano = 0;
    bool visitado[FILAS][COLUMNAS];
    memset(visitado, 0, sizeof(visitado));
    cola[cola_tamano++] = (Nodo){inicioX, inicioY, 0};
    visitado[inicioX][inicioY] = true;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (frente < cola_tamano) {
        Nodo actual = cola[frente++];
        int x = actual.x, y = actual.y, dist = actual.dist;
        if (laberinto[x][y] == 'S') {
            *salidaX = x;
            *salidaY = y;
            return dist;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < FILAS && ny >= 0 && ny < COLUMNAS && !visitado[nx][ny] && laberinto[nx][ny] != '#') {
                visitado[nx][ny] = true;
                cola[cola_tamano++] = (Nodo){nx, ny, dist + 1};
            }
        }
    }
    return -1;
}
int cargarLaberinto(char laberinto[FILAS][COLUMNAS], const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("Error: No se pudo abrir el archivo %s\n", nombreArchivo);
        return 0;
    }
    for (int i = 0; i < FILAS; i++) {
        if (fgets(laberinto[i], COLUMNAS + 1, archivo) == NULL) {
            printf("Error: El archivo tiene menos de %d líneas.\n", FILAS);
            fclose(archivo);
            return 0;
        }
        int len = strlen(laberinto[i]);
        if (len > 0 && laberinto[i][len - 1] == '\n') {
            laberinto[i][len - 1] = '\0';
        }
        if (len < COLUMNAS) {
            printf("Error: Línea %d tiene menos de %d caracteres.\n", i + 1, COLUMNAS);
            fclose(archivo);
            return 0;
        }
    }
    fclose(archivo);
    return 1;
}
void mostrarLaberinto(char laberinto[FILAS][COLUMNAS], int x, int y) {
    printf("\033[2J\033[H");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (i == x && j == y) printf("J ");
            else printf("%c ", laberinto[i][j]);
        }
        printf("\n");
    }
}
int validarMovimiento(char input) {
    return (input == 'w' || input == 'a' || input == 's' || input == 'd' || input == 'q');
}
void moverJugador(char laberinto[FILAS][COLUMNAS], int *x, int *y, char input) {
    switch (input) {
        case 'w': if (*x > 0 && laberinto[*x - 1][*y] != '#') (*x)--; break;
        case 's': if (*x < FILAS - 1 && laberinto[*x + 1][*y] != '#') (*x)++; break;
        case 'a': if (*y > 0 && laberinto[*x][*y - 1] != '#') (*y)--; break;
        case 'd': if (*y < COLUMNAS - 1 && laberinto[*x][*y + 1] != '#') (*y)++; break;
        case 'q': return;
    }
}
int main() {
    configurarTerminal();
    while (1) {
        mostrarMenuInicio();
        char opcion = getchar();
        if (opcion != '1' && opcion != '2') {
            printf("\n");
            printf("Opción inválida.\n");
            printf("Presiona ENTER para intentar nuevamente...\n");
            while (getchar() != '\n');
            continue;
        }
        if (opcion == '2') {
            printf("Saliendo...\n");
            printf("Presiona ENTER para cerrar el programa...\n");
            return 0;
        }
        char laberinto[FILAS][COLUMNAS];
        if (!cargarLaberinto(laberinto, "laberinto.txt")) {
            printf("No se pudo cargar el laberinto.\n");
            continue;
        }
        int salidaX, salidaY;
        int minMovimientos = calcularMinimosMovimientos(laberinto, 1, 1, &salidaX, &salidaY);
        printf("\033[2J\033[H");
        printf("¡Bienvenido al Juego de Laberinto!\n");
        printf("Tu eres el jugador: J\n");
        printf("Encuentra la salida: S\n");
        printf("Intenta salir con: %d movimientos\n", minMovimientos);
        printf("Presiona cualquier tecla para comenzar...\n");
        getchar();
        x = 1, y = 1;
        movimientos = 0;
        while (1) {
            mostrarLaberinto(laberinto, x, y);
            if (laberinto[x][y] == 'S') {
                printf("\n¡Felicidades! Has completado el laberinto.\n");
                printf("Movimientos totales: %d\n", movimientos);
                printf("Presiona cualquier tecla para volver al Menú...\n");
                getchar();
                break;
            }
            printf("Ingresa tu movimiento (W/A/S/D) o Q para regresar al Menú: ");
            char input = obtenerTecla();
            input = tolower(input);
            moverJugador(laberinto, &x, &y, input);
            movimientos++;
            if (input == 'q') {
                printf("Regresando al menú...\n");
                break;
            }
        }
    }
    struct termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}