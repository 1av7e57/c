//Inclusión de librerías:

/*Proporciona funciones para manipulación de caracteres, se incluye 
para convertir la entrada del usuario a minúscula ('tolower()')*/
#include <ctype.h>

/*Permite usar el tipo de dato 'bool', para el array 'visitado', 
que necesita representar estados lógicos (visitado/no visitado) 
dentro de la función 'calcularMinimosMovimientos()'.*/
#include <stdbool.h>

/*Se utiliza para acceder a las funciones de entrada y salida estándar, 
como 'printf()' para mostrar mensajes al usuario, 
'getchar()' para leer caracteres del teclado , y 
'fgets()' para leer líneas del archivo 'laberinto.txt'.*/
#include <stdio.h>

/*Se incluye para usar 'memset()' en la función 'calcularMinimosMovimientos()' 
para inicializar el array 'visitado[FILAS][COLUMNAS]' con valores 'false' (0)*/
#include <stdlib.h>

/*Es necesaria para: 
'memset()' que inicializa el array 'visitado' para evitar errores en la lógica de búsqueda.
'strlen()' que verifica la longitud de las líneas del laberinto cargado desde el archivo.*/
#include <string.h>

/*Se utiliza para acceder a funciones y estructuras relacionadas con 
la configuración de la terminal, específicamente para deshabilitar el 
modo eco (reproducción de caracteres ingresados en la pantalla) y 
el modo canónico (permitiendo entrada sin necesidad de presionar Enter).*/
#include <termios.h>

/*Proporciona acceso a funciones de bajo nivel del sistema operativo.
Se usa en conjunto con '<stdio.h>' para la configuración de la terminal 
y la lectura de teclas en tiempo real.*/
#include <unistd.h>

/*Definición de constantes para representar las dimensiones del laberinto:
se utiliza para definir el tamaño del array 'laberinto[FILAS][COLUMNAS]'.*/
#define FILAS 17
#define COLUMNAS 33

// Variables globales:
/*Se utilizan para rastrear la posición actual del jugador y 
el número de movimientos realizados durante el juego.*/
int x = 1, y = 1; // Coordenadas de inicio del jugador, (1,1) Extremo superior izquierdo.
int movimientos = 0; // Calcula el total de movimientos realizados por el jugador.

// Definición de estructura 'nodo':
/*Esta estructura define un nuevo tipo de dato llamado `Nodo`, que agrupa 
tres enteros: las coordenadas `(x, y)` y la distancia (`dist`) desde el punto de inicio.
Se utiliza en la función `calcularMinimosMovimientos()` 
para implementar un algoritmo de búsqueda en anchura (BFS) 
para encontrar el camino más corto desde el inicio hasta la salida*/
typedef struct {
    int x, y, dist;
} Nodo;

// Declaración de funciones (prototipos):
void configurarTerminal(); // No devuelve nada, no toma parámetros.
char obtenerTecla(); // Devuelve un 'char', no toma parámetros.
void mostrarMenuInicio(); // No devuelve nada, no toma parámetros.
// Devuelve un 'int', toma una array 'laberinto', coordenadas de inicio, y punteros a coordenadas de salida.
int calcularMinimosMovimientos(char laberinto[FILAS][COLUMNAS], int inicioX, int inicioY, int *salidaX, int *salidaY);
// Devuelve un 'int', toma un array 'laberinto' y el nombre del archivo.
int cargarLaberinto(char laberinto[FILAS][COLUMNAS], const char *nombreArchivo);
// No devuelve nada, toma un array 'laberinto'' y las coordenadas del jugador.
void mostrarLaberinto(char laberinto[FILAS][COLUMNAS], int x, int y);
// No devuelve nada, toma un array 'laberinto', coordenadas del jugador, y un caractér como entrada.
void moverJugador(char laberinto[FILAS][COLUMNAS], int *x, int *y, char input);

// Definición de funciónes:

// Función para configurar la terminal
/*Configura la terminal para deshabilitar el modo canónico y el eco, 
permitiendo la lectura de teclas individuales sin necesidad de presionar Enter.
Se utiliza en `main()` y funciona en conjunto a 'obtenerTecla()' para preparar 
la entrada del usuario. Es esencial para la interacción en tiempo real del juego*/
void configurarTerminal() {
    /* Se declaran dos estructuras de tipo 'termios':
    'oldt' Almacena la configuración actual de la terminal.
    'newt' Almacena la nueva configuración que se aplicará.*/
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // Se obtiene la configuración actual de la entrada estándar y la guarda en 'oldt'
    newt = oldt; // Se copia la configuración actual ('oldt') a 'newt' para poder modificar solo los parámetros necesarios.
    newt.c_lflag &= ~(ICANON | ECHO); // Desactivar el modo canónico y eco
    newt.c_cc[VMIN] = 1; // Mínimo número de caracteres a leer se establece en 1
    newt.c_cc[VTIME] = 0; // Tiempo de espera se establece en 0
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Aplicar la nueva configuración a la terminal
}

// Función para obtener una tecla sin Enter
/*Lee un carácter del teclado en tiempo real, sin esperar a que el usuario presione Enter.
Se utiliza en el bucle principal del juego para capturar las teclas `w`, `a`, `s`, `d`, o `q`.
En conjunto con configurarTerminal() permite una entrada de teclas inmediata, lo que mejora la experiencia del usuario.*/
char obtenerTecla() {
    /* Se declaran dos estructuras de tipo 'termios':
    'oldt' Almacena la configuración actual de la terminal.
    'newt' Almacena la nueva configuración que se aplicará.*/
    struct termios oldt, newt; // Se obtiene la configuración actual de la entrada estándar y la guarda en 'oldt'
    tcgetattr(STDIN_FILENO, &oldt); // Se obtiene la configuración actual de la entrada estándar y la guarda en 'oldt'
    newt = oldt; // Se copia la configuración actual ('oldt') a 'newt' para poder modificar solo los parámetros necesarios.
    newt.c_lflag &= ~(ICANON | ECHO); // Desactivar el modo canónico y eco
    newt.c_cc[VMIN] = 1; // Mínimo número de caracteres a leer se establece en 1
    newt.c_cc[VTIME] = 0; // Tiempo de espera se establece en 0
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Aplicar la nueva configuración a la terminal
    char ch = getchar(); /*lee un solo carácter tan pronto como el usuario presiona una tecla (sin necesidad de Enter).  
    Este carácter es almacenado en 'ch'*/
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restaurar la configuración original del terminal
    return ch; // Devuelve la tecla leída
}

// Función para mostrar el menú de inicio
/* Muestra el menú principal del juego con las opciones "Jugar" y "Salir".
Se llama en `main()` para presentar graficamente al usuario con las opciones disponibles.*/
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

// Función para calcular el mínimo número de movimientos
/*Calcula el número mínimo de movimientos necesarios para llegar a la salida usando 
un  algoritmo BFS('Breadth-First Search' o 'Búsqueda de anchura').
Se llama en 'main()' antes de iniciar el juego para presentar al usuario un desafío.
Mejora la experiencia proporcionando una meta clara para el jugador.*/
int calcularMinimosMovimientos(char laberinto[FILAS][COLUMNAS], int inicioX, int inicioY, int *salidaX, int *salidaY) {
    // Se declara una cola de tipo 'nodo' para BFS (usando array estático)
    Nodo cola[1000];
    int frente = 0, cola_tamano = 0;
    // 'frente' representa el índice del primer elemento en la cola (donde se extraerá el siguiente nodo).
    // 'cola_tamano' indica cuántos nodos hay en la cola actualmente.

    // Se crea una Matriz booleana 'visitado'
    bool visitado[FILAS][COLUMNAS]; // Rastreará qué celdas del laberinto ya han sido visitadas durante la búsqueda.
    memset(visitado, 0, sizeof(visitado)); // Inicializa todos los valores a `false` (no visitado aún)

    // Iniciar BFS
    cola[cola_tamano++] = (Nodo){inicioX, inicioY, 0}; // Se inserta el nodo inicial (posición de inicio) en la cola con distancia 0.
    visitado[inicioX][inicioY] = true; // Se marca la posición de inicio como visitada.

    // Estos arrays definen los desplazamientos en las cuatro direcciones cardinales
    // Direcciones: (-1,0)arriba, (1,0)abajo, (0,-1)izquierda, (0,1)derecha
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Bucle principal del BFS
    while (frente < cola_tamano) { // El bucle continúa mientras haya nodos en la cola por procesar.
        Nodo actual = cola[frente++]; // Se extrae el primer nodo de la cola
        int x = actual.x, y = actual.y, dist = actual.dist; /* Se obtienen sus coordenadas ('x', 'y') 
        y la distancia acumulada desde el inicio ('dist').*/

        // Verificar si se encontró la salida
        if (laberinto[x][y] == 'S') { // Si la celda actual contiene 'S', se ha encontrado la salida.
            /*Se asignan las coordenadas de la salida a los parámetros de salida (`salidaX`, `salidaY`)*/
            *salidaX = x;
            *salidaY = y;
            return dist; // Se devuelve la distancia mínima desde el inicio hasta la salida.
        }

        // Probar los 4 movimientos
        for (int i = 0; i < 4; i++) { // Para cada una de las cuatro direcciones posibles:
            int nx = x + dx[i], ny = y + dy[i]; // - Se calcula la nueva posición ('nx', 'ny').
            if (nx >= 0 && nx < FILAS && ny >= 0 && ny < COLUMNAS && !visitado[nx][ny] && laberinto[nx][ny] != '#') {
                /* - Se verifica que esté dentro de los límites del laberinto.
                   - Se asegura que no haya sido visitada antes.
                   - Se verifica que no sea una pared ('#').*/
                   // Si todas las condiciones se cumplen: 
                visitado[nx][ny] = true; // - Se marca la nueva posición como visitada
                cola[cola_tamano++] = (Nodo){nx, ny, dist + 1}; // - Se agrega a la cola con una distancia incrementada en 1.S
            }
        }
    }

    return -1; /*Si el bucle termina sin encontrar la salida, se devuelve `-1`, 
    indicando que no hay camino posible desde el inicio hasta la salida.*/
}

// Función para cargar el laberinto desde un archivo
/*Carga el laberinto desde un archivo de texto.
Se llama en 'main()' para leer un patrón desde el archivo `laberinto.txt`.*/
int cargarLaberinto(char laberinto[FILAS][COLUMNAS], const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r"); // Se intenta abrir el archivo en modo lectura ("r").
    if (!archivo) { // Si el archivo no se puede abrir 'fopen' devuelve 'NULL'.
        printf("Error: No se pudo abrir el archivo %s\n", nombreArchivo); // En ese caso, se muestra un mensaje de error.
        return 0; //la función retorna `0` (indicando fallo en la carga del laberinto).
    }

    for (int i = 0; i < FILAS; i++) { // Se itera a través de las `FILAS` (17) del laberinto.
        if (fgets(laberinto[i], COLUMNAS + 1, archivo) == NULL) { // Lee una línea del archivo y la guarda en 'laberinto[i]'
            /*El tamaño del buffer es `COLUMNAS + 1` para asegurar que haya espacio para el carácter nulo (`\0`) que se añadirá al final de la cadena.
              Si 'fgets' devuelve 'NULL', significa que se alcanzó el final del archivo antes de leer todas las líneas.*/
            // En ese caso:  
            printf("Error: El archivo tiene menos de %d líneas.\n", FILAS); // Se muestra un mensaje de error.
            fclose(archivo); // Se cierra el archivo.
            return 0;
        }
        int len = strlen(laberinto[i]); // Se calcula la longitud de la línea leída.
        if (len > 0 && laberinto[i][len - 1] == '\n') { // Si la línea termina en un salto de línea (`\n`).
            laberinto[i][len - 1] = '\0'; // se reemplaza por el carácter nulo (`\0`) para que la cadena se termine correctamente.
        }
        // // Se verifica que la línea tenga exactamente el numero de COLUMNAS(caractéres).
        if (len < COLUMNAS) { // Si la longitud es menor: 
            printf("Error: Línea %d tiene menos de %d caracteres.\n", i + 1, COLUMNAS); // Se muestra un mensaje de error.
            fclose(archivo); // Se cierra el archivo.
            return 0; // Se retorna 0.
        }
    }
    // Fin de la función
    fclose(archivo); // Se cierra el archivo
    return 1; // Se retorna '1' (éxito) si todos los pasos se completaron correctamente.
}

// Función para mostrar el laberinto
/*Muestra el laberinto en la pantalla, con el jugador en su posición actual.
Se llama en el bucle principal del juego para actualizar la visualización.
Permite al jugador visualizar su progreso al recorrer el laberinto.*/
void mostrarLaberinto(char laberinto[FILAS][COLUMNAS], int x, int y) {
    printf("\033[2J\033[H"); // Limpia la pantalla y mueve al cursor al extremo superior izquierdo.
    for (int i = 0; i < FILAS; i++) { // Recorre cada celda del laberinto fila por fila...
        for (int j = 0; j < COLUMNAS; j++) { // y columna por columna.
            if (i == x && j == y) printf("J "); 
            /*Verifica si la celda actual (i,j) coincide con la posición del jugador (x,y)
            Si coincide, imprime "J " (caracter que identifica al jugador).*/
            else printf("%c ", laberinto[i][j]);
            // Si no coincide, imprime el contenido real, celda por celda, del laberinto.
        }
        printf("\n"); // Al final de cada fila, se inserta un salto de línea para mantener la estructura del laberinto
    }
}

// Función para mover al jugador
/*Mueve al jugador en el laberinto según la tecla presionada.
Se llama en el bucle principal del juego para actualizar la posición del jugador.
Es esencial para la interacción del jugador con el laberinto.*/
void moverJugador(char laberinto[FILAS][COLUMNAS], int *x, int *y, char input) {
    switch (input) { // Utiliza un 'switch' para evaluar el valor de 'input' y ejecutar el movimiento correspondiente según la tecla presionada.
        // Casos del 'switch' 
        /* Mover hacia arriba :
        -Verifica que el jugador no esté en la primera fila
        -Verifica que la celda de arriba no sea un muro
        Si ambas condiciones se cumplen, se decrementa *x (movimiento hacia arriba)*/
        case 'w': if (*x > 0 && laberinto[*x - 1][*y] != '#') (*x)--; break;
        /* Mover hacia  abajo :
        -Verifica que el jugador no esté en la última fila
        -Verifica que la celda de abajo no sea un muro.
        Si ambas condiciones se cumplen, se incrementa *x (movimiento hacia abajo).*/
        case 's': if (*x < FILAS - 1 && laberinto[*x + 1][*y] != '#') (*x)++; break;
        /* Mover hacia la izquierda : 
        -Verifica que el jugador no esté en la primera columna
        -Verifica que la celda de la izquierda no sea un muro.
        Si ambas condiciones se cumplen, se decrementa *y (movimiento hacia la izquierda).*/
        case 'a': if (*y > 0 && laberinto[*x][*y - 1] != '#') (*y)--; break;
        /* Mover hacia la derecha :
        -Verifica que el jugador no esté en la última columna.
        -Verifica que la celda de la derecha no sea un muro.
        Si ambas condiciones se cumplen, se incrementa *y (movimiento hacia la derecha).*/
        case 'd': if (*y < COLUMNAS - 1 && laberinto[*x][*y + 1] != '#') (*y)++; break;
        // Regresar al menú :
        case 'q': // Si el usuario presiona la tecla 'q'          
            return; // Sale de la función, (no termina el programa)
            // El control regresa al bucle principal del main, donde se puede volver al menú.
    }
}

// Función principal main:
int main() {

    // Llamada para configurar la terminal
    configurarTerminal();

    // Primer bucle (bucle del menú)
    while (1) { 

        // Llamada para imprimir menú de inicio
        mostrarMenuInicio();
        char opcion = getchar(); //Lee un carácter del teclado. El carácter leído se almacena en la variable 'opcion'.
        if (opcion != '1' && opcion != '2') { // Si el usuario ingresa algo distinto de '1' o '2'...
            // Se muestra un mensaje de error.
            printf("\n");
            printf("Opción inválida.\n");
            printf("Presiona ENTER para intentar nuevamente...\n");
            // Limpiar el resto del buffer de entrada
            while (getchar() != '\n'); // Descarta cualquier entrada adicional
            continue; // El bucle vuelve al inicio, mostrando nuevamente el menú.
        }
        if (opcion == '2') { // Si el usuario selecciona '2'...
            // Se muestra un mensaje de despedida
            printf("Saliendo...\n");
            printf("Presiona ENTER para cerrar el programa...\n");
            return 0; // El programa termina con return 0

            /*Cuando el usuario presiona '1' en el menú, 
            la condición if (opcion != '1' && opcion != '2') 
            se evalúa como 'false' porque opcion es '1'. 
            Por lo tanto, el bloque de código que maneja opciones inválidas
            no se ejecuta. 
            El programa pasa entonces a cargar el laberinto.*/
        }

        // Cargar laberinto
        /*Se declara una matriz de caracteres de tamaño FILAS x COLUMNAS
        para almacenar el laberinto leído desde el archivo.*/
        char laberinto[FILAS][COLUMNAS];
        if (!cargarLaberinto(laberinto, "laberinto.txt")) {
            printf("No se pudo cargar el laberinto.\n");
            continue;
        /*Se intenta cargar el laberinto desde el archivo laberinto.txt 
        usando la función cargarLaberinto. Si no se puede cargar:
        se muestra un mensaje de error y el bucle continúa, volviendo al menú.*/
        }

        // Calcular mínimos movimientos
        int salidaX, salidaY; // Se declaran dos variables enteras para almacenar las coordenadas (x, y) de la salida del laberinto.
        int minMovimientos = calcularMinimosMovimientos(laberinto, 1, 1, &salidaX, &salidaY);
        /*Se llama a la función calcularMinimosMovimientos() 
        para calcular el número mínimo de movimientos necesarios 
        para llegar desde la posición inicial (1,1) hasta la posición
        de salida (marcada con 'S').*/

        // Mostrar instrucciones
        printf("\033[2J\033[H"); // Limpia la pantalla y mueve al cursor al extremo superior izquierdo.
        /*Se muestra un mensaje de bienvenida 
        con instrucciones básicas y el número 
        mínimo de movimientos requeridos.*/
        printf("¡Bienvenido al Juego de Laberinto!\n");
        printf("Tu eres el jugador: J\n");
        printf("Encuentra la salida: S\n");
        printf("Intenta salir con: %d movimientos\n", minMovimientos);
        printf("Presiona cualquier tecla para comenzar...\n");
        getchar(); /*Se espera a que el usuario presione cualquier tecla para comenzar el juego. 
        Esto da tiempo al usuario para leer las instrucciones.*/

        // Reiniciar estado del juego
        x = 1, y = 1; // Se establece la posición inicial del jugador en (1,1)
        movimientos = 0; // Se reinicia el contador de movimientos a 0.

        // Segundo bucle (bucle del juego)
        // Se ejecuta mientras el jugador esté en el laberinto.
        while (1) {
            mostrarLaberinto(laberinto, x, y); // Llamada para mostrar el laberinto
            /*Verificar si se ha alcanzado la salida: 
            -Si la posición actual del jugador coincide con la salida ('S')...*/
            if (laberinto[x][y] == 'S') {
                // Se muestra un mensaje de felicitación.
                printf("\n¡Felicidades! Has completado el laberinto.\n");
                // Se muestra el número de movimientos realizados.
                printf("Movimientos totales: %d\n", movimientos);
                printf("Presiona cualquier tecla para volver al menú...\n");
                getchar(); // Esperar a que el usuario presione una tecla
                break;     // Salir del juego y volver al menú
            }

            // Se muestra un mensaje pidiendo al usuario una acción.
            printf("Ingresa tu movimiento (W/A/S/D) o Q para regresar al Menú: ");
            char input = obtenerTecla(); // Llamada para obtener el input del usuario
            input = tolower(input); // Se convierte la tecla ingresada a minúscula.

            moverJugador(laberinto, &x, &y, input); // Llamada para mover al jugador
            movimientos++; // Se incrementa el contador de movimientos cada vez que el jugador se mueve.

            // Verificar si el jugador presionó 'Q' para regresar al menú
            if (input == 'q') {
                // Si es así, se muestra un mensaje.
                printf("Regresando al menú...\n");
                break; // Se sale del bucle del juego y se vuelve al menú.
            }
        }
    }

    // Restaurar modo terminal original antes de terminar
    struct termios oldt; // Estructura que almacena la configuración original.
    tcgetattr(STDIN_FILENO, &oldt); // Obtener la configuración original.
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Volver a aplicar configuración original.

    return 0; // Final exitoso del programa
}